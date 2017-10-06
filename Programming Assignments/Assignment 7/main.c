/*Programmer: Jeffery Fonda
Class: CptS 121, Fall 2014; Lab Section 5
Programming Assignment: Assignment 7
Date: November 25, 2014
Description: This is an educational math program that allows you to select the difficulty level of math problems to solve.
*/

#include "header.h"

int main (void)
{
	char initials[] = {'\0'}, option = '\0';
	int difficulty = 0, points = 0;
	FILE* output_file = NULL;
	Variables V; Answers A;

	output_file = fopen ("score.dat", "w");

	program (option, initials, output_file, difficulty, points);

	return 0;
}