#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool eAnagrama(char* cuvant1, char* cuvant2) {
    if (strlen(cuvant1) != strlen(cuvant2)) return false;

    char frecventaCuvant[26], frecventaCuvant2[26];

    int contor = 0;


    while (cuvant1[contor] != '\0') {
        frecventaCuvant[cuvant1[contor]]++;
        contor++;
    }

    contor = 0;

    while (cuvant2[contor] != '\0') {
        frecventaCuvant2[cuvant2[contor]]++;
        contor++;
    }
    
    for (int i = 0; i < 26; ++i) {
        if (frecventaCuvant[i] != frecventaCuvant2[i]) return false;
    }
    

    return true;
}


void main () {
    int n;
    char primul[256];

    printf("Introdu un numar: ");
    scanf("%d", &n);

    printf("Introdu %d cuvinte: ", n);

    scanf(" %[^\n]s", primul);
    n--;

    int anagrame = 0;

    while (n--) {
		char cuvant[256];
        scanf(" %[^\n]s", cuvant); 
        if (eAnagrama(primul, cuvant) == true) anagrame++;
    }

    printf("S-au gasit %d anagrame.", anagrame);
}