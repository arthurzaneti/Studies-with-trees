#include "abb.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct _no{
    int dado;
    arv_t* esq;
    arv_t* dir;
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
    if (arv==NULL)return NULL;
    else if (arv->dado == valor) return &(arv->dado);
    else if (arv->dado > valor) return busca(arv->esq, valor);
    else if (arv->dado < valor) return busca(arv->dir, valor); 
    //deixei os testes so pra clarificar que caso é, obviamente seria mais eficiente computacionalmente retirá-los
}

dado_t* busca_n_recursiva(arv_t *arv, dado_t valor){
    no_t* no_atual = arv;
    while (arv!=NULL){
        if (no_atual->dado == valor) return &(no_atual->dado);
        else if (no_atual->dado > valor) no_atual=no_atual->esq;
        else if (no_atual->dado < valor) no_atual=no_atual->dir;
        }
    return NULL; //árvore vazia
}

arv_t* insere(arv_t*arv, dado_t valor){
    if(arv==NULL) arv = cria_arv(valor, NULL,NULL);
    else if(arv->dado==valor) return NULL; //inserção de dado que já existe
    else if(arv->dado > valor) arv->esq = insere(arv->esq, valor);
    else if(arv->dado < valor) arv->dir = insere(arv->dir,valor);
    return arv;
}

void insere_com_ponteiro_duplo(arv_t**parv, dado_t valor){
    arv_t *arv = *parv;
    if (arv==NULL) {
        arv = cria_arv(valor, NULL,NULL);
    }
    else if(arv->dado==valor)return;
    else if(arv->dado > valor) insere_com_ponteiro_duplo(&(arv->esq), valor);
    else if(arv->dado < valor) insere_com_ponteiro_duplo(&(arv->dir), valor);
    return;
}

void insere_com_ponteiro_duplo_n_recursiva(arv_t **parv, dado_t valor){
    arv_t *arv;
    arv = *parv;
    while (arv!=NULL){
        if (arv->dado == valor) return;
        else if(arv->dado > valor){
            parv = &(arv->esq);
            arv = *parv;
        }
        else if(arv->dado < valor){
            parv = &(arv->dir);
            arv = *parv;
        }
        arv = cria_arv(valor, NULL,NULL);
        *parv = arv;
    }
}

void remove_no(arv_t **parv, dado_t valor){ 
    arv_t *arv = *parv;

    if (arv==NULL) return; //dado não ta na árvore
    else if (arv->dado > valor) remove_no(&(arv->esq), valor); //achando o nó para ser removido recursivamente
    else if (arv->dado < valor) remove_no(&(arv->dir), valor);

    else{ //remoção em si
        if (arv->esq==NULL && arv->dir==NULL){ //nó folha
            free(arv);
            *parv = NULL;
        }
        else if(arv->esq !=NULL && arv->dir==NULL){ //so tem filho esquerdo
            arv_t* temp = arv;
            *parv = arv->esq;
            free(temp);
        }
        else if(arv->esq ==NULL && arv->dir!=NULL){ //so tem filho direito
            arv_t* temp = arv;
            *parv = arv->dir;
            free(temp);
        }
        else{ //tem filho esquerdo e direito
            arv_t* sucessor = acha_sucessor(arv->dir);
            arv->dado = sucessor->dado;
            remove_no(&(arv->dir), sucessor->dado);

        }
    }
}
no_t* acha_sucessor(arv_t* arv){
    assert(arv!=NULL);
    if (arv->esq !=NULL) return acha_sucessor(arv->esq);
    else return arv;
}
void pre_ordem_esq(arv_t *arv){
    if(arv==NULL)return;
    printf("%d\n", arv->dado);
    pre_ordem_esq(arv->esq);
    pre_ordem_esq(arv->dir);
}

void em_ordem_esq(arv_t *arv){
    if(arv==NULL)return;
    em_ordem_esq(arv->esq);
    printf("%d\n", arv->dado);
    em_ordem_esq(arv->dir);
}

void pos_ordem_esq(arv_t*arv){
    if(arv==NULL)return;
    pos_ordem_esq(arv->esq);
    pos_ordem_esq(arv->dir);
    printf("%d\n",arv->dado);
}

void pre_ordem_dir(arv_t *arv){
    if(arv==NULL)return;
    printf("%d\n", arv->dado);
    pre_ordem_dir(arv->dir);
    pre_ordem_dir(arv->esq);
}

void em_ordem_dir(arv_t *arv){
    if(arv==NULL)return;
    em_ordem_dir(arv->dir);
    printf("%d\n", arv->dado);
    em_ordem_dir(arv->esq);
    
}

void pos_ordem_dir(arv_t*arv){
    if(arv==NULL)return;
    pos_ordem_dir(arv->dir);
    pos_ordem_dir(arv->esq);
    printf("%d\n",arv->dado);
}





