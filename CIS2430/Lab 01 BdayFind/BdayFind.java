import java.util.Scanner;

public class BdayFind {
    
    public static void main(String [] args){
        
        String userBday;
        String dayOfWeek;
        String[] bdayInfo;
        
        System.out.print("Enter your Birthday: ");
        
        Scanner userInput = new Scanner(System.in);     
        userBday = userInput.nextLine();                //get the userInput and initialize it to userBday
        
        userBday = userBday.trim();                     //trim up the trailing whitespaces 
        bdayInfo = userBday.split("\\s+");              //split the user input to day, month, and year
        
        if(Integer.parseInt(bdayInfo[2]) < 100)         //assumes that is is only ofr bdays in the 20th, and 21st century 
        {
            bdayInfo[2] = "19" + bdayInfo[2];           //user decides to use short form for year, ie. 99
        }
        
        Birthday bday = new Birthday(bdayInfo[1], bdayInfo[0], bdayInfo[2]);    //Calling the Birthday class to create a new object
        
        dayOfWeek = bday.getDayOfWeek();
        
        System.out.println(dayOfWeek);
        
        
    }
}