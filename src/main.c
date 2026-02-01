/*
    minhas feramenta para pos-instalação de linux mint ou quaquer sistema de base Debian
    ou ubuntu pretendo expandir para outras plataformas

    ver. refatorada pre-alfa-0.0.1
*/
#include "include.h"


int main(void)
{
    //variaveis

    int des=0;
    char res = 's';

    do{
        //toda a logica do codigo esta aqui
        // loop principal

        des = 0;
        system("clear");  
        principal();

        des = menu_principal();
        if(des == 1)
        {
            install_apps(menu_ultis());
        }
        else if (des == 2)
        {
            install_apps(menu_dev());
        }
        else if(des == 3){
            install_apps(menu_games());
        }
        else if(des == 4)
        {
            my_selection();
        }
        else if(des == 5)
        {
             sobre();
        }
        else if(des == 6)
        {
            puts("ok saindo...");
        }
        else
        {
            printf("opão não encontrada, porfavor tente novamente\n");
        }



        printf("\n\ndeseja instalar mais alguma coisa?\n(s)sim\n(n)não\n");
        scanf(" %c", &res);

    }while(res == 's' || res == 'S');


    printf("\nfim do progrma\n");

    return 0;

}
