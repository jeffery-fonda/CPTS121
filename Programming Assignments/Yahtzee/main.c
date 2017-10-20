#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.c"

int main (void)
{
  int die_arr[5] = {};
  int i = 0;
  int choice = 0;
  int score = 0, temp_score = 0;
  int die_value = 0;
  char exit_statment = '\0', roll = '\0', save = '\0';
  int save_value = 0;
  int num_rolls = 0;

  srand(time(NULL));

  do
  {
    for (i = 0; i < 5; i++)
    {
      die_value = rand() % 6 + 1;
      die_arr[i] = die_value;
    }
    i = 0;

    for (i = 0; i < 5; i++)
    {
      printf("Die %d value is: %d\n", i, die_arr[i]);
    }

    i = 0;
    choice = 0;

    printf("Roll again? Y/N\n");
    scanf(" %c", &roll);

    if (roll == 'Y')
    {
      printf("Do you wish to save any values?\n");
      scanf(" %c", &save);

      if (save == 'Y')
      {
        /*do {
          printf("Which values would you like to save (die number)?\n");
          scanf("%d", &save_value);

          switch (save_value)
          {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
          }

        } while(); //number of saved is less than 5*/
      }


    }
    else
    {
      printf("1. Three-of-a-kind\n");
      printf("2. Four-of-a-kind\n");
      printf("3. Full house\n");
      printf("4. Small straight\n");
      printf("5. Large straight\n");
      printf("6. Yahtzee\n");
      printf("7. Chance\n");
      printf("Select option: \n");
      scanf("%d", &choice);

      printf("Choice is: %d\n", choice);

      switch (choice)
      {
        case 1:
          temp_score = three_of_kind(die_arr, score);
          score = temp_score;
          printf("Score: %d\n", score);
          break;
        case 2:

          break;
        case 3:

          break;
        case 4:

          break;
        case 5:
          temp_score = large_straight(die_arr, score);
          score = temp_score;
          printf("Score: %d\n", score);
          break;
        case 6:

          break;
        case 7:
          temp_score = chance(die_arr, score);
          score = temp_score;
          printf("Score: %d\n", score);
          break;
      }
    }

    printf("Coninue? Y/N\n");
    scanf(" %c", &exit_statment);
    system("clear");

    num_rolls++;

  } while(exit_statment != 'N' || num_rolls != 16);

}
