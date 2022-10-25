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
    struct Guest *next;
};

void *creat_reservation(){
    guest * start_guest;
    guest * next_guest;

    int option;

    start_guest = (guest*)malloc(sizeof(guest));
    if(start_guest == NULL){
        exit(1);
    }

    next_guest = start_guest;

    while(1){
        printf("Inform the name: ");
        scanf(" %[^\n]", next_guest->name);
        printf("Inform the length of stay: ");
        scanf(" %[^\n]", next_guest->length_of_stay);
        printf("Inform the documentation: ");
        scanf("%d", &next_guest->documentation);
        printf("Inform the number: ");
        scanf("%d", &next_guest->bedRoom.number);    
        printf("Inform the availability:  ");
        scanf(" %[^\n]", &next_guest->bedRoom.availability);
        printf("Inform the price: ");
        scanf("%f", &next_guest->bedRoom.price);
        printf("Inform the localization: ");
        scanf(" %[^\n]", next_guest->bedRoom.localization);

        printf("Do you wish to continue?");
        printf(" <1> YES  <2> NO \n");
        scanf("%d", &option);

        if(option == 1){
            next_guest-> next=(guest*)malloc(sizeof(guest));
            next_guest= next_guest->next;
        }
        else
        break;
    }

    return 0;
} 