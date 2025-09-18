#include <stdio.h>
#include <stdlib.h>

typedef struct vagoes {
    int vagao;
    struct vagoes *prox;
} vagoes;


vagoes* alocar_vagao() {
    vagoes* new_vagao = (vagoes*) malloc(sizeof(vagoes));

    if(new_vagao == NULL) exit(-1);
    new_vagao->prox = NULL;
    new_vagao->vagao = 0;

    return new_vagao;
}


vagoes* pop(vagoes* vagoes) {

} 

vagoes* push(vagoes* v, int vag) {
    if(v == NULL) {
        v = alocar_vagao();
        v->vagao = vag;
        return v;
    }

    vagoes* new_vagao = alocar_vagao();
    new_vagao->vagao = vag;
    new_vagao->prox = v;
    return new_vagao;
}




int main(void) {

}