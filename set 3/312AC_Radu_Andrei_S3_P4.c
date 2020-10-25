#include <stdio.h>
#include <stdbool.h>

void main () {
    int vector[20], n;
    
    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    int distincte = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < n - 1; ++i) {
        for (int j = 1; j < n; ++j) {
            if (vector[i] != vector[j]) distincte++;
        }
    }

    if (distincte == n) printf("Toate distincte.");
    else if (distincte == 0) printf("Toate identice.");
    else printf("Oarecare");

    /*
        Am sortat vectorul folosind bubble sort si apoi am luat fiecare element si l-am comparat cu restul iar apoi am facut verificarea. Daca numarul de elemente distincte == n
        atunci inseamna ca toate sunt distincte, daca distincte == 0 atunci toate sunt identice, iar daca nu se trece de niciuna din cele 2 verificari
        atunci vectorul este oarecare.
    */


}