// auto install linux mint
#include <stdio.h>
#include <stdlib.h>
#include "kew.h"

int main(void){
	system("clear");
	setlocale(LC_ALL, "");

	//variaveis
	int desi=0;

	printf("seja bem vindo ao atutil minha feramenta de auto istalação para linux(Somente para ubuntu e linux mint, mas vou espandir para outras plataformas)\n");
	
	printf("(1)Produtividade\n(2)jogos(não está pronto ainda)\n(3)dev(não está pronto ainda)\n(4)sair(não esta pronto ainda)\n");
	scanf("%d", &desi);
	if(desi == 1){
		system("clear");
		printf("qual programas você deseja instalar?\n (1) ONLYOFFICE\n (2) Warehouse\n (3) Flatseal\n (4)outro (não esta pronto ainda)\n (5) sair\n");
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
			case 5:
				de5();
				break;
			
		}
	}
	return 0;

}
