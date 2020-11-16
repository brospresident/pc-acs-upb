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

void main () {
    int matriceA[10][10], lungimeA, matriceB[10][10], lungimeB;

    printf("Introdu numarul de elemente din matricea A: ");
    scanf("%d", &lungimeA);

    printf("Introdu numarul de elemente din matricea B: ");
    scanf("%d", &lungimeB);

    for (int i = 0; i < lungimeA; ++i) {
        for (int j = 0; j < lungimeA; ++j) {
            printf("matriceA[%d][%d] = ", i, j);
            scanf("%d", &matriceA[i][j]);
        }
    }

    for (int i = 0; i < lungimeB; ++i) {
        for (int j = 0; j < lungimeB; ++j) {
            printf("matriceB[%d][%d] = ", i, j);
            scanf("%d", &matriceB[i][j]);
        }
    }

    bool verificare = true;
    if (lungimeA != lungimeB) verificare = false; // daca nu au acelasi numar de linii si coloane nu mai are rost sa verific nimic din matrice.
    else {
        for (int i = 0; i < lungimeA && verificare != false; ++i) {
            verificare = verificaIdentitateVector(matriceA[i], lungimeA, matriceB[i], lungimeB);
        }
    }

    if (verificare == false) {
        printf("Matricele nu sunt identice.");
    }
    else {
        printf("Matricele sunt identice.");
    }
}

/*
    In cadrul rezolvarii am considerat ca 2 matrice sunt identice daca au aceleasi elemente pe aceeasi linie indiferent de pozitia lor. Deci daca pe linia 0 vom avea 1 3 2 
    respectiv 1 2 3, functia verificaIdentitateVector va intoarce true deoarece are aceleasi elemente, fara sa conteze ordinea. In cazul in care vrem sa conteze ordinea,
    scoatem al doilea for din functie si punem verificarea if (vectorA[i] != vectorB[i]) return false; astfel daca nu au aceeasi ordine, atunci functia
    va intoarce false.
*/