#include "include.h"
/*
    funções de cli, e menus

    ainda em desemvolvimento
*/
void principal()
{
    printf("    ============================\n\n");
    printf("        Seja muito Bem-vindo \n ");
    printf("           linux-ultils\n           pre-alfa-0.0.1    \n\n");
    printf("    ============================\n\n");
}
int menu_principal()
{
    //deve sempre aparecer no inicio do loop
    int a=0;
    printf("\n         ====================\n            MENU PRINCIPAL      \n         ====================\n");
    printf("     esloclha uma das opções abaixo\n         ====================\n");

    printf("(1)Utilidades\n(2)Dev's\n(3)games\n(4)my_selection\n(5)sobre\n(6)sair\n\n");
    scanf("%d", &a);

    return a;
}

void my_selection()
{
    int resp = 0;

    system("clear"); 
    puts("insto instalara todas os pacotes que eu jungo nesesario");
    puts("os seguintes pacotes serão instalados");
    printf("==steam==\n==Eroic(flatpak)===\n==Bottles(flatpak)==\n==Gamemode--Gamescop(flatapak e nativo)==\n\n");
    puts("--isto gera um log em log/log.md");
    puts("Deseja instalar os pacotes (digite 1 para sim, digite 2 para não)");   
    scanf("%d", &resp);

    if (resp == 1)
    {
        system("./shell_full/my_selection.sh");
               
    }
    
    else if(resp == 2)
    {
        puts("OK cancelando");
    }

    else 
    {
        puts("opção não encontrada");
    }

}

// instalçao de aplicatiovos

void install_apps(int a) {
    
    /*
        menu-utils
    */

    if(a == 1) {
        //code
    }

    else if(a == 2) {
        //code
    }

    else if(a == 3) {
      //code
    }

    else if (a == 4) {
      //code
    }
    else if (a == 5) {

    }

    else if(a == 6){
        puts("Opção não encontrada");
    }

    /*
        fim do menu-ultis
    */

    else {
        printf("opção não encontrada\n");
    }


}
//menus de instalar apps

int menu_ultis()
{
    int resp = 0;

    system("clear");
    printf("==== ULTILIDADES ====\n\n");
    printf("(1)Flatsea\n(2)Warhause\n(3)Fragimentador de arquivos \n(4)Peazip\n(5)Sair\n\n");
    printf("Digite o app desejado\n");
    scanf("%d", &resp);
    if(resp > 0 && resp < 6)
    {
        return resp;
    }
    else
    {
        return 6;   
    }

}

int menu_dev()
{
    int i = 0;

    return i;
}

int menu_games()
{
    int resp = 0;
    
    return resp;
}

void sobre()
{
    //provisorio espro achar um jeito melhor de fazer isso 
    //provavelmente em um siate ou em um .html
    //se for assim eu vou presisar criar um pasta escondida em com o arquivo .html .css .js para se o usuario auterar ele ter uma copia de segurança 
    //mas por agora eu vou somente usar um cat, ou outro comando para mostrar o sobre.md que é um arquivo provisorio.
    //ou somente rediresionar para o meu saite pessoao ou meu github, mas por agora eu vou usar a o terminal.
    
    printf("\n");
    system("echo 'ainda não esta pronto, mas se quiser pode in no meu github https://github.com/kewynlong'");

}
