#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"

struct quarto{
    int numero;
    char disponibilidade;
    float preco;
    char localizacao;
};

struct lista{
    Quartos info;
    Lista *nova_reserva;
};

int marcar_quarto(){

    
}