#include <stdio.h>
#include <string.h>


void main () {
    char sir1[256], sir2[256], sir3[256];

    printf("Introdu un sir: ");
    gets(sir1);
    fflush(stdin);

    printf("Introdu un sir: ");
    gets(sir2);
    fflush(stdin);

    printf("Introdu un sir: ");
    gets(sir3);
    fflush(stdin);

    int lungime1 = strlen(sir1), lungime2 = strlen(sir2), lungime3 = strlen(sir3);

    int lungime = lungime1 + lungime2;
    int c = 0;
    for (int i = lungime1; i < lungime; ++i) {
        sir1[i] = sir2[c];
        c++;
    } // am concatenat sir1 cu sir 2

    int final = lungime1 + lungime2 + lungime3;
    c = 0;
    for (int i = lungime; i < final; ++i) {
        sir1[i] = sir3[c];
        c++;
    }

    for (int i = 0; i < final; ++i) {
        printf("%c", sir1[i]);
    }
}