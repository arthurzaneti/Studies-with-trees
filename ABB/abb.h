#ifndef _ABB_H_
#define _ABB_H_

typedef int dado_t;
typedef struct _no no_t;
struct _no;
typedef no_t arv_t;

arv_t* cria_arv(dado_t data, arv_t* esq, arv_t* dir);

dado_t* busca(arv_t *arv, dado_t valor);
dado_t* busca_n_recursiva(arv_t *arv, dado_t valor);

arv_t* insere(arv_t*arv, dado_t valor);
void insere_com_ponteiro_duplo(arv_t**parv, dado_t valor);
void insere_com_ponteiro_duplo_n_recursiva(arv_t **parv, dado_t valor);

void remove_no(arv_t **parv, dado_t valor);
no_t* acha_sucessor(arv_t* arv); //auxiliar da remove_no

void pre_ordem_esq(arv_t *arv);
void em_ordem_esq(arv_t *arv);
void pos_ordem_esq(arv_t*arv);
void pre_ordem_dir(arv_t *arv);
void em_ordem_dir(arv_t *arv);
void pos_ordem_dir(arv_t*arv);


#endif