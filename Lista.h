#define ERRO_LISTA_VAZIA -1
#include <stdio.h>

typedef struct ele{ //aqui a gente dá nome "ele" à estrutura para que ela possa se auto referenciar na declaração do ponteiro proximo 
	void *info;
	struct ele *proximo;
}Elemento;

typedef struct{
	Elemento *cabeca;
	int tamInfo;
}Lista;

int lista_vazia(Lista l);
void inicializa_lista(Lista *p, int t);
Elemento *aloca_ele(void *x, int t);
int insereNoInicio(Lista *l, void *info);
void mostra_lista(Lista l, void(*mostra)(void*));
int lista_vazia(Lista l);
int removeDoInicio(Lista *l, void *info);
int insereNoFim(Lista *l, void *info);
int removeDoFim(Lista *l, void *info);
void desaloca_lista(Lista *l);
void desaloca_lista_v2(Lista *l);
