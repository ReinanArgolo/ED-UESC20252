#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int n;
    struct Lista* prox;
} Lista;

typedef struct Pos {
    int pini;
    int pfim;
}Pos;


Lista* alocar_elemento() {
    Lista* elemt = (Lista*) malloc(sizeof(Lista));
    if(elemt == NULL) exit(-1);

    elemt->prox = NULL;

    return elemt;
}

void push(Lista** L, int n) {
    // acessa o ponteiro da lista; 

    // pensar no ponteiro Duplo como se fosse uma caixa que guarda a Lista dentro

    // quando acessamos o pontteiro com (*L) a gnt pega o acesso a lista!

    // essas modificações acontecem dentro da lista e a caixa altera direto da main;

    if(*L == NULL) {
        Lista* new = alocar_elemento();
        new->n = n;

        (*L) = new;
        return;
    }


    Lista* new = alocar_elemento();

    new->n = n;
    
    Lista* aux = *L;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = new;
    
}


void pop(Lista* L) {

    // EXCLUIMOS O ÚLTIMO ELEMENTO
    while((L->prox)->prox != NULL) {
        L = L->prox;
    }

    free(L->prox->prox);
    L->prox = NULL;
    
}

void imprimir(Lista* L) {
    while (L != NULL) {
        printf("%d ", L->n);
        L =  L->prox;
    }

}


Pos process_list(Lista* L) {
    if (L == NULL) return (Pos){-1, -1};
    
    Pos final_pos = {-1, -1};
    Pos aux_pos = {0, 0}; 
    
    int pos = 0;
    int atual_valor = L->n;
    int tamanho_atual = 1;
    int maior_tamanho = 1;
    
    aux_pos.pini = 0;  

    while (L->prox != NULL) {
        pos++;
        L = L->prox;
        
        if (L->n == atual_valor) {
            tamanho_atual++;
            aux_pos.pfim = pos;
        } else {
            if (tamanho_atual > maior_tamanho) {
                maior_tamanho = tamanho_atual;
                final_pos = aux_pos;
            }
            
            atual_valor = L->n;
            tamanho_atual = 1;
            aux_pos.pini = pos;
            aux_pos.pfim = pos;
        }
    }
    
    if (tamanho_atual > maior_tamanho) {
        final_pos = aux_pos;
    }
    
    printf("Maior sequencia: ini: %d | fim: %d | tamanho: %d\n", 
           final_pos.pini, final_pos.pfim, final_pos.pfim - final_pos.pini + 1);
    
    return final_pos;
    
}


int main() {
    Lista* lista = NULL;

    int temp;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &temp);
        if(temp == 1 || temp == 0) {
            push(&lista, temp);
        } else {
            i--;
        }
    }

    imprimir(lista);

    process_list(lista);

    // pop(lista);

}