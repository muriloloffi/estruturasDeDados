/********************************************************
 * ADT List -- Abstract data type to initialize, manip- *
 *             ulate and to print Lists with any type   *
 *             of data.                                 *
 *                                                      *
 * Written by:   Murilo Loffi                           *
 *                                                      *
 * As seen during the lessons by:                       *
 * Professor RUI JORGE TRAMONTIN JUNIOR, PhD.           *
 *                                                      *
 * Purpose:  Learning abstract data types.              *
 *                                                      *
 * Usage:                                               *
 *      This is the library header file.                *
 *      Edit the main.c file using the data types       *
 *      according to this header.                       *
 *      View examples previously available for the      *
 *      main.c.                                         *
 ********************************************************/


/*
Header file begin - List.h
*/


#define ERRO_LISTA_VAZIA -1
#define ERRO_POS_INVALIDA -2

/*
Declaration of the data type 'Node':
Here, the structure is given the name 'ele', which stands for element, so this
structure can self reference when using the *next pointer for the next Node.
*/
typedef struct ele{ 
	void *info;
	struct ele *proximo; //to-do: translate to *next
}Elemento; //to-do: translate to Node

typedef struct{
	Elemento *cabeca; //to-do: translate to *head
	int tamInfo; //to-do: translate to infoSize
}Lista; //to-do: translate to List

int lista_vazia(Lista l); //to-do: translate to empty_list(List listToBeTested);
void inicializa_lista(Lista *p, int t); //to-do: start_list(List *referenceToList);
Elemento *aloca_ele(void *x, int t); //to-do: Node *ele_alloc(void *Node, int infoSize);
int insereNoInicio(Lista *l, void *info); //to-do: headInsertion(List *l, void *info);
void mostra_lista(Lista l, void(*mostra)(void*)); //to-do: showList(List l)
int lista_vazia(Lista l);
int removeDoInicio(Lista *l, void *info);
int insereNoFim(Lista *l, void *info);
int removeDoFim(Lista *l, void *info);
void desaloca_lista(Lista *l);
void desaloca_lista_v2(Lista *l);
int insereNaPos(Lista *l, void *info, int pos);
int removeDaPos(Lista *l, void *info, int pos);
int leNaPos(Lista *l, void *info, int pos);
int quantidade(Lista l);
int busca(Lista l, void *chave, int (*compara)(void *, void *));
int insereEmOrdem (Lista *l, void *info, int (*compara)(void *, void *));
