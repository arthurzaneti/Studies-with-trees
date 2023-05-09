#include <stdbool.h>

typedef char dado_t;
typedef struct _no no_t;
struct _no;
typedef no_t arv_t;

arv_t*cria_arv(dado_t data, arv_t*dir, arv_t*esq);
arv_t* cria_arv_vazia(void);
void troca_valor (arv_t* arv, dado_t dado);
int max (int a,int b);
bool vazia(arv_t *arv);
int num_nos(arv_t *arv);
int altura(arv_t*arv);
int num_nos_folha(arv_t* arv);
int num_nos_nao_folha(arv_t* arv);
int nivel_no( arv_t* arv, dado_t dado);
int fator_equilibrio(arv_t* arv);



