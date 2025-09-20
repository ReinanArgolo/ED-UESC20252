#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int value;
    struct Pilha* prox;
} Pilha;


Pilha* alocar_pilha(void) {
    Pilha* new_p = malloc(sizeof(Pilha));
    if(new_p == NULL) exit(-1);

    new_p->prox = NULL;

    return new_p;
}

Pilha* push (Pilha* p, int nro) {
    Pilha* new_p = alocar_pilha();
    new_p->value = nro;
    new_p->prox = p;
    return new_p;
}

Pilha* pop (Pilha* p) {
    if(p == NULL) return NULL;

    Pilha* old_p = p;
    p = p->prox;

    free(old_p);
    return p;
}

void print_pilha(Pilha* p) {
    if (p == NULL) {
        printf("*\n");
        return; 
    }

    for (Pilha* aux = p; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->value);
    }
    printf("\n");

        
}





int main(void) {

    int qtd_op = -1;
    char op;
    Pilha* pilha = NULL;

    while (1) {
        if (scanf("%d", &qtd_op) != 1) break;   
        if (qtd_op <= 0) break;

        for (int i = 0; i < qtd_op; i++) {
            if (scanf(" %c", &op) != 1) break;  

            if (op == 'E' || op == 'e') {
                int nro;
                scanf("%d", &nro);              
                pilha = push(pilha, nro);       
            } else if (op == 'D' || op == 'd') {
                pilha = pop(pilha);             
            }

            print_pilha(pilha);
        }

        // for (Pilha* aux = pilha; aux != NULL; aux = aux->prox) {
        //    pilha = pop(pilha);
        // }

        pilha = NULL;
    }

    return 0;
}