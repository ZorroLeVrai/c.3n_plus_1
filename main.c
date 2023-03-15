#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estring.h"
#include "uintlist.h"

int transform(uint previous)
{
  if (previous & 1)
  {
    // if previous is an odd number
    return 3 * previous + 1;
  }

  // divide previous by 2
  return previous >> 1;
}

UintList getSeries(uint number)
{
  UintList result = initIntList();
  append(&result, number);
  while (number != 1)
  {
    number = transform(number);
    append(&result, number);
  }

  return result;
}

int main()
{
  UintList numbers = getSeries(1025);
  String stringResult = seriesToString(numbers);

  printf(stringResult.content);

  freeUintList(numbers);
  freeString(stringResult);
}