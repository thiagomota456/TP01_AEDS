/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Thiago Soares Mota
Matricula: 201722040394
Descricao do programa: gera testes
Data: 16/09/2018
************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include"tipos.c"

//Soma pesos de um vetor de ITEM
//Recebe como parametro um vetor de ITEMS e o tamanho deles como um número inteiro

int somaDePesosDaLista( ITEM * lista, int tamanho){

	int i, aux = 0;

	//Para todos os elementos da lista

	for(i = 0; i < tamanho; i++){

			aux += lista[i].peso;

	}//end for

	return aux;

}//end somaDeValores


void gerarEstruturadeDados(ITEM **lista, int tamanhoDalista){

	int i;

	//Gera uma semente de inicialização pra função rand

	srand(time(NULL));

	//Gero vetor de itens

	(*lista) = (ITEM *) malloc(tamanhoDalista * sizeof(ITEM)); 

	//Para todos os itens do vetor

	for(i = 0; i < tamanhoDalista; i++){
		//printf("Gerando");
		//Add valores ao peso e valor da lista

		(*lista)[i].peso = rand() % 100;
		(*lista)[i].valor = rand() % 100;
	}

}//end gerarEstruturadeDados

int main(){

	//Variaveis padroes e inicialização de tamnho inicial de casos de teste

	FILE *PonteiroDeArquivo;
	int i, j, tamanhoDalista, capacidadeDaMochila, numero_de_casos_de_testes;
	int incremento;
	char nomeDoArquivo[200];
	ITEM * lista;

	//Leitura no console para gerar casos de testes
	
	printf("Valor inicial: ");	
	scanf("%d", &tamanhoDalista);

	printf("Incremento: ");
	scanf("%d", &incremento);

	printf("Numero de casos de teste: ");
	scanf("%d", &numero_de_casos_de_testes);

	//nome padrão do arquivo

 	memcpy( nomeDoArquivo, "teste_00.txt\0", 12);

	//Cria numero_de_casos_de_testes arquivos

	for(i = 0; i < numero_de_casos_de_testes; i++, tamanhoDalista += incremento){

		//printf("I'm here 1\n");

		//número apos o nome do arquivo

		nomeDoArquivo[6] = (i/10 + 48);
		nomeDoArquivo[7] = (i%10 + 48);	

		//printf("I'm here 2\n");
		//Abri arquivo para escrita, caso não exista, (o que deve acontecer), cria. Não permite leitura

		PonteiroDeArquivo = fopen( nomeDoArquivo, "w");

		//printf("I'm here 3\n");

		gerarEstruturadeDados(&lista, tamanhoDalista);

		//printf("I'm here 5\n");		

		//printf("Soma de pesos: %d\n", somaDePesosDaLista(lista, tamanhoDalista));

		capacidadeDaMochila = ( somaDePesosDaLista(lista, tamanhoDalista)/2 );

		fprintf(PonteiroDeArquivo, "%d\n", capacidadeDaMochila);

		fprintf(PonteiroDeArquivo, "%d\n", tamanhoDalista);

		for(j = 0; j < tamanhoDalista; j++){

			fprintf(PonteiroDeArquivo, "%d %d\n", lista[j].peso, lista[j].valor);

		};//end for j

		fclose(PonteiroDeArquivo);

	}//end for i

	
}//end main
