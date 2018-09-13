#include<stdio.h>
#include<stdlib.h>
#include "tipos.c"
#include "leitura.c"

//Função Principal

int main(){

	int CapacidadeDaMochila;
	ITEM * listaDeItens;

	//leietura do arquivo

	lerArquivo(&CapacidadeDaMochila,listaDeItens,"Documento sem título.txt\0");

	

	return 0;

}//end main
