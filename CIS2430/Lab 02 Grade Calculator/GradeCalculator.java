import java.util.ArrayList;
import java.util.Iterator;

public class GradeCalculator{
    /* private member variables.  Do not change these*/

    private ArrayList<Double> assignmentGrades = new ArrayList<>();
    private ArrayList<Double> selfStudyGrades = new ArrayList<>();
    private double midtermExam;
    private double finalExam;
    private double competenceExamTotal;
    private double labTotal;



    private void setAssignmentGrades(double a1, double a2, double a3){
        /* this is an example of how to add things to an array list
        but it is not a complete method.  You will need to finish it*/

        assignmentGrades.add(a1);
        assignmentGrades.add(a2);
        assignmentGrades.add(a3);
        
    }


    private  void setSelfStudyGrades(double s1, double s2, double s3){
        /*this will be similar to the setAssignmentGrades method*/
        
        selfStudyGrades.add(s1);
        selfStudyGrades.add(s2);
        selfStudyGrades.add(s3);
        
        }


    private  void setMidtermExamGrade(double grade){
        
        this.midtermExam = grade;
        
    }

    private void  setFinalExamGrade(double grade){

        this.finalExam = grade;
    }

    private void  setCompetenceExamTotal(double grade){
   
        this.competenceExamTotal = grade;
    
    }

    private  void setLabTotal(double grade){
        
        this.labTotal = grade;
      
    }

    private double getHomeworkGrade(){
        /* possibly useful is the ArrayList get(index) method.  
        somearraylist.get(1) will return the element in the second position
        because ArrayLists are zero indexed */
        
        double homeWorkGrades;
        
        //To calcualte the final assignment grade, you have to use the formula: self study grades * assignmentGrades = homeWorkGrades
        homeWorkGrades = (assignmentGrades.get(0) * selfStudyGrades.get(0) * 0.05) + (assignmentGrades.get(1) * selfStudyGrades.get(1) * 0.1) + (assignmentGrades.get(2) * selfStudyGrades.get(2) * 0.1);
        
        return homeWorkGrades;
        
    }
    
    public double getFinalCourseGrade(){
        
        double finalGrade;

        finalGrade = labTotal + getHomeworkGrade() + competenceExamTotal + midtermExam + finalExam;                    
        
        return finalGrade;

    }

    public void parseInput(String inputLine){
        /*part of this method is done for you, but not all of it. 
        You will need to finish it*/
    String singles[] = inputLine.split(",");
    setLabTotal(Double.parseDouble(singles[0]));
  
    //more code needed here calling the setter methods,
    setSelfStudyGrades(Double.parseDouble(singles[1]), Double.parseDouble(singles[2]), Double.parseDouble(singles[3]));
    
    setAssignmentGrades(Double.parseDouble(singles[4]), Double.parseDouble(singles[5]), Double.parseDouble(singles[6]));
    
    setCompetenceExamTotal(Double.parseDouble(singles[7]));
    
    setMidtermExamGrade(Double.parseDouble(singles[8]));
    
    setFinalExamGrade(Double.parseDouble(singles[9]));

    
    
        
    }


}