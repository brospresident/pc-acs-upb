#include <stdio.h>
#include <stdbool.h>


void main () {
    int vector[25], Vector[25], n;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    int contor = 0;
    for (int i = 0; i < n; ++i) {
        bool gasit = false;
        int element = vector[i];
        for (int j = 0; j < contor; ++j) {
            if (element == Vector[j]) gasit = true;
        }
        if (gasit == false) { // daca nu am gasit deja elementul in vector atunci il adaugam si crestem contorul.
            Vector[contor] = vector[i];
            contor++;
        }
    }

    printf("Vectorul format este: ");
    for(int i = 0; i < contor; ++i) {
        printf("%d ", Vector[i]);
    }

    // Varianta
    int VVector[25];
    contor = 0;
    for (int i = 0; i < n; ++i) {
        bool dublura = false;
        int element = vector[i];
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            if (vector[j] == element) dublura = true;
        }
        if (dublura == false) { // daca nu am gasit dublura pentru elementul cautat atunci il adaugam in vector.
            VVector[contor] = element;
            contor++;
        }
    }    

    printf("\nVectorul format este: ");
    for (int i = 0; i < contor; ++i) {
        printf("%d, ", VVector[i]);
    }
}