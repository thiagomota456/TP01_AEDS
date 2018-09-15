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

//Add itens a mochila
//Recebo a lista de Itens como um ponteiro que aopnta pra um vetor do tipo ITEM, a capacidade da mochila, e o tamanho da lista de itens

void addItensAMochila(ITEM *lista, int capacidade, int tamanhoDaLista){

	int i;

	//Copio tamanho pra uma variavel tamanho restante que vai verificar se há espaço pra add itens

	int tamanhoRestante = capacidade;

	//Ordeno lista

	ordenaDecrecente( lista, tamanhoDaLista);

	//Para todos os itens da mochila

	for(i = 0; i < tamanhoDaLista; i++){

		//Se cabe na mochila

		if( (tamanhoRestante-lista[i].peso) >= 0){

			//Subtraio peso da capacidade da mochila

			tamanhoRestante -= lista[i].peso;

			//Marco o item como dentro da mochila
			lista[i].naMochila = 1;

		}

	}//end for
	
}//end addItensAMochila
