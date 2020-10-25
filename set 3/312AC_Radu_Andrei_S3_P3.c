#include <stdio.h>

void main () {
    int n;
    
    printf("Introdu cate numere vrei sa citesti: ");
    scanf("%d", &n);

    int v[101] = {}; // am stabilit un interval de valori 0 <= v[i] <= 101 si vom rezolva folosind un vector de frecventa
    
    for (int i = 0; i < n; ++i) {
        int q;
        printf("Introdu un numar: ");
        scanf("%d", &q);
        v[q]++;
    } 

    int maxim = 0;

    for (int i = 0; i < 101; ++i) {
        if (v[i] > maxim) maxim = v[i];
    }

    for (int i = 0; i < 101; ++i) {
        if (v[i] == maxim) printf("%d ", i);
    }

    // Alta varianta(fara vector de frecventa)
    printf("\nAlta varianta\n");
    int vector[10];
    for (int i = 0; i < n; ++i) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    int elementCurent = vector[0], maximCurent = 0, element = 0;
    maxim = 0;

    for (int i = 0; i < n; ++i) {
        if (elementCurent == vector[i]) maximCurent++;
        else {
            if (maximCurent > maxim) {
                element = elementCurent;
                maxim = maximCurent;
                elementCurent = vector[i];
                maximCurent = 0;
            }
        }
    }
    printf("Elementul care apare de cele mai multe ori in vector este %d, cu %d aparitii.", element, maxim);

    /*
        Am sortat vectorul folosind bubble sort, astfel toate elementele care sunt identice vor fi unul langa altul si le voi putea numara foarte usor,
        elementCurent are rolul sa stocheze elementul pe care il verific in momentul de fata, maximCurent are rolul sa numere de cate ori apare elementCurent in vector,
        in cazul in care elementul pe care il verific se schimba, voi verifica daca numarul sau de aparitii este mai mare decat ultimul numar verificat,
        in acel caz voi schimba element cu elementCurent si maxim va deveni maximCurent.
    */

}