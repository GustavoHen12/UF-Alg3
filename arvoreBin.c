#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int chave;
    struct no *esq;
    struct no * dir;
} no;

no* criaNodo(int chave)
{
    no *n = malloc(sizeof(no));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

no* criaArvoreSim(int altura)
{
    no *n = criaNodo(rand()%100);
    if(altura == 0)
        return n;
    n->esq = criaArvoreSim(altura-1);
    n->dir = criaArvoreSim(altura-1);
    return n;
}

void printTree(no *n)
{
    if(n == NULL) return;
    printTree(n->esq);
    printf("%d ", n->chave);
    printTree(n->dir);
}

int main()
{
    no *arv;
    arv = criaArvoreSim(2);
    printTree(arv);
    printf("\n");
    return 0;
}

