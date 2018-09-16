#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

/* Teste da medicao do tempo*/

int main(int argc, char *argv[]){

	// Variaveis relacionadas com a medicao do tempo:

	int who = RUSAGE_SELF; //man: information shall be returned about resources used by the
	current process
	struct rusage usage;
	long utotalmicroseg, utotalseg; //tempo usuario: tempo que a CPU gasta executando o programa
	long stotalmicroseg, stotalseg; //tempo sistema: tempo que a CPU gasta executando chamadas de sistemas para o programa
	//coloque aqui o algoritmo

	getrusage(who, &usage);

	//tempo de usuário na CPU

	utotalseg = usage.ru_utime.tv_sec;
	utotalmicroseg = usage.ru_utime.tv_usec;

	//segundos
	//microsegundos
	//tempo de sistema na CPU

	stotalseg = usage.ru_stime.tv_sec;

	//segundos

	stotalmicroseg = usage.ru_stime.tv_usec; //microsegundos
	printf ("\n");
	printf ("***************************************************************\n");
	printf ("Tempo de usuario: %ld segundos e %ld microssegundos.\n", utotalseg, utotalmicroseg);
	printf ("Tempo de sistema: %ld segundos e %ld microssegundos.\n", stotalseg, stotalmicroseg);
	printf ("***************************************************************\n");
	printf ("\n");

	return(0);

}
