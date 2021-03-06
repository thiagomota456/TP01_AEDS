/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Thiago Soares Mota
Matricula: 201722040394
Descricao do programa: Add itens a mochila
Data: 16/09/2018
************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Printa um vetor de inteiros no console
//Recebe im vetor de inteiros e seu tamanho

void printavetorInt(int *vetor, int tamanho){

	int i;

	//Para todos os numeros contidos no vetor, print

	for(i = 0; i < tamanho; i++)
		printf("%d ", vetor[i]);

		//New line

		printf("\n");

}//end printavetor

//Calcula uma base elevada a um expoente
//Recebe como parametro um numero inteiro para bale e um número inteiro para o expoente

int elevar(int base, int expoente){

	int i, aux = base;

	for(i = 1; i < expoente; i++)
		aux *= base;

	return aux;

}//end elevar

//Coverte valor decimal pra vetor int em binario
//Recebe o inteiro a ser convertido, o vetor de inteiros que recebera os numeros, e o tamanho do vetor como um numero inteiro

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

//Pega vetor e add a lista de uteins, marcando quais estão e quais não estão na mochila
//Recebe um vetor do tipo ITEM representando a lista de itens, um vetor do tipo int representando a mochila e um int reoresentado o tamanho de ambos os vetores  

void addMochila(ITEM *lista, int * mochila, int tamanho){

	int i;

	//Para tamanho itens, add valor i da mochila a lista[i] na mochila

	for( i = 0; i < tamanho; i++){

		lista[i].naMochila = mochila[i];

	}//end for

}//end addMochila

//Copio segunda mochila pra primeira mochila
//Recebo vetor de origem int, vtor de destino int e tamanho deles como int, respectivamente

void copioMochila(int *mochilaDeDestino, int *mochilaDeOrigem, int tamanho){

	int i;

	//Para todos os itens da mochila de destino
	
	for(i = 0; i < tamanho; i++){

		// copio da mochila de origem para destino

		mochilaDeDestino[i] = mochilaDeOrigem[i];

	}//end for

}//end copioMochila

//Soma valores de um vetor de ITEM
//Recebe como parammetro um vetor de ITEMS e o tamanho dele como um número inteiro

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

//Soma pesos de um vetor de ITEM
//Recebe como parametro um vetor de ITEMS e o tamanho deles como um número inteiro

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

//Algoritimo de tentativa e erro pra encontrar a melhor combinação possivel quecaiba na mochila
//Recebe como parametro um vetor do tipo ITEM, um int representando o peso maximo que a mochila pode conter e tambem um int quantidade de itens do vetor

void addItensAMochila_tentativaEErro(ITEM *lista, int capacidadeDaMochila, int quantidadeDeItens){

	int i;
	int numeroDeCombinacoes = elevar(2, quantidadeDeItens);

	//printf("numero de combinações: %d", numeroDeCombinacoes);

	//Ao definir esses valores iniciais e como se eu iniciasse a comparação com a combinação todos os item fora da cochila, ou 000..000

	int somaDeValoresAtuais = 0, somaDeValoresGuardados = 0, somaDePesosAtuais = 0, somaDePesosGuardados = 0;
	int combinacaoAtual[quantidadeDeItens], maiorCombinacao[quantidadeDeItens];

	//Zera todo o vetor

	memset(combinacaoAtual, 0, quantidadeDeItens * sizeof(int));
	memset(maiorCombinacao, 0, quantidadeDeItens * sizeof(int));

	for(i = 1; i < numeroDeCombinacoes; i++){

		//Converto 1 em base 10 pra binario

		addParaBinario(i, combinacaoAtual, quantidadeDeItens);

		//Testes pra verificar combinações
//		printf("Conbinação %d:\n", i);
//		printavetorInt(combinacaoAtual, quantidadeDeItens);

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

//Função principal

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

void addItensAMochila_guloso(ITEM *lista, int capacidade, int tamanhoDaLista){

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
