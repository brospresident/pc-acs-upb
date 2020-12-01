#include <stdio.h>
#include <string.h>

void main () {
    char sir[101];

    printf("Introdu un sir: ");
    scanf("%[^\n]s", sir);

    int indiceDeEliminat = 0;
    while (indiceDeEliminat < strlen(sir)) {
        for (int i = 0; i < strlen(sir); ++i) {
            if (i != indiceDeEliminat) printf("%c", sir[i]);
        }
        printf("\n");
        indiceDeEliminat++;
    }
}