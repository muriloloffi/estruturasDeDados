#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializa_lista(Lista *p, int t){
	p->cabeca=NULL;
	p->tamInfo=t;
}

int lista_vazia(Lista l){
	return l.cabeca == NULL; //se o cabeca não aponta pra nenhum elemento, a lista está vazia
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
		while(p!=NULL){
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
	if(lista_vazia(*l))  //verifica se a lista já está vazia
		return ERRO_LISTA_VAZIA;
	if(l->cabeca->proximo == NULL) 		//Para esta codição há somente 1 elemento na lista.
		return removeDoInicio(l,info); 		//Novamente reutilizando código.
	Elemento *p = l->cabeca;     
	while(p->proximo->proximo != NULL){ //'p' percorre a lista até seu penúltimo elemento
		p = p->proximo;	
			/* Como o último elemento não tem ponteiro apontando para o elemento antecessor,
			por isso a lista é percorrida apenas até o penúltimo!*/
	}
	Elemento *x = p->proximo; //Novo elemento x recebe o último. Este será o elemento desalocado.
	memcpy(info, x->info, l->tamInfo); //copia informação para o ponteiro info, que ficará disponível
	free(x->info); //desaloca a informação do último elemento.
	free(x); //desaloca o último elemento.
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
}

//MÉTODO N.1

/* MÉTODO N.2:
Podemos utilizar abstração e resolver o mesmo problema com um
código mais elegante */

/*
void desaloca_lista_v2(Lista *l){ 
	void *aux = malloc(l->tamInfo); //cria-se um ponteiro que recebe
	while(!lista_vazia(*l)){
		removeDoInicio(l,aux);
	}
	free(aux);
}
*/
 
