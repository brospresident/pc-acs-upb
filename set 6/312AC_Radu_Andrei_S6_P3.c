#include <stdio.h>

void numara(int* vector, int len, int* nul, int* poz, int* neg) {
    for (int i = 0; i < len; ++i) {
        if (*(vector + i) < 0) (*neg)++;
        else if (*(vector + i) == 0) (*nul)++;
        else (*poz)++;
    }
}

void main () {
    int vector[] = {5, -6, -8, 0, 0, 11, 14, -3};
    int lungime = sizeof(vector) / sizeof(vector[0]);

    int nule = 0, pozitive = 0, negative = 0;

    numara(vector, lungime, &nule, &pozitive, &negative);
    printf("Vectorul dat are %d elemente nule, %d elemente pozitive si %d elemente negative.", nule, pozitive, negative);
}