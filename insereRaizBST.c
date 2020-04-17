#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int chave;
    struct no *esq;
    struct no *dir;
    struct no *pai;
} no;

no* criaNodo(int chave)
{
    no *n = malloc(sizeof(no));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
}


//insere a chave na raiz da arvore 
//seguindo: n.esq.chave <= n.chave < n.dir.chave
no* insereFolha(no *n, int chave)
{
    if(n == NULL)
        return criaNodo(chave);

    if(n->chave > chave){
        n->esq = insereFolha(n->esq, chave);
        n->esq->pai = n;
    }
    else if(n->chave <= chave){
        n->dir = insereFolha(n->dir, chave);
        n->dir->pai = n;
    }
    return n;
}

void rot_esq(no *tree, no *x)
{
    no * y = x->dir;
    x->dir = y->esq;
    if(y->esq != NULL)
        y->esq->pai = x;
    y->pai = x->pai;
    if(x->pai == NULL)
        tree = y;
    else if(x == x->pai->esq)
        x->pai->esq = y;
    else 
        x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}

void rot_dir(no *tree, no *x)
{
    no * y = x->esq;
    x->esq = y->dir;
    if(y->dir != NULL)
        y->dir->pai = x;
    y->pai = x->pai;
    if(x->pai == NULL)
        tree = y;
    else if(x == x->pai->esq)
        x->pai->esq = y;
    else 
        x->pai->dir = y;
    y->dir = x;
    x->pai = y;
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
    no *arv2;
    
    arv2 = malloc(sizeof(no));
    arv2->esq = NULL;
    arv2->dir = NULL;
    arv2->chave = 40;
   
    for(int i = 0; i < 10; i++)
        insereFolha(arv2, rand()%100);
    printTree(arv2);
    printf("\n");
    printf("> %d \n", arv2->dir->chave);
        

    rot_esq(arv2, arv2->dir);
    printf("> %d \n", arv2->dir->chave);
    printTree(arv2);
    printf("\n");

    printf("> %d \n", arv2->esq->chave);
    rot_esq(arv2, arv2->esq);
    printf("> %d \n", arv2->esq->chave);
    printTree(arv2);
    printf("\n");

    return 0;
}

