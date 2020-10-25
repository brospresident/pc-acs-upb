#include <stdio.h>

void main () {
    int A[5][5], c1, c2, m, n;

    printf("Introdu dimensiunile lui A(m,n): ");
    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Introdu coloanele pe care vrei sa le interschimbi: ");
    scanf("%d%d", &c1, &c2);

    printf("Inainte de interschimbarea coloanelor: %d si %d\n", c1, c2);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; ++i) {
        int temp = A[i][c1 - 1];
        A[i][c1 - 1] = A[i][c2 - 1];
        A[i][c2 - 1] = temp;
    }
    
    /* Am parcurs doar liniile din matrice deoarece indicii coloanelor ii stiam deja(c1, c2) si am folosit c1 - 1, respectiv c2 - 1 deoarece
       in input vom folosi, de exemplu c1 = 3 si c2 = 1 astfel aratam ca vrem sa interschimbam elementele de pe coloana 3 cu cele de pe coloana 1,
       care au de fapt indicii 2 si 0 in matrice atunci cand parcurgem cu for.
     */

    printf("Dupa interschimbarea coloanelor: %d si %d\n", c1, c2);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}