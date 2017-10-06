#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Menu

void program (char option, char initials[], FILE* output_file, int difficulty, int points);
void display_how_to (void);
void get_initials (char initials[], FILE* output_file);
void display_how_to (void);
void select_difficulty (char option, char initials[], FILE* output_file, int difficulty, int points);

// Difficulty Types

typedef struct variables
{
	int a;
	int b;
	int c;
	int d;
} Variables;

typedef struct answers
{
	int a;
	int b;
} Answers;

int easy_problems (int points);
int fair_problems (int points);
int intermediate_problems (int points);
int hard_problems (int points);
int impossible_problems (int points);

// Evaluate Problems

int eval_easy_problems (int a, int b, char opperand);
int eval_hard_problems (int a, int b, int c, char op1, char op2);
int eval_impossible_problems (int a, int b, int c, int d, char op1, char op2, char op3);

// Points to File

int write_points_to_file (int points, FILE* output_file);

#endif