#!/bin/bash
# Script simplificado de instalação de ferramentas para jogos
# Autor: Auto-util-main
# Versão: pre alfa 0.0.1

set -e  # Sai no primeiro erro

# Configurações - log no diretório atual
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
LOG_DIR="$SCRIPT_DIR/log"
LOG_FILE="$LOG_DIR/install_log_$(date +%Y%m%d_%H%M%S).md"
INSTALLED_PACKAGES=()

# Cores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Inicializa sistema de logs
init_logs() {
    mkdir -p "$LOG_DIR"
    echo "# Log de Instalação - $(date '+%d/%m/%Y %H:%M:%S')" > "$LOG_FILE"
    echo "## Script: $(basename "$0")" >> "$LOG_FILE"
    echo "## Diretório: $SCRIPT_DIR" >> "$LOG_FILE"
    echo "---" >> "$LOG_FILE"
    echo "" >> "$LOG_FILE"
    
    log_msg "INFO" "Iniciando instalação"
    log_msg "INFO" "Log será salvo em: $LOG_FILE"
}

# Funções de logging
log_msg() {
    local level="$1"
    local msg="$2"
    local timestamp=$(date '+%Y-%m-%d %H:%M:%S')
    
    # Output para terminal
    case $level in
        "INFO") echo -e "${GREEN}[INFO]${NC} $msg" ;;
        "WARN") echo -e "${YELLOW}[WARN]${NC} $msg" ;;
        "ERROR") echo -e "${RED}[ERROR]${NC} $msg" ;;
    esac
    
    # Escreve no arquivo de log (formato Markdown)
    echo "**$timestamp [$level]** $msg" >> "$LOG_FILE"
}

# Verifica se é root
check_root() {
    if [[ $EUID -ne 0 ]]; then
        log_msg "ERROR" "Este script requer privilégios de superusuário"
        log_msg "INFO" "Execute com: sudo $0"
        exit 1
    fi
}

# Atualiza sistema
update_system() {
    log_msg "INFO" "Atualizando repositórios do sistema..."
    apt-get update -y 2>> "$LOG_FILE"
    
    log_msg "INFO" "Atualizando pacotes instalados..."
    apt-get upgrade -y 2>> "$LOG_FILE"
}

# Instala pacote com verificação
install_package() {
    local name="$1"
    local cmd="$2"
    local pkg_name="$3"
    
    log_msg "INFO" "Verificando $name..."
    
    # Verifica se já está instalado
    if [[ -n "$pkg_name" ]]; then
        if dpkg -l | grep -q "$pkg_name"; then
            log_msg "INFO" "$name já está instalado"
            INSTALLED_PACKAGES+=("$name (já existia)")
            return 0
        fi
    fi
    
    log_msg "INFO" "Instalando $name..."
    echo "" >> "$LOG_FILE"
    echo "### Comando: $cmd" >> "$LOG_FILE"
    echo '```bash' >> "$LOG_FILE"
    
    if eval "$cmd" 2>> "$LOG_FILE"; then
        echo '```' >> "$LOG_FILE"
        echo "**Resultado:** Sucesso ✓" >> "$LOG_FILE"
        INSTALLED_PACKAGES+=("$name")
        log_msg "INFO" "$name instalado com sucesso"
        return 0
    else
        echo '```' >> "$LOG_FILE"
        echo "**Resultado:** Falha ✗" >> "$LOG_FILE"
        log_msg "ERROR" "Falha ao instalar $name"
        return 1
    fi
}

# Instala Steam
install_steam() {
    log_msg "INFO" "Configurando Steam..."
    
    # Multilib para 64-bit
    if [[ $(uname -m) == "x86_64" ]]; then
        dpkg --add-architecture i386
        apt-get update -y 2>> "$LOG_FILE"
    fi
    
    install_package "Steam" \
        "apt-get install -y steam-installer libgl1-mesa-glx:i386 libc6:i386" \
        "steam-installer"
}

# Instala Flatpak básico
setup_flatpak() {
    if ! command -v flatpak &> /dev/null; then
        install_package "Flatpak" \
            "apt-get install -y flatpak && flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo" \
            "flatpak"
    else
        log_msg "INFO" "Flatpak já está instalado"
    fi
}

# Instala Heroic (Flatpak)
install_heroic() {
    setup_flatpak
    
    # Verifica via flatpak
    if flatpak list | grep -q com.heroicgameslauncher; then
        log_msg "INFO" "Heroic já está instalado"
        INSTALLED_PACKAGES+=("Heroic Games Launcher (já existia)")
        return
    fi
    
    install_package "Heroic Games Launcher" \
        "flatpak install -y flathub com.heroicgameslauncher" \
        ""
}

# Instala Bottles (Flatpak)
install_bottles() {
    setup_flatpak
    
    if flatpak list | grep -q com.usebottles.bottles; then
        log_msg "INFO" "Bottles já está instalado"
        INSTALLED_PACKAGES+=("Bottles (já existia)")
        return
    fi
    
    install_package "Bottles" \
        "flatpak install -y flathub com.usebottles.bottles" \
        ""
}

# Instala Gamemode
install_gamemode() {
    install_package "Gamemode" \
        "apt-get install -y gamemode gamemode-daemon" \
        "gamemode"
}

# Instala Gamescope
install_gamescope() {
    install_package "Gamescope" \
        "apt-get install -y gamescope" \
        "gamescope"
}

# Instala dependências essenciais
install_deps() {
    log_msg "INFO" "Instalando dependências básicas..."
    
    install_package "Dependências Vulkan" \
        "apt-get install -y mesa-vulkan-drivers vulkan-tools" \
        ""
    
    install_package "Dependências gráficas" \
        "apt-get install -y libgl1-mesa-glx libglu1-mesa libopenal1" \
        ""
}

# Mostra resumo
show_summary() {
    echo "" >> "$LOG_FILE"
    echo "---" >> "$LOG_FILE"
    echo "## RESUMO DA INSTALAÇÃO" >> "$LOG_FILE"
    echo "**Data:** $(date '+%d/%m/%Y %H:%M:%S')" >> "$LOG_FILE"
    
    echo -e "\n${GREEN}════════════════════════════════════════════════${NC}"
    echo -e "${GREEN}✅ INSTALAÇÃO CONCLUÍDA${NC}"
    echo -e "${GREEN}════════════════════════════════════════════════${NC}"
    
    echo -e "\n${YELLOW}📦 Status dos pacotes:${NC}"
    
    if [ ${#INSTALLED_PACKAGES[@]} -gt 0 ]; then
        for pkg in "${INSTALLED_PACKAGES[@]}"; do
            echo -e "  ${GREEN}✓${NC} $pkg"
            echo "- ✓ $pkg" >> "$LOG_FILE"
        done
    else
        echo -e "  ${YELLOW}⚠️ Nenhum pacote foi instalado${NC}"
        echo "- ⚠️ Nenhum pacote foi instalado" >> "$LOG_FILE"
    fi
    
    echo -e "\n${YELLOW}📋 Log completo salvo em:${NC}"
    echo -e "  $LOG_FILE"
    echo "" >> "$LOG_FILE"
    echo "**Local do log:** \`$LOG_FILE\`" >> "$LOG_FILE"
    
    echo -e "\n${GREEN}════════════════════════════════════════════════${NC}"
}

# Função principal
main() {
    echo -e "${GREEN}Instalador de Ferramentas para Jogos${NC}"
    echo -e "${YELLOW}Script: $(basename "$0")${NC}"
    echo -e "${YELLOW}Diretório: $SCRIPT_DIR${NC}\n"
    
    check_root
    init_logs
    update_system
    install_deps
    
    # Instala todos os pacotes
    log_msg "INFO" "Iniciando instalação dos pacotes..."
    install_steam
    install_heroic
    install_bottles
    install_gamemode
    install_gamescope
    
    show_summary
}

# Executa
if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi
