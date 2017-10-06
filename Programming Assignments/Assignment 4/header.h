#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS

int get_bank_balance (int bank);
void print_game_rules (void) ;
int get_wager_amount (int money);
int check_wager_amount (int bank, int money) ;
int roll_die (void);
int sum_diceF (int die1 , int die2); 
int is_win_loss_or_point (int money , int bank , double add_wager , double subtract_wager , int die1 , int die2);
int is_point_loss_or_neither (int sum_dice, int point_value);
int add_winnings (int money , int bank);
int subtract_winnings (int money , int bank);
int adjust_bank_balance (int bank , int money , int add_winnings , int subtract_winnings , int adjusted_reserves);
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
int sum_dice;

#endif HEADER.H