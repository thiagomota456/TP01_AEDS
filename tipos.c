/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Thiago Soares Mota
Matricula: 201722040394
Descricao do programa: Tipo abstrato para as caracteristicas que um Item deve ter 
Data: 16/09/2018
************************************************/
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
