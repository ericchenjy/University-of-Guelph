package gradecalc;

import java.util.ArrayList;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import java.io.FileReader;

public class Roster {
    
    private ArrayList<Student> studentsList;
    
    public Roster(String JSONFilename){
        studentsList = new ArrayList<>();
        JSONParser parser = new JSONParser();
        JSONObject jsonObject = null;
        try {
            Object obj = parser.parse(new FileReader(JSONFilename));
            jsonObject = (JSONObject) obj;
            JSONArray students = (JSONArray) jsonObject.get("students");
            
            for (int a = 0; a < students.size(); a++) {
                JSONObject objStudent = (JSONObject) students.get(a);
                String stream = String.valueOf(objStudent.get("stream"));
                if(stream.equalsIgnoreCase("challenge")){
                    String name = String.valueOf(objStudent.get("name"));
                    double project = Double.parseDouble(String.valueOf(objStudent.get("projectGrade")));
                    double exam = Double.parseDouble(String.valueOf(objStudent.get("examGrade")));
                    Student s = new ChallengeStudent(name, project, exam);
                    studentsList.add(s);
                }
                else if(stream.equalsIgnoreCase("project")){
                    String name = String.valueOf(objStudent.get("name"));
                    JSONArray milestones = (JSONArray) objStudent.get("milestoneGrades");
                    double[] miles = new double[milestones.size()];
                    for (int i = 0; i < miles.length; i++) {
                        miles[i] = Double.parseDouble(milestones.get(i)+"");
                    }
                    double exam = Double.parseDouble(String.valueOf(objStudent.get("examGrade")));
                    double midterm = Double.parseDouble(String.valueOf(objStudent.get("midtermGrade")));
                    boolean participating = Boolean.parseBoolean(objStudent.get("participating")+"");
                    Student s = new ProjectStudent(name, miles, exam, midterm, participating);
                    studentsList.add(s);
                }
                else if(stream.equalsIgnoreCase("assignment")){
                    String name = String.valueOf(objStudent.get("name"));
                    JSONArray quizzes = (JSONArray) objStudent.get("quizGrades");
                    double[] quiz = new double[quizzes.size()];
                    for (int i = 0; i < quiz.length; i++) {
                        quiz[i] = Double.parseDouble(quizzes.get(i)+"");
                    }
                    JSONArray assignments = (JSONArray) objStudent.get("assignmentGrades");
                    double[] assign = new double[assignments.size()];
                    for (int i = 0; i < assign.length; i++) {
                        assign[i] = Double.parseDouble(assignments.get(i)+"");
                    }
                    double exam = Double.parseDouble(String.valueOf(objStudent.get("examGrade")));
                    boolean participating = Boolean.parseBoolean(objStudent.get("participating")+"");
                    Student s = new AssignmentStudent(name, quiz, assign, exam, participating);
                    studentsList.add(s);
                }
                
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void setStudents(ArrayList<Student> students){
        this.studentsList = students; 
    }
    
    public ArrayList<Student> getStudents(){
        return studentsList; 
    }
    
    
}
