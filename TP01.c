#include<stdio.h>
#include<stdlib.h>


//Tipo abstrato para as caracteristicas que um Item deve ter

typedef struct item{

	int peso; //Peso Vi
	int valor;//valor Wi

}ITEM;


//Função que le o arquivo nos padroes especificados
// Passo como parametro respectivamente o endereço de uma variavel int que representa a capacidade da mochila, um pontiro para lista de itens, e uma string com nome do arquivo

void lerArquivo(int *CapacidadeDaMochila, ITEM *listaDeItens, char *nomeDoArquivo){	

	FILE *PonteiroDeArquivo;
	int leituraDeCaracteresDoArquivo;
	int i = 0;

	//Abri arquivo para leitura

	PonteiroDeArquivo = fopen(nomeDoArquivo, "r");

	//Testa se realizoua a litura correta, 
	
	if(PonteiroDeArquivo == NULL){

		printf("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO");
		return;
	}

	//Ler Capacidade da Mochila

	/**********TESTE****************/
	printf("%d", leituraDeCaracteresDoArquivo-48);

	leituraDeCaracteresDoArquivo = fgetch(PonteiroDeArquivo);

	//Como a leitura e feita como int, porem representando um caracter da tabela ASCII ao subtrair 48 faço a converção de char para int

	*CapacidadeDaMochila = leituraDeCaracteresDoArquivo-48;

	//Remover new lines e caracteres de espaço ate encontar a quantidade de itens

	leituraDeCaracteresDoArquivo = fgetch(PonteiroDeArquivo);
	while(leituraDeCaracteresDoArquivo==' ' || leituraDeCaracteresDoArquivo=='\n')
		leituraDeCaracteresDoArquivo = fgetch(PonteiroDeArquivo);

	//Crio vetor do tipo itens

	/**********TESTE****************/
	printf("%d", leituraDeCaracteresDoArquivo-48);

	listaDeItens = (ITEM *) malloc(sizeof(ITEM) * (leituraDeCaracteresDoArquivo-48));

	//Le ate o final do arquivo

	leituraDeCaracteresDoArquivo = fgetch(PonteiroDeArquivo);
	while(leituraDeCaracteresDoArquivo != EOF){

		//Se nao for espaço ou new line

		if(!(leituraDeCaracteresDoArquivo==' ' || leituraDeCaracteresDoArquivo=='\n')){

			//Leio peso do Item

			/**********TESTE****************/
			printf("%d", leituraDeCaracteresDoArquivo-48);

			listaDeItens[i].peso = leituraDeCaracteresDoArquivo-48;
			
			//Remover new lines e caracteres de espaço ate encontar o valor

			leituraDeCaracteresDoArquivo = fgetch(PonteiroDeArquivo);
			while(leituraDeCaracteresDoArquivo==' ' || leituraDeCaracteresDoArquivo=='\n')
				leituraDeCaracteresDoArquivo = fgetch(PonteiroDeArquivo);

			//Leio valor do Item

			/**********TESTE****************/
			printf(" %d\n", leituraDeCaracteresDoArquivo-48);

			listaDeItens[i].valor = leituraDeCaracteresDoArquivo-48;

			//Add o proximo objeto
			
			i++;

		}//end if

	}//end while EOF
	
}//end lerArquivo

//Função Principal

int main(){

	int CapacidadeDaMochila;
	ITEM * listaDeItens;

	lerArquivo(&CapacidadeDaMochila,listaDeItens,"Documen!to sem título.txt\0");

	return 0;

}//end main
