#include <stdio.h>
#include <stdbool.h>

void main () {
    int vector[10], n;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    bool crescator = true, descrescator = true, constant = true;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vector[i] >= vector[j]) crescator = false;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vector[i] <= vector[j]) descrescator = false;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vector[i] != vector[j]) constant = false;
        }
    }

    if (crescator == true) printf("crescator");
    else if (descrescator == true) printf("descrescator");
    else if (constant == true) printf("constant");
    else printf("oarecare");


}