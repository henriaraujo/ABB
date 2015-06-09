#include "ArvBin.h"
#include<stdio.h>

void imprimir(int item) {
    printf("%d ", item);
}

int main() {
    ArvBin *minhaArv = criarArvore();
    minhaArv = inserir(minhaArv, 5);
    minhaArv = inserir(minhaArv, 3);
    minhaArv = inserir(minhaArv, 7);
    minhaArv = inserir(minhaArv, 4);
    minhaArv = inserir(minhaArv, 6);
    preOrdem(minhaArv, imprimir);
    printf("\n");
    inOrdem(minhaArv, imprimir);
    printf("\n");
    posOrdem(minhaArv, imprimir);

    if (buscar(minhaArv, 8) == TRUE)
        printf("\nElemento encontrado!\n");
    else
        printf("\nElemento não encontrado!\n");

    return 0;
}

