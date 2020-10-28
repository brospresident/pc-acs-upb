#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void main () {
    int vector[10], n;
    float medie = 0.0f;
    
    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ");
        scanf("%d", vector[i]);
        medie += vector[i];
    }

    // subpunct a
    medie /= n;

    bool existaMedia = false;
    for (int i = 0; i < n && existaMedia == false; ++i) {
        if (medie == vector[i]) existaMedia = true;
    }

    if (existaMedia == true) printf("Media elementelor din vector se regaseste in acesta.\n");
    else printf("Media elementelor din vector nu se regaseste in acesta.\n");

    // subpunct b
    int minim = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (vector[i] < minim) minim = vector[i];
    }

    printf("Valoarea minima este: %d\n", minim);
    printf("Pozitiile pe care apare sunt: ");
    for (int i = 0; i < n; ++i) {
        if (vector[i] == minim) printf("%d ", i);
    }

}