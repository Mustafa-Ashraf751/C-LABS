#include "mustafa_string.h"
#include <stdio.h>
#define TERMINATOR '\0'

int stringLen(char source[])
{
  unsigned int i = 0;
  while (source[i] != TERMINATOR)
  {
    i++;
  }
  return i;
}

void copyString(char dest[], char source[], int size)
{

  int i = 0;

  if (stringLen(source) <= size - 1)
  {
    while (source[i] != TERMINATOR)
    {
      dest[i] = source[i];
      i++;
    }
    dest[i] = '\0';
  }
  else
  {
    printf("Destination don't have enough space to contain source");
  }
};

void stringLower(char str[])
{
  int i = 0;
  while (str[i] != TERMINATOR)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
    i++;
  }
}

void stringUpper(char str[])
{
  int i = 0;
  while (str[i] != TERMINATOR)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = str[i] - 32;
    }
    i++;
  }
}

void stringConcat(char dest[], char source[], int size)
{
  // Determine the fill size of dest
  int length = stringLen(dest);
  if (stringLen(source) + length <= size)
  {
    int i = 0;
    int indexToAppend = stringLen(dest);
    for (int i = 0; i < stringLen(source); i++)
    {
      dest[indexToAppend++] = source[i];
    }
    dest[indexToAppend] = '\0';
  }
  else
  {
    printf("Destination and source can't be concatend try again");
  }
}

int stringCompare(char str1[], char str2[])
{
  int sumStr1 = 0;
  int sumStr2 = 0;
  for (int i = 0; i < stringLen(str1); i++)
  {
    sumStr1 += str1[i];
  }
  for (int i = 0; i < stringLen(str2); i++)
  {
    sumStr2 += str2[i];
  }
  if (sumStr1 == sumStr2)
  {
    return 0;
  }
  else if (sumStr1 > sumStr2)
  {
    return sumStr1 - sumStr2;
  }
  else
  {
    return sumStr1 - sumStr2;
  }
};