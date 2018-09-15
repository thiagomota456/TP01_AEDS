#include<stdio.h>
#include<stdlib.h>

//Função que le o arquivo nos padroes especificados
//Passo como parametro respectivamente o endereço de uma variavel int que representa a capacidade da mochila, um ponteiro para lista de itens, e uma string com nome do arquivo não ha retorno. Vetor de itens é gerado e valor em CapacidadeDaMochila é gravado no endereço passado.

void lerArquivo(int *CapacidadeDaMochila, int *tamanhoDalista, ITEM **listaDeItens, char *nomeDoArquivo){	

	FILE *PonteiroDeArquivo;
	int i = 0;
	int auxiliar;

	//Abri arquivo para leitura

	PonteiroDeArquivo = fopen(nomeDoArquivo, "r");

	//Testa se realizoua a litura correta, 
	
	if(PonteiroDeArquivo == NULL){

		printf("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
		return;
	}

	//Leio mochila

	fscanf( PonteiroDeArquivo, "%d", CapacidadeDaMochila);

	//Leio numero de itens

	fscanf( PonteiroDeArquivo, "%d", &auxiliar);
	*tamanhoDalista = auxiliar;

	//Crio vetor do tipo Itens

	*listaDeItens = (ITEM *) malloc(sizeof(ITEM) * auxiliar);

	//add todos os itens ao vetor

	while( fscanf(PonteiroDeArquivo, "%d %d", &(*listaDeItens)[i].peso, &(*listaDeItens)[i].valor) != EOF){

			
			//Add valor por peso
			
			(*listaDeItens)[i].valorPorPeso = (double)(*listaDeItens)[i].valor /(*listaDeItens)[i].peso;

			/***********************************************Testes*******************************************************
			* Mostra leitura
			*
			*printf("%d %d %.2lf\n", (*listaDeItens)[i].peso, (*listaDeItens)[i].valor, (*listaDeItens)[i].valorPorPeso);
			*
			*
			**************************************************************************************************************/

			//incremento o indice pra add proximo item

			i++;

	}//end while EOF

}//end lerArquivo

//Printa lista
//Recebe como parametro um ponteiro pro tipo item , e o tamanho do vetor para o qual o ponteiro deve apontar. Printa no terminal a lista

void printaLista(ITEM *lista, int tamanho){

	int i;

	for(i = 0; i < tamanho; i++){
		printf("%d %d %.2lf\n", lista[i].peso, lista[i].valor, lista[i].valorPorPeso);
	}

}//end printaLista

