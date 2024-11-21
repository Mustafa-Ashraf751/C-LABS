
#include <stdio.h>
#include "conio.h"

#define ARROWUP 65
#define ARROWDOWN 66
#define ENTER 10
#define BACKSPACE 127
#define SPACE 32
#define HOME 72
#define END 70
#define EXTENDEDKEY 27
#define OPTIONONE 0
#define OPTIONTWO 1
#define OPTIONTHREE 2
#define OPTIONFOUR 3
#define SIZE 4
#define EMPLOYEESIZE 100
#define NAMESIZE 50

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

typedef struct Employee
{
  int id;
  char name[NAMESIZE];
  int netSalary;

} Employee;

void ColorMenu(char *menuOptions[], int select);
void inputEmployee(Employee employee[], int size);
void showEmployee(Employee employee[], int size);
void modifyEmployeeByIds(Employee employee[], int size);

main()
{
  char input;
  Employee employeeArray[EMPLOYEESIZE];
  const char *menuOptions[] = {"New", "Display", "Modify", "Exit"};
  int selectedOption = 0;
  printf("Please choose a option \n\n\n");
  ColorMenu(menuOptions, selectedOption);
  int dontStop = 1;
  while (dontStop)
  {
    input = getch();
    // Arrow need 3 times to get the number
    if (input == EXTENDEDKEY)
    {
      input = getch();
      input = getch();
    }
    // we user press arrow up
    if (input == ARROWUP)
    {
      if (selectedOption == OPTIONONE)
      {
        selectedOption = 4;
      }
      if (selectedOption > OPTIONONE)
      {
        resetCursor();
        // decrease the cursor
        selectedOption--;
        // show the menu
        ColorMenu(menuOptions, selectedOption);
      }
    }
    // Arrow will go down
    if (input == ARROWDOWN)
    {
      if (selectedOption == OPTIONFOUR)
      {
        selectedOption = -1;
      }
      if (selectedOption < OPTIONFOUR)
      {
        resetCursor();
        selectedOption++;
        ColorMenu(menuOptions, selectedOption);
      }
    }

    if (input == HOME)
    {
      selectedOption = OPTIONONE;
      clearScreen();
      ColorMenu(menuOptions, selectedOption);
    }

    if (input == END)
    {
      selectedOption = OPTIONFOUR;
      clearScreen();
      ColorMenu(menuOptions, selectedOption);
    }

    // Incase user select one from the options and press enter

    if (input == ENTER)
    {
      int size;
      clearScreen();
      // Incase user choose first option
      if (selectedOption == OPTIONONE)
      {
        // Incase user choose new option
        char flag1 = 1;
        while (flag1)
        {
          flag1 = 0;
          printf("How many employees you want to enter ?\n");
          scanf("%d", &size);
          if (size <= 0)
          {
            printf("Invalid size please try again\n");
            flag1 = 1;
          }
          inputEmployee(employeeArray, size);
        };
      }

      // Incase user choose display option
      if (selectedOption == OPTIONTWO)
      {
        showEmployee(employeeArray, size);
      }

      // Incase user choose modify option
      if (selectedOption == OPTIONTHREE)
      {
        modifyEmployeeByIds(employeeArray, size);
      }

      if (selectedOption == OPTIONFOUR)
      {
        printf("Press backSpace to back to menu...or space to confirm \n");
      }
      else
      {
        printf("Press backSpace to back to menu...\n");
      }
      // To consume extra presses before user press backspace
      int continueToPress = 1;
      while (continueToPress)
      {
        input = getch();
        if (input == BACKSPACE)
          continueToPress = 0;
        if (input == SPACE && selectedOption == OPTIONFOUR)
          continueToPress = 0;
      }
      if (input == BACKSPACE)
      {
        clearScreen();
        ColorMenu(menuOptions, selectedOption);
      }
      if (selectedOption == OPTIONFOUR && input == BACKSPACE)
      {
        clearScreen();
        ColorMenu(menuOptions, selectedOption);
      }
      else if (selectedOption == OPTIONFOUR && input == SPACE)
      {
        printf("See you later ");
        dontStop = 0;
      }
    }
    // I need to do escape and end home
    /*if (!kbhit(input))
    {
      printf("See you later ");
      dontStop = 0;
    }*/
  };
  return 0;
}

// Function to color menu
void ColorMenu(char *menuOptions[], int select)
{
  for (int i = 0; i < SIZE; i++)
  {
    displayMenuOPtions(menuOptions[i], i == select);
  }
}

// Function to take the inputs of employee from the user
void inputEmployee(Employee employee[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int dontstop = 1;
    char unique = 1;
    int tempId;
    char validId = 1;
    // Make a loop to check inputs
    while (dontstop)
    {
      dontstop = 0;
      validId = 1;
      unique = 1;
      printf("Please enter employee number %d id: ", (i + 1));
      if (scanf("%d", &tempId) == 0 || tempId <= 0)
      {
        validId = 0;
        // Clear the input buffer to prevent program to enter infinite loop
        while (getchar() != '\n')
          ;
      }
      else if (validId)
      {
        for (int i = 0; i < size; i++)
        {
          if (tempId == employee[i].id)
          {
            unique = 0;
            while (getchar() != '\n')
              ;
            i = size;
          }
        }
        employee[i].id = tempId;
      }

      if (!unique || !validId)
      {
        if (!validId)
        {
          printf("Invalid id input format please try again: \n");
        }
        else if (!unique)
        {
          printf("Id is already exist please try again: \n");
        }

        dontstop = 1;

      } // If Id was valid it will be move to next step
      else
      {
        printf("Please enter employee number %d name: ", (i + 1));
        scanf(" %[^\n]*", employee[i].name);
        printf("Please enter employee number %d net salary: ", (i + 1));
        if (scanf("%d", &employee[i].netSalary) == 0 || employee[i].netSalary <= 0)
        {
          printf("Invalid salary input please try again: \n");
          dontstop = 1;

          // Clear the input buffer to prevent program to enter infinite loop
          while (getchar() != '\n')
            ;
        }
      }
    }
    if (i < size - 1)
    {
      // Ask the user if he want to continue or not
      printf("If you want to continue press 'y' or any key to out ");
      char input = 0;
      scanf(" %c", &input);
      if (input != 'y' && input != 'Y')
      {
        i = size;
      }
    }
  }

  ;
}

// Function to show the employees data to the user
void showEmployee(Employee employee[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("Employee number %d id: %d\n", (i + 1), employee[i].id);
    printf("Employee number %d name is: %s\n", (i + 1), employee[i].name);
    printf("Employee number %d net salary: %d\n", (i + 1), employee[i].netSalary);
  }
}

// Function to modify the employees
void modifyEmployeeByIds(Employee employee[], int size)
{
  int id;
  int dontstop = 1;
  char input;
  char newName[NAMESIZE];
  int salary;
  printf("Please choose one from the following employees ids: \n");
  for (int i = 0; i < size; i++)
  {
    printf("Employee number %d id: %d\n", (i + 1), employee[i].id);
  }
  while (dontstop)
  {
    dontstop = 0;
    if (scanf("%d", &id) == 0 || id <= 0)
    {
      printf("Invalid input please try again");
      dontstop = 1;
      while (getchar() != '\n')
        ;
    }
    else
    {
      for (int i = 0; i < size; i++)
      {
        if (id == employee[i].id)
        {
          printf("Press (n) to modify name and (s) to modify salary: ");
          scanf(" %c", &input);
          if (input == 'n' || input == 'N')
          {
            printf("Please enter new name: ");
            scanf(" %[^\n]*", newName);
            for (int j = 0; j < NAMESIZE - 1; j++)
            {
              employee[i].name[j] = newName[j];
            }
          }
          else if (input == 's' || input == 'S')
          {
            printf("Please enter new salary: ");
            scanf("%d", &salary);
            employee[i].netSalary = salary;
          }
        }
        else
        {
          printf("Id not found please choose one from the pervious ids");
          dontstop = 1;
          while (getch() != '\n')
            ;
        }
      }
    }
  }
}