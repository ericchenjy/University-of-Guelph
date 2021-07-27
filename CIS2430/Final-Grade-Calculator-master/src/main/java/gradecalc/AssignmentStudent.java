package gradecalc;

public class AssignmentStudent extends Student implements ResearchSubject{

    private double[] quiz;
    private double[] assignment;
    private double exam;
    private boolean participating;

    public AssignmentStudent() {
        super();
        this.quiz = new double[3];
        this.assignment = new double[10];
        this.exam = 0;
        this.participating = false;
    }

    public AssignmentStudent(String name, double[] quiz, double[] assignment, double exam, boolean participating) {
        super(name);
        this.quiz = quiz;
        this.assignment = assignment;
        this.exam = exam;
        this.participating = participating;
    }
    
    @Override
    public double finalGrade(){
        double assignSum = 0;
        for (int a = 0; a < assignment.length; a++) {
            assignSum += (assignment[a]*0.05);
        }
        double quizSum = 0;
        for (int a = 0; a < quiz.length; a++) {
            quizSum += (quiz[a]*0.10);
        }
        double e = exam*0.20;
        double research = researchPerk();
        double total = assignSum + quizSum + e + research;
        if(total > 100){
            super.setGrade(100);
        }
        else{
            super.setGrade(total);
        }
        return super.getGrade();
    }

    public double[] getQuiz() {
        return quiz;
    }

    public void setQuiz(double[] quiz) {
        this.quiz = quiz;
    }

    public double[] getAssignment() {
        return assignment;
    }

    public void setAssignment(double[] assignment) {
        this.assignment = assignment;
    }

    public double getExam() {
        return exam;
    }

    public void setExam(double exam) {
        this.exam = exam;
    }

    public boolean isParticipating() {
        return participating;
    }

    @Override
    public void setParticipating(boolean participating) {
        this.participating = participating;
    }

    @Override
    public double researchPerk() {
        if(participating == true){
            return 5.0;
        }
        else
            return 0;
    }
    
    @Override
    public String toString(){
        return super.getName()+" "+finalGrade();
    }
    
}
