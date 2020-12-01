#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
    Sirul suf contine sufixul, sirul str trebuie sa se termine cu sirul suf astfel parcurgem sirul suf si
    verificam de la coada la cap daca acesta e sufix in sirul str. Daca gasim un caracter diferit in parcurgere
    returnam false.
*/

bool eSufix(char str[], char suf[]) {
    if (strlen(str) < strlen(suf)) return false;
    for (int i = 0; i < strlen(suf); ++i) {
        if (str[strlen(str) - i - 1] != suf[strlen(suf) - i - 1]) return false;
    }
    return true;
}

void main () {
    char sir1[256], sir2[256];
    
    printf("Introdu sirul in care vrei sa cauti: ");
    scanf("%[^\n]s", sir1);

    printf("Introdu sirul pe care vrei sa il cauti: ");
    scanf(" %[^\n]s", sir2);

    bool rezultat = eSufix(sir1, sir2);

    if (!rezultat) printf("Negativ");
    else printf("Afirmativ");
}