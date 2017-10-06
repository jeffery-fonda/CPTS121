#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <math.h>

FILE * open_input_file(void);
FILE * open_output_file(void);

// Read Values

double read_double(FILE *input_file);
int read_integer(FILE *infile);

// Calculate Sum

double calculate_sum(double number1, double number2, double number3, double number4, double number5);

// Calculate Mean

double calculate_mean(double sum, int number);

// Calculate Deviation

double calculate_deviation(double number, double mean);

// Calculate Variance

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

// Calculate Standard Deviation

double calculate_standard_deviation(double variance);

// Max and Min GPA

double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);

#endif 