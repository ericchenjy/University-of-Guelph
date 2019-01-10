/*
  Junyan Chen
  jchen52@uoguelph.ca
  Computer Science CIS*1500
  Question 5:. Write a program that stores multiplication tables from 1 to 9 in a 2-dimensional array.
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
int timesChartTable[9][9] = { {1,2,3,4,5,6,7,8,9},         //stores all the Multiplacation Table from number 1 to 81 insde a variable 
                              {2,4,6,8,10,12,14,16,18},
                              {3,6,9,12,15,18,21,24,27},
                              {4,8,12,16,20,24,28,32,36},
                              {5,10,15,20,25,30,35,40,45},
                              {6,12,18,24,30,36,42,48,54},
                              {7,14,21,28,35,42,49,56,63},
                              {8,16,24,32,40,48,56,64,72},
                              {9,18,27,36,45,54,63,72,81},
                            };
                            
char rowNames[10][10] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};    //stores the 10 rows name inside a vabirbale 
char choice = 'y';          //stores correct user choice 'y' inside a variable when asked for yes or no 
int userInput  = 0;         //user number choices for the Multiplacation Table
int i = 0;                  //loop index
int j = 0;                  //loop index

  // it will loop until if the user enter something else than 'y' 
  while (choice == 'y'){
    
    
	  printf("Enter zero (0) to see all multiplication tables from 1 - 9 OR\n");
	  printf("Enter a specific number between 1 and 9 to see its multiplication table\n");
	  printf("\n");
	  
	  //ask user to enter a number from the Multiplacation Table value between 1 and 9
	  printf("Enter a choice:");
	  scanf("%d",&userInput);
	  
	  printf("\n");
	  
	    //It will show all of the Multiplication Tables if the user enter 0
	    if(userInput == 0){
	    
		    printf("\t\t\tPrinting Multiplication Tables 1-9\n");
		    printf("\n");
		   
		    printf("*******************************************************************************\n");     //Printing the 80*
		    printf("\tOne\tTwo\tThree\tFour\tFive\tSix\tSeven\tEight\tNine\n");     // \t stand for a tab
		
		    	//print out the 10 rows of names and all of the Multiplication Tables between 1 and 9
		    	for(i = 0; i < 9; i++){
			  
			    printf("%s", rowNames[i] );
			    
			    for (j = 0; j < 9; j++){
			      
			        printf("\t%d", timesChartTable[i][j]);
			    }
			    printf("\n");
		   	 }
		      
				  printf("*******************************************************************************\n");  //Printing the 80*
				  printf("\n");
				  
    	  //If the user enter a number between 0 and 10, it will print the specific Multiplication Table that the user asked for
	  } else if (userInput >= 1 && userInput <= 9){
	    
	      i = userInput - 1;
	      
	      printf("Printing multiplication table for %d\n",userInput);
		    printf("-----------------------------------\n");
		    
		     //print the specific Multiplication Table that the user asked for
		    for(j = 0 ;j < 9; j++){
		      
			    printf("%d X %d = %d\n", i + 1, j + 1, timesChartTable[i][j]);
			    
        }
        printf("\n");
      
      	  //If the user does not enter a number between 1 and 9, it will not compile, and it will print the following.
	  }else {
	    
	          printf("This is an invalid number.\n");
	  }
	    //It will then ask the user if the user wants to coninute or not
	    printf("Do you wish to continue? Enter y for yes, any other character for no:");
      	    getchar();
	    scanf("%c",&choice);  //if the user enter 'y' it will go back to the beginning of code and start looping until the user answer something else 
	}
	printf("\n");
	printf("Good Bye.\n");  //It will print "goodbye" if the user did not entered 'y' and entered something else.
	return 0;
}
