#include <stdio.h>
#define SIZE 6

int main()
{
  int arr[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    printf("Please enter number %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  int max = 0;
  int min = arr[0];
  for (int i = 0; i < SIZE; i++)
  {
    if (arr[i] > max) // 1 1 2
    {
      max = arr[i];
    }
    else if (min > arr[i])
    {
      min = arr[i];
    }
  }
  printf("The maximum value is: %d\n", max);
  printf("The minimum value is: %d\n", min);

  return 0;
}