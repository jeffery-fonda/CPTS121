#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum_dice(int die_arr[], int die_value, int score)
{
  int i = 0;
  int num_dice = 0;

  for (i = 0; i < 5; i++)
  {
    if (die_arr[i] == die_value)
      num_dice++;
  }

  score = score + (die_value * num_dice);
  printf("Number of %d: %d\n", die_value, num_dice);

  return score;
}

int three_of_kind(int die_arr[], int score)
{
  int i = 0, j = 0, count = 0;

  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 5; j++)
    {
      if (die_arr[i] == die_arr[j])
      {
        count++;
        printf("Count updated\n");
        break;
      }
    }
  }
  if (count == 3)
  {
    printf("Three of a kind!\n");
    score = score + 10;
  }

  return score;
}

int large_straight(int die_arr[], int score)
{
  int i = 0, j = 0;
  int temp = 0;
  int count = 0;

  for (i = 0 ; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (die_arr[i+1] < die_arr[i])
			{
				temp = die_arr[i];
				die_arr[i] = die_arr[i + 1];
				die_arr[i + 1] = temp;
			}
		}
	}
  i = 0;
  printf("Sorted array: \n");
  for (i = 0; i < 5; i++)
  {
    printf("Die %d value is: %d\n", i, die_arr[i]);
  }
  i = 0;

  for(i = 0 ; i < 5; i++)
  {
    if(die_arr[i] == die_arr[i+1])
      count++;
  }
  if (count == 5)
  {
    printf("Large straight!\n");
    score = score + 40;
  }
}

int chance (int die_arr[], int score)
{
  int i = 0;
  int sum = 0;

  for (i = 0; i < 5; i++)
  {
    sum = sum + die_arr[i];
  }

  printf("Sum of dice: %d\n", sum);
  score = score + sum;

  return score;
}
