/*  
  Junyan Chen
  jchen52@uoguelph.ca
  Computer Science CIS*1500
  Question 1: Write a program to display the following pattern on the screen. Your program must prompt the user for the number of lines to be printed and the desired width between the left and right figures. 
*/

#include <stdio.h>

int main(void){
  
  int numOfLines = 0;;               //number of lines of triangle
  int width = 0;                     //the width between the lines of triangle
              
  int i = 0;              //Loop index
  int j = 0;              //loop index
  int k = 0;              //loop index
  int l = 0;              //loop index
  
  //Ask user for how many numer of lines of triangle to print
  printf("Number of lines? ");
  scanf("%d", &numOfLines);
  
    //Calcualte if there is a remainder after divided by 2. It not, then compile. 
    if (numOfLines % 2 == 0){
    
      //Ask user how many many spaces want between the lines of triangle
      printf("Width between left and right figure?");
      scanf("%d", &width);
      
      printf("\n");
      
        // Print out the both side of the triangle and the spacing on the top 
        for(i = 1; i <= (numOfLines/2); i++){
          for (j = 1; j<=(numOfLines/2) - i; j++){
            
            printf(" ");
          }
        
          //Print out the right half of the triangle
          for(k = 1; k <= i; k++){
            printf("*");
          }
          
          //Print out the "-" spaces in the middle of the triangle
          for (l = 1; l <= width; l++){
           
            //if the i's number matches reaminder 0, then print -, or else print out a space. 
            if (i == numOfLines/ 2){
              printf("-");
            }else {
              printf(" ");
            }
          }
        
          //Print out the left half of the triangle
          for(k = 1; k <=i; k++){
            printf("*");
          }
        
            printf("\n");       //print out a space, and print the next triangle to the next line.
        }
        
        // Print out both sides of the trianggle and the spacing on the bottwom
        for(i = (numOfLines/2); i>= 1; i--){
          for (j = (numOfLines/2) - 1; j >= i; j--){
            
            printf(" ");
          }
        
          //Print out the right half of the triangle
          for(j = 1; j <= i; j++){
            printf("*");
          }
          
          //Print out the "-" spaces in the triangle
          for (k = 1; k <= width; k++){
            
            //if the i's number matches reaminder 0, then print -, or else print out a space. 
            if (i == numOfLines/ 2){
              printf("-");
            }else {
              printf(" ");
            }
          }
        
          //Print out the left half of the triangle
          for(k = 1; k <= i; k++){
            printf("*");
          }
        
            printf("\n");
        }
        
    // if it does have a remainder, then it won't compile, and print this statement below
    }else{
      printf("Invalid input - number of lines must be even");
    }
  return 0;
}

