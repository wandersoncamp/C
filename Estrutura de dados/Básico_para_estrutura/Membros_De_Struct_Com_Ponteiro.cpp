#include <stdio.h>
#include <stdlib.h>

main (){
	
	struct horario {
		int *pHora;
		int *pMinuto;
		int *pSegundo;
	};
	
	struct horario hoje; 
	
	int horas = 15;
	int minutos = 30;
	int segundo = 10; 
	
	hoje.pHora = &horas;
	hoje.pMinuto = &minutos;
	hoje.pSegundo = &segundo;
	
	printf ("\n%d:%d:%d\n", *hoje.pHora, *hoje.pMinuto, *hoje.pSegundo);
	
	
	*hoje.pSegundo = 200;
	
	printf ("\n%d",*hoje.pSegundo);
	
}
