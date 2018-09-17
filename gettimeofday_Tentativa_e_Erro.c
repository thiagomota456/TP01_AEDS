/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Thiago Soares Mota
Matricula: 201722040394
Descricao do programa: medição de tempo
Data: 16/09/2018
************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tipos.c"
#include"AddMochila.c"
#include "leituraEEscrita.c"

/* Teste da medicao do tempo*/

int main(int argc, char *argv[]){

	// Variaveis relacionadas com a medicao do tempo:

	struct timeval inicio, fim;

	/*estrutura que armazena o tempo total que o programa gasta, relaciona-se com a funcao gettimeofday()*/

	long totalmicroseg, totalseg;

	//tempo total do programa
	/* armazenam a diferenca entre o tempo inicial e o final, ou seja, o tempo total gasto pelo programa todo. */
	//obtendo o tempo em que o programa comeca.

	gettimeofday(&inicio, NULL);

	/****************************************************************/
	//coloque aqui o algoritmo

	int CapacidadeDaMochila, tamanhoDalista;
	ITEM * listaDeItens;

	//Verifica se os parametros na linha de comado foram passados adequadamente

	if(argc != 2){
		printf("SINATXE:  *.out File\n");
		exit(1);
	}

	//leietura do arquivo

	lerArquivo( &CapacidadeDaMochila, &tamanhoDalista, &listaDeItens, argv[1]);

	addItensAMochila_tentativaEErro(listaDeItens, CapacidadeDaMochila, tamanhoDalista);

	char arquivoDeSaida[strlen(argv[1]) + 19]; 
	memcpy( arquivoDeSaida, "(Tentativa_e_Erro)\0", 19);

	//Gero nome do arquivo de sáida sendo (Tentativa_e_Erro):argv[1]

	strcat( arquivoDeSaida, argv[1]);

	saidaNoArquivo( listaDeItens, tamanhoDalista, arquivoDeSaida);

	/*************************end my code*****************/

	gettimeofday(&fim, NULL);

	//obtem tempo final do programa

	totalseg = fim.tv_sec - inicio.tv_sec;

	//diferenca em segundos

	totalmicroseg = fim.tv_usec - inicio.tv_usec; //diferenca em microsegundos

	/*se a diferenca em microssegundos for negativa, os segundos terao que emprestar uma unidade; 1 microseg = 10E-6 s. */

	if (totalmicroseg <0){

		totalmicroseg += 1000000;
		totalseg -= 1;
	};

	printf ("\n");
	printf ("***************************************************************\n");
	printf ("Tempo total: %ld segundos e %ld microssegundos.\n", totalseg, totalmicroseg);
	printf ("***************************************************************\n");
	printf ("\n");

	return(0);

}
