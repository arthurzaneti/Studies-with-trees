#include "abb.h"
#include "abb.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    arv_t*minha_arv = cria_arv(rand(), NULL, NULL);
    for (int i=0; i<1000; i++){
        insere(minha_arv, rand());
    }
    
    //pre_ordem_esq(minha_arv);
    //em_ordem_esq(minha_arv);
    //pos_ordem_esq(minha_arv);
    //pre_ordem_dir(minha_arv);
    //em_ordem_dir(minha_arv);
    //pos_ordem_dir(minha_arv);
    
    return 0;
}