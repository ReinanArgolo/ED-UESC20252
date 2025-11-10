#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBi {
    int value;
    struct arvoreBi* esq;
    struct arvoreBi* dir;
} arvoreBi;


arvoreBi* aloc_no() {
    arvoreBi* new_no = (arvoreBi*) malloc(sizeof(arvoreBi));
    if(new_no == NULL) exit(-1);
    new_no->dir = NULL;
    new_no->esq = NULL;

    return new_no;
}


arvoreBi* adicionar_no(int n, arvoreBi* tree) {
    arvoreBi* new_no = aloc_no();
    new_no->value = n;

    if(tree == NULL) return new_no;

    if(n < tree->value) {
        tree->esq = adicionar_no(n, tree->esq);
    } else {
        tree->dir = adicionar_no(n, tree->dir);
    }

    return tree;
}

void imprimeInorder ( arvoreBi* raiz ) {
    if ( raiz == NULL ) return ;
    imprimeInorder ( raiz -> esq );
    printf ("%d ", raiz -> value );
    imprimeInorder ( raiz -> dir );
}

void imprimeEstrutura(arvoreBi* raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }
    
    imprimeEstrutura(raiz->dir, nivel + 1);
    
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("%d\n", raiz->value);
    
    imprimeEstrutura(raiz->esq, nivel + 1);
}


int encontrarNum(int n, arvoreBi* tree) {
    if(tree->value == n) {

        printf("1 [ ");
        if(tree->dir != NULL) printf("%d ", tree->dir->value);
        if(tree->esq != NULL) printf("%d ", tree->esq->value);

        printf("] ");

        return 1;
    } 

    if (tree->value < n) {
        encontrarNum(n, tree->esq);
    } else {
        encontrarNum(n, tree->dir);
    }
}

int main() {
    arvoreBi* tree =  NULL;

    int vals[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90};

    for(int i = sizeof(vals) / sizeof(int); i > 0; i--) {

        tree = adicionar_no(vals[i], tree);
    }

    printf("\n");
    imprimeEstrutura(tree, 0);




    printf("\n");

    imprimeInorder(tree);
}