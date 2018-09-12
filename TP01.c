#include<stdio.h>

//Prototipos das Funções

FILE *lerArquivo(char *nome);

//Tipo abstrato para as caracteristicas que um Item deve ter

typedef struct item{

	int peso; //Peso Vi
	int valor;//valor Wi

}ITEM;

//Função Principal

int main(){

	lerArquivo("Documen!to sem título.txt\0");
	lerArquivo("Do");
	
	return 0;
}//end main

//Função pra abrir um arquivo para leitura
//Recebe nome do arquivo e retorna ponteiro para Strem

FILE *lerArquivo(){

	FILE *PonteiroDeArquivo;

	//Abrir arquivo para leitura

	PonteiroDeArquivo = fopen(nomeDoArquivo, "r");
	
	//retorno conteudo do Ponteiro de Arquivo	

	return PonteiroDeArquivo;
	
}//end lerArquivo

void lerArquivo(ITEM *mochila, ITEM *listaDeItens, char *nomeDoArquivo){
	
	FILE *PonteiroDeArquivo;
	int leituraDeCaracteresDoArquivo;

	//Abri arquivo para leitura	

	PonteiroDeArquivo = fopen(nomeDoArquivo, "r");

	//Testa se realizoua a litura correta, 
	
	if(PonteiroDeArquivo == NULL){

		//caso não tenha sido possivel realizar a leirura do arquivo

		Mochila = NULL;
		ListaDeItens = NULL;
	}
	else{
		//Caso arquivo lido

		//Ler Capacidade da Mochila

		leituraDeCaracteresDoArquivo = fgetch(PonteiroDeArquivo);

		//Crio mochila

		mochila = (ITEM *) malloc(sizeof(ITEM * leituraDeCaracteresDoArquivo));

		//Crio lista de Itens	
	
	}

}//end lerArquivo


