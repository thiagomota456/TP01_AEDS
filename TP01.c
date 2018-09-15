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

	//Printo lista gerada a partir do arquivo

	printaLista( listaDeItens, tamanhoDalista);

	//Add itens a mochila

	printf("Mochila: \n");
	addItensAMochila(listaDeItens, CapacidadeDaMochila, tamanhoDalista);

	//Printo itens na mochila

	printaItensNaMochila( listaDeItens, tamanhoDalista);

	

	return 0;

}//end main
