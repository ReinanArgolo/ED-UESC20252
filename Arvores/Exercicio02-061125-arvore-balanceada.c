#include <stdlib.h>
#include <stdio.h>



typedef struct ArvAVL {
    int val;
    struct ArvAVL* dir; 
    struct ArvAVL* esq; 
} ArvAVL;


int max(int a, int b) {
    return (a > b) ? a : b;
}

int get_altura(ArvAVL* Node) {
    if (Node == NULL) {
        return -1;
    }

    return (max(get_altura(Node->esq), get_altura(Node->dir)) + 1);
}


int get_fatBalnceamento(ArvAVL* Node) {
    if (Node == NULL) return 0;

    return get_altura(Node->esq) - get_altura(Node->dir);
} 

ArvAVL* rotar_Direita(ArvAVL* Node) {
    ArvAVL* filho_esq = Node->esq;
    ArvAVL* neto_dir = filho_esq->dir;
    
    filho_esq->dir = Node;
    Node->esq = neto_dir;

    return filho_esq;

}

ArvAVL* rotar_Esq(ArvAVL* Node) {
    ArvAVL* filho_dir = Node->dir;
    ArvAVL* neto_esq = Node->esq;

    filho_dir->esq = Node;
    Node->dir = neto_esq;

    return filho_dir;

}


ArvAVL* balancear(ArvAVL* Node) {
    int fator_de_balanceamento = get_fatBalnceamento(Node);

    if(fator_de_balanceamento > 1 && get_fatBalnceamento(Node->esq) >= 0) return rotar_Direita(Node);

    if(fator_de_balanceamento > 1 && get_fatBalnceamento(Node->esq) < 0) {
        Node->esq = rotar_Esq(Node->esq);
        return rotar_Direita(Node);
    }

    if(fator_de_balanceamento < -1 && get_fatBalnceamento(Node->dir) <= 0) return rotar_Esq(Node);
    
    if(fator_de_balanceamento < -1 && get_fatBalnceamento(Node->dir) > 0) {
        Node->dir = rotar_Direita(Node->dir);
        return rotar_Esq(Node);
    }

    return Node;

}

ArvAVL* aloc_no() {
    ArvAVL* novo = (ArvAVL*)malloc(sizeof(ArvAVL));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->val = 0;
    return novo;
}

ArvAVL* adicionar_no(int n, ArvAVL* tree) {
    ArvAVL* new_no = aloc_no();
    new_no->val = n;

    if(tree == NULL) return new_no;

    if(n < tree->val) {
        tree->esq = adicionar_no(n, tree->esq);
    } else {
        tree->dir = adicionar_no(n, tree->dir);
    }

    tree = balancear(tree);

    return tree;
}

void imprimir_arvore_helper(ArvAVL* Node, int espaco, int nivel) {
    if (Node == NULL) return;
    
    espaco += nivel;
    
    imprimir_arvore_helper(Node->dir, espaco, nivel);
    
    printf("\n");
    for (int i = nivel; i < espaco; i++) {
        printf("   ");
    }
    printf("%d\n", Node->val);
    
    imprimir_arvore_helper(Node->esq, espaco, nivel);
}

void imprimir_arvore(ArvAVL* Node) {
    printf("\n========== ARVORE AVL ==========\n");
    imprimir_arvore_helper(Node, 0, 5);
    printf("\n================================\n\n");
}

void imprimir_arvore_detalhada(ArvAVL* Node, char* prefixo, int is_direita) {
    if (Node == NULL) return;
    
    printf("%s", prefixo);
    printf("%s", is_direita ? "|-- " : "`-- ");
    printf("%d (FB: %d, H: %d)\n", Node->val, get_fatBalnceamento(Node), get_altura(Node));
    
    char novo_prefixo[1000];
    sprintf(novo_prefixo, "%s%s", prefixo, is_direita ? "|   " : "    ");
    
    if (Node->esq != NULL || Node->dir != NULL) {
        if (Node->dir != NULL) {
            imprimir_arvore_detalhada(Node->dir, novo_prefixo, 1);
        } else {
            printf("%s|-- (vazio)\n", novo_prefixo);
        }
        
        if (Node->esq != NULL) {
            imprimir_arvore_detalhada(Node->esq, novo_prefixo, 0);
        } else {
            printf("%s`-- (vazio)\n", novo_prefixo);
        }
    }
}

void mostrar_arvore(ArvAVL* Node) {
    if (Node == NULL) {
        printf("Arvore vazia!\n");
        return;
    }
    
    printf("\n==========================================\n");
    printf("         ARVORE AVL BALANCEADA          \n");
    printf("==========================================\n\n");
    printf("Raiz: %d (FB: %d, Altura: %d)\n", Node->val, get_fatBalnceamento(Node), get_altura(Node));
    
    if (Node->dir != NULL || Node->esq != NULL) {
        if (Node->dir != NULL) {
            imprimir_arvore_detalhada(Node->dir, "", 1);
        } else {
            printf("|-- (vazio)\n");
        }
        
        if (Node->esq != NULL) {
            imprimir_arvore_detalhada(Node->esq, "", 0);
        } else {
            printf("`-- (vazio)\n");
        }
    }
    printf("\n");
}


int main (void) {
    ArvAVL* arvore = NULL;
    
    printf("Inserindo valores: 10, 20, 30, 40, 50, 25, 5, 15\n");
    
    arvore = adicionar_no(10, arvore);
    arvore = adicionar_no(20, arvore);
    arvore = adicionar_no(30, arvore);
    arvore = adicionar_no(40, arvore);
    arvore = adicionar_no(50, arvore);
    arvore = adicionar_no(25, arvore);
    arvore = adicionar_no(5, arvore);
    // arvore = adicionar_no(4, arvore);
    arvore = adicionar_no(15, arvore);
    
    mostrar_arvore(arvore);
    
    return 0;
}

