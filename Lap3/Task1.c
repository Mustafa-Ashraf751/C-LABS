#include <stdio.h>
#define SIZE 12

int main()
{
  int arr[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    printf("Please enter number %d: ", i + 1);
    scanf(" %d", &arr[i]);
  }
  int row = 0;
  int col = 0;
  int flag = 0;

  do
  {
    flag = 0;
    printf("Please enter row number: ");
    scanf("%d", &row);
    if (SIZE % row != 0)
    {
      printf("Invalid row number try again\n");
      flag = 1;
    }
    else
    {
      printf("Please enter col number: ");
      scanf("%d", &col);
      if (SIZE % col != 0)
      {
        printf("Invalid col number try again\n");
        flag = 1;
      }
    }

  } while (flag);

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      printf(" %d \t", arr[col * i + j]);
    }
  }
}