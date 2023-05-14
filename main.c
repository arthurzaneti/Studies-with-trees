#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "tree.c"

int main(){
    arv_t* arv = cria_arv('a', cria_arv('b',cria_arv('d',cria_arv('g',NULL,NULL),NULL), cria_arv('e',cria_arv('i',NULL, NULL), cria_arv('j',NULL,NULL))),
                                        cria_arv('c',NULL, cria_arv('f',cria_arv('h',NULL,NULL), cria_arv('k',NULL,NULL))));
    em_largura_dir(arv);
    return 0;
}
