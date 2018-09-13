#include<stdio.h>
#include<stdlib.h>

#define MAX 2147483640

//Tipo abstrato para as caracteristicas que um Item deve ter

typedef struct item{

	//Peso Vi

	int peso;
 
	//valor Wi

	int valor;

	//Valor dividido por peso

	double valorPorPeso; 

}ITEM;

/*

Pretendo criar uma estrutura pra mochila

typedef struct mochila{

	//Vetor de itens na mochila

	int itensinclusos[MAX][3];	
	
	//itens add

	int itensAdd

}MOCHILA;
*/
