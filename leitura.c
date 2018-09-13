#include<stdio.h>
#include<stdlib.h>

//Função que le o arquivo nos padroes especificados
// Passo como parametro respectivamente o endereço de uma variavel int que representa a capacidade da mochila, um ponteiro para lista de itens, e uma string com nome do arquivo não ha retorno. Vetor de itens é gerado e valor em CapacidadeDaMochila é gravado no endereço passado.

void lerArquivo(int *CapacidadeDaMochila, ITEM *listaDeItens, char *nomeDoArquivo){	

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

	//Crio vetor do tipo Itens

	listaDeItens = (ITEM *) malloc(sizeof(ITEM) * auxiliar);

	//add todos os itens ao vetor

	while( fscanf( PonteiroDeArquivo, "%d %d", &listaDeItens[i].peso, &listaDeItens[i].valor) != EOF ){		

			//Add valor por peso

			listaDeItens[i].valorPorPeso = (double)listaDeItens[i].valor/listaDeItens[i].peso; 

			//Mostra leitura

			printf("%d %d %lf\n", listaDeItens[i].peso, listaDeItens[i].valor, listaDeItens[i].valorPorPeso);

			//incremento o indice pra add proximo item

			i++;

	}//end while EOF

}//end lerArquivo

