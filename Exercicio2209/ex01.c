#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{
    int pessoa;
    struct Fila* prox;
} Fila;


Fila* alocar_pessoa() {
    Fila* nova = malloc(sizeof(Fila));
    if(nova == NULL) exit(-1);

    nova->prox = NULL;
    return nova;
}

void inserirPessoa(Fila** fila, int pessoa) {
    if(*fila == NULL) {
        *fila = alocar_pessoa();
    }

    Fila* aux = *fila;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    Fila *novo = alocar_pessoa;
    novo->pessoa = pessoa;
    aux->prox = novo;
}

void remove_elements(Fila** fila, Fila* out) {
    Fila* aux_f = *fila;
    
    while(aux_f->prox != NULL) {
        
    }
}



int main(void) {

}