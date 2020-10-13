#include <stdio.h>

void main () {
    int zi;
    
    printf("Introduceti un numar: ");
    scanf("%d", &zi);

    switch (zi) {
        case 1: {
            printf("Luni");
            break;
        }
        case 2: {
            printf("Marti");
            break;
        }
        case 3: {
            printf("Miercuri");
            break;
        }
        case 4: {
            printf("Joi");
            break;
        }
        case 5: {
            printf("Vineri");
            break;
        }
        case 6: {
            printf("Sambata");
            break;
        }
        case 7: {
            printf("Duminica");
            break;
        }
        default : printf("eroare");
    }
}