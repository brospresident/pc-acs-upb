#include <stdio.h>
#include <string.h>
#include <ctype.h>

void interschimbaLitere(char* sir) {
    if (strlen(sir) % 2) return; // daca nu are numar par de litere nu face interschimbarile(ar ramane o litera ce nu are cu ce sa se schimbe)

    for (int i = 0; i < strlen(sir); i += 2) {
        char temp = sir[i];
        sir[i] = sir[i + 1];
        sir[i + 1] = temp; 
    }
}

void main () {
    char cuvant[25];
    printf("Introdu un cuvant: ");
    scanf("%[^\n]s", cuvant);

    printf("%s\n", cuvant);
    interschimbaLitere(cuvant);

    printf("%s\n", cuvant);
}