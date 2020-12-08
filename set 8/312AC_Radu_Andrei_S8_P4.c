#include <stdio.h>

struct Timp {
    int ora;
    int minut;
    int secunda;
};

struct Data {
    int zi;
    int luna;
    int an;
    struct Timp moment;
};



void main () {
    struct Data data;

    printf("Introdu ziua, luna si anul: ");
    scanf("%d%d%d", &data.zi, &data.luna, &data.an);

    printf("Introdu momentul(ora, minut, secunda): ");
    scanf("%d%d%d", &data.moment.ora, &data.moment.minut, &data.moment.secunda);

    printf("Datele introduse sunt: \n");
    printf("Data: %d/%d/%d", data.zi, data.luna, data.an);
    printf("Moment: ");
    data.moment.ora < 10 ? printf("0%d:", data.moment.ora) : printf("%d:", data.moment.ora);
    data.moment.minut < 10 ? printf("0%d:", data.moment.minut) : printf("%d:", data.moment.minut);
    data.moment.secunda < 10 ? printf("0%d", data.moment.secunda) : printf("%d", data.moment.secunda);
}