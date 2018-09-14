#include<stdio.h>
#include<stdlib.h>
#include "tipos.c"
#include "leitura.c"

//Printa lista

void printaLista(ITEM *lista, int tamanho){

	int i;

	for(i = 0; i < tamanho; i++){
		printf("%d %d %.2lf\n", lista[i].peso, lista[i].valor, lista[i].valorPorPeso);
	}

}//end printaLista

//Ordeno os elementos em ordem crecente  
//Erro na ora de ordenar, elementos não estão sendo trocados

void ordenaDecrecente(ITEM *lista, int tamanho){

	int IndiceDoMaior;
	int i = 0, j = 0;
	ITEM aux;

	printf("inicio: \n");
	printaLista( lista, tamanho);

	//Para todos os elementos da lista

	while (i < tamanho){

		IndiceDoMaior = i;

		//Comparo o elemeto escolhido com todos os outros para encontrar o maior 

		for(j = i + 1; j <  tamanho; j++){

			//Se encontrei um maior guardo o indice dele

			if(lista[j].valorPorPeso > lista[IndiceDoMaior].valorPorPeso)
				IndiceDoMaior = i;
		}//end for

		//Troco o maior com o item 1

		aux =  lista[i];
		lista[i] = lista[IndiceDoMaior];
		lista[IndiceDoMaior] = aux; 

		printf("Troca %d\n", i+1);
		printaLista( lista, tamanho);
		i++;
	}//end while(i<tamanho)
	
}//end ordenaDecrecente

//Função Principal

int main(){

	int CapacidadeDaMochila, tamanhoDalista;
	ITEM * listaDeItens;

	//leietura do arquivo

	lerArquivo( &CapacidadeDaMochila, &tamanhoDalista, &listaDeItens, "Documento sem título.txt\0");
	printaLista( listaDeItens, tamanhoDalista);
	printf("Ordenado: \n");
	ordenaDecrecente(listaDeItens, tamanhoDalista);
	printaLista( listaDeItens, tamanhoDalista);

	return 0;

}//end main
