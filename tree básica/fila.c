#include "fila.h"
#include "tree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define CAPACIDADE_INICIAL 5
#define FATOR_REDIMENSIONAMENTO 2
#define FATOR_REDIMENSIONAMENTO_INVERSO 0.5

struct _fila{
    int cap;
    int num;
    arv_t **vet;

};

fila fila_cria(void){
    fila f = malloc(sizeof(struct _fila));
    if (f == NULL) return NULL;
    f->vet = malloc(CAPACIDADE_INICIAL * sizeof(arv_t*));
    if (f->vet == NULL) {
        free(f);
        return NULL;
    }
    f->cap = CAPACIDADE_INICIAL;
    f->num = 0;
    return f;   
}

void fila_destroi(fila f){
    free(f->vet);
    free(f);
}

arv_t* fila_remove(fila f){
    assert(!fila_vazia(f));
    arv_t *primeiro = f->vet[0];

    for (int i=0; i < f->num -1; i++){
        f->vet[i] = f->vet[i+1];
    }
    f->num--;
    return primeiro;
    
}

void fila_insere(fila f, arv_t* d){
    if (fila_cheia(f)){
        int nova_capacidade = f->cap *FATOR_REDIMENSIONAMENTO;
        arv_t**novo_vet = realloc(f->vet, sizeof(arv_t*)*nova_capacidade);
        assert(novo_vet!=NULL); 
        f->cap = nova_capacidade;
        f->vet = novo_vet;
    }
    f->vet[f->num++]= d;
}

arv_t* fila_mostra_inicio(fila f){
    return f->vet[0];
}

arv_t* fila_mostra_fim(fila f){
    return f->vet[(f->num)-1];
}

bool fila_cheia(fila f){
    return(f->cap==f->num);
}

bool fila_vazia(fila f){
    return(f->num ==0);
}







