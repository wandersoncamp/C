#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 5

struct pilha {
	int topo;
	float nota[tam];
};


int menu (){
	int r;
	
	printf ("0 – SAIR\n");
	printf ("1 – EMPILHAR\n");
	printf ("2 – DESEMPILHAR\n");
	printf ("3 – EXIBIR A PILHA\n");
	printf ("4 - LOCALIZAR NÓ ATRAVÉS DE UMA NOTA\n");
	printf ("5 - LOCALIZER NOTA ATRAVÉS DO NÓ\n");
	printf ("6 - MAIOR E MENOR NOTA\n");
	printf ("7 - MOSTRAR NOTA DO TOPO\n");
	printf ("8 - MOSTRAR NOTAS DE NÓS PARES\n");
	printf ("9 - ORDENAR PILAH DE FORMA CRESCENTE\n");
	printf ("ESCOLHA SUA OPÇÃO>  ");
	scanf ("%d",&r);
	
	return (r);		
}


//Inicia pilhar.
void startpile (struct pilha *p){ 
	p->topo = -1;
}

//1
void stackUp (struct pilha *p){
	system ("cls");
	printf ("\n*----EMPILHANDO----*\n");
	float n;
	if (p->topo == tam-1){
		printf ("ERROR - PILHA CHEIA\n");
	} else {
		printf ("\nDigite uma nota: ");
		scanf ("%f",&n);
		
		p->topo++;
		p->nota[p->topo] = n;			
	}
}

//2
void unPack (struct pilha *p){
	
	if (p->topo == -1){
		printf ("ERROR - PILHA VAZIA");
	} else {
		p->topo--;
	}
}

//3
void showPile (struct pilha *p){
	
	int cont;
	int x = p->topo;
	
	if (p->topo == -1){
		printf ("ERROR - NADA PARA MOSTRAR");
	} else {
		for (cont = 0; cont < x; cont++){
			printf ("----*NOTA's*----");
			printf ("\n   %f",p->nota[cont]);
		}		
	}
}

//4
void findElement (struct pilha *p){
	int cont;
	int x = p->topo;
	float auxNota;
	
	printf ("Digite a nota que deseja encontrar: ");
	scanf ("%f",&auxNota);
	
	for (cont = 0; cont < x; cont++){
		if (auxNota == p->nota[cont]){
			break;
		}		
	}
	printf ("\n%d",cont);
}

//5
void findNode (struct pilha *p){
	int posicaoNo;
	int cont, x = p->topo;
	float aux;
	
	printf ("Qual nó deseja encontrar: ");
	scanf ("%d",&posicaoNo);
	
	while(posicaoNo > x){
		printf ("ERROR - PROCURANDO NO FORA DOS LIMITES...");
		scanf ("%d",&posicaoNo);	
	}
	for (cont = 0; cont <x; cont++){
		if (posicaoNo == cont){
			aux = p->nota[cont];
		}
	}
	printf ("Valor do %dº No é: %f ",posicaoNo,aux);
}

//6
void bigSmall (struct pilha *p){
	
	float bigNo = p->nota[0];
	float smallNo = p->nota[0];
	int cont, x = p->topo;
	
	for (cont = 0; cont <x; cont++){
		if (bigNo > p->nota[cont]){
			bigNo = p->nota[cont];
		} 
		else if (smallNo < p->nota[cont]){
			smallNo = p->nota[cont];	
		}		
	}
	printf ("MAIOR NOTA: %f\n",bigNo);
	printf ("MENOR NOTA: %f\n",smallNo);
}

//7
void topElement (struct pilha *p){
	float aux;
	
	if (p->topo == -1){
		printf ("ERROR - PILHA VAZIA");
	} else {
		aux = p->nota[p->topo];
	}
	printf ("\n%f", aux);	
}

//8
void ParElement (struct pilha *p){
	
	int soma;
	int cont, x = p->topo;
	float notasPar[5];
	
	for (cont = 0; cont <x; cont++){
		if (cont%2 == 0){
			notasPar[cont] = p->nota[cont];	
			soma++;
		}
	}	
	
	printf ("\n---*NOTAS DE NÓ PAR*---");
	for (cont = 0; cont < soma; cont++){
		printf ("\nNOTA: %f",cont, notasPar[cont]);
	}
}

//9
void order (struct pilha *p){
	
	float aux;
	int x,y;
	
	for (x = 0; x < p->topo; x++){
		for (y = x; x < p->topo; y++){
			if (p->nota[y] < p->nota[x]){
				aux = p->nota[x];
				p->nota[x] = p->nota[y];
				p->nota[y] = aux;
			}
		}
	}
	
	printf ("NOTAS ORDENADAS: ");
	for (x = 0; x < p->topo; x++){
		printf ("\n[%f]",p->nota[x]);
	}
	
}


main (){
	
	setlocale(LC_ALL,"portuguese_Brazil");
	
	int escolha;
	struct pilha p;
	
	escolha = menu();
	
	while (escolha != 0){
		if (escolha == 1) stackUp(&p);
		else if (escolha == 2) unPack(&p);
		else if (escolha == 3) showPile(&p);
		else if (escolha == 4) findElement(&p);
		else if (escolha == 5) findNode(&p);
		else if (escolha == 6) bigSmall(&p);
		else if (escolha == 7) topElement(&p);
		else if (escolha == 8) ParElement(&p);
		else if (escolha == 9) order(&p);
		
		escolha = menu();
	}
	
}

