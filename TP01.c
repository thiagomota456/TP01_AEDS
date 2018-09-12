#include<stdio.h>


//Estruturra para cada Item

typedef struct item{

	int peso; //Peso Vi
	int valor;//valor Wi

}ITEM;

int main(){

	ITEM item1, item2;

	item1.peso = 34;
	item1.valor = 34;


	item2.peso = 35;
	item2.valor = 35;

	printf("item1.peso = %d ", item1.peso);
	printf("item2.peso = %d ", item2.peso);
	
	return 0;
}
