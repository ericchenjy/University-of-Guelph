/* 
  Junyan Chen
  jchen52@uoguelph.ca
  Computer Science CIS*1500
  Quesion 4: Write a program that prompts the user to enter a string and prints the goodness of the string. 
*/

#include <stdio.h>
#include<string.h>

int main (void){
  char userString[100] = "";        //stores how many characters can it hold
  int goodCount = 0;                
  int stringLength = 0;             //the length of the string
  int i = 0;                        //loop index
  
  //ask the user for the string
  printf("Enter a string with no spaces:");
  scanf("%s", userString);
  
  //find the length of the string of the user
  stringLength = strlen(userString);
  
    //find the 1 in the user string, if found it will add up the goodness count by 1
    for (i = 0; i < stringLength; i++){
      
      if (userString[i] == '1'){    
        ++goodCount;                
      }
    }
    
    //If find any number that's not 1 or 0, the goodness count will be initialed to 0
    for (i = 0; i < stringLength; i++){
    
      //If find not find 0 and 1, the number of ones will be 0
      if (userString[i] != '1' && userString[i] !='0'){     

         goodCount = 0;     
      }
    }
    printf("Goodness of the input string is %d\n",goodCount);
  return 0;
}

