/*carbon.c
  Junyan Chen
  1026737
  jchen52@uoguelph.ca
  Source: https://www.robertcina.com/2015/02/19/an-exercise-in-permutations-using-java/
*/

#include<stdio.h>

int carbon(){

        char word[]={'c','a','r','b','o','n'};  
        int length = 6;				/*the total character of the carbon is 6*/
	int c = 0;
	int a = 0;
	int r = 0;
	int b =	0;
	int o = 0;
	int n = 0;

	/*a nested loop that will literates over these characters, and make them combine together, and no bigger than 6 words*/
        for(c = 0; c < length; c++){
                for(a = 0; a < length; a++){
                        for(r = 0; r < length; r++){
                                for(b = 0; b < length; b++){
                                        for(o = 0; o < length; o++){
                                                for(n = 0; n < length; n++){

							/*making sure that there aren't any repeated letters on the same line*/
                                                        if(c!=a && c!=r && c!=b && c!=o && c!=n && a!=r && a!=b && a!=o && a!=n && r!=b && r!=o && r!=n && b!=o && b!=n && o!=n)
                                                        {

                                                        printf("%c%c%c%c%c%c \n",word[c],word[a],word[r],word[b],word[o],word[n]);

                                                       }
                                                }
                                        }
                                }
                        }
                }
        }
return 0;
}
