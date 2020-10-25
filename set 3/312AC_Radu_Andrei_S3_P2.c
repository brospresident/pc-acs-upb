#include <stdio.h>

void main () {
    int n;
    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);
    int v[100], im = 0, p = 0, pare[50], impare[50];

    for (int i = 0; i < n; ++i) {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
        if (v[i] % 2) {
            impare[im] = v[i];
            im++;            
        }
        else {
            pare[p] = v[i];
            p++;
        }
    }

    for (int i = 0; i < im; ++i) {
        printf("%d ", impare[i]);
    }
    printf("\n");
    for (int i = 0; i < p; ++i) {
        printf("%d ", pare[i]);
    }
}