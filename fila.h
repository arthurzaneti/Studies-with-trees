#ifndef _FILA_H_
#define _FILA_H_
#include <stdbool.h>
#include "tree.h"

typedef struct _fila *fila;

fila fila_cria();
void fila_destroi(fila f);

arv_t* fila_remove(fila f);
void fila_insere(fila f, arv_t *arv);

arv_t* fila_mostra_inicio(fila f);
arv_t* fila_mostra_fim(fila f);

bool fila_cheia(fila f);
bool fila_vazia(fila f);



#endif