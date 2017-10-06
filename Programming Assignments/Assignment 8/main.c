/*Programmer: Jeffery Fonda
Class: CptS 121, Fall 2014; Lab Section 5
Programming Assignment: Assignment 8
Date: December 5, 2014
Description: This program contains several interview like functions.
*/

#include "header.h"

int main(void)
{
	char destination_arr[50] = { 'I', 'm' }, source_arr[50] = { 'G', 'r', 'o', 'o', 't' };
	unsigned int n = 0;
	int sum = 0;
	char*arr_bubble[5];
	int list[5] = { '1', '3', '4', '5', '6' }, target = 0;
	char string1[100] = { "Roses are grey, violets are grey, everything is grey. I'm a dog" };
	int number_array[] = { 5, 7, 16, 21, 42, 54 }, num_items = 6;
	int found = 0, index = 0;
	Occurrences num_occurrences[100] = { 0 };
	int answer_pal = 0;
	char *str_pal[] = {"racecar"};
	int lenght = 6, i = 0;
	int prob5_n = 0, ans_5 = 0;
	char str_bubble1[50] = "Programming";
	char str_bubble2[50] = "isnotthatfun";
	char str_bubble3[50] = "itmakesmethinkwaytoomuch";
	char str_bubble4[50] = "blahblahblahblah";
	char str_bubble5[50] = "windowsvistaforthewin";

	srand((unsigned int)time(NULL));

	// My String Cat

	my_str_cat (destination_arr, source_arr);

	// Bubble Sort

	arr_bubble[0] = str_bubble1;
	arr_bubble[1] = str_bubble2;
	arr_bubble[2] = str_bubble3;
	arr_bubble[3] = str_bubble4;
	arr_bubble[4] = str_bubble5;

	bubble_sort(arr_bubble, 5); 

	printf("%s\n", arr_bubble[0]);
	printf("%s\n", arr_bubble[1]);
	printf("%s\n", arr_bubble[2]);
	printf("%s\n", arr_bubble[3]);
	printf("%s\n", arr_bubble[4]);

	// Sum Primes

	prob5_n = (rand() % 10);
	printf("Initial n: %d\n", prob5_n);
	ans_5 = sum_primes(prob5_n);
	printf("The sum of the primes is: %d\n", ans_5);

	// Is Palindrome

	answer_pal = is_palindrome (str_pal, lenght, i); 
	printf("If answer is 1 it is a palindrome, if it is 1 than it is a palindrome %d\n", answer_pal);

	// Binary Search

	binary_search(number_array, num_items, &found, &index);

	// Maximum Occurences

	maximum_occurences(string1);

	// Smallest Sum Sequence

	smallest_sum_sequence(number_array, num_items);

	return 0;
}