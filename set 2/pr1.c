#include <stdio.h>
#include <ctype.h>

void main () {
    char caracter;
    
    printf("Introduceti un caracter: ");
    scanf("%c", &caracter);
    
    if (isdigit(caracter) != 0) printf("Caracterul %c este o cifra.\n", caracter);
    else if (isalpha(caracter) != 0 && islower(caracter) != 0) printf("Caracterul %c este o litera mica.\n", caracter);
    else if (isalpha(caracter) != 0 && isupper(caracter) != 0) printf("Caracterul %c este o litera mare.\n", caracter);
    else printf("Caracterul %c este alt caracter.", caracter);

  /*  printf("Verificare functie isdigit('2'): %d\n", isdigit('2'));
    printf("Verificare functie isdigit('a'): %d\n", isdigit('a'));

    printf("Verificare functie isalpha('a'): %d\n", isalpha('a'));
    printf("Verificare functie isalpha('/'): %d\n", isalpha('/'));

    printf("Verificare functie islower('a'): %d\n", islower('a'));
    printf("Verificare functie islower('/'): %d\n", islower('/'));

    printf("Verificare functie isupper('A'): %d\n", isupper('A'));
    printf("Verificare functie isupper('a'): %d\n", isupper('a'));*/

    // >= <= == > < != || 

}