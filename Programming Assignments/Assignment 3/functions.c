#include "Header.h"

double read_double(FILE *input_file)
{
	double number = 0.0;
	fscanf (input_file, "%lf", &number);
	return number;
}

int read_integer(FILE *input_file)
{
	int number2 = 0.0;
	fscanf(input_file, "%d", &number2);
	return number2;
}

double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	return (number1 + number2 + number3 + number4 + number5);
}

double calculate_mean(double sum, int number)
{
	return (sum/number);
}

double calculate_deviation(double number, double mean)
{
	return ((number - mean)*(number - mean));
}

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	return ((deviation1 + deviation2 + deviation3 + deviation4 + deviation5)/4);
}

double calculate_standard_deviation(double variance)
{
	return (variance);
}

double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double max = 4.0;

	max = number1;

	if (number2 > max)
	{
		max = number2;
	}
	if (number3 > max)
	{
		max = number3;
	}
	if (number4 > max)
	{
		max = number4;
	}
	if (number5 > max)
	{
		max = number5;
	}
	return max;
}

double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double min = 0.0;

	min = number1;

	if (number2 < min)
	{
		min = number2;
	}
	if (number3 < min)
	{
		min = number3;
	}
	if (number4 < min)
	{
		min = number4;
	}
	if (number5 < min)
	{
		min = number5;
	}
	return min;
}