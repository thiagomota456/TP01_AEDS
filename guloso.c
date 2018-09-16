#include<stdio.h>
#include<stdlib.h>
#include "tipos.c"
#include"AddMochila.c"
#include "leituraEEscrita.c"

//Função Principal

int main(int argc, char *argv[]){

	int CapacidadeDaMochila, tamanhoDalista;
	ITEM * listaDeItens;

	//Verifica se os parametros na linha de comado foram passados adequadamente

	if(argc != 2){
		printf("SINATXE: gcc tentativa_e_erro.c File\n");
		exit(1);
	}

	//leietura do arquivo

	lerArquivo( &CapacidadeDaMochila, &tamanhoDalista, &listaDeItens,  argv[1]);

	//Printo lista gerada a partir do arquivo

	printaLista( listaDeItens, tamanhoDalista);

	//Add itens a mochila

	printf("Mochila: \n");
	addItensAMochila_guloso(listaDeItens, CapacidadeDaMochila, tamanhoDalista);

	//Printo itens na mochila

	printaItensNaMochila( listaDeItens, tamanhoDalista);

	saidaNoArquivo( listaDeItens, tamanhoDalista,  argv[1]);

	return 0;

}//end main
