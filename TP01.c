#include<stdio.h>
#include<stdlib.h>
#include "tipos.c"
#include "leitura.c"

//Ordeno os elementos em ordem crecente  

void ordenaDecrecente(ITEM *lista, int tamanho){

	int IndiceDoMaior;
	int i = 0, j = 0;
	ITEM aux;



	//Para todos os elementos da lista

	while (i < tamanho){

		IndiceDoMaior = i;

		//Comparo o elemeto escolhido com todos os outros para encontrar o maior 

		for(j = i + 1; j <  tamanho; j++){

			//Se encontrei um maior guardo o indice dele

			if(lista[j].valorPorPeso > lista[IndiceDoMaior].valorPorPeso)
				maior = i;
		}//end for


		//Troco o maior com o item 1

		aux =  lista[i];
		lista[i] = lista[IndiceDoMaior];
		lista[IndiceDoMaior] = aux; 


	}//end while(i<tamanho)

	
}

//Função Principal

int main(){

	int CapacidadeDaMochila, tamanhoDalista;
	ITEM * listaDeItens;

	//leietura do arquivo

	lerArquivo( &CapacidadeDaMochila, &tamanhoDalista, listaDeItens, "Documento sem título.txt\0");


	return 0;

}//end main
