#include "Lista.h"

void mostra_float(void *p){
	printf("%.1f\n", *(float *)p);
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
}
