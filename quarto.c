#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"

struct quarto{
  int disponibilidade;
  char localizacao;
  float preco;
  int nuemero_quarto;
};

struct list{
  Quarto *dados;
  List *next;
};