#include <stdio.h>

void numaraPerechi(int* v, int len, int* per) {
    int perechi = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (v[i] == v[i + 1]) {
            perechi++;
        }
    }
    *per = perechi;
}

void main () {
    int vector[] = {2, 3, 3, 3, 5, 7, 7, 9};
    int lungimeVector = sizeof(vector) / sizeof(vector[0]);

    int perechi;
    numaraPerechi(vector, lungimeVector, &perechi);

    printf("In vector exista %d perechi de elemente consecutiv identice.", perechi);
}