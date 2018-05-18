 /********************************************************           
  * TAD Lista -- program to initialize, manipulate and   *
  *            print Lists.                              *
  *                                                      *   
  * Author:  LOFFI, Murilo                               *   
  *                                                      *   
  * Purpose:  Learning abstract types of data.           *   
  *                                                      *   
  * Usage:                                               *   
  *      Edit the main.c archive to include fuctions and *
  *      variables at your desire.                       *   
  ********************************************************/


//Lista.h


#define ERRO_LISTA_VAZIA -1
#define ERRO_POS_INVALIDA -2
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
int insereNaPos(Lista *l, void *info, int pos);
int removeDaPos(Lista *l, void *info, int pos);
int leNaPos(Lista *l, void *info, int pos);
