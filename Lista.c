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
 ********************************************************/


//Lista.c


#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializa_lista(LDE *p, int t){
	p->cabeca = NULL; //lista inicia vazia
	p->tamInfo = t; 
}

int lista_vazia(LDE l){
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

EleDuplo *aloca_ele(void *x, int t){
	EleDuplo *p=malloc(sizeof(EleDuplo));
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

int insereNoInicio(LDE *l, void *info){
	EleDuplo *novo = aloca_ele(info, l->tamInfo);
	if(novo == NULL)
		return 0; //Erro na alocacao
	novo->suc = l->cabeca;
	l->cabeca = novo;
	novo->ant = NULL;
	if(novo->suc != NULL){
		novo->suc->ant = novo; //Se a lista não estiver vazia, aponta o antecessor do segundo elemento de volta para o primeiro.
	}
	return 1; //sucesso
}

void mostra_lista(LDE l, void(*mostra)(void*)){
	if(lista_vazia(l))
		printf("Lista vazia!\n");
	else{ 
		EleDuplo *p = l.cabeca;
		while(p != NULL){
			mostra(p->info);
			p = p->suc;
		}
	} //ADAPTAR PARA LDE
}

int removeDoInicio(LDE *l, void *info){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	EleDuplo *p = l->cabeca;
	l->cabeca = p->suc;
	if(l->cabeca != NULL) //testa se só havia 1 elemento
		p->suc->ant = NULL;
	memcpy(info, p->info, l->tamInfo);
	free(p->info);
	free(p);
	return 1; //sucesso
}

int insereNoFim(LDE *l, void *info){
	if (lista_vazia(*l))
		return insereNoInicio(l,info);
	EleDuplo *p = l->cabeca;
	while(p->suc != NULL){
		p = p->suc;
	}
	EleDuplo *novo = aloca_ele(info, l->tamInfo); 
	/*REAPROVEITANDO CÓDIGO, 
	conforme código refatorado 
	anteriormente NA FUNÇÃO 'insereNoInicio'
	*/
	if (novo == NULL)
		return 0; //Erro na alocação.
	novo->suc = NULL;
	p->suc = novo;
	novo->ant = p; 
	return 1; //sucesso
}

int removeDoFim(LDE *l, void *info){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(l->cabeca->suc == NULL) //Somente 1 elemento.
		return removeDoInicio(l,info); //Novamente reutilizando código.
	EleDuplo *p = l->cabeca;
	while(p->suc->suc != NULL){ 
		p = p->suc;	
		/* Condição de parada no penultimo elemento, que após a operação apontará para NULL */
	}
	EleDuplo *x = p->suc; //Este será o elemento desalocado
	memcpy(info, x->info, l->tamInfo);
	free(x->info);
	free(x);
	p->suc = NULL; 
	/*Penúltimo elemento passa a apontar para NULL sem que seja necessário
	percorrer toda a lista novamente*/
	return 1; //sucesso
}
	
void desaloca_lista(LDE *l){
	EleDuplo *p = l->cabeca;
	while (p != NULL){
		EleDuplo *sucessor = p->suc;
		free(p->info);
		free(p);
		p=sucessor;
	}
	l->cabeca = NULL; //ADAPTAR PARA LDE
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

int insereNaPos(LDE *l, void *info, int pos){
	if (pos < 0)
		return ERRO_POS_INVALIDA; //Nao é possível posições negativas
	if (pos == 0)
		return insereNoInicio(l, info); //chamamento de função == reaproveitando código
	if (lista_vazia(*l)) 
		return ERRO_POS_INVALIDA; //caso a posição > 0
	EleDuplo *p = l->cabeca;
	int cont = 0;
	while(cont < pos-1 && p->suc != NULL ){
		p = p->suc;
		cont++;
	}
	if(cont != pos-1)
		return ERRO_POS_INVALIDA;
	EleDuplo *novo = aloca_ele(info, l->tamInfo);
	if(novo == NULL)
		return 0; //Erro na alocação
	novo->suc = p->suc;
	p->suc->ant = novo; 		//atenção com a ordem neste fim,
	p->suc = novo; 		//caso 'p->proximo = novo'
	novo->ant = p;
	return 1; //sucesso
}

int removeDaPos(LDE *l, void *info, int pos){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(pos<0)
		return ERRO_POS_INVALIDA;
	if(pos==0)
		return removeDoInicio(l,info);
	EleDuplo *p = l->cabeca;
	int cont = 0;
	while(cont < pos-1 && p->suc != NULL){
		p=p->suc;
		cont++;
	}
	if(p->suc == NULL)
		return ERRO_POS_INVALIDA;
	EleDuplo *x = p->suc;
	p->suc = x->suc;
	p->suc->ant = p;
	memcpy(info, x->info, l->tamInfo);
	free(x->info);
	free(x);
	return 1; //sucesso
}

int leNaPos(LDE *l, void *info, int pos){
	if(lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if(pos<0)
		return ERRO_POS_INVALIDA;
	EleDuplo *p = l->cabeca;
	int cont = 0;
	while(cont < pos && p->suc != NULL){
		p=p->suc;
		cont++;
	}
	if(cont != pos)
		return ERRO_POS_INVALIDA;
	memcpy(info, p->info, l->tamInfo); //para a função modificaNaPos, basta inverter os 2 primerios parâmetros.
	return 1; //sucesso
}

int quantidade(LDE l){
	EleDuplo *p = l.cabeca;
	int count = 0;
	while (p != NULL){
		count++;
		p = p->suc;
			}
	return count;
}

int busca(LDE l, void *chave, int (*compara)(void *, void *)){
	EleDuplo *p = l.cabeca;
	int cont = 0;
	while(p != NULL){
		if(compara(chave,p->info)==0)
			return cont; //ENCONTROU!
		cont++; //DO CONTRÁRIO CONTINUA PERCORRENDO
		p = p->suc;
		}
	return -1; //Não encontrou
}//REFATORAR p/ LDE

//EXERCICIO 9 - LISTA 5
void inverte (LDE l){
	EleDuplo *p1=l.cabeca;
	EleDuplo *p2=l.cabeca;
	while(p2->suc!=NULL)
		p2=p2->suc;
	while(p1 != p2 && p2->suc != p1){
 		/*também poderíamos utilizar 'p2 != p1->ant'
		como critério de parada*/
		void *aux = p1->info;
		p1->info = p2->info;
		p2->info = aux;
		p1 = p1->suc;
		p2 = p2->ant;
	}
}

