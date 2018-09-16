#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tipos.c"
#include"AddMochila.c"
#include "leituraEEscrita.c"

//Função Principal

int main(int argc, char *argv[]){

	int CapacidadeDaMochila, tamanhoDalista;
	ITEM * listaDeItens;

	//Verifica se os parametros na linha de comado foram passados adequadamente

	if(argc != 2){
		printf("SINATXE:  *.out File\n");
		exit(1);
	}

	//leietura do arquivo

	lerArquivo( &CapacidadeDaMochila, &tamanhoDalista, &listaDeItens,  argv[1]);

	//Printo lista gerada a partir do arquivo

	//printaLista( listaDeItens, tamanhoDalista);

	//Add itens a mochila

	//printf("Mochila: \n");
	addItensAMochila_guloso(listaDeItens, CapacidadeDaMochila, tamanhoDalista);

	//Printo itens na mochila

	//printaItensNaMochila( listaDeItens, tamanhoDalista);

	//Crio string para abrigar nome de arquivo de saida do alg. guloso

	char arquivoDeSaida[strlen(argv[1]) + 9]; 
	memcpy( arquivoDeSaida, "(guloso)\0", 9);

	//Gero nome do arquivo de sáida sendo (guloso):argv[1]

	strcat( arquivoDeSaida, argv[1]);

	saidaNoArquivo( listaDeItens, tamanhoDalista, arquivoDeSaida);

	return 0;

}//end main
