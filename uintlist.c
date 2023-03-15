#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uintlist.h"

const uint LIST_INIT_CAPACITY = 8;
const uint NUMBER_MAX_LENGTH = 11;

UintList initIntList()
{
  UintList result = {
      .content = calloc(LIST_INIT_CAPACITY, sizeof(uint)),
      .length = 0,
      .capacity = LIST_INIT_CAPACITY};
  return result;
}

void append(UintList *dest, uint value)
{
  size_t neededSize = dest->length + 1;
  if (neededSize > dest->capacity)
  {
    size_t newCapacity = 2 * neededSize;
    dest->content = (uint *)realloc(dest->content, newCapacity * sizeof(uint));
    dest->capacity = newCapacity;
  }
  dest->content[dest->length] = value;
  ++(dest->length);
}

String seriesToString(UintList numbers)
{
  String result = initString();
  concat(&result, "[", 1);

  for (int i = 0; i < numbers.length; ++i)
  {
    if (i > 0)
      concat(&result, ", ", 2);

    char intInStr[NUMBER_MAX_LENGTH + 1];
    snprintf(intInStr, NUMBER_MAX_LENGTH, "%u", numbers.content[i]);
    concat(&result, intInStr, strlen(intInStr));
  }

  concat(&result, "]", 1);
  return result;
}

void freeUintList(UintList list)
{
  free(list.content);
  list.content = NULL;
  list.capacity = 0;
  list.length = 0;
}