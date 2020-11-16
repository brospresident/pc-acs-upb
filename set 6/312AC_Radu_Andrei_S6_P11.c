#include <stdio.h>
#include <stdbool.h>

bool verificaIdentitateVector(int* vectorA, int lVA, int* vectorB, int lVB) {
    bool gasit = true;
    if (lVA != lVB) return false;
    for (int i = 0; i < lVA; ++i) {
        gasit = false;
        for (int j = 0; j < lVA; ++j) {
            if (vectorA[i] == vectorB[j]) {
                gasit = true;
            }
        }
        if (gasit == false) return gasit;
    }
    return true;
}

void citesteMatrice(int matrice[][10], int* lungimeMatrice, char numeMatrice) {
    printf("Introdu lungimea matricei %c: ", numeMatrice);
    scanf("%d", lungimeMatrice);
    for (int i = 0; i < *lungimeMatrice; ++i) {
        for (int j = 0; j < *lungimeMatrice; ++j) {
            printf("%c[%d][%d] = ", numeMatrice, i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

void citesteVector(int* vector, int* lungimeVector, char numeVector) {
    printf("Introdu lungimea vectorului %c: ", numeVector);
    scanf("%d", lungimeVector);
    for (int i = 0; i < *lungimeVector; ++i) {
        printf("%c[%d] = ", numeVector, i);
        scanf("%d", &vector[i]);
    }
}

void main () {
    int A[10], M[10][10], lA, lM;

    citesteMatrice(M, &lM, 'M');
    citesteVector(A, &lA, 'A');

    bool verificat;
    int verificari = 0;
    if (lA != lM) verificat = false;
    else {
        for (int i = 0; i < lA; ++i) {
            verificat = verificaIdentitateVector(A, lA, M[i], lM);
            if (verificat) {
                 printf("Vectorul coincide cu linia %d din matrice.\n", i);
                 verificari++;
            }
        }
    }
    if (verificari == 0) printf("Vectorul nu coincide cu nicio linie din matrice.");
}
