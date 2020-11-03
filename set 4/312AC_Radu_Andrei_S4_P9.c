#include <stdio.h>
#include <stdbool.h>

void main () {
    int vector[10], n;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    bool cititCorect = true;

    int i = 0;
    printf("vector[%d] = ", i);
    scanf("%d", &vector[i]);
    i++;
    for ( ; i < n && cititCorect == true; ++i) {
        printf("vector[%d] = ", i);
        int element;
        scanf("%d", &element);
        if (element < vector[i - 1]) {
            cititCorect = false;
        }
        vector[i] = element;
    }


    if (cititCorect == true) {
        printf("Vectorul ordonat a fost citit cu succes! Elementele lui sunt: \n");
        for (int i = 0; i < n; ++i) {
            printf("%d ", vector[i]);
        }
        printf("\n");

        int numar, pozitieDeAdaugat = n; // in cazul in care nu o sa gasesc loc intre elementele vectorului, il voi adauga la final.

        printf("Introdu numarul pe care vrei sa il adaugi la vector: ");
        scanf("%d", &numar);

        for (int i = 0; i < n; ++i) {
            if (numar > vector[i - 1] && numar < vector[i]) {
                pozitieDeAdaugat = i;
                break;
            }
        }

        for (int i = n; i >= pozitieDeAdaugat; --i) {
            vector[i] = vector[i - 1];
        }
        
        vector[pozitieDeAdaugat] = numar;

        printf("Vectorul dupa ce am adaugat un nou element: ");
        for (int i = 0; i < n + 1; ++i) {
            printf("%d ", vector[i]);
        }
    }
    else {
        printf("Vectorul nu a fost citit corect.");
    }
}