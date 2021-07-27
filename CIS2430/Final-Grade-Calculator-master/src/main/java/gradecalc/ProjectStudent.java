package gradecalc;

public class ProjectStudent extends Student implements ResearchSubject {
    
    private double[] milestones;
    private double exam;
    private double midterm;
    private boolean participating;
                    
    public ProjectStudent(){
        super();
        this.milestones = new double[3];
        this.exam = 0;
        this.midterm = 0;
        this.participating = false;
    }
    
    public ProjectStudent(String name, double[] milestones, double exam, double midterm, boolean participating) {
        super(name);
        this.milestones = milestones;
        this.exam = exam;
        this.midterm = midterm;
        this.participating = participating;
    }

    public double[] getMilestones() {
        return milestones;
    }

    public void setMilestones(double[] milestones) {
        this.milestones = milestones;
    }

    public double getExam() {
        return exam;
    }

    public void setExam(double exam) {
        this.exam = exam;
    }

    public double getMidterm() {
        return midterm;
    }

    public void setMidterm(double midterm) {
        this.midterm = midterm;
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
    public double finalGrade(){
        double milesSum = 0;
        for (int a = 0; a < milestones.length; a++) {
            milesSum += (milestones[a]*0.20);
        }
        double e = exam*0.20;
        double m = midterm*0.20;
        double research = researchPerk();
        double total = milesSum + e + m + research;
        if(total > 100){
            super.setGrade(100);
        }
        else{
            super.setGrade(total);
        }
        return super.getGrade();
    }
    
    @Override
    public String toString(){
        return super.getName()+" "+finalGrade();
    }
    
}
