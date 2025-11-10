#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum_digit(int n) {
    
    if(n < 10) return n % 10;

    return (n%10) + sum_digit(n / 10);
}

int main(void) {
    int n;
    scanf("%d", &n);
    if(n <= 0 || n >= pow(10, 9)) exit(-1);
    int sum = sum_digit(n);

    printf("%d", sum);
}

