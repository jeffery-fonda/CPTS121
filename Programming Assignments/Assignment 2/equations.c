// Function File

#include "equations.h"

#define PI 3.14159


int calculate_series_resistance(int r1, int r2, int r3)
{
	return r1 + r2 + r3; // Equation 1
}

double calculate_total_sales_tax(double sales_tax_rate, double item_cost) 
{
	return (item_cost * sales_tax_rate) + item_cost; // Equation 2
}

double calculate_volume_pyramid(double length, double width, double height) 
{
	return (length * width * height) / 3; // Equation 3
}

double calculate_parallel_resistance(int r1a, int r2a, int r3a) 
{
	return 1 / (double)(1 / r1a + 1 / r2a + 1 / r3a); // Equation 4
}

char perform_character_encoding(char plaintext_character, int shift_key) 
{
	return (plaintext_character-65) + 97 - shift_key; // Equation 5
}

double calculate_distance_between_2pts(double x1, double x2, double y1, double y2) 
{
	return sqrt(pow((x1-x2),2) + pow((y1-y2),2)); // Equation 6
}

double calculate_general_equation(int a, double x1a, double y1a, double z) 
{
	return y1a / ((float)3 / (float)17) - z + x1a / (float)(a % 2) + PI; // Equation 7
}