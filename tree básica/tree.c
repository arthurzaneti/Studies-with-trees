#include "tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "fila.c"
#include "fila.h"

struct _no{
    dado_t data;
    no_t*dir;
    no_t*esq;
};

arv_t*cria_arv(dado_t data, arv_t*esq, arv_t*dir){
    arv_t*novo_no = malloc(sizeof(no_t));
    assert(novo_no != NULL);
    novo_no->data = data;
    novo_no->dir = dir;
    novo_no->esq = esq;
    return novo_no;
}
arv_t* cria_arv_vazia(void){
    arv_t* arv = malloc(sizeof(arv_t));
    assert(arv!=NULL);
    arv->esq = NULL;
    arv->dir = NULL;
    return arv;
}
void arv_destroi (arv_t*arv){
    if (arv==NULL)return;
    arv_destroi(arv->esq);
    arv_destroi(arv->dir);
    free(arv);
}

void troca_valor (arv_t* arv, dado_t dado){
    if (arv==NULL){
        arv->esq = cria_arv_vazia();
        arv->dir = cria_arv_vazia();
    }
    arv->data = dado;
}

int max (int a,int b){
    if (a >b) return a;
    else return b;
}

int num_nos(arv_t *arv){
    if (arv==NULL) return 0;
    return 1 + num_nos(arv->esq) + num_nos(arv->dir);
}

int altura(arv_t*arv){
    if (arv ==NULL) return -1;
    return 1 + max(altura(arv->esq), altura(arv->dir));
}
int num_nos_folha(arv_t* arv){
    if (arv==NULL) return 0;
    if (arv->esq == NULL && arv->dir == NULL) return 1;
    return num_nos_folha(arv->esq)+num_nos_folha(arv->dir);
}
int num_nos_nao_folha(arv_t* arv){
    if (arv==NULL ||(arv->dir ==NULL && arv->esq ==NULL)) return 0;
    return 1 + num_nos_nao_folha(arv->esq) + num_nos_nao_folha(arv->dir);
}

int nivel_no( arv_t* arv, dado_t dado){
    //implementação mais complexa do código e só consegui com ajuda da internet. 
    
    if (arv ==NULL) return -1;
    if (arv->data == dado) return 0;
    if (arv->dir ==NULL && arv->esq ==NULL) return -1;
    
    int nivel_esq = nivel_no(arv->esq, dado);
    int nivel_dir = nivel_no(arv->dir, dado);

    if (nivel_esq == -1 && nivel_dir==-1) return -1;
    return 1 + max(nivel_esq, nivel_dir);
}

int fator_equilibrio(arv_t* arv){
    return abs(altura(arv->esq)- altura(arv->dir));
}

void pre_ordem_esq(arv_t *arv){
    if(arv==NULL)return;
    printf("%c", arv->data);
    pre_ordem_esq(arv->esq);
    pre_ordem_esq(arv->dir);
}

void em_ordem_esq(arv_t *arv){
    if(arv==NULL)return;
    em_ordem_esq(arv->esq);
    printf("%c", arv->data);
    em_ordem_esq(arv->dir);
}

void pos_ordem_esq(arv_t*arv){
    if(arv==NULL)return;
    pos_ordem_esq(arv->esq);
    pos_ordem_esq(arv->dir);
    printf("%c",arv->data);
}

void pre_ordem_dir(arv_t *arv){
    if(arv==NULL)return;
    printf("%c", arv->data);
    pre_ordem_dir(arv->dir);
    pre_ordem_dir(arv->esq);
}

void em_ordem_dir(arv_t *arv){
    if(arv==NULL)return;
    em_ordem_dir(arv->dir);
    printf("%c", arv->data);
    em_ordem_dir(arv->esq);
    
}

void pos_ordem_dir(arv_t*arv){
    if(arv==NULL)return;
    pos_ordem_dir(arv->dir);
    pos_ordem_dir(arv->esq);
    printf("%c",arv->data);
}

void em_largura_esq(arv_t* arv) {
    fila f = fila_cria();
    if (arv == NULL) return;
    fila_insere(f, arv);
    while (!fila_vazia(f)) {
        arv_t* no = fila_remove(f);
        printf("%c ", no->data);
        if (no->esq != NULL) fila_insere(f, no->esq);
        if (no->dir != NULL) fila_insere(f, no->dir); 
    }
    fila_destroi(f);
}
void em_largura_dir(arv_t* arv) {
    fila f = fila_cria();
    if (arv == NULL) return;
    fila_insere(f, arv);
    while (!fila_vazia(f)) {
        arv_t* no = fila_remove(f);
        printf("%c ", no->data);
        if (no->dir != NULL) fila_insere(f, no->dir); 
        if (no->esq != NULL) fila_insere(f, no->esq);
    }
    fila_destroi(f);
}