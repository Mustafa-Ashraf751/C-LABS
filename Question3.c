
#include <stdio.h>

int main()
{
  int input = 0;
  do
  {
    printf("Please enter a number of choice: ");
    scanf(" %d", &input);
    switch (input)
    {
    case 1:
      printf("First choice!");
      break;
    case 2:
      printf("Second choice!");
      break;
    case 3:
      printf("Third choice!");
      break;
    default:
      printf("You entered wrong number please  try again!\n");
      break;
    }
    if (input == 1 || input == 2 || input == 3)
    {
      break;
    }

  } while (1);
  return 0;
}
