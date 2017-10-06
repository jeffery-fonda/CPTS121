#include "header.h"

void print_welcome_screen (void)
{
	printf ("\n");
	printf ("***** Welcome to Battleship! *****\n");
	printf ("\n");
}

void print_game_rules (void)
{
	printf ("Rules of the Game:\n");
	printf ("\n");
	printf ("1. This is a two player game.\n");
	printf ("\n");
	printf ("2. Player1 is you and Player2 is the computer.\n");
	printf ("\n");
	printf ("3. Take turns entering coordinates to try and sink a ship.\n");
	printf ("\n");
	printf ("4. Letters stand for columns, numbers stand for rows.\n");
	printf ("\n");
	printf ("5. Whoever sinks all of their opponents ships first wins.\n");
	printf ("\n");
}

char clear_screen (void)
{
	char input = '\0';
	printf ("If you understand the rules, hit 'Y'.\n");
	scanf ("%c", &input);
	
	if ((input == 'Y') || (input == 'y'))
	{
		system ("cls");
	}
	return input;
}

void method_of_place_ships (char board[][MAX_COLS])
{
	int option = 0;
	do
	{
		printf ("Please select from the following menu: \n");
		printf ("\n");
		printf ("1. Enter positions of ships manually.\n");
		printf ("\n");
		printf ("2. Allow the program to randomly select positions of ships.\n");
		printf ("\n");
		scanf ("%d", &option);

		if (option == 1)
		{
			manually_place_ship(board, 5, 'C');
			manually_place_ship(board, 4, 'B');
			manually_place_ship(board, 3, 'S');
			manually_place_ship(board, 3, 'R');
			manually_place_ship(board, 2, 'D');
		}
		else if (option == 2)
		{
			random_place_ships(board, 'D', 2);
			random_place_ships(board, 'R', 3);
			random_place_ships(board, 'S', 3);
			random_place_ships(board, 'B', 4);
			random_place_ships(board, 'C', 5);
		}
		else
		{
			printf("Please press either 1 or 2\n");
		}

	}while ((option != 1) && (option != 2));

	display_board(board, MAX_ROWS, MAX_COLS);
	 
}

void init_game_board (char board[][MAX_COLS], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < rows; row_index++)
	{
		for (col_index = 0; col_index < cols; col_index++)
		{
			board[row_index][col_index] = '~';
		}
	}
}

void generate_start_point (int direction, int length, int *row_ptr, int *col_ptr)
{
	if (direction == 0)
	{
		*row_ptr = rand () % MAX_ROWS;
		*col_ptr = rand () % (MAX_COLS - length - 1);
	}
	else
	{
		*row_ptr = rand () % (MAX_ROWS - length -1);
		*col_ptr = rand () % MAX_COLS;
	}
}

int generate_dir (void)
{
	int direction = 0;

	direction = rand () % 2;

	return direction;
}

void manually_place_ship (char board[][MAX_COLS], int length, char symbol)
{
	int direction = 0, row_start = 0, col_start = 0, counter = 0;

	direction = generate_dir ();
	generate_start_point (direction, 5, &row_start, &col_start);
	
	if (direction == 0)
	{
		while (counter < length)
		{
			board[row_start][col_start + counter] = symbol;
			counter++;
		}
	}
	else
	{
		while (counter < length)
		{
			board[row_start + counter][col_start] = symbol;
			counter++;
		}
	}
}

int check_water (int direction, int length, char board[][MAX_COLS], int row_start, int column_start)
{
	int open = 0, row = 0, column = 0, direc = 0;
	row = row_start;
	column = column_start;
	direc = direction;

	if (direc == 0)
	{
		do
		{
			if (board[row][column] == '~')
			{
				open = 1;
				column++;
			}
			else if (board[row][column] != '~')
			{
				return open = 0;
			}
		} while (column < (length + column_start));
	}

	else if (direc == 1)
	{
		do
		{
				
			if (board[row][column] == '~')
			{
				open = 1;
				row++;
			}
			else if (board[row][column] != '~')
			{
				return open = 0;
			}
		} while (row < (length + row_start));
	}
	return open;
}

void random_place_ships(char board[][MAX_COLS], char ship_title, int lenght)
{
	int row_index = 0, column_index = 0;
	int row_start1 = 0, column_start1 = 0, direction = 0, open = 0;

	do
	{
		direction = generate_dir();
		generate_start_point (direction, lenght, &row_start1, &column_start1);
		open = check_water (direction, lenght, board, row_start1, column_start1);
	} while (open == 0);

	if (direction == 0)
	{
		for (column_index = column_start1; column_index < (lenght + column_start1); column_index++)
		{
			row_index = row_start1;
			board[row_index][column_index] = ship_title;
		}
	}
	else if (direction == 1)
	{
		for (row_index = row_start1; row_index < (lenght + row_start1); row_index++)
		{
			column_index = column_start1;
			board[row_index][column_index] = ship_title;
		}
	}
}

void display_board (char board[][MAX_COLS], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	printf (" 0 1 2 3 4 5 6 7 8 9\n");

	for (row_index = 0; row_index < rows; row_index++)
	{
		printf ("%d", row_index);

		for (col_index = 0; col_index < cols; col_index++)
		{
			printf ("%c ", board[row_index][col_index]);
		}
		putchar ('\n');
	}
}

coordinate intialize_player_coordinates()
{
	coordinate player_choice;
	player_choice.row = 0;
	player_choice.column = 0;
	return player_choice;
}

coordinate initialize_comp_coordinates()
{
	coordinate comp;
	comp.row = 0;
	comp.column = 0;
	return comp;
}

coordinate attempt()
{
	coordinate player_choice;
	player_choice.row = 0;
	player_choice.column = 0;
	printf("Enter coordinates for your attack: \n");
	scanf("%d", &player_choice.row);
	scanf("%d", &player_choice.column);
	return player_choice;
}

hits_misses initialize_player()
{
	hits_misses player1;
	player1.hits = 0;
	player1.misses = 0;
	return player1;
}
hits_misses initialize_comp()
{
	hits_misses comp;
	comp.hits = 0;
	comp.misses = 0;
	return comp;
}
void check_hit_miss (coordinate player_choice, hits_misses player1, char comp_board[][MAX_COLS],char attack_board[][MAX_COLS], FILE *output_file)
{
	if (attack_board[player_choice.row][player_choice.column] == '~')
	{
		printf ("Miss\n");
		fprintf (output_file, "Miss: [%d,%d]", player_choice.row, player_choice.column);
		comp_board[player_choice.row][player_choice.column] = 'x';
		display_board(comp_board, MAX_ROWS, MAX_COLS);
		player1.misses++;
	}
	else
	{
		printf ("HIT!!!\n");
		fprintf (output_file, "HIT: [%d,%d]", player_choice.row, player_choice.column);
		comp_board[player_choice.row][player_choice.column] ='*';
		display_board(comp_board, MAX_ROWS, MAX_COLS);
		player1.hits++;
	}
	return;
}

void player_turn (coordinate player_choice, hits_misses player1, char board [][MAX_COLS], char comp_board [][MAX_COLS], char attack_board [][MAX_COLS], FILE *output_file)
{
	coordinate initialize_player;
	player_choice.row = 0;
	player_choice.column = 0;
	player_choice = attempt();
	printf ("[%d,%d]\n", player_choice.row, player_choice.column);
	check_hit_miss (player_choice, player1, comp_board, attack_board, output_file);
	hit_or_miss_player();
	return;
}

void computer_turn (char player1_board[][MAX_COLS], FILE *output_file)
{
	coordinate comp_coordinates;
	comp_coordinates.row = 0;
	comp_coordinates.column = 0;
	comp_coordinates = random_coordinate_comp();
	printf ("[%d,%d]\n" , comp_coordinates.row , comp_coordinates.column);
	check_hit_miss_comp(comp_coordinates, player1_board, output_file);
	hit_or_miss_comp();
}

hits_misses check_hit_miss_comp (coordinate comp_coordiantes, char player1_board[][MAX_COLS], FILE *output_file)
{
	hits_misses comp;
	comp.misses = 0;
	comp.hits = 0;

	if (player1_board[comp_coordiantes.row][comp_coordiantes.column] == '~')
	{
		printf("Miss by computer\n");
		fprintf(output_file, "Miss by computer: [%d,%d]", comp_coordiantes.row, comp_coordiantes.column);
		comp.misses++;
	}
	else
	{
		printf("HIT BY COMPUTER!!!\n");
		fprintf(output_file, "HIT BY COMPUTER: [%d,%d]", comp_coordiantes.row, comp_coordiantes.column);
		comp.hits++;
	}
	return comp;
}
char hit_or_miss_player(void)
{
	hits_misses player1;
	player1.hits = 0;
	player1.misses = 0;
	
	if(player1.hits == 1)
	{
		player1.hits++;
	}
	else
	{
		player1.misses++;
	}
}
char hit_or_miss_comp(void)
{
	hits_misses comp;
	comp.hits = 0;
	comp.misses = 0;

	if(comp.hits == 1)
	{
		comp.hits++;
	}
	else
	{
		comp.misses++;
	}
}
coordinate random_coordinate_comp()
{
	coordinate comp_coordinates;
	comp_coordinates.row = 0;
	comp_coordinates.column = 0;

	comp_coordinates.row = (rand() % MAX_ROWS);
	comp_coordinates.column = (rand() % MAX_COLS);
	return comp_coordinates;
}
void win_or_lose (coordinate player_choice, char board [][MAX_COLS], char comp_board[][MAX_COLS], char attack_board [][MAX_COLS],char player1_board [][MAX_COLS], FILE *output_file)
{
	hits_misses player1;
	hits_misses comp;
	player1.hits = 0;
	player1.misses = 0;
	comp.hits = 0;
	comp.misses = 0;

	do
	{
		player_turn(player_choice, player1, board, comp_board, attack_board, output_file);
		check_if_ship_sunk_player(comp_board, ships);
		system("pause");
		system("cls");
		computer_turn(player1_board, output_file);
		check_sunk_ship_comp(player1_board, ships);
		system("pause");
		system("cls");
	}while(player1.hits || comp.hits < 17);

	if(player1.hits == 17)
	{
		fprintf(output_file, "You Win!\n");
		printf("Winner\n");
	}
	else if(comp.hits == 17)
	{
		fprintf(output_file, "You Lose. You Suck\n");
		printf("You Lose.\n");
	}
}
fleet ships ()
{
	destroyer = 'D';
	carrier = 'C';
	battleship = 'B';
	submarine = 'S';
	cruiser = 'R';
}

void check_if_ship_sunk_player(char comp_board [][MAX_COLS], int ships)
{
	scanf("%c", &comp_board);
	switch(ships);
	{
		case(comp_board [MAX_ROWS][MAX_COLS] != fleet carrier);
		{
			printf("Enemy Carrier Sunk!");
			break;
		}
		case(comp_board[MAX_ROWS][MAX_COLS] != fleet Battleship);
		{
			printf("Enemy Battleship Sunk!");
			break;
		}
		case(comp_board[MAX_ROWS][MAX_COLS] != fleet Cruiser);
		{
			printf("Enemy Cruiser Sunk!");
			break;
		}
		case(comp_board[MAX_ROWS][MAX_COLS] != fleet Submarine);
		{
			printf("Enemy Submarine Sunk!");
			break;
		}
		case(comp_board[MAX_ROWS][MAX_COLS] != fleet Destroyer);
		{
			printf("Enemy Destroyer Sunk!");
			break;
		}
	}
}

void check_sunk_ship_comp(char player1_board[MAX_ROWS][MAX_COLS], int ship)
{
		scanf("%c", &player1_board);

	switch(ships);
	{
		case(player1_board[MAX_ROWS][MAX_COLS] != fleet Carrier)
		{
		printf("Carrier Sunk!");
		break;
		}
		case(player1_board[MAX_ROWS][MAX_COLS] != fleet Destroyer)
		{
			printf("Destroyer Sunk");
			break;
		}
		case(player1_board [MAX_ROWS][MAX_COLS] != fleet Cruiser)
		{
			printf("Cruiser Sunk");
			break;
		}
		case(player1_board[MAX_ROWS][MAX_COLS] != fleet Battleship)
		{
			printf("Battleship Sunk");
			break;
		}
		case(player1_board[MAX_ROWS][MAX_COLS] != fleet Submarine)
		{
			printf("Submarine Sunk");
			break;
		}
	}
}