#include <stdio.h>

void main () {
    int a, b, c;
    printf("Introduceti numarul a: ");
    scanf("%d", &a);
    printf("Introduceti numarul b: ");
    scanf("%d", &b);
    printf("Introduceti numarul c: ");
    scanf("%d", &c);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d + %d = %d\n", a, c, a + c);
    printf("%d + %d = %d\n", b, c, b + c);
}