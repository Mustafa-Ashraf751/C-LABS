#include <stdio.h>

int main()
{
  int size;
  printf("Please enter the size of magic box: ");
  scanf(" %d", &size);
  if (size % 2 == 0)
  {
    printf("Only odd numbers are allowed");
    return 0;
  }
  int row = 0;
  int col = size / 2;

  for (int i = 1; i <= size * size; i++)
  {
    printf("\033[%d;%dH", row + 2, col * 4 + 2);

    printf("%d ", i);
    // Increase col and decrease row by 1
    int newRow = row - 1;
    int newCol = col + 1;
    // Check row if it out of bounds
    if (newRow < 0)
      newRow = size - 1;
    // Check for column if it out of bounds
    if (newCol >= size)
      newCol = 0;
    // Check if current index is occupied
    if (i % size == 0)
    {
      newRow = row + 1;
      newCol = col;
    }

    row = newRow;
    col = newCol;
  }

  return 0;
}