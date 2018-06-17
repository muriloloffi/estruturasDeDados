 /********************************************************           
  * TAD LDE -- program to initialize, manipulate and     *
  *            print Lists.                              *
  *                                                      *   
  * Author:  LOFFI, Murilo                               *   
  *                                                      *   
  * Purpose:  Learning abstract types of data.           *   
  *                                                      *   
  * Usage:                                               *   
  *      Edit the main.c archive to include fuctions and *
  *      variables at your desire.                       *
  *	 Every element points to its next and previous   *
  *	 one.						 *  
  ********************************************************/


//Lista.h


#define ERRO_LISTA_VAZIA -1
#define ERRO_POS_INVALIDA -2

typedef struct ele{ //aqui a gente dá nome "ele" à estrutura para que ela possa se auto referenciar na declaração do ponteiro proximo 
	void *info;
	struct ele *suc, *ant;
}EleDuplo;

typedef struct{
	int tamInfo;
	EleDuplo *cabeca;
}LDE;

int lista_vazia(LDE l);
void inicializa_lista(LDE *p, int t);
EleDuplo *aloca_ele(void *x, int t);
int insereNoInicio(LDE *l, void *info);
void mostra_lista(LDE l, void(*mostra)(void*));
int lista_vazia(LDE l);
int removeDoInicio(LDE *l, void *info);
int insereNoFim(LDE *l, void *info);
int removeDoFim(LDE *l, void *info);
void desaloca_lista(LDE *l);
void desaloca_lista_v2(LDE *l);
int insereNaPos(LDE *l, void *info, int pos);
int removeDaPos(LDE *l, void *info, int pos);
int leNaPos(LDE *l, void *info, int pos);
int quantidade(LDE l);
int busca(LDE l, void *chave, int (*compara)(void *, void *));
