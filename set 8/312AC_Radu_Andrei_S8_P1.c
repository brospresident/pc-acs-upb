#include <stdio.h>

struct nr_complex {
    int real;
    int imaginar;
};

struct nr_complex calculeazaSuma(struct nr_complex nr1, struct nr_complex nr2) {
    struct nr_complex rezultat;
    rezultat.real = nr1.real + nr2.real;
    rezultat.imaginar = nr1.imaginar + nr2.imaginar;
    return rezultat;
}

struct nr_complex calculeazaDiferenta(struct nr_complex nr1, struct nr_complex nr2) {
    struct nr_complex rezultat;
    rezultat.real = nr1.real - nr2.real;
    rezultat.imaginar = nr1.imaginar - nr2.imaginar;
    return rezultat;
}

void main () {
    struct nr_complex numar1, numar2;
    scanf("%d%d", &numar1.real, &numar1.imaginar);
    scanf("%d%d", &numar2.real, &numar2.imaginar);

    struct nr_complex rezult1, rezult2;
    rezult1 = calculeazaSuma(numar1, numar2);
    rezult2 = calculeazaDiferenta(numar1, numar2);

    printf("%d + %d * i", rezult1.real, rezult1.imaginar);
    printf("%d + %d * i", rezult2.real, rezult2.imaginar);
}