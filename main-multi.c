//multi-lista - Lista de listas (matriz)

#include "List.h"

int main(){

	int lin, col, i, j;

	printf("Digite o nº de lin e de col: \n");
	scanf("%d %d", &lin, &col);

	Lista multi; 
	float x;
	inicializa_lista(&multi, sizeof(Lista));
	for(i=0; i<lin; i++){
		Lista sub;
		inicializa_lista(&sub, sizeof(float));
		for(j=0; j<col; j++){
			printf("%d, %d: ", i, j);
			scanf("%f", &x)	;
			insereNoFim(&sub, &x);
		}
		insereNoFim(&multi, &sub);
	}
	for(i=0; i<lin; i++){
		Lista sub;
		leNaPos(&multi, &sub, i);
		for(j=0; j<col; j++){
			leNaPos(&sub, &x, j);
			printf("%4.1f ", x);
		}
		printf("\n");
	}

	for(i=0; i<lin; i++){
		Lista sub;
		leNaPos(&multi, &sub, i);
		desaloca_lista(&sub);
	}

	desaloca_lista(&multi);
}	
