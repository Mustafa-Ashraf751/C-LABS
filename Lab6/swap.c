#include <stdio.h>

void swap(int *num1, int *num2)
{
  *num1 = *num2 - *num1;
  *num2 = -1 * (*num1 - *num2);
  *num1 = *num1 + *num2;
}

/*void swap2(int *num1, int *num2)
{
  if (*num1 == 0 || *num2 == 0)
    return;
  *num1 = *num1 / *num2;
  *num2 = *num1 * *num2;
  *num1 = *num2 / *num1;
}*/

int main()
{

  int num1 = 3;
  int num2 = 10;
  printf("num1 and num2 before swap: %d %d\n", num1, num2);
  swap(&num1, &num2);
  printf("num1 and num2 after swap: %d %d\n", num1, num2);

  return 0;
}