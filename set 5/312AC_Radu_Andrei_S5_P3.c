#include <stdio.h>

char testareCaracter(int a, int b, int c) {
    if ((a < b) && (a < c) && (b < c)) return 'C';
    else if ((a > b) && (b > c) && (a > c)) return 'D';
    else if ((a == b) && (b == c) && (a == c)) return 'I';
    else return 'N';
}


void main () {
    int teste, a, b, c;

    printf("Introdu numarul de teste: ");
    scanf("%d", &teste);

    while (teste--) {
        printf("a = ");
        scanf("%d", &a);
        printf("b = ");
        scanf("%d", &b);
        printf("c = ");
        scanf("%d", &c);
        printf("%c\n", testareCaracter(a, b, c));
    }    
}