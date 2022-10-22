#include <stdio.h>
#include <stdlib.h>
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

guest *creat_reservation(char *reverse_data){
    guest *g = (guest *) malloc(sizeof(guest));
    
    if(g == NULL){
        printf("insufficient memory");
        exit(1);
    }

    printf("Enter the name: ");
    scanf(" %[^\n]",g->name);

    printf("Enter the length of stay: ");
    scanf("%d",&g->length_of_stay);

    printf("Enter the CPF: ");
    scanf("%d", &g->documentation);

    printf("Enter the number: ");
    scanf("%d", &g->bedRoom.number);

    printf("Enter the avaibility: ");
    scanf("%[^\n]", g->bedRoom.availability);

    printf("Enter the price: ");
    scanf("%f", &g->bedRoom.price);

    printf("Enter the localization: ");
    scanf("%[^\n]", g->bedRoom.localization);

    FILE *arq;
    arq = fopen(reverse_data, "a");

    if(g == NULL){
        printf("Error opening file");
        exit(0);
    }

    fprintf(arq, "Number: %d\nAvailability: %s\nPrice: %f\nLocalization: %s",g->bedRoom.number, g->bedRoom.availability, g->bedRoom.price, g->bedRoom.localization);
    fprintf(arq, "Name: %s\nLength of stay: %d\nDcumentation: %d\n", g->name, g->length_of_stay, g->documentation);
    
    return(g);
} 