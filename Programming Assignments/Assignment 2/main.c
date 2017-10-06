/*	Programmer: Jeffery Fonda
	Class: CptS 121, Fall 2014; Lab Section 5
	Programming Assignment: Assingment 2
	Date: September 16, 2014
	Description: This program will be used to solve several different equations. 
*/

#include "equations.h"

int main (void) 
{
	int r1 = 0, r2 = 0, r3 = 0; // Resister variables and total resistance
	double item_cost = 0.0, sales_tax_rate = 0.0; // Item cost and sales tax defined
	double length = 0.0, width = 0.0, height = 0.0; // Variables for pyramid defined
	double r1a = 0, r2a = 0, r3a = 0; // New resister variables defined
	char plaintext_character = '\0'; // Character input defined
	int shift_key = 0; //Shift defined
	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0; // Points defined
	double distance = 0.0; // Distance defined
	int y1a = 0, x1a = 0, z = 0, a = 0; // Variables defined for final computation
	
	// Computation 1

	printf ("Enter values for resisters: ");
	scanf("%d%d%d", &r1, &r2, &r3);

	printf("Total series resistance: %d\n", calculate_series_resistance(r1, r2, r3));

	// Computation 2

	printf("Please enter item cost and sales tax seperated by a space (Example: 32.99 0.08): "); // Prompt for item cost and sales tax
	scanf("%lf%lf", &item_cost, &sales_tax_rate); // Address of item cost and sales tax

	printf("Total cost: %.2lf\n", calculate_total_sales_tax(sales_tax_rate, item_cost));

	// Computation 3

	printf("Please enter the length, width and height of a pyramid seperated by a space: "); // Prompt user for pyramid's dimensions
	scanf("%lf%lf%lf", &length, &width, &height); // Address for variables

	printf("Volume: %.2lf\n", calculate_volume_pyramid(length, width, height));

	// Computation 4

	printf("Please enter three new vaules for the three resisters seperated by a space: "); // Prompt user for new resister values
	scanf("%lf%lf%lf", &r1a, &r2a, &r3a); // Address for new resister variables

	printf("Parallel resistance: %.2lf\n", calculate_parallel_resistance(r1a, r2a, r3a));

	// Computation 5

	printf("Please enter number to shift character: "); // Prompt user for number
	scanf("%d", &shift_key); // Address for number

	printf("Number: %d\n", shift_key);

	printf("Please enter character to be encoded: "); // Prompt user for character
	scanf(" %c", &plaintext_character); // Address for character

	printf("ASCII value: %d\n", plaintext_character);

	printf("Character: %c\n", plaintext_character);

	printf("Your new character is: %c\n", perform_character_encoding(plaintext_character, shift_key));

	// Computation 6

	printf("Please enter values for x1, x2, y1, y2: "); // Prompt user to input coordinates
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

	printf("Distance: %.2lf\n", calculate_distance_between_2pts(x1, x2, y1, y2));

	// Computation 7

	printf("Please enter values for y, z, x, and a: "); // Prompt user to input variables
	fseek(stdin, 0, SEEK_END); // clear buffer
	scanf("%d%d%d%d", &y1a, &z, &x1a, &a);

	if (a % 2 == 0) {
		printf("Cannot divide by zero you buffoon!");
	}
	else {
		printf("new value for y: %f\n", calculate_general_equation(a, x1a, y1a, z));
	}

	return 0;
}