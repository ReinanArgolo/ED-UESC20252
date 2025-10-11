#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int valor;
    struct  Fila* prox;
    int* qtd_elemnts;
} Fila;


Fila* alocar_elemento() {
    Fila* novo = (Fila*) malloc(sizeof(Fila));
    if (novo == NULL) exit(-1);

    novo->prox = NULL;
    novo->valor = -1;
    novo->qtd_elemnts = NULL;

    return novo;
}

void adicionar_elemento(Fila** fila, int elemeto) {

    if(*fila == NULL) {
        Fila* novo = alocar_elemento();
        novo->valor = elemeto;
        *fila = novo;
        return;
    }
    
    Fila* novo = alocar_elemento();
    novo->valor = elemeto;
    Fila* aux = *fila;
    
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    
    aux->prox = novo;
}

void remove_topo(Fila** fila) {
    
    if(*fila == NULL) return;

    Fila* aux = *fila;

    printf("%d\n", aux->valor);

    *(aux->qtd_elemnts);

    *fila = (*fila)->prox;
    free(aux);
}


void imprimir_lista(Fila* lista) {
    if(lista == NULL) printf("fila vazia"); 

    while(lista != NULL) {
        printf(" %d ", lista->valor);
        lista = lista->prox;
    }


    printf("\n");
}


int get_elemento() {
    int e; 
    scanf("%d", &e);
    return e;
}


int main(void) {

    Fila* fila = NULL;
    char c;

    int contador = 0;

    // while(1) {
    //     if(c == "E") adicionar_elemento(&fila, get_elemento()); 
    //     if(c == "D") remove_topo(&fila);

    // }

    adicionar_elemento(&fila, 1);
    adicionar_elemento(&fila, 2);
    adicionar_elemento(&fila, 3);
    adicionar_elemento(&fila, 4);
    remove_topo(&fila);

    imprimir_lista(fila);
    
    return 0;
}