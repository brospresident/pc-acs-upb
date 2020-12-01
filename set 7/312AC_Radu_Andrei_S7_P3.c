#include <stdio.h>
#include <string.h>

void main () {
    char nume1[16], nume2[16];
    int varsta1, varsta2;

    printf("Introdu datele primei persoane: \n");
    printf("Nume: ");
    gets(nume1);
    fflush(stdin);
    printf("Varsta: ");
    scanf("%d", &varsta1);

    fflush(stdin);
    printf("Introdu datele primei persoane: \n");
    printf("Nume: ");
    gets(nume2);
    fflush(stdin);
    printf("Varsta: ");
    scanf("%d", &varsta2);

    if (strcmp(nume1, nume2)) {
        varsta1 < varsta2 ? printf("%s", nume1) : printf("%s", nume2);
        printf("\n");
        if (varsta1 == varsta2) printf("%s \n %s", nume1, nume2); 
    }
}