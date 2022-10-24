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

    start_guest = (guest*)malloc(sizeof(guest));
    if(start_guest == NULL){
        exit(1);
    }

    next_guest = start_guest;

    return 0;
} 