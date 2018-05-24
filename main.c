//main.c

#include "Lista.h"
#include <stdio.h>

void mostra_float(void *p){
	printf("%.1f\n", *(float *)p);
}

int compara_float(void *a, void *b){
	float *x = a, *y = b; //Pode ser feito cast aqui, assim como na função 'mostra_float'
	if(*x > *y)
		return 1; // A > B
	if(*x < *y)
		return -1; // A < B
	return 0;	// A == B
	/*The 'compara_float' function is implemented here because it's 
	the application's problem, not the library's problem.*/
}

int main(){
	Lista l1;
	inicializa_lista(&l1, sizeof(float));
	float x=1,y=0;
	insereNoInicio(&l1,&x);
	printf("\nnumero 1 inserido no inicio\n");
	x=4.5;
	printf("\nnumero 4.5 inserido no inicio\n");
	insereNoInicio(&l1,&x);
	x=3;
	printf("\nnumero 3.0 inserido no inicio\n");
	insereNoInicio(&l1,&x);
	mostra_lista(l1,mostra_float);
	removeDoInicio(&l1,&y);
	printf("\nnumero 3 removido do inicio:\n");
	printf("%.1f\n",y);
	printf("\nlista atual:\n");
	mostra_lista(l1,mostra_float);
	x=3;
	insereNoFim(&l1,&x);
	printf("\ninseriu 3 no fim\n");
	x=6;
	insereNoFim(&l1,&x);
	printf("\ninseriu 6 no fim\n");
	printf("\nitens da lista:\n");
	mostra_lista(l1,mostra_float);
	printf("\n\n");
	removeDoFim(&l1,&y);
	printf("\nremoveu do fim:\n%f \n\n",y);
	printf("\nlista atual:\n");
	mostra_lista(l1,mostra_float);
	printf("\n\nInserido na posição 3:\n");
	x=7;
	insereNaPos(&l1, &x, 3);
	mostra_lista(l1,mostra_float);
	printf("\n\nInseridos na posição 3:\n");
	x=4.7;
	insereNaPos(&l1, &x, 3);
	x=5.1;
	insereNaPos(&l1, &x, 3);
	mostra_lista(l1,mostra_float);
	removeDaPos(&l1, &x, 1);
	printf("\nRemovida na posicao 1: %.1f\n", x);
	mostra_lista(l1,mostra_float);
	leNaPos(&l1, &y, 3);
	printf("\n\nLeitura na posicao 3: %.1f\n", y);
	//x=5.1;
//int pos = busca(Lista l1, &x, compara_float){
	//	printf("\n\nPosicao do valor 5.1: %d\n", count);
	x=11;
	scanf("%f",&x);
	while(x!=0){
		insereEmOrdem(&l1, &x, compara_float);
		mostra_lista(l1,mostra_float);
		scanf("%f", &x);
	}
	desaloca_lista(&l1);

	printf("\n\n\n NAO SE ESQUECAM GALERA,\n PROVA 3 ESTA CHEGANDO \n NO DIA 06/06\n");
	return 0;
}
