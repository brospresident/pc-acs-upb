#include <stdio.h>

void main () {
    printf("*\n");
    printf("**\n");
    printf("***\n");
    char litera;
    printf("Introdu o litera: ");
    scanf("%c", &litera);
    printf("%c\n", litera);
    printf("%c%c\n", litera, litera);
    printf("%c%c%c", litera, litera, litera);
}