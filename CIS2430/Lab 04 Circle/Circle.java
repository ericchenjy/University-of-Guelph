import java.lang.Math;

/**
 * This class is used to represent circle objects.
 *
 * @author Le
 * @version September 22, 2019
 */
public class Circle {

    /* instance variables */
    private double radius;
    private double area;
    private double diameter;
    private double circumference;

    /**
     * The constructor initializes radius to the argument value.
     * @param newRadius - new radius of a circle
     */
    public Circle(double newRadius) {
        
        this.radius = newRadius;

    }

    /**
     * This method is used to calculate and set the diameter of a circle.
     */
    public void calculateDiameter() {
        
        
        diameter = radius * 2;

    }

    /**
     * This method is used to calculate and set the length of circumference of a
     * circle.
     */
    public void calculateCircumference() {
        
        circumference = Math.PI * radius * 2;

    }

    /**
     * This method is used to calculate the area of a circle.
     */
    public void calculateArea() {
        
        area = Math.PI * radius * radius;

    }

    /**
     * This method is used to get the radius of a circle.
     */
    public double getRadius() {
        return radius;
    }

    /**
     * This method is used to set the radius of a circle.
     */
    public void setRadius(double newRadius) {
       
       this.radius = newRadius;
    }

    /**
     * This method is used to get the area of a circle.
     */
    public double getArea() {
        return area;
    }

    /**
     * This method is used to get the diameter of a circle.
     */
    public double getDiameter() {
        return diameter;
    }

    /**
     * This method is used to get the circumference of a circle.
     */
    public double getCircumference() {
        return circumference;
    }

}