#include <stdio.h>
#include <limits.h>

void cautaPozitiiMinim(int* vectorCautat, int lungimeVector, int* vectorPozitii, int* lPozitii) {
    int contor = 0, min = INT_MAX;
    for (int i = 0; i < lungimeVector; ++i) {
        if (vectorCautat[i] < min) min = vectorCautat[i];
    }

    for (int i = 0; i < lungimeVector; ++i) {
        if (vectorCautat[i] == min) {
            vectorPozitii[contor++] = i;
        }
    }
    *lPozitii = contor;
}

void main () {
    int vector[100], n;

    printf("Introdu lungimea vectorului: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("v[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    int pozitii[100], lungimePozitii = 0;

    cautaPozitiiMinim(vector, n, pozitii, &lungimePozitii);

    for (int i = 0; i < lungimePozitii; ++i) {
        printf("%d ", pozitii[i]);
    }
}