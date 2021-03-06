#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 5

typedef struct {
	int inicio, fim;
	int matricula[tam];
	float prova[tam];
	float trab[tam];
}fila;


int menu (){
	printf ("\n<<<<<<<<<|MENU|>>>>>>>>>\n");
	
	int r;
	
	printf ("0 � SAIR");
	printf ("\n1 � INSERIR NA FILA");
	printf ("\n2 � EXCLUIR DA FILA");
	printf ("\n3 � EXIBIR A FILA");
	printf ("\n4 � MOSTRA A MATRICULA COM MAIOR M�DIA");
	printf ("\n5 � MOSTRA O PRIMEIRO ELEMENTO DA FILA");
	printf ("\nDigite sua op��o: ");
	scanf ("%d",&r);
	
	return r;
}

void startfila (fila *f){
	f->inicio = 0;
	f->fim = -1;		
}


void insertfila (fila *f){ //1
	float n_prova, n_trab;
	int matricula;
	
	printf ("\n<<<<<<<<<|INSERIR NA FILA|>>>>>>>>>\n");
	
	printf ("\nUSER V�RGULA \",\" AO INV�S DE PONTO \".\"\n");	
	if (f->fim == tam-1){
		printf ("ERROR - FILA EST� CHEIA.\n");
	}else{		
		printf ("\nDigite a matricula: ");
		scanf ("%d",&matricula);
		
		printf ("\nDigite a nota da prova: ");
		scanf ("%f",&n_prova);
		
		printf ("\nDigite a nota do trabalho: ");
		scanf ("%f",&n_trab);	
		
		f->fim++;		
		
		f->matricula[f->fim] = matricula;
		f->prova[f->fim] = n_prova;
		f->trab[f->fim] = n_trab; 
	}
	system("pause");
}


void removefila (fila *f){ //2
	
	printf ("\n<<<<<<<<<|REMOVER FILA|>>>>>>>>>\n");
	
	if (f->fim < f->inicio){
		printf ("\nERROR - FILA VAZIA\n");
	}else{
		f->inicio++;
	}
	system("pause");
}


void showfila (fila *f){ //3
	printf ("\n<<<<<<<<<|MOSTRAR FILA|>>>>>>>>>\n");
	
	int cont;
	
	if (f->fim < f->inicio){
		printf ("\nERROR - FILA VAZIA\n");
	}
	for (cont = f->inicio; cont < f->fim+1; cont++){		
		printf ("\n\nMatricula: %d ",f->matricula[cont]);
		printf ("\nNota da prova: %0.2f",f->prova[cont]);
		printf ("\nNota do trabalho: %0.2f",f->trab[cont]);
		printf ("\nM�dia: %0.2f",(f->prova[cont]+f->trab[cont])/2);
		
		if ((f->prova[cont]+f->trab[cont])/2 >= 7.0){
			printf ("\nAPROVADO");
		}else{
			printf("\nREPROVADO");
		}
	}
	system("pause");
}


void bignote (fila *f){ //4
	printf ("\n<<<<<<<<<|MAIOR NOTA|>>>>>>>>>\n");
	
	int cont;
	float media[tam];
	
	if (f->fim < f->inicio){
		printf ("\nERROR - FILA VAZIA\n");
	}else {
		for (cont = f->inicio; cont < f->fim+1; cont++){
			media[cont] = (f->prova[cont]+f->trab[cont])/2;
		}
	
		float maior = media[0];
	
		for (cont = f->inicio; cont < f->fim+1; cont++){
			if (maior < media[cont]){
				maior = media[cont];	
			}
		}
		printf ("\nA maior nota �: %0.2f\n", maior);
	}	
	system("pause");	
}


void showtop (fila *f){ //5
	printf ("\n<<<<<<<<<|ELEMENTO DO TOPO|>>>>>>>>>\n");
	int x;
	float auxp;
	float auxt;
	
	if (f->fim < f->inicio){
		printf ("\nERROR - FILA VAZIA\n");
	}else {
		x = f->matricula[f->inicio];
		auxp = f->prova[f->inicio];
		auxt = f->trab[f->inicio];		
		printf ("\nMatricula: %d, Prova: %0.2f, Nota do trabalho: %0.2f.\n",x,auxp,auxt);
	}
	system("pause");
}


main ()	{

	setlocale(LC_ALL,"portuguese_Brazil");
	
	fila f;
	
	int r;
	
	startfila(&f);
	
	r = menu ();
	
	while (r != 0){
		
		if (r == 1 ){
			system ("cls");
			insertfila (&f);
			system ("cls");	
		}
		else if (r == 2){
			system ("cls");
			removefila (&f);
			system ("cls");
		}
		else if (r == 3){
			system ("cls");
			showfila (&f);
			system ("cls");
		}
		else if (r == 4){
			system ("cls");
			bignote (&f);
			system ("cls");
		}
		else if (r == 5){
			system ("cls");
			showtop (&f);
			system ("cls");
		}
		
		r = menu ();		
	}
	
	
	return 0;
}

