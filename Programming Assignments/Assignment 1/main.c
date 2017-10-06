/*	Programmer: Jeffery Fonda
	Class: CptS 121, Fall 2014; Lab Section 5
	Programming Assignment: Assingment 1
	Date: September 8, 2014
	Description: This program will be used to solve several different equations. 
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main (void)
{
	// Variables
	
	int R1 = 0, R2 = 0, R3 = 0, series_resistance = 0; // Resister variables and total resistance
	double item_cost = 0.0, sales_tax = 0.0, total_cost = 0; // Item cost and sales tax defined
	int length = 0, width = 0, height = 0, volume_pyramid = 0; // Variables for pyramid defined
	double R1a = 0, R2a = 0, R3a = 0; // New resister variables defined
	double parallel_resistance = 0; // Parallel Resistance defined
	char letter = '\0'; // Character input defined
	int number = 0; //Shift defined
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0; // Points defined
	double distance = 0.0; // Distance defined
	int y1a = 0, x1a = 0, z = 0, a = 0; // Variables defined for final computation
	int newASCII = 0; // New ASCII variable defined
	float newY = 0; // New X variable defined
	char response;
	
	// Computation 1

	printf ("Please enter three numbers from your resisters seperated by a space: "); // Prompt for user input of resisters
	scanf ("%d%d%d", &R1, &R2, &R3); // Address of resisters

	series_resistance = R1 + R2 + R3; //Equation 1

	printf ("series_resistance: %d\n", series_resistance); 

	// Computation 2

	printf ("Please enter item cost and sales tax seperated by a space (Example: 32.99 0.08): "); // Prompt for item cost and sales tax
	scanf ("%lf%lf", &item_cost, &sales_tax); // Address of item cost and sales tax

	total_cost = (item_cost * sales_tax) + item_cost; // Equation 2

	printf ("total_cost: %.2lf\n", total_cost);

	// Computation 3

	printf ("Please enter the length, width and height of a pyramid seperated by a space: "); // Prompt user for pyramid's dimensions
	scanf ("%d%d%d", &length, &width, &height); // Address for variables

	volume_pyramid = (length * width * height) / 3; // Equation 3

	printf ("volume_pyramid: %d\n", volume_pyramid);

	// Computation 4

	printf ("Please enter three new vaules for the three resisters seperated by a space: "); // Prompt user for new resister values
	scanf ("%lf%lf%lf", &R1a, &R2a, &R3a); // Address for new resister variables

	parallel_resistance = 1 / (double)(1 / R1a + 1 / R2a + 1 / R3a); // Equation 4
	printf ("parallel_resistance: %lf\n", parallel_resistance);

	// Computation 5

	printf ("Please enter number to shift character: "); // Prompt user for number
	scanf ("%d", &number); // Address for number

	printf ("Number: %d\n", number);

	printf ("Please enter character to be encoded: "); // Prompt user for character
	scanf (" %c", &letter); // Address for character

	printf ("ASCII value: %d\n", letter);

	printf ("Character: %c\n", letter);

	newASCII = (letter-65) + 97 - number;
	printf ("Your new character is: %c\n", (char)newASCII);

	// Computation 6

	printf ("Please enter values for x1, x2, y1, y2: "); // Prompt user to input coordinates
	scanf ("%d%d%d%d", &x1, &x2, &y1, &y2);

	distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2)); // Equation 6

	printf ("distance: %lf\n", distance);

	// Computation 7 - Credits to my friend Cole Markusen for helping me with computation 7.

	printf ("Please enter values for y, z, x, and a: "); // Prompt user to input variables
	fseek(stdin,0,SEEK_END); // clear buffer
	scanf ("%d%d%d%d", &y1a, &z, &x1a, &a);

	if (a % 2 == 0) {
		printf ("Cannot divide by zero you buffoon!");
	}
	else {
		float newY = y1a / ((float)3 / (float)17) - z + x1a / (float)(a % 2) + PI; // Equation 7
		printf ("new value for y: %f\n", newY);
	}

	return 0;
}