#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char a) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
    return false;
}

void main () {
    char sir[256];
    
    printf("Introdu un sir de caractere: ");
    scanf("%[^\n]s", sir);

    int cuvinteCareIncepCuVocala = 0;

    for (int i = 0; i < strlen(sir); ++i) {
        if (isVowel(sir[i]) && (i == 0 || sir[i - 1] == ' ')) {
            int pozitie = i;
            while (sir[i] != ' ' && i < strlen(sir)) {
                i++;
            } 
            if (isVowel(sir[i - 1])) cuvinteCareIncepCuVocala++;
        }
    }

    printf("%d cuvinte din input incep cu vocala.", cuvinteCareIncepCuVocala);
}