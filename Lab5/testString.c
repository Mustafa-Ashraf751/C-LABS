#include <stdio.h>
#include "mustafa_string.h"

int main()
{

  char name1[20] = "mustafa";
  char name2[20] = "ashraf";
  // int length = stringLen(name1);
  // int value = stringCompare(name1, name2);
  // copyString(name1, name2, 5);
  //  stringLower(name1);
  //  stringUpper(name2);
  stringConcat(name1, name2, 20);
  printf("%s", name1);
  // printf("%s", name2);

  return 0;
}