#ifndef ESTRING_H
#define ESTRING_H

#include <stdlib.h>
#include "basicTypes.h"

typedef struct
{
  char *content;
  size_t length;
  uint capacity;
} String;

String initString();

void concat(String *dest, char *src, size_t length);
void freeString(String dest);

#endif