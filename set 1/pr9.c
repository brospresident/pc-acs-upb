#include <stdio.h>

void main () {
    int a, b;
    printf("Introduceti valoarea lui a: ");
    scanf("%d", &a);
    printf("Introduceti valoarea lui b: ");
    scanf("%d", &b);

    // schimbam variabilele
    int temp = a;
    a = b;
    b = temp;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("media = %.2f", (float)(a + b) / 2);
}