#Name: Junyan Chen
#Date: September 24th, 2018
#Student ID: 1026737
#E-mail: jchen52@uoguelph.ca
#Assignemnt: Assignment 1

------------------------------------
Question 1: Carbon
-In this question, there are supposed to be 720 words to be printed. 
-"C", "A", "R", "B", "O", "N" are supposed to be printed in different orders, they cannot be repeated vacaulary on the same line.

Question 2: Anckerman's method
-In this question, it is a Anckermann's method caluclation
-I put the "-1" when m or n get a value that's negative. It cannot be a negative value. -1 shows that it doesn't work.
-The range is A(4,0), since A(4,1) give an answer of 65533 but it is too big to store it in an integer.

Question 3:Newton's method
-Find the accuracy of x when using the Newton's method and the square root method.
-write in two functions, one in recursion and one without a recursion.

------------------------------------

Sample Output:

--Carbon.c------
noabcr 
noabrc 
norcab 
norcba 
noracb 
norabc 
norbca 
norbac 
nobcar 
nobcra 
nobacr 
nobarc 
nobrca 
nobrac 

--Ackermann.c-----
A(1, 0) = 2
A(1, 3) = 5
A(1, 7) = 9
A(2, 2) = 7
A(2, 6) = 15
A(2, 9) = 21
A(3, 3) = 61
A(3, 5) = 253
A(3, 8) = 2045

--newtoon.c--------

Enter a number for x and calculate the square root of the x: 4

Enter the accuracy of the sqaure root: 0.0001

The recursion of the square root of 4.000000 that has an accuracy 1.000000e-04 is: 2.000000e+00
The loop of the square root 4.000000: that has an accuracy 1.000000e-04 is: 2.000000e+00


