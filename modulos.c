include "include.h"
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

    printf("()Utilidades\n()Dev's\n()games\n()my_selection\n()sobre\n()sair\n\n");

    return a;
}

void my_selection()
{
    int resp = 0;

    system("clear"); 
    puts("insto instalara todas os pacotes que eu jungo nesesario");
    puts("os seguintes pacotes serão instalados");
    printf("==steam==\n==Eroic(flatpak)===\n==Bottles(flatpak)==\n==Gamemode--Gamescop(flatapak e nativo)==\n\n");
    puts("Deseja instalar os pacotes (digite 1 para sim, digite 2 para não)");
    scanf("%d", &resp);

    if (resp == 1)
    {
        system("");
        system("");
        system("");
        system("");
               
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

int install_apps(int a) {
    
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

    return;

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
    if(resp > 0 && resp == < 6)
    {
        return resp;
    }
    else
    {
        return 6;   
    }

}