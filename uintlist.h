#ifndef UINT_LIST_H
#define UINT_LIST_H

#include "basicTypes.h"
#include "estring.h"

typedef struct
{
  uint *content;
  uint length;
  uint capacity;
} UintList;

UintList initIntList();
void append(UintList *dest, uint value);
String seriesToString(UintList numbers);
void freeUintList(UintList list);

#endif