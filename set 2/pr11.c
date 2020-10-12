#include <stdio.h>

void main () {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            printf("%7dx%d=%d", i, j, i*j);
        }
        printf("\n");
    }
}