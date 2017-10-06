#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct occurrences
{
	int num_occurrences[100];
	double frequency;
} Occurrences;

char my_str_cat(char*dest_arr, char*source_arr);
void bubble_sort(char* arr[], int num);
void binary_search(int list[], int size, int *found_ptr, int *index_ptr);
int is_prime(int n);
int sum_primes(int n);
int are_char_same(char *str[], int *length, int i);
int is_palindrome(char *str[], int length, int i);
void maximum_occurences(char *string1);
int smallest_sum_sequence(int number_array[], int num_items);

#endif