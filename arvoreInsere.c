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

//a partir de uma altura (vai ate 0) cria
//uma arvore balanceada e completa
no* criaArvoreSim(int altura)
{
    no *n = criaNodo(altura);
    if(altura == 0)
        return n;
    n->esq = criaArvoreSim(altura-1);
    n->dir = criaArvoreSim(altura-1);
    return n;
}

//busca chave na arvore de raiz n
//se achar devolve o no em acha
//se nao achar cria o no e devolve ele
no* buscaBinaria(no *n, int chave, no *achou)
{
    if(n == NULL){
        achou = criaNodo(chave);
        return achou;
    }
    
    if(n-> chave == chave)
        achou = n;
    else if(n->chave > chave)
        n->esq = buscaBinaria(n->esq, chave, achou);
    else if(n->chave < chave)
        n->dir = buscaBinaria(n->dir, chave, achou);

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
    no *arv2;

    arv = criaArvoreSim(2);
    printTree(arv);
    printf("\n");
    
    arv2 = malloc(sizeof(no));
    arv2->esq = NULL;
    arv2->dir = NULL;
    arv2->chave = 40;
    no *found;
    for(int i = 0; i < 10; i++)
        buscaBinaria(arv2, rand()%100, found);
    printTree(arv2);
    printf("\n");

    return 0;
}

