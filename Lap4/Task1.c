#include <stdio.h>
#define ROW 3
#define COL 4

int main()
{

  int arr[ROW][COL];
  int sum1 = 0, sum2 = 0, sum3 = 0, avg1 = 0, avg2 = 0, avg3 = 0, avg4 = 0;
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      printf("Please enter element number[%d][%d]: ", i, j);
      scanf("%d", &arr[i][j]);
      // For find each row sum
      if (i == 0)
      {
        sum1 += arr[i][j];
      }
      else if (i == 1)
      {
        sum2 += arr[i][j];
      }
      else if (i == 2)
      {
        sum3 += arr[i][j];
      }
      // For find average of each column we find the sum first
      if (j == 0)
      {
        avg1 += arr[i][j];
      }
      else if (j == 1)
      {
        avg2 += arr[i][j];
      }
      else if (j == 2)
      {
        avg3 += arr[i][j];
      }
      else if (j = 3)
      {
        avg4 += arr[i][j];
      }
    }
  }

  avg1 = avg1 / ROW;
  avg2 = avg2 / ROW;
  avg3 = avg3 / ROW;
  avg4 = avg4 / ROW;

  printf("The sum of each row is %d \t %d \t %d\n", sum1, sum2, sum3);

  printf("The average of each column is %d \t %d \t %d \t %d\n", avg1, avg2, avg3, avg4);

  return 0;
}
