#include <stdio.h>

void main () {
    int n;
    
    printf("Introdu cate numere vrei sa citesti: ");
    scanf("%d", &n);

    int v[10001] = {}; // am stabilit un interval de valori 0 <= v[i] <= 10001 si vom rezolva folosind un vector de frecventa
    
    for (int i = 0; i < n; ++i) {
        int q;
        printf("Introdu un numar: ");
        scanf("%d", &q);
        v[q]++;
    } 

    int maxim = 0;

    for (int i = 0; i < 10001; ++i) {
        if (v[i] > maxim) maxim = v[i];
    }

    for (int i = 0; i < 10001; ++i) {
        if (v[i] == maxim) printf("%d ", i);
    }
}