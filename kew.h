#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//exibir menus 
void menu2(){
	system("clear");
	printf("qual e o programa que voce deseja instalar?\n");
	printf("(1)steam\n (2)Lutris\n (3)Heroic \n (4)cancelar\n");
}

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
	printf("qual você quer instalar native(1) ou flatpak(2)\n");
	scanf("%d", &a);
	if(a == 1)
	{
		printf("ainda não disponivel");
	}
	else if(a == 2)
	{
		system("echo tudo certo");
	}
}

void insta2(){
	system("echo tudo certo 2");
}

void insta3(){
	system("echo tudo certo 3");
}
void insta4(){
	printf("tudo certo");
}
