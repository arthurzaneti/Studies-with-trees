#include "abb.h"
#include "abb.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    arv_t*minha_arv = cria_arv(100, NULL, NULL);
    for (int i=0; i<1000; i++){
        insere(minha_arv, i);
    }
    pos_ordem_esq(minha_arv);
    return 0;
}