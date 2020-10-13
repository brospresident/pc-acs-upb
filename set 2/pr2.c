#include <stdio.h>

void main () {
    int a, b, c; // laturile triunghiului
    
    printf("Introduceti prima latura: ");
    scanf("%d", &a);
    printf("Introduceti a doua latura: ");
    scanf("%d", &b);
    printf("Introduceti a treia latura: ");
    scanf("%d", &c);
    
    if ((a > 0 && b > 0 && c > 0) && (a + b > c && a + c > b && b + c > a)) {
        printf("Cele trei laturi pot forma un triunghi.\n");
        if (a == b && a == c && b == c) printf("Triunghiul este echilateral.\n");
        else if (a == b || a == c || b == c) printf("Triunghiul este isoscel.\n");
        else if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a)) printf("Triunghiul este dreptunghic.\n");
        else printf("Triunghiul este oarecare.\n");
    }
    else printf("Cele trei laturi nu pot forma un triunghi.");
}