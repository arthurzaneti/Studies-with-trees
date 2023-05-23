#include "abb.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct _no{
    int dado;
    dado_t* esq;
    dado_t* dir
};

arv_t* cria_arv(dado_t data, arv_t* esq, arv_t* dir){
    arv_t* novo_no = malloc(sizeof(no_t));
    assert(novo_no!=NULL);
    novo_no->dado = data;
    novo_no->esq = esq;
    novo_no->dir = dir;
    return novo_no;
}

dado_t* busca(arv_t *arv, dado_t valor){
    if (arv==NULL)return;
    if (arv->dado == valor) return &(arv->dado);
    if (arv->dado > valor) return busca(arv->esq, valor);
    if (arv->dado < valor) return busca(arv->dir, valor);
}

dado_t* busca_n_recursiva(arv_t *arv, dado_t valor){
    no_t* no_atual = arv;
    while (arv!=NULL){
        if (no_atual->dado == valor) return &(no_atual->dado);
        if (no_atual->dado > valor) no_atual=no_atual->esq;
        if (no_atual->dado < valor) no_atual=no_atual->dir;
        }
    return NULL; //árvore vazia
}

