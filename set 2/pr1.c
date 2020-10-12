#include <stdio.h>

void main () {
    char caracter;
    printf("Introduceti un caracter: ");
    scanf("%c", &caracter);
    if ((caracter >= 32 && caracter <= 47) || (caracter >= 58 && caracter <= 64) || (caracter >= 91 && caracter <= 96) || (caracter >= 123 && caracter <= 126)) 
        printf("Caracterul %c este caracter special.", caracter);
    else if (caracter >= 48 && caracter <= 57) printf("Caracterul %c este o cifra.", caracter);
    else if (caracter >= 65 && caracter <= 90) printf("Caracterul %c este o litera mare.", caracter);
    else if (caracter >= 97 && caracter <= 122) printf("Caracterul %c este o litera mica.", caracter);
}