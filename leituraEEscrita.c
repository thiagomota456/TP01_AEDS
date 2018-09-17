/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Thiago Soares Mota
Matricula: 201722040394
Descricao do programa: leitura e escrita de arquivos
Data: 16/09/2018
************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

			//Marca item como forra da mochila

			(*listaDeItens)[i].naMochila = 0;

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

//Printar Mochila
//Recebe como parametro um ponteiro pro tipo item , e o tamanho do vetor para o qual o ponteiro deve apontar. Printa no terminal a lista

void printaItensNaMochila(ITEM *lista, int tamanho){

	int i;

	//Percorro toda minha lista

	for(i = 0; i < tamanho; i++){

		//Se esta na mochila
 
		if(lista[i].naMochila != 0)

			//Printo item

			printf("%d %d %.2lf\n", lista[i].peso, lista[i].valor, lista[i].valorPorPeso);

	}//end for

}//end printaItensNaMochila

//Cria um arquivo de saída

void saidaNoArquivo( ITEM *lista, int tamanhoDalista, char *nomeDoArquivoLido){
	
	FILE *PonteiroDeArquivo;
	int somatorioDosPesosDosItens = 0;
	int somatorioDosValoresDosItens = 0;
	int i;
	int j = 0;

	//Crio string para abrigar nome de arquivo de saida

	char arquivoDeSaida[strlen(nomeDoArquivoLido) + 12];
	memcpy( arquivoDeSaida, "Resposta : \0", 12);

	//Gero nome do arquivo de sáida sendo Resposta : nomeDoArquivoLido

	strcat( arquivoDeSaida, nomeDoArquivoLido);

	//Abri arquivo para escrita, caso não exista, (o que deve acontecer), Não permite leitura

	PonteiroDeArquivo = fopen( arquivoDeSaida, "w");
		
	//Para cada item escolhido para a solução, o número do item, seu peso e seu valor (uma linha por item)
	//Interpretei o "o número do item" com a posição dele na lsita, mas não tenho certeza se compeendi bem o que ela queria com essa frase
	
	//Percorro toda minha lista

	for(i = 0; i < tamanhoDalista; i++){

		//Se esta na mochila
 
		if(lista[i].naMochila != 0){

			//Printo item

			fprintf( PonteiroDeArquivo, "%3d° %3d %3d\n", j+1,lista[i].peso, lista[i].valor);

			somatorioDosPesosDosItens += lista[i].peso;
			somatorioDosValoresDosItens += lista[i].valor;


			j++;

		}//end if
	
			//j++;

	}//end for

	fprintf( PonteiroDeArquivo, "%3d\n", somatorioDosPesosDosItens);
	fprintf( PonteiroDeArquivo, "%3d\n", somatorioDosValoresDosItens);

}//end saidaNoArquivo




