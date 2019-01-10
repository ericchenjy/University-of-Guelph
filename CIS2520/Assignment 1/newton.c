/*Junyan Chen
  1026737
  jchen52@uoguelph.ca
*/

#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>

double newtonLoop(double x, double e, double a);
double newtonRecur(double x, double e, double a);

int newton(){

	double x = 0.0;
	double e = 0.0;
	double a = 0.0;
	double function1 = 0.0;
	double function2 = 0.0;

	printf("Enter a number for x and calculate the square root of the x: ");
	scanf("%lf", &x);
	printf("\n");

	printf("Enter the accuracy of the sqaure root: ");
	scanf("%lf", &e);
	printf("\n");

	a = x / 2;		/*initial approximation*/

	function1 = newtonRecur(x, e, a);  		/*calling the recursion function*/

	printf("The recursion of the square root of %lf that has an accuracy %e is: %e\n",x,e,function1);


	function2 = newtonLoop(x, e, a);		/*calling the loop function*/
	printf("The loop of the square root %lf: that has an accuracy %e is: %e\n", x,e,function2);


return 0;
}

double newtonRecur(double x, double e, double a){


	/*if the value that is caluated is smaller or equals to the e, then it will exit and return the a value.*/
	if (abs(( a *  a) - x) <= e){

		return  a;

	} else {

		a = (a + (x / a) ) / 2;			/*if it doesn't it will use the newton's equation*/
		return newtonRecur(x, e, a);		/*recursion*/
	}
}

double newtonLoop(double x, double e, double a){


	/*it will continue lopping while it is bigger than e, and will stop if it equals or smaller than e*/
	while (abs(( a *  a) - x) > e){

		a = (a + (x / a) ) / 2;			/*newton's equation*/
		}

	return a;
}
