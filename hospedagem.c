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
    
    return 0;
} 