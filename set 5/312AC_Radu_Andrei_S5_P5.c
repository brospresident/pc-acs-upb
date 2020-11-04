#include <stdio.h>

void numarCifre(int nr, int *vectorCifre, int *nrC) {
    if (nr < 0) nr = -nr; // daca numarul e negativ atunci il fac pozitiv pentru a nu imi afisa cifrele cu - in fata.
    int cifre = 0;
    while (nr) {
        *(vectorCifre + cifre) = nr % 10;
        nr /= 10;
        cifre++;
    }
    *nrC = cifre;    
}

// am transmis numarul prin valoare deoarece nu am vrut sa pierd continutul variabilei in care era stocat.

void main () {
    int numar, cifre[3], nrCifre;
    printf("Introdu un numar care sa aiba cel mult 3 cifre: ");
    scanf("%d", &numar);
    if (numar >= -999 && numar <= 999) {
        numarCifre(numar, cifre, &nrCifre);
        printf("Numarul %d are %d cifre. Acestea sunt: ", numar, nrCifre);
        for (int i = 0; i < nrCifre; ++i) {
            printf("%d ", cifre[i]);
        }
    }
    else printf("Numarul introdus are mai mult de 3 cifre.");
}

