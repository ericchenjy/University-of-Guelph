import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator;

public class GradeTester{
    

public static void main(String args[]){
/* the main method should instantiate a Scanner, 
get the grade string from the user instantiate a new GradeCalculator,
call the parseInput method for the grade calculator and 
get the final grade from the grade calculator- printing it to standard out

hint: use the nextLine() method from the Scanner class
*/


// your code here

    String grades;
    String userGrades[];
  
    Scanner scnr = new Scanner(System.in);
    
    System.out.print("Enter your grades: ");
    
    grades = scnr.nextLine();
    userGrades = grades.split(",");
    
    //check the number if it is valid number, and also check if it also a positive number
    if(Double.parseDouble(userGrades[0]) > 10 || Double.parseDouble(userGrades[0]) < 0 ||
       Double.parseDouble(userGrades[1]) > 1 || Double.parseDouble(userGrades[1]) < 0 ||
       Double.parseDouble(userGrades[2]) > 1 || Double.parseDouble(userGrades[2]) < 0 ||
       Double.parseDouble(userGrades[3]) > 1 || Double.parseDouble(userGrades[3]) < 0 ||
       Double.parseDouble(userGrades[4]) > 100 || Double.parseDouble(userGrades[4]) < 0 ||
       Double.parseDouble(userGrades[5]) > 100 || Double.parseDouble(userGrades[5]) < 0 ||
       Double.parseDouble(userGrades[6]) > 100 || Double.parseDouble(userGrades[6]) < 0 ||
       Double.parseDouble(userGrades[7]) > 15 || Double.parseDouble(userGrades[7]) < 0 ||
       Double.parseDouble(userGrades[8]) > 20 || Double.parseDouble(userGrades[8]) < 0 ||
       Double.parseDouble(userGrades[9]) > 30 || Double.parseDouble(userGrades[9]) < 0)
    {
        System.out.println("Invalid Grade Input");
    }
    else
    {
        //if the number is valid, call the GradeCalculator Class to calculate for the final grade by passing in the user input
        GradeCalculator gradesInput = new GradeCalculator();
        gradesInput.parseInput(grades);
        
        System.out.println(gradesInput.getFinalCourseGrade());
    }
    



}

}