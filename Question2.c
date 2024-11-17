
#include <stdio.h>

int main()
{
  int sum = 0;
  int input = 0;
  do
  {
    printf("Please enter a number to sum: ");
    scanf(" %d", &input);
    sum += input;

  } while (sum <= 100);
  return 0;
}
