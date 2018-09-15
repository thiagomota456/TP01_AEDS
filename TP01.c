#include<stdio.h>
#include<stdlib.h>
#include "tipos.c"
#include"guloso.c"
#include "leituraEEscrita.c"

//Função Principal

int main(){

	int CapacidadeDaMochila, tamanhoDalista;
	ITEM * listaDeItens;

	//leietura do arquivo

	lerArquivo( &CapacidadeDaMochila, &tamanhoDalista, &listaDeItens, "Documento sem título.txt\0");
	printaLista( listaDeItens, tamanhoDalista);
	printf("Ordenado: \n");
	ordenaDecrecente(listaDeItens, tamanhoDalista);
	printaLista( listaDeItens, tamanhoDalista);

	return 0;

}//end main
