#include <stdio.h>

int main()
{
  for (int i = 10; i >= 1; i--)
  {
    for (int j = 1; j <= 12; j++)
    {
      printf("%d * %d = %d\n", i, j, i * j);
    }
    if (i != 1)
    {
      printf("**************\n");
    }
  }
  return 0;
}
