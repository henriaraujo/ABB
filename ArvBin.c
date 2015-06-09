#include "ArvBin.h"
#include<stdlib.h>

ArvBin* criarArvore() {
    return NULL;
}

int estahVazia(ArvBin* arv) {
    if (arv == NULL)
        return TRUE;
    return FALSE;
}

ArvBin* criarNoFolha(int item) {
    ArvBin* folha = malloc(sizeof(*folha));
    if (folha == NULL)
        return NULL;
    folha->item = item;
    folha->sae = NULL; folha->sad = NULL;
    return folha;
}

int buscar(ArvBin* arv, int item) {
    if (arv == NULL)
        return FALSE;
    if (item < arv->item)
        return buscar(arv->sae, item);
    if (item > arv->item)
        return buscar(arv->sad, item);
    return TRUE;
}

ArvBin* inserir(ArvBin* arv, int item) {
    if (arv == NULL)
        return criarNoFolha(item);
    if (item < arv->item) {
        arv->sae = inserir(arv->sae, item);
    } else if (item > arv->item) {
        arv->sad = inserir(arv->sad, item);
    }
    return arv;
}

void preOrdem(ArvBin* arv, void (*f) (int)) {
    if (arv != NULL) {
      (*f)(arv->item);
      preOrdem(arv->sae, f);
      preOrdem(arv->sad, f);
    }
}

void inOrdem(ArvBin* arv, void (*f) (int)) {
    if (arv != NULL) {
      inOrdem(arv->sae, f);
      (*f)(arv->item);
      inOrdem(arv->sad, f);
    }
}


void posOrdem(ArvBin* arv, void (*f) (int)) {
    if (arv != NULL) {
      posOrdem(arv->sae, f);
      posOrdem(arv->sad, f);
      (*f)(arv->item);
    }
}
