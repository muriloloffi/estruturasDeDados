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


//Lista.c


#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializa_lista(Lista *p, int t){
	p->cabeca=NULL;
	p->tamInfo=t;
}

int lista_vazia(Lista l){
	return l.cabeca == NULL;
}

/*int insereNoInicio(Lista *p, void *info){
	Elemento *novo = malloc(sizeof(Elemento));
	if (novo == NULL)
		return 0; //erro! faltou memória
	novo->info = malloc(p->tamInfo);
	if(novo->info == NULL){
		free(novo);
		return 0; //Erro!
	}
	memcpy(novo->info, info, p->tamInfo);
	novo->proximo = p->cabecaca;
	p->cabeca = novo;
	return 1; //sucesso
}*/

/* >>>>>FUNÇÃO 'INSERE NO INICIO' ACIMA */
/* >>>>>REFATORADA ABAIXO */
/* >>>>>FUNÇÃO 'ALOCA ELEMENTO' SERÁ REUTILIZADA */ 

Elemento *aloca_ele(void *x, int t){
	Elemento *p=malloc(sizeof(Elemento));
	if(p == NULL)
		return NULL; //Erro!
	p->info = malloc(t);
	if(p->info == NULL){
		free(p);
		return NULL; //Erro!
	}
	memcpy(p->info, x, t);
	return p;
}

int insereNoInicio(Lista *l, void *info){
	Elemento *novo = aloca_ele(info, l->tamInfo);
	if(novo == NULL)
		return 0; //Erro na alocacao
	novo->proximo = l->cabeca;
	l->cabeca = novo;
	return 1; //sucesso
}

void mostra_lista(Lista l, void(*mostra)(void*)){
	if(lista_vazia(l))
		printf("Lista vazia!\n");
	else{ 
		Elemento *p = l.cabeca;
		while(p != NULL){
		mostra(p->info);
		p = p->proximo;
		}
	}
}

int removeDoInicio(Lista *l, void *info){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	Elemento *p = l->cabeca;
	l->cabeca = p->proximo;
	memcpy(info, p->info, l->tamInfo);
	free(p->info);
	free(p);
	return 1; //sucesso
}

int insereNoFim(Lista *l, void *info){
	if (lista_vazia(*l))
		return insereNoInicio(l,info);
	Elemento *p = l->cabeca;
	while(p->proximo != NULL){
		p = p->proximo;
	}
	Elemento *novo = aloca_ele(info, l->tamInfo); 
	/*REAPROVEITANDO CÓDIGO, 
	conforme código refatorado 
	anteriormente NA FUNÇÃO 'insereNoInicio'
	*/
	if (novo == NULL)
		return 0; //Erro na alocação.
	novo->proximo = NULL;
	p->proximo = novo; 
	return 1; //sucesso
}

int removeDoFim(Lista *l, void *info){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(l->cabeca->proximo == NULL) //Somente 1 elemento.
		return removeDoInicio(l,info); //Novamente reutilizando código.
	Elemento *p = l->cabeca;
	while(p->proximo->proximo != NULL){ 
		p = p->proximo;	
		/* Como o último elemento não tem ponteiro apontando para o elemento,
		por isso a lista é percorrida apenas até o penúltimo*/
	}
	Elemento *x = p->proximo; //Este será o elemento desalocado
	memcpy(info, x->info, l->tamInfo);
	free(x->info);
	free(x);
	p->proximo = NULL; 
	/*Penúltimo elemento passa a apontar para NULL sem que seja necessário
	percorrer toda a lista novamente*/
	return 1; //sucesso
}
	
void desaloca_lista(Lista *l){
	Elemento *p = l->cabeca;
	while (p != NULL){
		Elemento *proximo = p->proximo;
		free(p->info);
		free(p);
		p=proximo;
	}
	l->cabeca = NULL;
} //MÉTODO N.1

/* MÉTODO N.2:
Podemos utilizar abstração e resolver o mesmo problema com um
código mais elegante

void desaloca_lista_v2(Lista *l){
	void *aux = malloc(l->tamInfo);
	while(!lista_vazia(*l)){
		removeDoInicio(l,aux);
	}
	free(aux);
}
*/

int insereNaPos(Lista *l, void *info, int pos){
	if (pos < 0)
		return ERRO_POS_INVALIDA; //Nao é possível posições negativas
	if (pos == 0)
		return insereNoInicio(l, info); //chamamento de função == reaproveitando código
	if (lista_vazia(*l)) 
		return ERRO_POS_INVALIDA; //caso a posição > 0
	Elemento *p = l->cabeca;
	int cont = 0;
	while(cont < pos-1 && p->proximo != NULL ){
		p = p->proximo;
		cont++;
	}
	if(cont != pos-1)
		return ERRO_POS_INVALIDA;
	Elemento *novo = aloca_ele(info, l->tamInfo);
	if(novo == NULL)
		return 0; //Erro na alocação
	novo->proximo = p->proximo; 	//atenção com a ordem neste fim,
	p->proximo = novo; 		//caso 'p->proximo = novo'
	return 1; //sucesso
}

int removeDaPos(Lista *l, void *info, int pos){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(pos<0)
		return ERRO_POS_INVALIDA;
	if(pos==0)
		return removeDoInicio(l,info);
	Elemento *p = l->cabeca;
	int cont = 0;
	while(cont < pos-1 && p->proximo != NULL){
		p=p->proximo;
		cont++;
	}
	if(p->proximo == NULL)
		return ERRO_POS_INVALIDA;
	Elemento *x = p->proximo;
	p->proximo = x->proximo;
	memcpy(info, x->info, l->tamInfo);
	free(x->info);
	free(x);
	return 1; //sucesso
}

int leNaPos(Lista *l, void *info, int pos){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(pos<0)
		return ERRO_POS_INVALIDA;
	Elemento *p = l->cabeca;
	int cont = 0;
	while(cont < pos && p->proximo != NULL){
		p=p->proximo;
		cont++;
	}
	if(cont != pos)
		return ERRO_POS_INVALIDA;
	memcpy(info, p->info, l->tamInfo); //para a função modificaNaPos, basta inverter os 2 primerios parâmetros.
	return 1; //sucesso
}

int quantidade(Lista l){
	Elemento *p = l.cabeca;
	int count = 0;
	while (p != NULL){
		count++;
		p = p->proximo;
			}
	return count;
}

int busca(Lista l, void *chave, int (*compara)(void *, void *)){
	Elemento *p = l.cabeca;
	int cont = 0;
	while(p != NULL){
		if(compara(chave,p->info)==0)
			return cont; //ENCONTROU!
		cont++; //DO CONTRÁRIO CONTINUA PERCORRENDO
		p = p->proximo;
		}
	return -1; //Não encontrou
}	
