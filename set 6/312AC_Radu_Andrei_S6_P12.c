#include <stdio.h>

void interschimbaVectori(int* vectorA, int len, int* vectorB) {
    for (int i = 0; i < len; ++i) {
        int temp = vectorA[i];
        vectorA[i] = vectorB[i];
        vectorB[i] = temp;
    }
}


void main () {
    
}