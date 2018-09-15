#include<stdio.h>
#include<stdlib.h>

//Tipo abstrato para as caracteristicas que um Item deve ter

typedef struct item{

	//Peso Vi

	int peso;
 
	//valor Wi

	int valor;

	//0 esta fora da mochila, qualquer outro número dentro da mochila
	int naMochila;

	//Valor dividido por peso

	double valorPorPeso; 

}ITEM;
