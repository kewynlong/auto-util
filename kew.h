//minha biblioteca para o beta do app de utilidades aprendi c esse ano se tiver bugs to aprendendo a usar essa linguagem infernal
//que eu presiso de 4 linhas para imprimir um "olá mundo" obs:necessito de ajuda.
//abrir o terminal pois não quero fazer interface grafica

//quando o usuario digita uma letra o programa so termina
//tenho que corigir isso


//exibir menus
void menu2(){
	system("clear");
	printf("qual é o programa que voce deseja instalar?\n");
	printf("(1)steam\n (2)Lutris\n (3)Heroic \n (4)cancelar\n");
}
int menu3() {
	int a=0;
	system("clear");
	printf("qual desses programas que voce quer instalar\n");
	printf("(1)vscode\n(2)notepad next next\n(3)vscodium\n");
	scanf("%d", &a);
	return a;
}
/*
	fazer com que a função retorne se deu certo ou errado mas por agora e melhor eu terminar deixar funcional e depois colocar detalhes
*/
//install do menu 1 (sujeito a melhoras)
void de1(){
	system("flatpak install flathub org.onlyoffice.desktopeditors");
}

void de2(){
	system("flatpak install flathub io.github.flattool.Warehouse");
}

void de3(){
	system("flatpak install flathub com.github.tchx84.Flatseal");
}

int de4(){
	printf("fim do programa\n");
	return 0;
}

//install do menu 2
void insta1(){
	int a = 0;
	printf("qual você quer instalar native(1(somete para distros baseadas em debian e ubuntu)) ou flatpak(2(universal))\n");
	scanf("%d", &a);
	if(a == 1)
	{
	system("wget https://steamcdn-a.akamaihd.net/client/installer/steam.deb");
    system("sudo dpkg -i steam.deb");
    system("sudo apt install -f");
	}
	else if(a == 2)
	{
		system("flatpak install flathub com.valvesoftware.Steam");
	}
	else
	{
		printf("opção invalida\n");
	}
}

void insta2(){
	int a = 0;
	printf("qual você deseja instalar ?\n(1(somente para debian, ubuntu e dereivados))nativo\n(2(universal))flatpak\n");
	scanf("%d", &a);
	if(a == 1)
	{
		system("sudo apt update && sudo apt install lutris -y");
	}

	else if(a == 2)
	{
		system("flatpak install flathub net.lutris.Lutris");
	}
	else{
		printf("opção invalida\n");
	}
}

void insta3(){
	//isso vai ser temporario (eu espero), tenho que achar uma maneira melhor
	//por que esse metodo e meio bruto
	 int a = 0;
    printf("Qual você deseja instalar?\n");
    printf("(1 - Somente para Debian, Ubuntu e derivados) Nativo\n");
    printf("(2 - Universal) Flatpak\n");
    scanf("%d", &a);

    if(a == 1)
    {
        system("curl -s https://api.github.com/repos/Heroic-Games-Launcher/HeroicGamesLauncher/releases/latest | grep \"browser_download_url.*deb\" | cut -d : -f 2,3 | tr -d \\\" | wget -qi -");
        system("sudo dpkg -i heroic_*.deb");
        system("sudo apt install -f");
    }
    else if(a == 2)
    {
        system("flatpak install flathub com.heroicgameslauncher.hgl");
    }
    else
    {
        printf("Opção inválida!\n");
    }
}
void insta4(){
	printf("cancelando\n...\n...");
}
int dev_in1(){
	int a=0;
	a = system("flatpak install flathub com.visualstudio.code");
	return a;
}
int dev_in2(){
	int a=0;
	a = system("flatpak install flathub com.github.dail8859.NotepadNext");
	return a;
}
int dev_in3(){
	int a = 0;
	a = system("flatpak install flathub com.vscodium.codium");
	return a;
}
