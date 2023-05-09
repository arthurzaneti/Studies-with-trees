#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

int main(){
    arv_t* arv = cria_arv('a', cria_arv('b', cria_arv('d',NULL,NULL), cria_arv('e',NULL,NULL)),cria_arv('c',NULL, NULL));
    assert(num_nos(arv)==5);
    assert(altura(arv)==2);
    assert(num_nos_folha(arv)==3);
    assert(num_nos_nao_folha(arv)==2);
    assert(nivel_no(arv, 'd')==2);
    assert(fator_equilibrio(arv)==1);
    return 0;
}
