#include <stdio.h>
#include <string.h>
#include "hospedagem.h"

struct Bedroom{
    int number;
    char availability[80];
    float price;
    char localization[121];
};

struct Guest{
    char name[80];
    int length_of_stay;
    int documentation;
    bedroom bedRoom;
};

/*guest *creat_reservation(char *reverse_data){
    guest *g;
    g = (guest *) malloc(sizeof(guest));
    
    if(g == NULL){
        printf("insufficient memory");
        return 1;
    }

    printf("Enter the name: ");
    scanf(" %[^\n]",g->name);

    printf("Enter the length of stay: ");
    scanf("%d",&g->length_of_stay);

    printf("Enter the CPF: ");
    scanf("%d", &g->documentation);

    printf("Enter the number: ");
    scanf("%d", &g->bedRoom->number);

    printf("Enter the avaibility: ");
    scanf("%[^\n]", g->bedRoom->availability);

    printf("Enter the price: ");
    scanf("%f", &g->bedRoom->price);

    printf("Enter the localization: ");
    scanf("%[^\n]", g->bedRoom->localization);



    return(g);
} */