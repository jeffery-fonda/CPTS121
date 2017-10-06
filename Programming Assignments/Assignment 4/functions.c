#include "header.h"

int get_bank_balance (int bank)
{
	printf("Enter in bank balance: ");
	scanf("%d" , &bank);
	printf("Your bank balance : %d\n" , bank);
	return bank;
}

void print_game_rules (void)
{
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. \n After the dice have come to rest, the sum of the spots on the two upward faces is calculated. \n If the sum is 7 or 11 on the first throw, the player wins. \n If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (i.e. the house wins). \n If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point. \n To win, you must continue rolling the dice until you make your point. \n The player loses by rolling a 7 before making the point.\n");
	return;
}

int get_wager_amount (int money)
{
	printf("Enter wager: ");
	scanf("%d", &money);
	printf("Your wager  %d\n", money);
	return money;
}

int check_wager_amount (int bank , int money )
{
	printf("Wager %d\n", money);
	printf("Bank %d\n", bank);
      if (money <= bank)
    {
	  printf ("Wager is within bank balance.\n");
	  return 0;
    }
      else 
    {
	  printf("Bet exceeds bank balance.\n");
	  return 1;
    } 
	return 0;
}
int roll_die (void)
{
	int die_value = 0;

	die_value = (rand () % 6) + 1;

	return die_value;
}

int sum_diceF (int die1, int die2)
{
	int sum_dice = 0;

	sum_dice = die1 + die2;
	printf("Sum of Dice: %d\n", sum_dice);
	return sum_dice;
}

int is_win_loss_or_point (int money, int bank, double add_wager, double subtract_wager, int die1, int die2)
{
	sum_dice = sum_diceF (die1 , die2);
	if ((sum_dice == 7) || (sum_dice == 11))
	{ 
		printf ("Winner!\n");
		return add_winnings (money , bank);
	}
	else if ((sum_dice == 4) || (sum_dice == 5) || (sum_dice == 6) || (sum_dice == 8) || (sum_dice == 9) || (sum_dice == 10)) 
	{
		int sum_dice_temp = sum_dice;
		
		printf ("Made point. To win you must roll for the same value before a seven or craps.\n");
		 
			 while ((sum_dice != sum_dice_temp) || (sum_dice == 4) || (sum_dice == 5) || (sum_dice == 6) || (sum_dice == 8) || (sum_dice == 9) || (sum_dice == 10))
			{
		       die1 = roll_die();
			   printf("New Dice: %d\n", die1);
			   die2 = roll_die();
			   printf("New Dice: %d\n", die2);
			   sum_dice = sum_diceF (die1 , die2);

				if((sum_dice == 2) || (sum_dice == 3) || (sum_dice == 12) || (sum_dice == 7))
				{
				printf("Failed to make point. Craps. Loose wager\n");
				return subtract_winnings (bank , money);
				}
			
				if (sum_dice == sum_dice_temp)
				{
				printf("Congratulations. You made point. Collect your wager\n");
				return add_winnings (money , bank);
				}
			sum_dice_temp == sum_dice;
		}
		return 0;
		 }
		 
	else if ((sum_dice == 2) || (sum_dice == 3) || (sum_dice == 12))
	{
			printf ("Lost!\n");
		return subtract_winnings (money , bank);
	
	}
	return is_win_loss_or_point;
}



int add_winnings (int money, int bank)
{
    printf("Bank: %d\n", bank);
	printf("Wager: %d\n", money);
	bank = money + bank;
	printf ("Play again?\n");

    return (bank);
}

int subtract_winnings (int money, int bank)
{
    printf("Bank: %d\n", bank);
	printf("Wager: %d\n", money);
	bank = bank - money;
    printf("Keep playing?\n");
	return (bank);
}



int adjust_bank_balance (int bank, int money, int add_winnings, int subtract_winnings, int adjusted_reserves)   // adjusting bank balance and returning
 {
	add_winnings = 0;
	subtract_winnings = 0;
	 if (bank)
	{
		printf("New Bank Reserves: %d\n", add_winnings);
		return add_winnings;
	}
	 
	else 
	{
		printf("New Bank Reserves: %d\n", subtract_winnings);
		return subtract_winnings;
	}
	return adjusted_reserves;
}