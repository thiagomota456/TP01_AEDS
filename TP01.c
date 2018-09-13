#include<stdio.h>
#include<stdlib.h>
#include "tipos.c"
#include "leitura.c"

//Função Principal

int main(){

	int CapacidadeDaMochila;
	ITEM * listaDeItens;

	lerArquivo(&CapacidadeDaMochila,listaDeItens,"Documento sem título.txt\0");

	//teste de leitura da capacidade da mochila

	printf("Capacidade da Mochila: %d\n", CapacidadeDaMochila);

	return 0;

}//end main
