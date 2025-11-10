#include <stdlib.h>
#include <stdio.h>

typedef unsigned int u_int;

typedef struct Lista {
    u_int elemento;
    struct Lista* prox;
    struct Lista* anter;
} Lista;

Lista* alocar_elemento(u_int elemt) {
    Lista* no = (Lista*) malloc(sizeof(Lista));
    if (no == NULL) exit(-1);
    no->elemento = elemt;
    no->anter = NULL;
    no->prox = NULL;
    return no;
}

Lista* add_elemt_head(Lista* lista, u_int elemento) {
    Lista* lista_nova = alocar_elemento(elemento);
    if (lista == NULL) return lista_nova;
    lista_nova->prox = lista;
    lista->anter = lista_nova;
    return lista_nova;
}

Lista* add_elemt_tail(Lista* lista, u_int elemento) {
    Lista* novo = alocar_elemento(elemento);
    if (lista == NULL) return novo;

    Lista* tail = lista;
    while (tail->prox != NULL) tail = tail->prox;

    tail->prox = novo;
    novo->anter = tail;
    return lista;
}
        
Lista* reordena_lista(Lista* l) {
    if (l == NULL || l->prox == NULL) return l;

    Lista *imparInicio = NULL, *imparFim = NULL;
    Lista *parInicio = NULL, *parFim = NULL;

    int posicao = 1;
    Lista* atual = l;
    while (atual != NULL) {
        Lista* proximo = atual->prox;

        atual->prox = NULL;
        atual->anter = NULL;

        if (posicao % 2 == 0) {
            if (imparInicio == NULL) {
                imparInicio = imparFim = atual;
            } else {
                imparFim->prox = atual;
                atual->anter = imparFim;
                imparFim = atual;
            }
        } else {
            if (parInicio == NULL) {
                parInicio = parFim = atual;
            } else {
                parFim->prox = atual;
                atual->anter = parFim;
                parFim = atual;
            }
        }

        atual = proximo;
        posicao++;
    }

    
    if (parInicio != NULL) {
        parFim->prox = imparInicio;
        if (imparInicio != NULL) imparInicio->anter = parFim;
        return parInicio; 
    }

    return imparInicio; 
}

void imprimir_lista(const Lista* l) {
    const Lista* p = l;
    while (p != NULL) {
        printf("%d", p->elemento);
        if (p->prox != NULL) printf(" ");
        p = p->prox;
    }
    printf("\n");
}

void liberar_lista(Lista* l) {
    while (l != NULL) {
        Lista* prox = l->prox;
        free(l);
        l = prox;
    }
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    Lista* l = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        if (scanf("%d", &x) != 1) break;
        l = add_elemt_tail(l, (u_int)x);
    }

    l = reordena_lista(l);
    imprimir_lista(l);
    liberar_lista(l);
    return 0;
}