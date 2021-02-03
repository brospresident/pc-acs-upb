#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct client {
    char nume[128];
    float debit;
    float credit;
    int codClient;
} Client;

void afiseaza(Client* list, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%s\n", list[i].nume);
    }
}

int codClientMaxim(Client* lista, int intrari) {
    int max = INT_MIN;

    for (int i = 0; i < intrari; ++i) {
        if (lista[i].codClient > max) max = lista[i].codClient;
    }

    return max;
}

void sorteazaClientiAlfabetic(Client* clienti, int nrClienti) {
    for (int i = 0; i < nrClienti; ++i) {
        Client cheie;
        memcpy(&cheie, &clienti[i], sizeof(Client));

        int j = i - 1;

        while (j >= 0 && strcmp(clienti[j].nume, cheie.nume) > 0) {
            memcpy(&clienti[j + 1], &clienti[j], sizeof(Client));
            j--;
        }
        memcpy(&clienti[j + 1], &cheie, sizeof(Client));
    }
}


void unesteClientii(Client* lista1, int clienti1, Client* lista2, int clienti2, Client* primaBanca, int* clientiPrima, Client* aDouaBanca, int* clientiADoua, Client* clientiComuni, int* nrComuni) {
    sorteazaClientiAlfabetic(lista1, clienti1);
    sorteazaClientiAlfabetic(lista2, clienti2);

    afiseaza(lista1, clienti1);
    printf("\n\n");
    afiseaza(lista2, clienti2);

    int comuni = 0, prima = 0, aDoua = 0;

    for (int i = 0; i < clienti1; ++i) {
        for (int j = 0; j < clienti2; ++j) {
            if (strcmp(lista1[i].nume, lista2[j].nume) == 0) {
                memcpy(&clientiComuni[comuni], &lista1[i], sizeof(Client));
                clientiComuni[comuni].codClient = lista2[j].codClient;
                comuni++;
            }
        }
    }

    for (int i = 0; i < clienti1; ++i) {
        for (int j = 0; j < comuni; ++j) {
            if (strcmp(lista1[i].nume, clientiComuni[j].nume) == 0) continue;
            memcpy(&primaBanca[prima], &lista1[i], sizeof(Client));
            prima++;
        }
    }

    for (int i = 0; i < clienti2; ++i) {
        for (int j = 0; j < comuni; ++j) {
            if (strcmp(lista1[i].nume, clientiComuni[j].nume) == 0) continue;
            memcpy(&aDouaBanca[aDoua], &lista2[i], sizeof(Client));
            aDoua++;
        }
    }

    *clientiPrima = prima;
    *clientiADoua = aDoua;
    *nrComuni = comuni;
}


void citesteFisier(FILE* fis, Client* lista, int* persoane) {
    fseek(fis, 0, SEEK_SET);

    char linie[128];

    int contor = 0;

    while (fgets(linie, 128, fis)) {
        strcpy(lista[contor].nume, linie);
        lista[contor].nume[strlen(lista[contor].nume) - 1] = 0;

        fgets(linie, 128, fis);
        linie[strlen(linie) - 1] = 0;
        lista[contor].debit = atof(linie);

        fgets(linie, 128, fis);
        linie[strlen(linie) - 1] = 0;
        lista[contor].credit = atof(linie);

        fgets(linie, 128, fis);
        lista[contor].codClient = atoi(linie);

        contor++;
    }

    *persoane = contor;
}

void main () {
    FILE* fisier1 = fopen("banca1.txt", "r");
    FILE* fisier2 = fopen("banca2.txt", "r");

    if (!fisier1 || !fisier2) {
        printf("Unul din fisiere nu a putut fi deschis.");
        exit(1);
    }

    Client* banca1 = (Client*)malloc(1000);
    Client* banca2 = (Client*)malloc(1000);

    int clientiBanca1 = 0, clientiBanca2 = 0;

    citesteFisier(fisier1, banca1, &clientiBanca1);
    citesteFisier(fisier2, banca2, &clientiBanca2);

    banca1 = realloc(banca1, clientiBanca1 + 1);
    banca2 = realloc(banca2, clientiBanca2 + 1);

    int cmax = codClientMaxim(banca1, clientiBanca1);

    Client* primaBanca = (Client*)malloc(1000);
    Client* aDouaBanca = (Client*)malloc(1000);
    Client* comuni = (Client*)malloc(1000);

    int prima = 0, aDoua = 0, clientiComuni = 0;

    unesteClientii(banca1, clientiBanca1, banca2, clientiBanca2, primaBanca, &prima, aDouaBanca, &aDoua, comuni, &clientiComuni);

    FILE* fisierUnit = fopen("Unit.dat", "wb");

    if (!fisierUnit) {
        printf("Nu am putut deschide fisierul final.");
        exit(1);
    }

    if (aDoua > 0) {
        fwrite(aDouaBanca, sizeof(Client) * aDoua, 1, fisierUnit);
    }

    if (clientiComuni > 0) {
        fwrite(comuni, sizeof(Client) * clientiComuni, 1, fisierUnit);
    }

    if (prima > 0) {
        for (int i = 0; i < prima; ++i) {
            primaBanca[i].codClient = cmax + i + 1;
        }

        fwrite(primaBanca, sizeof(Client) * prima, 1, fisierUnit);
    }

    printf("Numarul total de clienti este %d.", prima + aDoua + clientiComuni);

    fclose(fisier1);
    fclose(fisier2); 
    fclose(fisierUnit);

    free(banca1);
    free(banca2);
    free(primaBanca);
    free(aDouaBanca);
    free(comuni);
}