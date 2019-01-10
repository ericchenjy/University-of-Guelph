/*
Junyan Chen
1026737
jchen52@uoguelph.ca
*/

#include <stdio.h>
int ackermannMethod(int m, int n);

int ackermann() {

        int number1 = 0;
        int number2 = 0;

        printf("Enter two numbers: ");
        scanf("%d%d", &number1, &number2);


        printf("%d ", ackermannMethod(number1, number2));
        printf("\n");
return 0;

}

int ackermannMethod(int m, int n){

	/*if m and n are both less than 0 or at least one of them is less than 0, it will return -1, */
	if( (m < 0 && n < 0) || (m < 0 && n >= 0) || (m >= 0 && n < 0)){

	return  -1;

	}

	/*if m is euqal to 0 and n is euqal to 0 or bigger, n will add up by 1*/
	else if( m == 0 && n >= 0){

    		return n+1;

	/*if m is bigger than 0 and n is euqalto 0, m will substract 1,
	  the function will call itelft until m = 0*/
	} else if (m > 0 && n == 0){

		return ackermannMethod(m-1, 1 );

	/*if m and n are both bigger than 0, the function will call itslef from the ackermann(m, n - 1),
	  then the outside ackermann( m-1, ackermann(m, n-1) );
	  and will call itself until it reaches the answer */
	} else {
		 return ackermannMethod( m-1, ackermannMethod(m, n-1) );

	}
}

