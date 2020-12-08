#include <stdio.h>

struct Timp {
    int ora;
    int minut;
    int secunda;
};

struct Timp calculeazaTimp(struct Timp m1, struct Timp m2) {
    struct Timp rezultat = {
        .ora = 0,
        .minut = 0,
        .secunda = 0,
    };

    if (m1.secunda + m2.secunda > 59) {
        rezultat.minut += 1;
        rezultat.secunda = m1.secunda + m2.secunda - 60;
    }
    else rezultat.secunda = m1.secunda + m2.secunda;

    if (m1.minut + m2.minut > 59) {
        rezultat.ora += 1;
        rezultat.minut = m1.minut + m2.minut - 60; 
    } 
    else rezultat.minut = m1.minut + m2.minut;

    if (m1.ora + m2.ora > 23) {
        rezultat.ora = m1.ora + m2.ora - 24;
    }
    else rezultat.ora = m1.ora + m2.ora;
    
    return rezultat;
}

void main () {
    struct Timp moment1, moment2, result;

    printf("Introdu primul timp: ");
    scanf("%d%d%d", &moment1.ora, &moment1.minut, &moment1.secunda);

    printf("\nIntrodu al doilea timp: ");
    scanf("%d%d%d", &moment2.ora, &moment2.minut, &moment2.secunda);

    result = calculeazaTimp(moment1, moment2);
    if (result.ora < 10) {
        printf("0%d:", result.ora);
    }
    else printf("%d:", result.ora);

    if (result.minut < 10) {
        printf("0%d:", result.minut);
    }
    else printf("%d:", result.minut);

    if (result.secunda < 10) {
        printf("0%d", result.secunda);
    }
    else printf("%d", result.secunda);
}