#include <stdio.h>

void stergePrimulElement(int* vectorDeSters, int* lVector) {
    int prim = vectorDeSters[0], deSters = 0;

    for (int i = 0; i < *lVector; ++i) {   
        if (vectorDeSters[i] == prim) deSters++;
    }

    for (int i = 0; i < *lVector; ++i) {
        if (vectorDeSters[i] == prim) {
            int pozitie = i;
            pozitie++;
            while (vectorDeSters[pozitie] == prim && pozitie < *lVector) pozitie++;
            vectorDeSters[i] = vectorDeSters[pozitie];
            vectorDeSters[pozitie] = prim;
        }
    }

    *lVector -= deSters;
}

void main () {
    int vector[100], n;

    printf("Introdu lungimea vectorului: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("v[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    stergePrimulElement(vector, &n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", vector[i]);
    }

}