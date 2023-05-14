#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "tree.c"

int main(){
    arv_t* arv = cria_arv('a', cria_arv('b',cria_arv('d',cria_arv('g',NULL,NULL),NULL), cria_arv('e',cria_arv('i',NULL, NULL), cria_arv('j',NULL,NULL))),
                                        cria_arv('c',NULL, cria_arv('f',cria_arv('h',NULL,NULL), cria_arv('k',NULL,NULL))));
    // Create a fila
    fila f = fila_cria();

    // Create some arv_t nodes
    arv_t* node1 = cria_arv('A', NULL, NULL);
    arv_t* node2 = cria_arv('B', NULL, NULL);
    arv_t* node3 = cria_arv('C', NULL, NULL);

    // Insert the arv_t nodes into the fila
    fila_insere(f, node1);
    fila_insere(f, node2);
    fila_insere(f, node3);

    // Get the first arv_t node in the fila
    arv_t* firstNode = fila_mostra_inicio(f);
    printf("First node: %c\n", firstNode->data);

    // Get the last arv_t node in the fila
    arv_t* lastNode = fila_mostra_fim(f);
    printf("Last node: %c\n", lastNode->data);

    // Remove an arv_t node from the fila
    arv_t* removedNode = fila_remove(f);
    printf("Removed node: %c\n", removedNode->data);

    arv_t* new_removedNode = fila_remove(f);
    printf("Removed node: %c\n", new_removedNode->data);

    // Destroy the fila and free memory
    fila_destroi(f);

    // Cleanup the arv_t nodes
    arv_destroi(node1);
    arv_destroi(node2);
    arv_destroi(node3);
    return 0;
}
