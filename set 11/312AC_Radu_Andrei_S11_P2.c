#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adaugaInFisier(FILE* fisier) {
    char linie[1000];
    printf("Scrie o noua linie pentru a o adauga in fisier: \n");
    scanf(" %[^\n]s", linie);
    fprintf(fisier, "%s", linie);
    fprintf(fisier, "\n");
}

void inlocuieste(char* sir, char* vechi, char* nou) {
    char* pozitie, temp[1024];

    int index, lungimeVechi = strlen(vechi);

    // trect prin toata propozitia pana nu mai gasesc cuvantul cautat
    while ((pozitie = strstr(sir, vechi)) != NULL) {
        strcpy(temp, sir); 
        index = pozitie - sir; 
        sir[index] = 0; 
        strcat(sir, nou); 
        strcat(sir, temp + index + lungimeVechi); 
    }
}


void main () {
    FILE* text = fopen("P2.txt", "w+");

    if (text == NULL) {
        printf("Nu l-am putut deschide.");
        exit(1);
    }

    adaugaInFisier(text);

    char cuvantCautat[100], cuvantNou[100];
    printf("Care este cuvantul pe care vrei sa il cauti? ");
    scanf(" %s", cuvantCautat);
    printf("Care este cuvantul cu care vrei sa il inlocuiesti? ");
    scanf(" %s", cuvantNou);

    FILE* temp = fopen("temp.txt", "w");

    if (temp == NULL) {
        printf("Nu am putut deschide fisierul temporar.");
        exit(1);
    }

    char cuvant[100];
    fseek(text, 0, SEEK_SET);
    while ((fgets(cuvant, 1024, text)) != NULL) {
        inlocuieste(cuvant, cuvantCautat, cuvantNou);
        fputs(cuvant, temp);
    }

    fclose(text);
    fclose(temp);
    remove("P2.txt");
    rename("temp.txt", "P2.txt");

    fclose(temp);

}