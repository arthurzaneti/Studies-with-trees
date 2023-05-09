#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char dado_t;
typedef struct _no no_t;
struct _no{
    dado_t data;
    no_t*dir;
    no_t*esq;
};
typedef no_t arv_t;

arv_t*cria_arv(dado_t data, arv_t*dir, arv_t*esq){
    arv_t*novo_no = malloc(sizeof(no_t));
    assert(novo_no != NULL);
    novo_no->data = data;
    novo_no->dir = dir;
    novo_no->esq = esq;
    return novo_no;
}
int max (int a,int b){
    if (a >b) return a;
    else return b;
}

int num_nos(arv_t *arv){
    if (arv == NULL) return 0;
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
    return num_nos(arv)- num_nos_folha(arv);
}
//makes no sense to me still
int nivel_no( arv_t* arv, dado_t dado){
    if (arv==NULL) return -1;
    else if (arv->data == dado) return 0;
    
    int nivel_esq = nivel_no(arv->esq, dado);
    int nivel_dir = nivel_no(arv->dir, dado);

    if (nivel_dir == -1 && nivel_esq == -1) return -1;
    else if ( nivel_esq == -1) return nivel_dir + 1;
    return nivel_esq + 1;
}

int fator_equilibrio(arv_t* arv){
    return abs(altura(arv->esq)- altura(arv->dir));
}

/*
implementação creativa de num_nos_folha, pena que retornava uma float...
int num_nos_folha (arv_t *arv){
    if (arv==NULL) return 0.5;
    return num_nos_folha(arv->esq) + num_nos_folha(arv->dir);
}
*/