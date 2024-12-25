#include <stdio.h>

// Create function to compute the power operation
double power(double base, int exp)
{
  if (exp == 0)
  {
    return 1;
  }

  if (exp < 0)
  {
    return 1 / power(base, -exp);
  }

  return base * power(base, exp - 1);
}

int main()
{
  double base;
  int exp;

  printf("Enter the base number: ");
  scanf(" %lf", &base);

  printf("Enter the exponent number: ");
  scanf(" %d", &exp);

  double result = power(base, exp);

  printf("The result is: %.5f", result);

  return 0;
}