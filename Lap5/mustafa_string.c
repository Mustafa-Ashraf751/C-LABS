#include "mustafa_string.h"
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

void copyString(char dest[], char source[])
{

  int i = 0;

  while (dest[i] != TERMINATOR)
  {
    dest[i] = source[i];
    i++;
  }
  dest[i] = '\0';
};