#include <stdio.h>

int palindrom(int n) {
    int save = n, oglindit = 0; // am salvat numarul pentru verificarea din final
    while (n) {
        oglindit = oglindit * 10 + n % 10;
        n /= 10;
    }
    if (save == oglindit) return 1;
    else return 0;
}

void main () {
    printf("%d\n", palindrom(15651));
    printf("%d\n", palindrom(23532));
    printf("%d\n", palindrom(15652));
    printf("%d\n", palindrom(23534));
}