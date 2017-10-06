#include "header.h"

void program (char option, char initials[], FILE* output_file, int difficulty, int points)
{
	do {
		system ("cls");
		printf ("a. How to use this program.\n");
		printf ("\n");
		printf ("b. Enter initials.\n");
		printf ("\n");
		printf ("c. Select difficulty.\n");
		printf ("\n");
		printf ("d. Change difficulty.\n");
		printf ("\n");
		printf ("e. Save and Quit.\n\n");

		printf ("Please select option:\n");
		scanf ("%c", &option);

		switch (option) {
		case 'a':	display_how_to();
		break;
		case 'b':	get_initials(initials, output_file);
		break;
		case 'c':	select_difficulty(option, initials, output_file, difficulty, points);
		break;
		case 'd':	select_difficulty(option, initials, output_file, difficulty, points);
		break;
		case 'e':	write_points_to_file (points, output_file);
					printf ("Saving and Exiting program...\n");
					exit(0);
		default: printf ("Invalid input.\n");
		}
		system ("pause");
		system ("cls");
	} while (option != 'e');
}

void display_how_to (void)
{
	printf ("\n");
	printf ("This program generates math problems based on the difficulty selected.\n");
	printf ("There are five different difficulty settings: \n");
	printf ("	-Easy: Includes addition and subtraction problems\n");
	printf ("	-Fair: Includes multiplication problems\n");
	printf ("	-Intermediate: Includes division problems\n");
	printf ("	-Hard: Includes a mix of addition, subtraction, multiplication, and division problems\n");
	printf ("	-Impossible: addition/subtraction/multiplation/division with positive and negative numbers\n");
	printf ("\n");
	printf ("Earn points for getting problems correct, loose points for getting problems wrong.\n");
	printf ("\n");
}

void get_initials (char initials[], FILE* output_file)
{
	printf ("Enter initials: \n");
	scanf ("%s", initials);

	printf ("Initials entered are: %s\n", initials);
	fprintf (output_file, "%s", initials);

	return;
}

void select_difficulty (char option, char initials[], FILE* output_file, int difficulty, int points)
{
	do {
		printf ("\n");
		printf ("1. Easy\n");
		printf ("\n");
		printf ("2. Fair\n");
		printf ("\n");
		printf ("3. Intermediate\n");
		printf ("\n");
		printf ("4. Hard\n");
		printf ("\n");
		printf ("5. Impossible\n");
		printf ("\n");
		printf ("6. Return to Main Menu\n");
		printf ("\n");

		printf ("Please select difficulty or menu: \n");
		scanf ("%d", &difficulty);

		switch (difficulty) {
		case 1: easy_problems(points);
		break;
		case 2: fair_problems(points);
		break;
		case 3: intermediate_problems(points);
		break;
		case 4: hard_problems(points);
		break;
		case 5: impossible_problems(points);
		break;
		case 6: program (option, initials, output_file, difficulty, points);
		default: printf ("Invalid input.\n");
		}
		system ("pause");
		system ("cls");
	} while (difficulty != 5);
}

int easy_problems (int points)
{
	int answer = 0, current_points = 0;
	char opperand = '\0';
	Variables V;

	current_points = points;

	system ("cls");
	printf ("You selected easy problems.\n"); 
	printf ("These consist of simple addition and subtraction problems.\n");
	printf ("You get ONE point for a correct answer.\n");
	printf ("You loose ONE point for an incorrect answer.\n\n");

	do {
		V.a = rand () % 10;
		V.b = rand () % 10;
		opperand = '+';

		if (current_points >= points + 5)
		{
			opperand = '-';
			printf ("%d %c %d = ?\n", V.a, opperand, V.b);
			scanf ("%d", &answer);
			if (answer == (eval_easy_problems (V.a, V.b, opperand)))
				{
					current_points++;
					printf ("Answer correct, +1 point.\n\n");
				}
				else
				{
					current_points--;
					printf ("Answer incorrect, -1 point.\n\n");
				}
		}
		printf ("%d %c %d = ?\n", V.a, opperand, V.b);
		scanf ("%d", &answer);
		if (answer == (eval_easy_problems (V.a, V.b, opperand)))
			{
				current_points++;
				printf ("Answer correct, +1 point.\n\n");
			}
			else
			{
				current_points--;
				printf ("Answer incorrect, -1 point.\n\n");
			}
	} while (current_points <= (points + 10));

	printf ("Your received %d points for this section.\n\n", current_points);

	points = points + current_points;

	printf ("Your total points are: %d\n", points);

	return points;
}

int eval_easy_problems (int a, int b, char opperand)
{
	int answer = 0;

	switch (opperand) {
		case '+':	answer = a + b;
		break;
		case '-':	answer = a - b;
		break;	
	}
	return answer;
}

int fair_problems (int points)
{
	int answer = 0, current_points = 0;
	Variables V;

	current_points = points;

	system ("cls");
	printf ("You selected fair problems.\n"); 
	printf ("These consist of simple multiplication problems.\n");
	printf ("You get TWO points for a correct answer.\n");
	printf ("You loose TWO points for an incorrect answer.\n\n");

	do {
		if (current_points >= points + 10)
		{
			V.a = rand () % 20;
			V.b = rand () % 10;
		}
		else
		{
			V.a = rand () % 10;
			V.b = rand () % 10;
		}

		printf ("%d * %d = ?\n", V.a, V.b);
		scanf ("%d", &answer);
			if (answer == V.a * V.b)
			{
				current_points = current_points + 2;
				printf ("Answer correct, +2 points.\n\n");
			}
			else
			{
				current_points = current_points - 2;
				printf ("Answer incorrect, -2 point.\n\n");
			}
	} while (current_points <= (points + 20));

	printf ("Your received %d points for this section.\n\n", current_points);

	points = points + current_points;

	printf ("Your total points are: %d\n", points);

	return points;
}

int intermediate_problems (int points)
{
	int answer = 0, current_points = 0;
	Variables V;
	Answers A;

	system ("cls");
	printf ("You selected intermediate problems.\n"); 
	printf ("These consist of simple division problems.\n");
	printf ("You get THREE points for a correct answer.\n");
	printf ("You loose THREE points for an incorrect answer.\n\n");

	do {
		V.a = rand () % 50;
		V.b = rand () % 10;

		printf ("%d / %d = ?\n", V.a, V.b);
		scanf ("%d %d", &A.a, &A.b);
			if ((A.a == V.a / V.b) && (A.b == V.a % V.b))
			{
				current_points = current_points + 3;
				printf ("Answer correct, +3 points.\n\n");
			}
			else
			{
				current_points = current_points - 3;
				printf ("Answer incorrect, -3 point.\n\n");
			}

	} while (current_points <= (points + 30));

	printf ("Your received %d points for this section.", current_points);

	points = points + current_points;

	printf ("Your total points are: %d\n", points);

	return points;
}

int hard_problems (int points)
{
	int answer = 0, current_points = 0;
	char opperand[] = {'+', '-', '*'}, op1 = '\0', op2 = '\0';
	Variables V;

	current_points = points;

	system ("cls");
	printf ("You selected hard problems.\n"); 
	printf ("These consist of a mix of addition, subtraction, multiplication,\n");
	printf ("and division problems, with positive and negative \n");
	printf ("single digit operands and up to three terms only.\n");
	printf ("You get FOUR points for a correct answer.\n");
	printf ("You loose FOUR points for an incorrect answer.\n\n");

	do {
		V.a = rand () % 10;
		V.b = rand () % 10;
		V.c = rand () % 10;

		if (current_points >= points + 20)
		{
			op1 = opperand[rand () % 3];
			op2 = opperand[rand () % 3];
		}
		else
		{
			op1 = opperand[rand () % 2];
			op2 = opperand[rand () % 2];
		}

		printf ("%d %c %d %c %d = ?\n", V.a, op1, V.b, op2, V.c);
		scanf ("%d", &answer);
		if (answer == eval_hard_problems(V.a, V.b, V.c, op1, op2))
			{
				current_points = current_points + 4;
				printf ("Answer correct, +4 points.\n\n");
			}
			else
			{
				current_points = current_points - 4;
				printf ("Answer incorrect, -4 point.\n\n");
			}
	} while (current_points <= (points + 40));

	printf ("Your received %d points for this section.", current_points);

	points = points + current_points;

	printf ("Your total points are: %d\n", points);

	return points;
}

int eval_hard_problems (int a, int b, int c, char op1, char op2)
{
	int answer = 0;

	if (op2 == '*')
	{
		if (op1 == '*')
		{
			answer = a * b * c;
		}
		if (op1 == '+')
		{
			answer = b * c + a;
		}
		if (op1 == '-')
		{
			answer = b * c - a;
		}
	}
	if (op1 == '+')
	{
		if (op2 == '+')
		{
			answer = a + b + c;
		}
		if (op2 == '-')
		{
			answer = a + b - c;
		}
	}
	if (op1 == '-')
	{
		if (op2 == '-')
		{
			answer = a - b - c;
		}
		if (op2 == '+')
		{
			answer = a - b + c;
		}
	}
	return answer;
}

int impossible_problems (int points)
{
	int answer = 0, current_points = 0;
	char opperand[] = {'+', '-', '*', '%'}, op1 = '\0', op2 = '\0', op3 = '\0';
	Variables V;

	current_points = points;

	system ("cls");
	printf ("You selected impossible problems.\n"); 
	printf ("These consist of a mix of addition, subtraction, multiplication,\n");
	printf ("and division problems, with positive and negative \n");
	printf ("two and three digit operands and up to four terms only.\n");
	printf ("You get FIVE points for a correct answer.\n");
	printf ("You loose FIVE points for an incorrect answer.\n");

	do {
		V.a = rand () % 100;
		V.b = rand () % 100;
		V.c = rand () % 100;
		V.d = rand () % 100;

		if (current_points >= points + 15)
		{
			op1 = opperand[rand () % 3];
			op2 = opperand[rand () % 3];
		}
		if (current_points >= points + 25)
		{
			op1 = opperand[rand () % 4];
			op2 = opperand[rand () % 4];
		}
		if (current_points >= points + 35)
		{
			op1 = opperand[rand () % 5];
			op2 = opperand[rand () % 5];
		}
		else
		{
			op1 = opperand[rand () % 2];
			op2 = opperand[rand () % 2];
		}

		printf ("%d %c %d %c %d %c %d = ?\n", V.a, op1, V.b, op2, V.c, op3, V.d);
		scanf ("%d", &answer);
			if (answer == (eval_impossible_problems (V.a, V.b, V.c, V.d, op1, op2, op3)))
			{
				points = points + 5;
				printf ("Answer correct, +5 points.\n\n");
			}
			else
			{
				points = points - 5;
				printf ("Answer incorrect, -5 point.\n\n");
			}

	} while (points != (points + 50));

	printf ("Your received %d points for this section.\n", &points);

	return points;
}

int eval_impossible_problems (int a, int b, int c, int d, char op1, char op2, char op3)
{
	int answer = 0;

	if (op3 == '*')
	{
		if (op2 == '*')
		{
			if (op1 == '*')
			{
				answer = a * b * c * d;
			}
			if (op1 == '%')
			{
				answer = a % b * c * d;
			}
			if (op1 == '+')
			{
				answer = a + b * c * d;
			}
			if (op1 == '-')
			{
				answer = a - b * c * d;
			}
		}
		if (op2 == '%')
		{
			if (op1 == '*')
			{
				answer = a * b % c * d;
			}
			if (op1 == '%')
			{
				answer = a % b % c * d;
			}
			if (op1 == '+')
			{
				answer = a + b % c * d;
			}
			if (op1 == '-')
			{
				answer = a - b % c * d;
			}
		}
	}
	return answer;
}

int write_points_to_file (int points, FILE* output_file)
{
	printf ("The total points you received were: %d", points);
	fprintf (output_file, "Total Points: %d", points);

	return points;
}