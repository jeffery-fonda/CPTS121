/*Programmer: Jeffery Fonda
Class: CptS 121, Fall 2014; Lab Section 5
Programming Assignment: Assignment 3
Date: September 20, 2014
Description: This program asses the values based on input from a file.
*/


#include "Header.h"

int main(void)
{
	FILE *input_file = NULL, *output_file = NULL;
	int Student_ID_1 = 0, Student_ID_2 = 0, Student_ID_3 = 0, Student_ID_4 = 0, Student_ID_5 = 0;
	double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0, sum_gpa = 0.0;
	int class_standing1 = 0, class_standing2 = 0, class_standing3 = 0, class_standing4 = 0, class_standing5 = 0, sum_class_standing = 0;
	double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0, sum_age = 0.0;
	double mean_gpa = 0.0, mean_class_standings = 0.0, mean_age = 0.0;
	double deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0;
	double variance = 0.0;
	double standard_deviation = 0.0;
	double max_gpa = 0.0, min_gpa = 0.0;
	input_file = fopen("data_file.dat","r");
	output_file = fopen("output_file.dat", "w");

	// Student 1

	Student_ID_1 = read_integer(input_file);
	printf("Student1 ID: %d\n", Student_ID_1);
	gpa1 = read_double(input_file);
	printf("gpa1: %lf\n", gpa1);
	class_standing1 = read_integer(input_file);
	printf("class_standing1: %d\n", class_standing1);
	age1 = read_double(input_file);
	printf("age1: %lf\n", age1);

	// Student 2

	Student_ID_2 = read_integer(input_file);
	printf("Student2 ID: %d\n", Student_ID_2);
	gpa2 = read_double(input_file);
	printf("gpa2: %lf\n", gpa2);
	class_standing2 = read_double(input_file);
	printf("class_standing2: %d\n", class_standing2);
	age2 = read_double(input_file);
	printf("age2: %lf\n", age2);

	// Student 3

	Student_ID_3 = read_integer(input_file);
	printf("Student3 ID: %d\n", Student_ID_3);
	gpa3 = read_double(input_file);
	printf("gpa3: %lf\n", gpa3);
	class_standing3 = read_double(input_file);
	printf("class_standing3: %d\n", class_standing3);
	age3 = read_double(input_file);
	printf("age3: %lf\n", age3);

	// Student 4

	Student_ID_4 = read_integer(input_file);
	printf("Student4 ID: %d\n", Student_ID_4);
	gpa4 = read_double(input_file);
	printf("gpa4: %lf\n", gpa4);
	class_standing4 = read_double(input_file);
	printf("class_standing4: %d\n", class_standing4);
	age4 = read_double(input_file);
	printf("age4: %lf\n", age4);

	// Student 5

	Student_ID_5 = read_integer(input_file);
	printf("Student5 ID: %d\n", Student_ID_5);
	gpa5 = read_double(input_file);
	printf("gpa5: %lf\n", gpa5);
	class_standing5 = read_double(input_file);
	printf("class_standing5: %d\n", class_standing5);
	age5 = read_double(input_file);
	printf("age5: %lf\n", age5);

	// Calculate Sum GPAs

	sum_gpa = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	printf("Sum of Gpas: %lf\n", sum_gpa);

	fprintf(output_file, "%lf\n", sum_gpa);

	// Calculate Class Standing

	sum_class_standing = calculate_sum(class_standing1, class_standing2, class_standing3, class_standing4, class_standing5);
	printf("Sum of Class Standings: %d\n", sum_class_standing);

	fprintf(output_file, "%d\n", sum_class_standing);

	// Calculate Sum Ages

	sum_age = calculate_sum(age1, age2, age3, age4, age5);
	printf("Sum of Ages: %lf\n", sum_age);

	fprintf(output_file, "%lf\n", sum_age);

	// Mean GPA

	mean_gpa = calculate_mean(sum_gpa, 5);
	printf("Mean Gpa: %lf\n", mean_gpa);

	fprintf(output_file, "%lf\n", mean_gpa);

	// Mean Class Standing

	mean_class_standings = calculate_mean(sum_class_standing, 5);
	printf("Mean Class Standing: %lf\n", mean_class_standings);

	fprintf(output_file, "%lf\n", mean_class_standings);
	
	// Mean Age

	mean_age = calculate_mean(sum_age, 5);
	printf("Mean of Ages: %lf\n", mean_age);

	fprintf(output_file, "%lf\n", mean_age);

	// Deviation of GPA

	deviation1 = calculate_deviation(gpa1, mean_gpa);
	deviation2 = calculate_deviation(gpa2, mean_gpa);
	deviation3 = calculate_deviation(gpa3, mean_gpa);
	deviation4 = calculate_deviation(gpa4, mean_gpa);
	deviation5 = calculate_deviation(gpa5, mean_gpa);

	// Variance of GPA

	variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 4);

	// Standard Deviation
	
	standard_deviation = calculate_standard_deviation(variance);
	
	fprintf(output_file, "%lf\n", standard_deviation);

	// Max GPA

	max_gpa = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);

	fprintf(output_file, "%lf\n", max_gpa);

	// Min GPA

	min_gpa = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);

	fprintf(output_file, "%lf\n", min_gpa);

	return 0;
}