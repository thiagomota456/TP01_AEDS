#include<stdio.h>
#include<stdlib.h>
#include "tipos.c"
#include"guloso.c"
#include "leituraEEscrita.c"

//Coverte valor decimal pra vetor int em binario
//Recebe o inteiro a ser convertido, o vetor de inteiros que recebera os numeros, e o tamanho do vetor

void addParaBinario(int numero, int *vetor, int tamanhoDovetor){

	//Zera todo o vetor

	memset(vetor, 0, tamanhoDovetor * sizeof(int));

	int i = 1;
	
	//Equanto numero dividido por dois não for igual a um

	while(numero != 1){
		
		//armazemo o resto no final do vetor e divido numero

		vetor[tamanhoDovetor - i] = numero%2; //printf("resto : %d", numero%2);
		numero = numero/2;

		//incremento

		i++;

	}//end while

	//1 no bit mais significativo

	vetor[tamanhoDovetor - i] = numero;

}//end addParaBinario


/****************TESTE*****************
*
*	ITEM lista[5];
*
*	lista[0].naMochila = 0;
*	lista[1].naMochila = 0;
*	lista[2].naMochila = 0;
*	lista[3].naMochila = 0;
*	lista[4].naMochila = 0;
*
*	int mochila[ 5 ] = {1, 0, 0, 0, 1 };
*
*	printf("Antes: \n");
*	printaItensNaMochila(lista,5);
*
*
*	addMochila(lista, mochila, 5);
*	
*	printf("Depois: \n");
*	printaItensNaMochila(lista,5);
*
*
****************************************/

//Pega vetor e add a lista de uteins, marcando quais estão e quais não estão na mochila
//Recebe um vetor do tipo ITEM representando a lista de itens, um vetor do tipo int representando a mochila e um int reoresentado o tamanho de ambos os vetores  

void addMochila(ITEM *lista, int * mochila, int tamanho){

	int i;

	//Para tamanho itens, add valor i da mochila a lista[i] na mochila

	for( i = 0; i < tamanho; i++){

		lista[i].naMochila = mochila[i];

	}//end for

}//end addMochila

/********TESTE************
	
	int vetor1[6] = {1, 2, 3, 4, 6, 7};

	int vetor2[6] = {7, 7, 7, 7, 7, 7};

	copioMochila( vetor2, vetor1, 6);

	int i = 0;

	for(; i < 6; i++){

		printf("%d ", vetor1[i]);

	}//end for

**************************/

//Copio segunda mochila pra 1 mochila
//Recebo vetor de origem int, vtor de destino int e tamanho deles, respectivamente

void copioMochila(int *mochilaDeDestino, int *mochilaDeOrigem, int tamanho){

	int i;

	//Para todos os itens da mochila de destino
	
	for(i = 0; i < tamanho; i++){

		// copio da mochila de origem para destino

		mochilaDeDestino[i] = mochilaDeOrigem[i];

	}//end for

}//end copioMochila

int main(){

	//int CapacidadeDaMochila, tamanhoDalista;
	//ITEM * listaDeItens;

	//leietura do arquivo

	//lerArquivo( &CapacidadeDaMochila, &tamanhoDalista, &listaDeItens, "Documento sem título.txt\0");

	//Printo lista gerada a partir do arquivo

	//printaLista( listaDeItens, tamanhoDalista);

	//Add itens a mochila

	//printf("Mochila: \n");

	//aparentemente so preciso mudar essa linha

	//addItensAMochila_guloso(listaDeItens, CapacidadeDaMochila, tamanhoDalista);

	//Printo itens na mochila

	//printaItensNaMochila( listaDeItens, tamanhoDalista);

	//saidaNoArquivo( listaDeItens, tamanhoDalista, "Documento sem título.txt\0");


	return 0;

}//end main
