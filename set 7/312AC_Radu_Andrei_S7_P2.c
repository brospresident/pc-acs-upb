#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main () {
    char sir[256];

    printf("Introdu un sir: ");
    //gets(sir);
    scanf("%[^\n]s", sir);

    int lungime = 0;
    
    for (int i = 0; sir[i] != '\0'; ++i) {
        lungime++;
    }

    printf("Sirul citit are lungimea %d.\n", lungime);

    for (int i = 0; i < lungime; ++i) {
        printf("%c", sir[i]);
    }
}