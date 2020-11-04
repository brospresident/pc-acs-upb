#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int delta(int a, int b, int c) {
    return pow(b, 2) - 4 * a * c;
}

bool rezultat(int a, int b, int c, float *x, float *y) {
    int d = delta(a, b, c);
    if (d < 0) return false;
    *x = (-b + sqrt(d)) / (2 * a);
    *y = (-b - sqrt(d)) / (2 * a);
    return true;
}

void main () {
    int a, b, c;
    float x1, x2;

    printf("Introdu coeficientii ecuatiei: ");
    scanf("%d%d%d", &a, &b, &c);

    bool rezolvat = rezultat(a, b, c, &x1, &x2);
    if (!rezolvat) printf("Delta < 0.");
    else printf("Solutiile ecuatiei sunt x1 = %.2f, x2 = %.2f.", x1, x2);
}