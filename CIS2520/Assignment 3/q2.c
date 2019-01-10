/*Junyan Chen
  1026737
  October 15,2018
  Assignment 2: Question 2
  jchen52@uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

/*creating a stack structure*/
typedef struct stack
{
	int top;
	double array[SIZE];

}stack;


void newStack(stack *s);
void push(stack *s, double number);
double pop(stack *s);

int main(int argc, char *argv[])
{
	stack stacks;

	int i = 0;
	int length = 0;
	double num1 = 0;
	double num2 = 0;
	double finalAnswer = 0;

	char array[50];
	char character;
	length = strlen(array);


	if (argc != 2)

	{
		printf("Error, add an argument to the command line argument!\n");
		return 1;

	}

	strcpy(array, argv[1]);		/*copying the expression into the buffer*/

	length = strlen(array);		/*finding the length */

	newStack(&stacks);		/*fucntion call*/

	for(i = 0; i <= length; i++){

		character = array[i];

		if(isdigit(character))		/*if it is a number or a string*/
		{
			push(&stacks, character - '0');
		}
		else{
			/*adding vlaues for num1 and num2*/
			num1 = pop(&stacks);
			num2 = pop(&stacks);

			/*problem solving*/
			if(character == '+')
			{

				finalAnswer = num1 + num2;

			}

			if(character == '-')
			{

				finalAnswer = num1-num2;

			}

			if(character == '*')
			{

				finalAnswer = num1 * num2;

			}

			if(character  == '/')
			{

				finalAnswer = num1 / num2;
			}

			push(&stacks, finalAnswer);	/*push the final answer back onto the stack*/
		}

	}

	printf("The result is %0.2lf\n",finalAnswer);
	return 0;
}

/*initialize the top of the stack to be 0*/
void newStack(stack *s)
{
	s->top = 0;
}


/*Got this function off the lecture slides*/
void push(stack *s, double number)
{
	/*adding a value into the stack*/
	if(s->top >= SIZE-1)
	{
		printf("Stack is full\n");

	}

	s->top++;
	s->array[s->top] = number;
}

/*Got this function off the lecture slides*/
double pop(stack *s)
{

	double number = 0;

	/*removing the top value off the stack*/
	if(s->top < 0)
	{

		printf("Stack is empty\n");
		return 0;

	}else{

		number = s->array[s->top];
		s->top--;
	return number;
	}
}

