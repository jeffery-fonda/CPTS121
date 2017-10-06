/*Programmer: Jeffery Fonda
Class: CptS 121, Fall 2014; Lab Section 5
Programming Assignment: Assingment 5
Date: October 10, 2014
Description: This program reads in sequences of DNA and outputs where the mutated pairs are.
*/

#include "header.h"

int main(void)
{
	char seq_1[2][15] = { 0 }, seq_2[2][15] = { 0 }, seq_3[2][15] = { 0 }, seq_4[2][15] = { 0 };
	FILE *infile = NULL, *output_file = NULL;
	char identifier, eat_space;

	infile = fopen("sequence.dat", "r");
	output_file = fopen("output_file.dat", "w");

	// Reading in the first array

	fscanf(infile, "%c", &identifier);
	fscanf(infile, "%c", &eat_space);
	readseq(seq_1, infile);

	// Reading in the second array

	fscanf(infile, "%c", &eat_space);
	fscanf(infile, "%c", &eat_space);
	readseq(seq_2, infile);

	// Reading in the third array

	fscanf(infile, "%c", &eat_space);
	fscanf(infile, "%c", &eat_space);
	fscanf(infile, "%c", &identifier);
	fscanf(infile, "%c", &eat_space);
	readseq(seq_3, infile);

	// Reading in the fourth array

	fscanf(infile, "%c", &eat_space);
	fscanf(infile, "%c", &eat_space);
	readseq(seq_4, infile);

	// writing the mutations to an outputfile

	fprintf(output_file, "Mutations found in sequence 1:\n");
	check_mutation(seq_1, seq_3, output_file);
	fprintf(output_file, "\n");
	fprintf(output_file, "Mutations found in sequence 2:\n");
	check_mutation(seq_2, seq_4, output_file);
	fprintf(output_file, "\n");

	return 0;
}