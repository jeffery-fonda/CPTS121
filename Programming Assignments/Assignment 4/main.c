/*
Programmer: Jeffery Fonda
Class: CptS 121, Fall 2014; Lab Section 5
Programming Assignment: Assignment 4
Date: October 5, 2014
Description: This program plays craps.
*/

#include "header.h"

int main (void)
{
	int bank1 = 0, money1 = 0,  die1 = 0,  die2 = 0,  wager = 0, monies = 0, bank = 0, wager_check = 0;
	int add_wager = 0,  subtract_wager = 0;
	int bank_reserves = 0.0;
	int sum = 0;
	int adjusted_reserves = 0;
	
	srand ((unsigned int) time(NULL));

	// Print game rules

	print_game_rules();

	// Enter bank balance

	bank1 = get_bank_balance (bank);

	// Enter wager

	money1 = get_wager_amount (monies);

	// Check wager

	wager_check = check_wager_amount (bank1 , money1);

	// Roll Dice

	die1 = roll_die();
	printf("Die1 %d\n" , die1);
	die2 = roll_die();
	printf("Die2 %d\n" , die2);

	// Sum of Dice

	sum = sum_diceF (die1 , die2);
	printf("Sum %d\n" , sum_dice);

	// Outcome

	is_win_loss_or_point (monies ,bank ,add_wager ,subtract_wager , die1 , die2);

    // Adjust Bank

	adjust_bank_balance (bank, monies, add_winnings, subtract_winnings, adjusted_reserves);

	return 0 ;
}