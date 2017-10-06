#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct hits_misses
{
	int hits;
	int misses;
}hits_misses;

void print_welcome_screen (void);
void print_game_rules (void);
char clear_screen (void);
void method_of_place_ships(char board[][MAX_COLS]);
void init_game_board (char board[][MAX_COLS], int rows, int cols);
void generate_start_point (int direction, int length, int *row_ptr, int *col_ptr);
int generate_dir (void);
void manually_place_ship (char board[][MAX_COLS], int length, char symbol);
int check_water (int direction, int length, char board[][MAX_COLS], int row_start, int column_start);
void random_place_ships(char board[][MAX_COLS], char ship_title, int lenght);
void display_board (char board[][MAX_COLS], int rows, int cols);

typedef struct coordinate
{
	int row;
	int column;

}coordinate;

typedef struct fleet
{
	int carrier;
	int battleship;
	int Submarine;
	int destroyer;
	int cruiser;
}fleet;

coordinate intialize_coordinates();
coordinate attempt();
void check_hit_miss (coordinate player_choice, hits_misses player1, char comp_board[][MAX_COLS], char attack_board[][MAX_COLS], FILE *output_file);
void player_turn(char board [][MAX_COLS], char comp_board [][MAX_COLS], char attack_board [][MAX_COLS], FILE *output_file);
void computer_turn (char player1_board[][MAX_COLS], FILE *output_file);
hits_misses check_hit_miss_comp (coordinate comp_coordinates, char player1_board[][MAX_COLS], FILE *output_file);
char hit_or_miss_player();
char hit_or_miss_comp();
coordinate random_coordinate_comp();
void player_turn(coordinate player_choice, hits_misses player1, char board [][MAX_COLS], char comp_board [][MAX_COLS], char attack_board [][MAX_COLS], FILE *output_file);
void win_or_lose (coordinate player_choice, char comp_board[][MAX_COLS], char attack_board [][MAX_COLS], char player1_board[][MAX_COLS], FILE *output_file);
void check_if_ship_sunk_player(char comp_board [][MAX_COLS], int ships);
void check_sunk_ship_comp(char player1_board[][MAX_COLS], int ship);

#endif