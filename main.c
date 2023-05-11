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


//funções cria 
arv_t*cria_arv(dado_t data, arv_t*esq, arv_t*dir);
arv_t* cria_arv_vazia(void);
//função troca que não sei pra que vou usar ainda
void troca_valor (arv_t* arv, dado_t dado);

//funções auxiliares
int max (int a,int b);

//funções da árvore mesmo
int num_nos(arv_t *arv);
int altura(arv_t*arv);
int num_nos_folha(arv_t* arv);
int num_nos_nao_folha(arv_t* arv);
int nivel_no( arv_t* arv, dado_t dado);
int fator_equilibrio(arv_t* arv);

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

/*
implementação creativa de num_nos_folha, pena que retornava uma float...
int num_nos_folha (arv_t *arv){
    if (arv==NULL) return 0.5;
    return num_nos_folha(arv->esq) + num_nos_folha(arv->dir);
}
*/
int main(){
    arv_t* arv = cria_arv('a', cria_arv('b', cria_arv
                                        ('d',NULL,NULL), cria_arv('e',NULL,NULL))
                                ,cria_arv('c',cria_arv('f', NULL, NULL), NULL));
    assert(num_nos(arv)==6);
    assert(altura(arv)==2);
    assert(num_nos_folha(arv)==3);
    assert(num_nos_nao_folha(arv)==3);
    printf("%d",nivel_no(arv, 'c'));
    assert(fator_equilibrio(arv)==0);
    return 0;
}