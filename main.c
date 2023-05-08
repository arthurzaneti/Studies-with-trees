#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    char data;
    struct _no*dir;
    struct _no*esq;
}no;

no cria_no(char data, no*dir, no*esq){
    no *novo_no = malloc(sizeof(no));
    if (novo_no==NULL) {
        print("Erro ao criar no");
        return;
    }
    novo_no->data = data;
    novo_no->dir = dir;
    novo_no->esq = esq;
    return *novo_no;
}
