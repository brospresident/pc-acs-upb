#include <stdio.h>
#include <limits.h>

int gasesteMaximImpar(int* v, int  lungimeV) {
    int maximImpar = INT_MIN;
    for (int i = 0; i < lungimeV; ++i) {
        if (v[i] % 2 && v[i] > maximImpar) maximImpar = v[i]; 
    }
    return maximImpar;
}

void main () {
    int vector[10], n;

    printf("Introdu lungimea vectorului: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    int maxImpar = gasesteMaximImpar(vector, n);

    printf("Maximul impar din vector este %d.", maxImpar);
}