#include <stdio.h>
#include <stdlib.h>

void citesteVector(int* vector, int lungimeVector, char* numeVector) {
    for (int i = 0; i < lungimeVector; ++i) {
        printf("%s[%d] = ", numeVector, i);
        scanf("%d", &vector[i]);
    }
}

void unesteVectori(int* v1, int lungimeV1, int* v2, int lungimeV2) {
    int contor = 0;
    if (lungimeV1 < lungimeV2) {
        v1 = (int*)realloc(v1, lungimeV1 + lungimeV2);
        for (int i = lungimeV1; i < lungimeV1 + lungimeV2; ++i) {
            v1[i] = v2[contor];
            contor++;
        }
    }
    else {
        v2 = (int*)realloc(v2, lungimeV1 + lungimeV2);
        for (int i = lungimeV2; i < lungimeV1 + lungimeV2; ++i) {
            v2[i] = v1[contor];
            contor++;
        }
    }
}


void main () {
    int n1, n2;

    printf("Introdu lungimile celor 2 vectori: ");
    scanf("%d%d", &n1, &n2);

    int* primulVector = (int*)calloc(n1, sizeof(int));
    int* alDoileaVector = (int*)calloc(n2, sizeof(int));

    if (primulVector == NULL) {
        printf("Nu s-a alocat la primul");
        return;
    }

    if (alDoileaVector == NULL) {
        printf("Nu s-a alocat la al doilea.");
        return;
    }

    citesteVector(primulVector, n1, "primulVector");
    citesteVector(alDoileaVector, n2, "alDoileaVector");

    printf("Vectorii cititi sunt: \n");
    for (int i = 0; i < n1; ++i) {
        printf("%d ", primulVector[i]);
    }
    printf("\n");
    for (int i = 0; i < n2; ++i) {
        printf("%d ", alDoileaVector[i]);
    }
    printf("\n");

    unesteVectori(primulVector, n1, alDoileaVector, n2);


    printf("Vectorul format prin unirea celor 2 este:\n ");
    if (n1 < n2) {
        for (int i = 0; i < n1 + n2; ++i) {
            printf("%d ", primulVector[i]);
        }
    }
    else{
        for (int i = 0; i < n1 + n2; ++i) {
            printf("%d ", alDoileaVector[i]);
        }
    }
}