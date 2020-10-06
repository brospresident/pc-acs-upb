#include <stdio.h>

void main () {
    char c;
    printf("Introduceti un caracter: ");
    scanf("%c", &c);

    // subpunct a)
    printf("Codul ASCII al caracterului %c este %d.\n", c, c);

    // subpunct b)
    printf("Urmatorul caracter in ordine lexicografica este %c.\n", c + 1);

    // subpunct c)
    char s = 'a';
    printf("%c%c%c%c%c\n", s, s + 1, s + 2, s + 3, s + 4);
    
    // subpunct d)
    char ex = 'A';
    printf("A 16-a litera mare din alfabet este %c", ex + 15);
}