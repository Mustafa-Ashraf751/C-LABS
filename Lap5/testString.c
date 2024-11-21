#include <stdio.h>
#include "mustafa_string.h"

int main()
{

  char name1[20] = "mustafa";
  char name2[20] = "ahmed";
  copyString(name1, name2);
  printf("%s", name1);

  return 0;
}