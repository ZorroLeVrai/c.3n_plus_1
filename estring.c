#include <string.h>
#include "estring.h"

const uint STRING_INIT_CAPACITY = 16;

String initString()
{
  String result = {
      .content = calloc(STRING_INIT_CAPACITY, sizeof(char)),
      .length = 0,
      .capacity = STRING_INIT_CAPACITY};
  return result;
}

void concat(String *dest, char *src, size_t length)
{
  size_t neededSize = dest->length + length + 1;
  if (neededSize > dest->capacity)
  {
    size_t newCapacity = 2 * neededSize;
    dest->content = (char *)realloc(dest->content, newCapacity * sizeof(char));
    dest->capacity = newCapacity;
  }

  strncpy(dest->content + dest->length, src, length + 1);
  dest->length += length;
}

void freeString(String dest)
{
  free(dest.content);
  dest.content = NULL;
  dest.capacity = 0;
  dest.length = 0;
}