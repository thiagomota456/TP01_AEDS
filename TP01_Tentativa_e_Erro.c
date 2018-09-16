#include<stdio.h>
#include<stdlib.h>
#include "tipos.c"
#include"guloso.c"
#include "leituraEEscrita.c"

void printavetor(int *vetor, int tamanho){

	int i;

	for(i = 0; i < tamanho; i++)
		printf("%d ", vetor[i]);

		printf("\n");

}//end printavetor

int elevar(int base, int expoente){

	int i, aux = base;

	for(i = 1; i < expoente; i++)
		aux *= base;

	return aux;

}//end elevar

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

//Copio segunda mochila pra primeira mochila
//Recebo vetor de origem int, vtor de destino int e tamanho deles, respectivamente

void copioMochila(int *mochilaDeDestino, int *mochilaDeOrigem, int tamanho){

	int i;

	//Para todos os itens da mochila de destino
	
	for(i = 0; i < tamanho; i++){

		// copio da mochila de origem para destino

		mochilaDeDestino[i] = mochilaDeOrigem[i];

	}//end for

}//end copioMochila

/************TESTE********************
	ITEM lista[5];

	lista[0].naMochila = 0;
	lista[1].naMochila = 1;
	lista[2].naMochila = 0;
	lista[3].naMochila = 1;
	lista[4].naMochila = 0;

	lista[1].valor = 10;
	lista[3].valor = 389;

	printf("%d\n", somaDeValores(lista, 5));

********************************/

int somaDeValores( ITEM * lista, int tamanho){

	int i, aux = 0;

	//Para todos os elementos da lista

	for(i = 0; i < tamanho; i++){

		//Se o item estiver na mochila

		if(lista[i].naMochila != 0)
			aux += lista[i].valor;

	}//end for

	return aux;

}//end somaDeValores

int somaDePesos( ITEM * lista, int tamanho){

	int i, aux = 0;

	//Para todos os elementos da lista

	for(i = 0; i < tamanho; i++){

		//Se o item estiver na mochila

		if(lista[i].naMochila != 0)
			aux += lista[i].peso;

	}//end for

	return aux;

}//end somaDeValores

void addItensAMochila_tentativaEErro(ITEM *lista, int capacidadeDaMochila, int quantidadeDeItens){

	int i;
	int numeroDeCombinacoes = elevar(2, quantidadeDeItens);

	printf("numero de combinações: %d", numeroDeCombinacoes);

	//Ao definir esses valores iniciais e como se eu iniciasse a comparação com a combinação todos os item fora da cochila, ou 000..000

	int somaDeValoresAtuais = 0, somaDeValoresGuardados = 0, somaDePesosAtuais = 0, somaDePesosGuardados = 0;
	int combinacaoAtual[quantidadeDeItens], maiorCombinacao[quantidadeDeItens];

	//Zera todo o vetor

	memset(combinacaoAtual, 0, quantidadeDeItens * sizeof(int));
	memset(maiorCombinacao, 0, quantidadeDeItens * sizeof(int));

	for(i = 1; i < numeroDeCombinacoes; i++){

		//Converto 1 em base 10 pra binario

		addParaBinario(i, combinacaoAtual, quantidadeDeItens);

		printf("Conbinação %d:\n", i);
		printavetor(combinacaoAtual, quantidadeDeItens);

		//adiciono combinação a mochila

		addMochila( lista, combinacaoAtual, quantidadeDeItens);

		//Soma de valores da combinação selecionada e add a somaDeValoresAtuais

		somaDeValoresAtuais =  somaDeValores( lista, quantidadeDeItens);

		//Soma de peso da atual combinação e add a somaDePesosAtuais

		somaDePesosAtuais = somaDePesos( lista, quantidadeDeItens);

		//Testa se a combinação cabe na mochila

		if(capacidadeDaMochila-somaDePesosAtuais >= 0){

			//printf("%d cabe \n", i);
			//printavetor(combinacaoAtual, quantidadeDeItens);

			//testa de a soma de valores atuais é maior que a anterior ou se caso iguais, peso menor que anterior

			if( (somaDeValoresAtuais>somaDeValoresGuardados)  || ((somaDeValoresAtuais==somaDeValoresGuardados)&&(somaDePesosAtuais<somaDePesosGuardados))){


				//printf("%d cabe e é melhor\n", i);
				//printavetor(combinacaoAtual, quantidadeDeItens);


					//Guardo soma de pesos e valores dessa combinação

					somaDeValoresGuardados = somaDeValoresAtuais;
					somaDePesosGuardados = somaDePesosAtuais;

					//Guardo combinação de itens

					copioMochila( maiorCombinacao, combinacaoAtual, quantidadeDeItens);

			}//end if armazena combinação de itens

		}//end if que testa se combinação de itens cabe na mochila
		
	}//end for

	//Add maior e melhor combinação de mocila a lista

	addMochila( lista, maiorCombinacao, quantidadeDeItens);
	
}//end tentativaEErro

int main(){

	int CapacidadeDaMochila, tamanhoDalista;
	ITEM * listaDeItens;

	//leietura do arquivo

	lerArquivo( &CapacidadeDaMochila, &tamanhoDalista, &listaDeItens, "Documento sem título.txt\0");

	//Printo lista gerada a partir do arquivo

	printaLista( listaDeItens, tamanhoDalista);

	//Add itens a mochila

	printf("Mochila: \n");

	//aparentemente so preciso mudar essa linha

	addItensAMochila_tentativaEErro(listaDeItens, CapacidadeDaMochila, tamanhoDalista);

	//Printo itens na mochila

	printaItensNaMochila( listaDeItens, tamanhoDalista);

	saidaNoArquivo( listaDeItens, tamanhoDalista, "Documento sem título.txt\0");


	return 0;

}//end main
