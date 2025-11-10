#include <stdio.h>
#include <stdlib.h>

static int contador = 0;

int fib_rec(int n) {

    if(n <= 0) return 0;
    if(n == 1) return 1;

    contador++;
    
    return fib_rec(n-1) + fib_rec(n-2);
}

int get_contador() {
    return (contador * 2);
}

void get_fib_n(int n) {
    contador = 0;
    if(n < 1 || n >= 39) return;
    int fib = fib_rec(n);

    printf("fib(%d) = %d calls = %d\n", n, get_contador(), fib);
}


int main() {
    int n;

    while (n > 0) {
        scanf("%d", &n);
        get_fib_n(n);
    }
    
    return 0;
}