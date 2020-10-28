#include <stdio.h>

void main () {
    int A[50], B[50], elA, elB;

    printf("Introdu numarul de elemente al lui A: ");
    scanf("%d", &elA);

    printf("Introdu numarul de elemente al lui B: ");
    scanf("%d", &elB);
    
    for (int i = 0; i < elA; ++i) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < elB; ++i) {
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }

    int C[50], elC = 0, contorA = 0, contorB = 0;

    while (contorA < elA && contorB < elB) {
        if (A[contorA] < B[contorB]) {
            if (A[contorA] % 2 != 0) {
                C[elC] = A[contorA];
                elC++;
            }
            contorA++;
        }
        else {
            if (B[contorB] % 2 != 0) {
                C[elC] = B[contorB];
                elC++;
            }
            contorB++;
        }
    }

    if (contorA <= elA) {
        for (int i = contorA; i < elA; ++i) {
            if (A[i] % 2 != 0) {
                C[elC] = A[i];
                elC++;
            }
        }
    }

    if (contorB <= elB) {
        for (int i = contorB; i < elB; ++i) {
            if (B[i] % 2 != 0) {
                C[elC] = B[i];
                elC++;
            }
        }
    }

    for (int i = 0; i < elC; ++i) {
        printf("%d ", C[i]);
    }

}