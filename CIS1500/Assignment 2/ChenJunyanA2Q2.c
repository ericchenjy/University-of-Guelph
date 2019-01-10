/*
  Junyan Chen
  jchen52@uoguelph.Canada
  Computer Science CIS*1500
  Question 2: Write a program that prompts the user to enter the population of ten provinces of Canada and stores them in an array called population of size 10. 
*/

#include <stdio.h>

int main (void){
 
  const int NUM_PROVINCES = 10;             //Store numbers of provinces
  double provincePop[NUM_PROVINCES];        //Province population
  int provHigh;                             //The Province number that has the highest population           
  int provLow;                              //The Province number that has the lowest population    
  double averagePop = 0;                    //The average population of all the province together
  double highestPop = 0;                    //The highest population of a province
  double lowestPop = 0;                     //The highest population of a provinc
  int i = 0;                                //Loop index


  printf("Enter the population of 10 provinces of Canada (in million):\n");
  
  //Ask user for the population for the 10 provinces
  for (i = 1; i <= NUM_PROVINCES; ++i){
    printf("Province number %d:", i);
    scanf("%lf", &provincePop[i]);
  }
  
  
  //Print out the line of stars
  for (i = 1; i <= 49; ++i){
    printf("*");
  }
  printf("\n");
  
  
  averagePop = 0;
    
    //Calculate for the avegrage population
    for (i = 1; i <= NUM_PROVINCES; ++i){
      averagePop = averagePop + provincePop[i] /10;         //divide the total population by the total number                                                     of provinces*/
    }
       printf("Average Population in Canada = %.2lf million.\n", averagePop);
  
  
    //Calculate for the highest and the lowest Population
    highestPop = provincePop[1];
    lowestPop = provincePop[1];
    
    for (i = 1; i <= NUM_PROVINCES; ++i){
      
      //find the highest population
      if (provincePop[i] > highestPop){
          highestPop = provincePop[i];        //Everytime when it see a higher number it wil store in the vairbale highestPop
          provHigh = i;                       //Store the province that have the highest population
          
      //find the lowest population
      }if (provincePop[i] < lowestPop){
        lowestPop = provincePop[i];          //Everytime when it see a lower number it wil store in the vairbale lowestPop
         provLow = i;                       //Store the province that have the lowest population
         
      }
    }
      printf("The province number %d has the highest population.\n",provHigh);
      printf("Highest population = %.2lf million.\n", highestPop);
      
      printf("The province number %d has the lowest population.\n",provLow);
      printf("Lowest population = %.2lf million.\n", lowestPop);
      
      
      //Print out the line of stars
      for (i = 1; i <= 49; ++i){
      printf("*");
      }
      printf("\n");

  return 0;
  }
  
  
