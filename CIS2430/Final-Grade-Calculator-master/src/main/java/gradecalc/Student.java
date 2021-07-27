package gradecalc;

public class Student {
    private String name;
    private double grade;
    
    public Student(){
        name = "";
        grade = 0;
    }
    
    public Student(String name){
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getGrade() {
        return grade;
    }

    public void setGrade(double grade) {
        this.grade = grade;
    }
    
    public double finalGrade(){
        return 0;
    }
    
    @Override
    public String toString(){
        return name +" "+grade;
    }
    
}
