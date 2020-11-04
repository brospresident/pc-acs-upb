#include <stdio.h>
#include <stdbool.h>

bool eNumarPerfect(int n) {
    int perfect = 1; // am initializat cu 1 deoarece 1 e divizorul oricarui numar
    for (int i = 2; i <= n / 2; ++i) { // am parcurs pana la n / 2 deoarece dupa jumatatea numarului nu mai exista alt divizor in afara de el insusi
        if (n % i == 0) perfect += i;
    }
    if (perfect == n) return true;
    else return false;
}

void main () {
    printf("%d\n", eNumarPerfect(6));
    printf("%d\n", eNumarPerfect(28));
    printf("%d\n", eNumarPerfect(29));
}