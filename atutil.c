// auto install linux mint
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "kew.h"

int main(void){
	//localidade do teclado
	setlocale(LC_ALL, "PORTUGUESE");

	//variaveis
	int desi=0;
	int d[2];
	char resf = 's';

	do{

		 //começo do promgrama

		system("clear");
		printf("seja bem vindo ao atutil minha feramenta de auto instalacao para linux(Somente para ubuntu e linux mint, mas vou espandir para outras plataformas)\n");
		 
		// menu principal

		printf("(1)Produtividade\n(2)jogos\n(3)dev\n(4)sair\n");
		scanf("%d", &desi);
		//caso for 1
		if(desi == 1){
			system("clear");
			printf("qual programas voce deseja instalar?\n (1) ONLYOFFICE\n (2) Warehouse\n (3) Flatseal\n (4) sair\n");
			scanf(" %d", &desi);
			switch(desi){
				case 1:
					de1();
					break;
				case 2:
					de2();
					break;
				case 3:
					de3();
					break;
				case 4:
					de4();
					break;
			}
		}
		// caso for 2
		else if(desi == 2){
			menu2();
			scanf(" %d", &d[0]);
			switch(d[0]){
				case 1:
					insta1();
					break;
				case 2:
					insta2();
					break;
				case 3:
					insta3();
					break;
				case 4:
					insta4();
					break;
				default:
					printf("opção invalida\n");
			}
		}
		// caso for 3
		else if(desi == 3){
			d[1] = menu3();
			if(d[1] == 1)
			{
				dev_in1();
			}
			else if (d[1] == 2)
			{
				dev_in2();
			}
			else if (d[1]==3)
			{
				dev_in3();
			}
			
		}
		// caso for 4
		else if(desi == 4){
			printf("fim do programa\n");
			return 0;
		}
		else
		{
			printf("opção invalida\n");
		}
		
		printf("\n");
		printf("\ndeseja instalar mais alguma coisa? (s)sim (n)não: \n");
		scanf(" %c", &resf);
		
		// onde o loop termina se o usuario quiser
	}while(resf == 's' || resf == 'S');

	printf("fim do programa\n");

	return 0;
}
