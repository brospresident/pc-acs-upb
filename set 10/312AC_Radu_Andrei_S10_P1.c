#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inlocuieste(char* sir, char* vechi, char* nou) {
    char* pozitie, temp[1024];

    int index, lungimeVechi = strlen(vechi);

    // trect prin toata propozitia pana nu mai gasesc cuvantul cautat
    while ((pozitie = strstr(sir, vechi)) != NULL) {
        strcpy(temp, sir); // salvez in temp propozitia curenta
        index = pozitie - sir; // pozitia unde a fost gasit cuvantul
        sir[index] = 0; // pun terminatorul de sir la pozitia unde a fost gasit vechiul cuvant
        strcat(sir, nou); // concatenez sirul cu caracterul de sfarsit la pozitia vechiului cuvant cu noul cuvant
        strcat(sir, temp + index + lungimeVechi); // concatenez sirul care se termina la noul cuvant cu restul sirului salvat deja in temp
    }
}


void main () {
    FILE* output = fopen("outputProblema1.txt", "w");
    if (output == NULL) {
        printf("Fisierul nu a putut sa fie deschis.");
        return;
    }

    char text[256];
    scanf("%[^\n]s", text);

    // SUBPUNCT A
    // asezarea textului cu totul in fisier
    fputs(text, output);
    fputs("\n", output);

    // asezarea textului caracter cu caracter
    for (int i = 0; i < strlen(text); ++i) {
        fputc(text[i], output);
    }
    fputs("\n", output);
    char saveText[256];
    strcpy(saveText, text); // am salvat textul deoarece dupa ce foloseam strtok se pierdea input-ul initial

    // asezarea textului cuvant cu cuvant
    char* cuv = strtok(text, " ");
    while (cuv) {
        fputs(cuv, output);
        cuv = strtok(NULL, " ");
    }
    fputs("\n", output);
    
    // asezarea textului cuvant cu cuvant, un cuvant pe linie
    cuv = strtok(saveText, " ");
    while (cuv) {
        fprintf(output, "%s\n", cuv);
        cuv = strtok(NULL, " ");
    }

    // SUBPUNCT B
    // citit si afisat caracter cu caracter
    fclose(output); // am inchis fisierul apoi l-am redeschis in read & write mode.
    output = fopen("outputProblema1.txt", "r+");
    int caracter = fgetc(output);
    while (caracter != EOF) {
        printf("%c", caracter);
        caracter = fgetc(output);
    }
    printf("\n");

    // citit si afisat cuvant cu cuvant
    fseek(output, 0, SEEK_SET); // am resetat pozitia unde se afla in parcurgerea sirului
    char cuvant[1024];
    while (fscanf(output, "%s", cuvant) != EOF) {
        printf("%s ", cuvant);
    }
    printf("\n\n");

    // citit si afisat tot fisierul
    fseek(output, 0, SEEK_SET);
    char intreg[1024];
    fscanf(output, "%[^\0]s", intreg);
    printf("%s", intreg);

    // SUBPUNCT C
    char cautat[35], inlocuit[35];
    printf("\nIntrodu cuvantul pe care vrei sa il cauti: ");
    scanf(" %s", cautat);
    printf("Introdu cu ce vrei sa il inlocuiesti: ");
    scanf(" %s", inlocuit);

    // voi folosi textul pe care il am deja citit de la subpunctul b (intreg)
    fseek(output, 0, SEEK_SET);
    FILE* temporar = fopen("temporarProblema1.txt", "w");
    if (temporar == NULL) {
        printf("Nu s-a putut deschide fisierul temporar.");
        return;
    }

    char cuv_fis[1024];
    while ((fgets(cuv_fis, 1024, output)) != NULL) {
        inlocuieste(cuv_fis, cautat, inlocuit);
        fputs(cuv_fis, temporar);
    }

    fclose(temporar);
    fclose(output);
    remove("outputProblema1.txt");
    rename("temporarProblema1.txt", "outputProblema1.txt");

    // FINAL
    fclose(temporar);
    fclose(output);
}