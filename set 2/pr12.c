#include <stdio.h>

void main () {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) { // for sa stim ce numar trebuie scris
        for (int linii = 1; linii <= i; ++linii) { // for sa stim pe ce linie suntem
            for (int j = 0; j < i; ++j) {
                printf("%d ", i); // for sa stim cate numere sa scriem pe linie
            }
            printf("\n");
        }
        
    }
}