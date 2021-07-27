package gradecalc;

public class ChallengeStudent extends Student {
    private double projectGrade;
    private double examGrade;
    
    public ChallengeStudent(){
        super();
        projectGrade = 0;
        examGrade = 0;
    }
    public ChallengeStudent(String name, double projectGrade, double examGrade){
        super(name);
        this.projectGrade = projectGrade; 
        this.examGrade = examGrade; 
    }

    public double getProjectGrade() {
        return projectGrade;
    }

    public void setProjectGrade(double projectGrade) {
        this.projectGrade = projectGrade;
    }

    public double getExamGrade() {
        return examGrade;
    }

    @Override
    public double finalGrade(){
        double p = projectGrade * 0.50;
        double e = examGrade * 0.50;
        super.setGrade(p+e);
        return super.getGrade();
    }
    
    public void setExamGrade(double examGrade) {
        this.examGrade = examGrade;
    }
    
    @Override
    public String toString(){
        return super.getName()+" "+finalGrade();
    }
    
}
