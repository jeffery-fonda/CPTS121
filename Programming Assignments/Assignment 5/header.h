#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

void readseq(char seq[2][15], FILE *infile);
void readseq_2(char seq[2][15], FILE *infile, FILE *output_file);
void check_mutation(char seq[2][15], char seq2[2][15], FILE *output_file);

#endif 