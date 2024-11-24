#include <stdio.h>
#include "conio.h"

#define ARROWLEFT 68
#define ARROWRIGHT 67
#define ENTER 10
#define BACKSPACE 127
#define SPACE 32
#define INSERT 80
#define HOME 72
#define END 70
#define DELETE 81
#define EXTENDEDKEY 27
#define LINESIZE 100
#define TERMINATOR '\0'

void clearScreen()
{
  printf("\033[H\033[J");
}

void moveCursorBetween(int n)
{
  gotox(n + 1);
  fflush(stdout);
}

int main()
{
  char line[LINESIZE] = "";
  char *head = NULL;
  char *tail = NULL;
  char *current = NULL;
  head = line;
  tail = &line[LINESIZE - 1];
  current = line;
  int dontStop = 1;
  int arrayCounter = 0;
  int currentIndex = 0;
  int insertMode = 0;
  // Start to take input from the user
  while (dontStop)
  {
    // Get the current index the pointer point to
    currentIndex = current - head;
    // Consume the user inputs
    int input = getch();
    if (input == EXTENDEDKEY)
    {
      input = getch();
      input = getch();
      if (input == ARROWRIGHT && currentIndex <= arrayCounter)
      {
        moveCursorBetween(current++);
      }
      else if (input == ARROWLEFT && currentIndex > 0)
      {
        moveCursorBetween(current--);
      }
      else if (input == INSERT)
      {
        if (insertMode)
        {
          insertMode = 0;
        }
        else
        {
          insertMode = 1;
        }
      }
      else if (input == HOME)
      {
        moveCursorBetween(0);
        current = line;
      }
      else if (input == END)
      {
        moveCursorBetween(arrayCounter);
        current = &line[arrayCounter];
      }
      else if (input == DELETE && !insertMode)
      {
        if (currentIndex <= arrayCounter)
        {
          for (int i = currentIndex; i < arrayCounter; i++)
          {
            line[i] = line[i + 1];
            if (i == arrayCounter)
            {
              line[i] = '\0';
            }
          }
          clearScreen();
          for (int i = 0; i < arrayCounter; i++)
          {
            printf("%c", line[i]);
          }
          arrayCounter--;
        }
      }
    }
    else if (input == BACKSPACE)
    {
      for (int i = currentIndex; i < arrayCounter; i++)
      {
        line[i] = line[i + 1];
        if (i == arrayCounter - 1)
        {
          line[i] = '\0';
        }
      }
      clearScreen();
      for (int i = 0; i < arrayCounter; i++)
      {
        printf("%c", line[i]);
      }
      current--;
      arrayCounter--;
    }
    else
    {
      if (insertMode)
      {
        line[currentIndex] = input;
      }
      else
      {
        // Incase cursor go to left
        if (currentIndex < arrayCounter)
        {
          // Shifting the elements to the right
          for (int i = arrayCounter; i > currentIndex; i--)
          {
            line[i] = line[i - 1];
          }

          line[currentIndex + 1] = input;
          current++;
          arrayCounter++;
        }
        else
        {
          // Incase cursor at the end
          line[arrayCounter++] = input;
          current++;
        }
      }
      // To make refresh to screen and print new stuff
      clearScreen();
      for (int i = 0; i < arrayCounter; i++)
      {
        printf("%c", line[i]);
      }
      if (arrayCounter == LINESIZE)
      {
        dontStop = 0;
      }
    }
    // Make cursor stand on current place
    moveCursorBetween(currentIndex);
  }

  return 0;
}
