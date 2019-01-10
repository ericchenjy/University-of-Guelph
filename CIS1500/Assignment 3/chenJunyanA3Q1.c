/* Junyan Chen
   jchen52@uoguelph.ca
   Computer Science CIS*1500
   Assignment 3 Question 1
*/

#include <stdio.h>

float percentage(float, float);

float contribution(float, float, float);

float assignmentContribution(float, float, float);

float dailyPracticeContribution(float [11]);

float labContribution(float [9], float, float);

float totalTermMark(float, float, float);

float finalMarkRequired(float, float);


//percentage
float percentage(float actualMark, float maxMark){
  
    float finalMark = 0;
    
    //calculate the final mark 
    finalMark = ((actualMark / maxMark)) * 100;
  
  return finalMark;
}

//contribution
float contribution(float actualMark, float maxMark, float weight){
  
  float finalWeight = 0;
  
  //calculate the final weight 
  finalWeight = (actualMark / maxMark) * weight;
  
  return finalWeight;
}

//assignmentContribution
float assignmentContribution (float assignment1, float assignment2, float assignment3){
  
  float totalAssignWeight = 0;
  
  //find the weight percentage of each assignment
  assignment1 = (assignment1 / 50) * 5;
  assignment2 = (assignment2 / 60) * 10;
  assignment3 = (assignment3 / 60) * 10;
 
  //add up all the weight to find the total assignement weight
  totalAssignWeight = assignment1 + assignment2 + assignment3;
  
  return totalAssignWeight;
}

//Daily Practice Contribution 
float dailyPracticeContribution(float zybooks[11]){
  
  float finalMark = 0;
  float lowGrade = 0;
  int i = 0;
  
  lowGrade = zybooks[0];  //smallest so far
  
  //determine the lowest grade
  for (i = 0; i < 11; i++){
  
    if(zybooks[i] < lowGrade){
      lowGrade = zybooks[i];
    }
  }

  //add up all the zybooks marks
  for (i = 0; i < 11; i++){
    finalMark = finalMark + zybooks[i] ;
  }
  
  //return the final weight by subtracting the lowest grade from zybook then times 100 and divide by 10 
return ((finalMark - lowGrade) / 100) * 10;
}

//Lab Contributtion, Weekly labs, and lab exam 1, and lab exam 2
float labContribution(float weeklyLab[9], float labExam1, float labExam2){
  
  float finalWeight = 0;
  float labsMark = 0;
  int i = 0;
  
  //determine the total weight for the weekly lab
  for (i = 0; i < 9; i++){
    labsMark = labsMark + ((weeklyLab[i] / 9) * 10);
  }
  
  labExam1 = (labExam1 / 50) * 10;    //determine the weight for the first assignment
  
  labExam2 = (labExam2 /50) * 10;     //determine the weight for the second assignment
  
  finalWeight = labExam1 + labExam2 + labsMark;    //determine the final weight by adding all the weight together
  
  return finalWeight;
}

//Total Term Mark
float totalTermMark(float assignWeight, float zybookWeight, float labsWeight){
  
  float finalMark  = 0;
  
  finalMark = assignWeight + zybookWeight + labsWeight;   //detemine all the weight
  
  //check if the final mark is 65% or not
    if (finalMark == 65){
    
      finalMark = finalMark + 5;    //if it is the 5 extra bonus mark
    }else{
    
      finalMark = finalMark;        //if it is not than the mark will be the same.
    }
  
  return finalMark;
}

//Final Mark
float finalMarkRequired(float totalTermMark, float iDesire){
  
  float requiredMark = 0;
  
  //find the required mark that is needed 
  requiredMark = (iDesire - totalTermMark)/ 0.35; 
  
  return requiredMark;
}

