/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Thiago Soares Mota
Matricula: 201722040394
Descricao do programa: medição de tempo
Data: 16/09/2018
************************************************/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include<stdlib.h>
#include<string.h>
#include "tipos.c"
#include"AddMochila.c"
#include "leituraEEscrita.c"


/* Teste da medicao do tempo*/

int main(int argc, char *argv[]){

	// Variaveis relacionadas com a medicao do tempo:

	int who = RUSAGE_SELF; //man: information shall be returned about resources used by the
	//current process
	struct rusage usage;
	long utotalmicroseg, utotalseg; //tempo usuario: tempo que a CPU gasta executando o programa
	long stotalmicroseg, stotalseg; //tempo sistema: tempo que a CPU gasta executando chamadas de sistemas para o programa

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

	getrusage(who, &usage);

	//tempo de usuário na CPU

	utotalseg = usage.ru_utime.tv_sec;
	utotalmicroseg = usage.ru_utime.tv_usec;

	//segundos
	//microsegundos
	//tempo de sistema na CPU

	stotalseg = usage.ru_stime.tv_sec;

	//segundos

	stotalmicroseg = usage.ru_stime.tv_usec; //microsegundos
	printf ("\n");
	printf ("***************************************************************\n");
	printf ("Tempo de usuario: %ld segundos e %ld microssegundos.\n", utotalseg, utotalmicroseg);
	printf ("Tempo de sistema: %ld segundos e %ld microssegundos.\n", stotalseg, stotalmicroseg);
	printf ("***************************************************************\n");
	printf ("\n");

	return(0);

}
