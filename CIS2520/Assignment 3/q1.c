/*Junyan Chen
  1026737
  October 15, 2018
  Assignment 2: Question 1
  jchen52@uoguelph.ca
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct carStructure{

        int mileAge;
        int returnDate;
        char* plateNumber;
        double charge;

        struct carStucture *next;

}carStructures;

carStructures *newCar();
void returnCar();
void returnCarToPair();
void transferCar();
void firstAvailableCar();
int printMenu(void);

/*creating a linked list */
carStructures *createCar(int mileAge, int returnDate, double charge, char* plateNumber)
{

	carStructures *newCar = (carStructures *)malloc(sizeof(carStructures));

	newCar->plateNumber = (char *)malloc(sizeof(char));

	/*if the new car is empty, is it an error*/
	if(newCar == NULL)
		{
			return NULL;
		}


	newCar->mileAge = mileAge;
	newCar->returnDate = returnDate;
	newCar->charge = charge;
	strcpy(newCar->plateNumber, plateNumber);
	newCar->next = NULL;


	return newCar;
}


int main(){

	int userInput = 0;

	userInput = printMenu();


	scanf("%d", &userInput);

	if(userInput == 1)
	{
		newCar();

	}
	else if(userInput == 2)
	{
		returnCarToPair();
	}

	else if(userInput == 3)
	{
		transferCar();
	}

	else if(userInput == 4)
	{
		transferCar();
	}

	else if(userInput == 5)
	{
		firstAvailableCar();
	}

	else if(userInput == 6)
	{

	}

	else if(userInput == 7)
	{
		exit(0);
	}

return 0;

}

/*adding a new car to the available-for-rent list*/
carStructures *newCar()
{
	int mileage = 0;
        char plateNumber[100];

	printf("Enter the milage: ");
	scanf("%d", &mileage);

	printf("Enter the plate number: ");
	scanf("%s", plateNumber);

	return 0;
}

/*add a returned car to the available-for-rent list*/
void returnCar()
{

	int mileage = 0;
        char plateNumber[100];

        printf("Enter the milage: ");
        scanf("%d", &mileage);

        printf("Enter the plate number: ");
        scanf("%s", plateNumber);

}

/*transfer a car from the repair list to the available-for-rent list*/
void returnCarToPair()
{

	int mileage = 0;
        char plateNumber[100];

        printf("Enter the milage: ");
        scanf("%d", &mileage);

        printf("Enter the plate number: ");
        scanf("%s", plateNumber);

}

/*add a returned car to the repair list*/
void transferCar()
{
        char plateNumber[100];

        printf("Enter the plate number: ");
        scanf("%s", plateNumber);

}

/*rent the first available car*/
void firstAvailableCar()
{
	int returnDate;

	printf("Please enter the return date (YYMMDD):");
	scanf("%d", &returnDate);

}

/*print all the menus*/
int printMenu(void)
{

	printf("1. Add a new car to the available-for-rent list.\n");
	printf("2. Add a returned car to the availabe-for-rent list.\n");
	printf("3. Add a returned car to the repair list.\n");
	printf("4. Transfer a car from the repair list to the availabe-for-rent list.\n");
	printf("5. Rent the first available car.\n");
	printf("6. Print all the lists.\n");
	printf("7. Quit\n");
	printf("Choice:");

	return 0;
}

