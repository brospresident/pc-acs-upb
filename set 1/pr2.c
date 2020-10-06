#include <stdio.h>

void main () {
    float nr1, nr2;
    printf("Introduceti 2 numere: ");
    scanf("%f%f", &nr1, &nr2); // citirea datelor de la tastatura
    // subpunct a)
    printf("Afisarea cu 3 zecimale: %.3f %.3f\n", nr1, nr2);
    printf("Afisarea cu 5 zecimale: %.5f %.5f\n", nr1, nr2);
    printf("Afisearea cu 2 zecimale: %.2f, %.2f\n", nr1, nr2);
    /* Observam ca atunci cand afisam cu 3 zecimale se afiseaza exact numerele pe care le-am introdus.
     * Observam ca atunci cand afisam cu 5 zecimale apare cifra 0 de 2 ori la finalul numarului afisat.
     * Observam ca atunci cand afisam cu 2 zecimale numerele sunt rotunjite. Exemplu: input: 1.345 => output: 1.35.
    */

    // subpunct b)
    printf("Valorile celor doua numere in format mantissa-exponent sunt: %E %E\n", nr1, nr2);

    // subpunct c)
    printf("Afisarea sumei folosind un numar intreg: %d\n", nr1 + nr2);
    printf("Afisarea sumei folosind un numar real: %f\n", nr1 + nr2);
    // Observam ca primim un numar aleator, nu ce trebuia sa afiseze.

    // subpunct d)
    float f;
    scanf("%d", &f); // am citit un float de la tastatura folosind %d
    printf("%f\n", f); // l-am afisat folosind %f si am observat ca are valoarea 0.000000
    // Observam ca nu i se atribuie nici o valoare lui variabilei f.

    // subpunct e)
    float nr = 5;
    printf("Am afisat un float cu 3 zecimale: %.3f", nr);
}