#include <stdio.h>
#include <stdlib.h>


void main () {
    char sir1[256], sir2[256];
    scanf("%s", &sir1);
    printf("%s\n", sir1);
    fflush(stdin);
    gets(sir2);
    printf("%s", sir2);
}

/*
    Observatii: functia scanf citeste un cuvant pana cand gaseste caracterul space, iar functia gets citeste un sir intreg.
*/