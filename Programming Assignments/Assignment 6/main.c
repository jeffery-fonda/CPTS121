#include "header.h"

int main (void)
{
	char p1_board[MAX_ROWS][MAX_COLS] = {'\0'};
	char comp_board[MAX_ROWS][MAX_COLS] = {'\0'};
	char attack_board[MAX_ROWS][MAX_COLS] = {'\0'};
	int row_start1 = 0, column_start1 = 0, row_start2 = 0, column_start2 = 0;
	int row_start3 = 0, column_start3 = 0, row_start4 = 0, column_start4 = 0, row_start5 = 0, column_start5 = 0;
	int direction = 0, hits = 0;
	coordinate player_choice;
	player_choice.row = 0;
	player_choice.column = 0;
	FILE *output_file = NULL;

	srand ((unsigned int) time (NULL));

	output_file = fopen ("battleship.log", "w");

	// Game

	init_game_board(p1_board, MAX_ROWS, MAX_COLS);
	init_game_board(attack_board, MAX_ROWS, MAX_COLS);
	display_board(p1_board, MAX_ROWS, MAX_COLS);
	display_board(attack_board, MAX_ROWS, MAX_COLS);

	printf("An empty ocean ready for battle!\n");

	method_of_place_ships(p1_board);
	init_game_board(comp_board, MAX_ROWS, MAX_COLS);
	random_place_ships(comp_board, 'D', 2);
	random_place_ships(comp_board, 'R', 3);
	random_place_ships(comp_board, 'S', 3);
	random_place_ships(comp_board, 'B', 4);
	random_place_ships(comp_board, 'C', 5);

	display_board(attack_board, MAX_ROWS, MAX_COLS);
	printf("(%d,%d)", player_choice.row, player_choice.column);
	init_game_board(attack_board, MAX_ROWS , MAX_COLS);

	do
	{
		initialize_player();
		initialize_comp()
		player_turn ();
		intialize_player_coordinates();
		initialize_comp_coordinates();
		attempt();
		check_hit_miss ();
		computer_turn ();
		player_turn ():
		check_hit_miss_comp ();
		hit_or_miss_player ();
		hit_or_miss_comp ();
		random_coordinate_comp();
	} while (hits <= 17);

	win_or_lose(player_choice, comp_board, attack_board, p1_board, output_file);

	fclose (output_file);

	return 0;
}