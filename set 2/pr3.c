#include <stdio.h>
#include <math.h>

void main () {
    int numar;
    printf("Introdu un numar: ");
    scanf("%d", &numar);
    
    int verificare = 1; 
    /* se porneste de la ideea ca numarul e prim si adaugam o conditie suplimentara in for (verificare != 0), 
       in momentul in care verificare = 0 for se opreste si se trece la ultimul if. */
       
    for (int i = 2; i < sqrt(numar) && verificare != 0; ++i) {
        if (numar % i == 0) {
            verificare = 0;
        }
    }

    if (verificare == 0) printf("Numarul %d nu este prim.", numar);
    else printf("Numarul %d este prim.", numar);

}