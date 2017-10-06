#include "header.h"

void readseq(char seq[2][15], FILE *infile, FILE *output_file)
{
	char temp = '\0';
	int i = 0, size_top = 0, size_bottom = 0;

	do
	{
		fscanf(infile, "%c", &temp);
		if (temp != '\n')
		{
			seq[0][i] = temp;
			fprintf(output_file, "%c", temp);
			i++;
		}
	} while (temp != '\n');
	fprintf(output_file,"\n");
	size_top = i;

	i = 0;
	do
	{
		fscanf(infile, "%c", &temp);
		if (temp != '\n' && temp != 'S')
		{
			seq[1][i] = temp;
			fprintf(output_file, "%c", temp);
			i++;
		}
	} while (temp != '\n' && i < size_top);
	fprintf(output_file, "\n");
}

void check_mutation(char seq[2][15], char seq2[2][15], FILE *output_file)
{
	int j = 0;
	do
	{
		if ((seq[0][j] != seq2[0][j]) || (seq[1][j] != seq2[1][j]))
		{
			if (((seq[0][j] + seq[1][j]) == (seq2[0][j] + seq2[1][j])))
			{
				fprintf(output_file, "pairs are flipped at pair: %d \n", j+1);
				j++;
			}
			else
			{
				fprintf(output_file, "Pairs are mismatched at pair: %d \n", j+1);
				j++;
			}
		}
		else if ((seq[0][j] == seq2[0][j]) && (seq[1][j] == seq2[1][j]))
		{
			j++;
		}
	} while (j < 15);
}