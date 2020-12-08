#include <stdio.h>
#include <math.h>
#include <ctype.h>

struct fig_geom {
    char nume;
    int raza;
    int lungime;
    int latime;
};

void main () {
    char figura;

    printf("Introdu ce tip de figura vrei(c - cerc, p - patrat, d - dreptunghi): ");
    scanf("%c", &figura);

    figura = tolower(figura);

    struct fig_geom figuraGeometrica;

    switch (figura) {
        case 'c': {
            printf("Introdu raza: ");
            scanf("%d", &figuraGeometrica.raza);
            printf("Perimetrul cercului: %f\n", 2 * (M_PI) * figuraGeometrica.raza);
            printf("Aria cercului: %f", (M_PI) * pow(figuraGeometrica.raza, 2));
            break;
        }

        case 'p': {
            printf("Introdu lungimea: ");
            scanf("%d", &figuraGeometrica.lungime);
            figuraGeometrica.latime = figuraGeometrica.lungime;
            printf("Perimetrul patratului: %d\n", 4 * figuraGeometrica.lungime);
            printf("Aria patratului: %d\n", figuraGeometrica.lungime * figuraGeometrica.latime);
            break;
        }

        case 'd': {
            printf("Introdu lungimea: ");
            scanf("%d", &figuraGeometrica.lungime);
            printf("Introdu latimea: ");
            scanf("%d", &figuraGeometrica.latime);
            printf("Perimetrul dreptunghiului: %d\n", 2 * (figuraGeometrica.lungime + figuraGeometrica.latime));
            printf("Aria dreptunghiului: %d\n", figuraGeometrica.lungime * figuraGeometrica.latime);
            break;
        }
        default: printf("Nu exista");
    }
}