#include<stdio.h>

int carbon();
int ackermann();
int newton();

int main(){

	int choice = 0;

	printf("Select one of the question below:\n");

        printf("1. Carbon\n");
        printf("2. Anckermann\n");
        printf("3. Newton\n");

	scanf("%d", &choice);

	if (choice == 1)
	{
		carbon();
	}
	else if (choice == 2)
	{
		ackermann();
	}
	else if (choice == 3)
	{
		newton();
	}
	else
	{
		printf("Sorry, there are no other choices avilable");

	}

return 0;
}

