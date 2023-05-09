#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree_func.c"


int main(){
    arv_t* arv = cria_arv('a', cria_arv('b', cria_arv('d',NULL,NULL), cria_arv('e',NULL,NULL)),cria_arv('c',NULL, NULL));
    printf("Num_nos: %d\n", num_nos(arv));
    printf("Altura: %d\n", altura(arv));
    printf("Num_nos_folha: %d\n", num_nos_folha(arv));
    printf("Num_nos_nao_folha: %d\n", num_nos_nao_folha(arv));
    printf("Nivel_no: %d\n", nivel_no(arv, 'd'));
    return 0;
}
