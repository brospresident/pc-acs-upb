#include <stdio.h>

void construiesteVector(int* initial, int lInitial, int* vPare, int* lPare, int* vImpare, int* lImpare) {
    *lPare = 0;
    *lImpare = 0;
    for (int i = 0; i < lInitial; ++i) {
        if (initial[i] % 2) {
            vImpare[(*lImpare)++] = initial[i];
        }
        else {
            vPare[(*lPare)++] = initial[i];
        }
    }
}

void main () {
    int vectorInit[100], n;
    
    printf("Introdu lungimea vectorului initial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vectorInit[%d] = ", i);
        scanf("%d", &vectorInit[i]);
    }

    int vectorPare[100], vectorImpare[100], lungimePare = 0, lungimeImpare = 0;

    construiesteVector(vectorInit, n, vectorPare, &lungimePare, vectorImpare, &lungimeImpare);

    if (lungimePare == 0) {
        printf("In vectorul initial nu au fost elemente pare.\n");
    }
    else {
        printf("Vectorul cu elemente pare: ");
        for (int i = 0; i < lungimePare; ++i) {
            printf("%d ", vectorPare[i]);
        }
        printf("\n");
    }

    if (lungimeImpare == 0) {
        printf("In vectorul initial nu au fost elemente impare.\n");
    }
    else {
        printf("Vectorul cu elemente impare: ");
        for (int i = 0; i < lungimeImpare; ++i) {
            printf("%d ", vectorImpare[i]);
        }
        printf("\n");
    }
}