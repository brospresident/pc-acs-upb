#include <stdio.h>
#include <math.h>

void main () {
    int n;
    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);
    int v[n];

    for (int i = 0; i < n; ++i) {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }

    // subpunct a)
    int prag;
    printf("Introdu pragul: ");
    scanf("%d", &prag);

    printf("Subpunct a:\n");
    for (int i = 0; i < n; ++i) {
        if (v[i] > prag) {
            printf("%d apare pe pozitia %d \n", v[i], i);
        }
    }
    printf("\n");

    // subpunct b)
    printf("Subpunct b:\n");
    for (int i = 0; i < n; i += 2) { // am plecat cu i de la 0 si am crescut cu 2 deci vom afisa doar v[0], v[2], v[4]...adica elementele de pe pozitii pare
        printf("%d\n", v[i]);
    }
    printf("\n");

    // subpunct c)
    int sterse = 0; // cate elemente de 0 vom sterge
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) sterse++;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            int pozitie = i;
            pozitie++;
            while (v[pozitie] == 0 && pozitie < n) {
                pozitie++;
            } // daca avem valori consecutive de 0 trecem peste ele pana gasim una diferita de 0 fara sa depasim limita vectorului.
            v[i] = v[pozitie];
            v[pozitie] = 0;
             
        }
    }
    

    
    printf("Subpunct c:\n");
    for (int i = 0; i < n - 1 - sterse; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");


    // subpunct d)
    for (int i = 0; i < n - sterse - 1; ++i) { // am setat i < n - sterse deoarece de la n - sterse + 1 se gasesc valorile de 0 din vector
        int element = v[i], nrdivizori = 1; // 1 este divizor al oricarui numar asa ca vom incepe loop-ul de la 2.
        for (int j = 2; j <= element; ++j) {
            if (element % j == 0) nrdivizori++;
        }
        v[i] = nrdivizori;
    }
    
    printf("Subpunct d:\n");
    for (int i = 0; i < n - sterse - 1; ++i) {
        printf("%d ", v[i]);
    }
}
