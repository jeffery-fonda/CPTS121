#include "header.h"

char my_str_cat(char *dest_arr, char *source_arr)
{
	char character = '\0';
	int i = 0, n = 0;
	for (i = 0; dest_arr[i] != '\0'; i++)
	{
		dest_arr[i];
	}
	n = i;
	for (i = 0; source_arr[i] != '\0'; i++)
	{
		character = source_arr[i];
		dest_arr[(n) + i] = character;
	}
	printf("%s\n", dest_arr);

	return (*dest_arr);
}

void bubble_sort(char* arr[], int num)
{
	char* temp;
	int U;
	int C;
	int compare = 0;
	
	for (U = (num - 1); 0 <= U; U--)
	{
		for (C = 1; C <= U; C++)
		{
			compare = strcmp(arr[C], arr[C-1]);
			if (compare == -1)
			{
				temp = arr[C];
				arr[C] = arr[C - 1];
				arr[C - 1] = temp;
			}
		}
	}
}

int is_palindrome(char *str, int length, int i)
{
	if (i > length-1)
	{
		return 1;
	}
	else
	{
		if (str[i] == str[length - 1])
		{
			i++;
			length--;
			return is_palindrome(str, length, i);
		}
		else if (str[i] != str[length - 1])
		{
			printf("NOT a palindrome!!");
			return 0;
		}
	}
	return 1;
}

int are_char_same(char *str[], int *length, int i)
{
	if (*str[i] == *str[*length-1])
	{
		return 1;
	}
	else if (*str[i] != *str[*length-1])
	{
		printf("NOT a palindrome!!");
		return 0;
	}
}

int is_prime(int n)
{
	int mod = 0;

	for (mod = 2; mod < n; mod++)
	{
		if ((n % mod) == 0)
		{
			return 0;
		}
	}
	return n;
}

int sum_primes(int n)
{
	int num = 0;

	if (n == 2)
	{
		return 2;
	}
	else
	{
		num = is_prime(n);

		if (num == 0)
		{
			num = (0 + sum_primes(n - 1));
		}
		else
		{
			num = (num + sum_primes(n - 1));
		}
		return num;
	}
}

void binary_search(int number_array[], int num_items, int found_ptr, int index_ptr)
{
	int left_index = 0, right_index = num_items - 1, mid = 0, target = 0;

	printf("Enter item to be found: \n");
	scanf("%d", &target);

	found_ptr = 0;
	index_ptr = -1;

	for (left_index = 0, right_index = num_items - 1; (found_ptr == 0) && (left_index <= right_index);)
	{
		mid = (left_index + right_index) / 2;

		if (target == number_array[mid])
		{
			found_ptr = 1;
			index_ptr = mid;
		}
		else if (target > number_array[mid])
		{
			left_index = mid + 1;
		}
		else
		{
			right_index = mid - 1;
		}
	}
	if (index_ptr >= 1)
	{
		printf("Item %d found at location #%d\n", target, index_ptr);
	}
	else
	{
		printf("Item not found!\n");
	}
}

void maximum_occurences(char *string1, Occurrences occurrences)
{
	int i, j = 0, k = 0, l, max, index, flag = 0;
	double frequency = 0.0;
	char visited[100];
	int count[100] = { 0 };

	l = strlen(string1);

	for (i = 0; i < l; i++)
	{
		if (i == 0)
		{
			visited[j++] = string1[i];
			count[j - 1]++;
		}
		else
		{
			for (k = 0; k < j; k++)
			{
				if (string1[i] == visited[k])
				{
					count[k]++;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				visited[j++] = string1[i];
				count[j - 1]++;
			}
			flag = 0;
		}
	}
	for (i = 0; i < j; i++)
	{
		if ((i == 0) && (visited[i] != ' '))
		{
			max = count[i];
			continue;
		}
		if ((max < count[i]) && (visited[i] != ' '))
		{
			max = count[i];
			index = i;
		}
	}
	frequency = ((count[index]) / (double) l);

	printf("Max repeated character in the string: %c\n", visited[index]);
	printf("It occurs %d times.\n", count[index]);
	printf("Frequency: %.2lf\n", frequency);

	count == occurrences.num_occurrences;
	frequency == occurrences.frequency;
}

int smallest_sum_sequence(int number_array[], int num_items)
{
	int index = 0, sum = 0, min = 0;

	min = sum = number_array[0];

	for (index = 1; num_items < index; index++)
	{
		if (sum > 0)
		{
			sum = number_array[index];
		}
		else
		{
			sum += number_array[index];
		}
		if (sum >= min)
		{
			min = sum;
		}
	}
	printf("The smallest number: %d\n", sum);
	return min;
}