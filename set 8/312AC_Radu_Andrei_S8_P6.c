#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

struct Student {
    char nume[50];
    int nota1;
    int nota2;
    int nota3;
};

void sortare(struct Student studenti[], int lungime) {
    for (int i = 0; i < lungime; ++i) {
        struct Student cheie = studenti[i];
        int j = i - 1;

        while (j >= 0 && studenti[j].nota2 < cheie.nota2) {
            studenti[j + 1] = studenti[j];
            j--;
        }
        studenti[j + 1] = cheie;
    }
}

void main () {
    struct Student studenti[20];

    int n;

    printf("Introdu numarul de studenti: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Introdu numele studentului %d:", i);
        scanf(" %[^\n]s", studenti[i].nume);

        printf("Introdu nota la programare: ");
        scanf("%d", &studenti[i].nota1);

        printf("Introdu nota la analiza: ");
        scanf("%d", &studenti[i].nota2);

        printf("Introdu nota la algebra: ");
        scanf("%d", &studenti[i].nota3);
    }

    char studentCautat[20];
    printf("Introdu numele studentului cautat: ");
    scanf(" %[^\n]s", studentCautat);

    bool gasit = false;

    for (int i = 0; i < n; ++i) {
        if (strcmp(studenti[i].nume, studentCautat) == 0) {
            gasit = true;
            printf("Nota programare: %d\n", studenti[i].nota1);
            printf("Nota analiza: %d\n", studenti[i].nota2);
            printf("Nota algebra: %d\n", studenti[i].nota3);
        }
    }

    if (!gasit) printf("Nu a fost gasit studentul cautat.");

    char materie[20];
    printf("Pentru ce materie vrei sa aflii cel mai bun student? ");
    scanf(" %[^\n]s", materie);

    int notaMax = INT_MIN;

    if (strcmp(materie, "programare") == 0) {
        for (int  i = 0; i < n; ++i) {
            if (studenti[i].nota1 > notaMax) {
                notaMax = studenti[i].nota1;
            }
        }
        printf("Cea mai mare nota: %d\n", notaMax);
        for (int i = 0; i < n; ++i) {
            if (studenti[i].nota1 == notaMax) {
                printf("%s\n", studenti[i].nume);
            }
        }
    }
    else if (strcmp(materie, "algebra") == 0) {
        for (int  i = 0; i < n; ++i) {
            if (studenti[i].nota2 > notaMax) {
                notaMax = studenti[i].nota2;
            }
        }
        printf("Cea mai mare nota: %d\n", notaMax);
        for (int i = 0; i < n; ++i) {
            if (studenti[i].nota2 == notaMax) {
                printf("%s\n", studenti[i].nume);
            }
        }
    }
    else if (strcmp(materie, "analiza") == 0) {
        for (int  i = 0; i < n; ++i) {
            if (studenti[i].nota3 > notaMax) {
                notaMax = studenti[i].nota3;
            }
        }
        printf("Cea mai mare nota: %d\n", notaMax);
        for (int i = 0; i < n; ++i) {
            if (studenti[i].nota3 == notaMax) {
                printf("%s\n", studenti[i].nume);
            }
        }
    }
    else {
        printf("Nu exista acea materie.\n");
    }

    float medieGenMax = 0.0f;

    for (int  i = 0; i < n; ++i) {
        float medieGen = (float)((studenti[i].nota1 + studenti[i].nota2 + studenti[i].nota3) / 3);
        if (medieGen > medieGenMax) medieGenMax = medieGen;
    }
    printf("Premiantii grupei: ");
    for (int i = 0; i < n; ++i) {
        float medieGen = (float)((studenti[i].nota1 + studenti[i].nota2 + studenti[i].nota3) / 3);
        if (medieGen == medieGenMax) printf("%s\n", studenti[i].nume);
    }

    sortare(studenti, n);
    for (int i = 0; i < n; ++i) {
        printf("Nume: %s. Nota: %d\n", studenti[i].nume, studenti[i].nota2);
    }

    int nepromovati = 0;
    for (int i = 0; i < n; ++i) {
        if (studenti[i].nota1 < 5 || studenti[i].nota2 < 5 || studenti[i].nota3 < 5) {
            nepromovati++;
        }
    }
    if (nepromovati == 0) printf("Toti studentii au promovat.");
    else printf("In total nu au promovat %d studenti.", nepromovati);
}