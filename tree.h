#ifndef _TREE_H_
#define _TREE_H_
typedef char dado_t;
typedef struct _no no_t;
struct _no;
typedef no_t arv_t;


//funções cria e destroi
arv_t*cria_arv(dado_t data, arv_t*esq, arv_t*dir);
arv_t* cria_arv_vazia(void);
void arv_destroi (arv_t*arv);
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

//funões de percurso
void pre_ordem_esq(arv_t *arv);
void em_ordem_esq(arv_t *arv);
void pos_ordem_esq(arv_t*arv);
void pre_ordem_dir(arv_t *arv);
void em_ordem_dir(arv_t *arv);
void pos_ordem_dir(arv_t*arv);
void percorre_largura(arv_t *arv);
#endif