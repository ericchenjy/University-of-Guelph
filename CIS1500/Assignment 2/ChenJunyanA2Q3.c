/*
  Junyan Chen
  jchen52@uoguelph.ca
  Computer Science CIS*1500
  Question 3:Write a program that prompts the user to enter a sentence. It then counts the vowels and consonants in it. It also calculates the average word length of the input sentence.
*/

#include <stdio.h>

int main (void){
  
  char userString[50];                    //stores how many characters can it hold
  int vowels = 0;                         //number of vowels
  int consonants = 0;                     //number of consonants
  int alphabeticChars = 0;                //the total characters in a line
  int countWord = 0;                      //increases the word by 1 when comilping
  double averageword = 0.0;               //the average word in a string
  int i = 0;                              //loop index
  
  //ask user for the string
  printf("Enter a sentence:");
  fgets(userString, 100, stdin);
  
  //calulate for the vowels and the consonants
  for(i = 1; userString[i] != '\0'; i++){
    
     //find the any Lower/Upper case vowels*/
     if ((userString[i] == 'a' || userString[i] == 'e' || userString[i] ==
     'i' || userString[i] == 'o' || userString[i] == 'u') ||
        (userString[i] == 'A' || userString[i] == 'E' || userString[i] == 
    'I' || userString[i] == 'O' || userString[i] == 'U')){
      
      ++vowels;             //If found, vowels count and increases by 1.
    }
    else{
      ++consonants;         //Consonants will count and increases by 1 if the alphabetics(including spaces) does not equals to vowels.
    }
    
      //find the spaces 
      if(userString[i] == ' ') {
      --consonants;         //if any space found the consonants will decrease by 1, because consonants include all the characters that includes the spaces.
      }
  }

    printf("Number of vowels in the sentence = %d\n", vowels);
    printf("Number of consonants in the sentence = %d\n", consonants);
  
  
  averageword = 0;

  //find the average word
  for(i = 1; userString[i] != '\0'; i++){
    
    alphabeticChars = vowels + consonants;      //add up vowels and the consonants to find the total characters
  
      if (userString[i] == ' ' || userString[i] == '\n' || userString[i] == '\t'){
        ++countWord;        //It will count a word if it finds a space, next line, and a tab

        averageword = (double) alphabeticChars / countWord;        //total word divide by the numbers of word 
     
      }
  } 
    printf("Average word length %.2lf\n", averageword);
  
  return 0;
}
