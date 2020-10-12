#include <stdio.h>

void main () {
    int zi;
    printf("Introduceti un numar: ");
    scanf("%d", &zi);
    if (zi == 1) printf("Luni");
    else if (zi == 2) printf("Marti");
    else if (zi == 3) printf("Miercuri");
    else if (zi == 4) printf("Joi");
    else if (zi == 5) printf("Vineri");
    else if (zi == 6) printf("Sambata");
    else if (zi == 7) printf("Duminica");
    else printf("eroare");
}