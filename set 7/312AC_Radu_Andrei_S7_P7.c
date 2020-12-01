#include <stdio.h>
#include <string.h>

void main () {
    char sir[256];

    printf("Introdu textul pe care vrei sa il codifici: ");
    scanf("%[^\n]s", sir);

    for (int i = 0; i < strlen(sir); ++i) {
        if (sir[i] != ' ') {
            if (sir[i] == 'z') sir[i] = 'a';
            else {
                sir[i]++;
            }
        }
    }

    printf("%s", sir);
}