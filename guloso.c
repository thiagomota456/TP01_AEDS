#include<stdio.h>
#include<stdlib.h>


//Ordeno os elementos em ordem crecente  
//Recebo um pontiro do tipo lista e um int tamanho que dee ser igual ao tamanho do vetor o qual o ponteiro deve apontar. Ordeno vetor em ordem decressente sendo o tem de comparação o ValorPorPeso

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
				IndiceDoMaior = j;
		}//end for

		//Troco o maior com o item 1

		aux = lista[i];
		lista[i] = lista[IndiceDoMaior];
		lista[IndiceDoMaior] = aux;

		//Incremento

		i++;
	}//end while(i<tamanho)
	
}//end ordenaDecrecente

