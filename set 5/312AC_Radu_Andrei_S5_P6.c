#include <stdio.h>
#include <stdbool.h>

bool transform(int nr, int *trans) {
    int pare = 0, nrPare = 0;
    while (nr) {
        if (nr % 2 == 0) {
            nrPare = nrPare * 10 + nr % 10;
            pare++;
        }
        nr /= 10;
    }
    *trans = 0;
    while (nrPare) {
        *trans = *trans * 10 + nrPare % 10;
        nrPare /= 10;
    }
    if (pare) return true;
    else return false;
}

void main () {
    int numar, trans = 0;
    bool transformat;

    printf("Introdu un numar: ");
    scanf("%d", &numar);

    transformat = transform(numar, &trans);

    if (!transformat) printf("Numarul nu contine cifre pare.");
    else printf("Numarul obtinut din %d este %d.", numar, trans);

}