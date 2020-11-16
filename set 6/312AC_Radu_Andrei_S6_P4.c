#include <stdio.h>
#include <stdbool.h>

bool construiesteVectorComune(int* vA, int lA, int* vB, int lB, int* construit, int* lConstruit) {
    int contor = 0;
    for (int i = 0; i < lA; ++i) {
        for (int j = 0; j < lB; ++j) {
            if (vA[i] == vB[j]) {
                construit[contor++] = vA[i];
            }
        }
    }
    if (contor == 0) return false;
    else {
        *lConstruit = contor;
        return true;
    }       
}
    

void main () {
    int vectorA[] = {2, 6, 8, 11, 33, 28, 55, 79, 81};
    int vectorB[] = {6, 8, 12, 34, 28, 56, 81, 79};

    int lungimeA = sizeof(vectorA) / sizeof(vectorA[0]);
    int lungimeB = sizeof(vectorB) / sizeof(vectorB[0]);

    int vectorConstruit[9], elementeConstruit = 0;

    bool aFostConstruit = construiesteVectorComune(vectorA, lungimeA, vectorB, lungimeB, vectorConstruit, &elementeConstruit);

    if (!aFostConstruit) printf("Cei 2 vectori nu au elemente comune.");
    else { 
        for (int i = 0; i < elementeConstruit; ++i) {
            printf("%d ", vectorConstruit[i]);
        }
    }
    


}