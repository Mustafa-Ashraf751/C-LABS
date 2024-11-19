
#include <stdio.h>
#include "conio.h"
#define SIZE 3

void blue()
{
  printf(" \033[0;34m");
}

void white()
{
  printf("\033[0;37m");
};

void resetColor()
{
  printf("\x1B[0m");
};

void resetCursor()
{
  printf("\033[H\033[J");
}

void clearScreen()
{
  printf("\033[H\033[J");
}

// Create function to display menu
void displayMenuOPtions(char *option, int isSelected)
{
  if (isSelected)
  {
    blue();
  }
  else
  {
    white();
  }
  printf("%s\n\n\n", option);
  resetColor();
};

int main()
{
  char input;
  // right 27 91 67 // left 27 91 68 //up 27 91 65 //down 27 91 66 // enter equal 10 // space -> 32 // backspace 127
  /* printf("Please choose");
   input = getch();
   input = getch();
   input = getch();
   printf("%d", input);*/
  const char *menuOptions[] = {"New", "Display", "Exit"};
  int selectedOption = 0;
  printf("Please choose a option \n\n\n");
  for (int i = 0; i < SIZE; i++)
  {
    displayMenuOPtions(menuOptions[i], i == selectedOption);
  }
  int dontStop = 1;
  while (dontStop)
  {
    input = getch();
    // Arrow need 3 times to get the number
    if (input == 27)
    {
      input = getch();
      input = getch();
    }
    // we user press arrow up
    if (input == 65)
    {
      if (selectedOption == 0)
      {
        selectedOption = 3;
      }
      if (selectedOption > 0)
      {
        resetCursor();
        // decrease the cursor
        selectedOption--;
        // show the menu
        for (int i = 0; i < SIZE; i++)
        {
          displayMenuOPtions(menuOptions[i], i == selectedOption);
        }
      }
    }
    // Arrow will go down
    if (input == 66)
    {
      if (selectedOption == SIZE - 1)
      {
        selectedOption = -1;
      }
      if (selectedOption < SIZE - 1)
      {
        resetCursor();
        selectedOption++;
        for (int i = 0; i < SIZE; i++)
        {
          displayMenuOPtions(menuOptions[i], i == selectedOption);
        }
      }
    }

    // Incase user select one from the options and press enter

    if (input == 10)
    {
      clearScreen();
      printf("You have selected: %s\n", menuOptions[selectedOption]);

      if (selectedOption == 2)
      {
        printf("Press backSpace to back to menu...or space to confirm \n");
      }
      else
      {
        printf("Press backSpace to back to menu...\n");
      }
      input = getch();
      if (input == 127)
      {
        clearScreen();
        for (int i = 0; i < SIZE; i++)
        {
          displayMenuOPtions(menuOptions[i], i == selectedOption);
        }
      }
      if (selectedOption == 2 && input == 127)
      {
        clearScreen();
        for (int i = 0; i < SIZE; i++)
        {
          displayMenuOPtions(menuOptions[i], i == selectedOption);
        }
      }
      else if (selectedOption == 2 && input == 32)
      {
        printf("See you later ");
        dontStop = 0;
      }
    }
  };
  return 0;
}