#include <stdio.h>

int fibo(int n) {
    int a0 = 0, a1 = 1, t;
    for (int i = 2; i <= n; ++i) {
        t = a0 + a1;
        a0 = a1;
        a1 = t;
    }
    return t;
}

int fact(int n) {
    int f = 1;
    if (n <= 1) return f;
    for (int i = 2; i <= n; ++i) {
        f *= i;
    }
    return f;
}

float expresie(int n) {
    float exp = 1.0f * fibo(n) / fact(n);
    printf("%f\n", exp);
    return exp;
}

void main () {
    int n;
    
    printf("Introdu numarul n: ");
    scanf("%d", &n);

    printf("fibo = %d\n", fibo(n));
    printf("fact = %d\n", fact(n));

    printf("%f", expresie(n));

}