/* You must create this file entirely.  Remember to include any imports
you might need.  Also remember that you will need some instance variables 


This is the minimum set of methods
*/

import java.util.*;

public class WordAnalyzer{
    
    private String word;
    
    public WordAnalyzer(){
        
        this.word = "Wherever you go, there you are";
        
    }
    
    public WordAnalyzer(String theWords){
    
        this.word = theWords;

    }

    public void setWords(String text) {
    
        this.word = text;

    }

    public String getWords(){
    
        return word;
    

    }

    public int countLetters(){
    
        int count = 0;
        int i = 0;
        
        for(i = 0; i < word.length(); i++)
        { 
            if(word.charAt(i) != ' ' && word.charAt(i) != ',')
            {
                count++;
            }
        }
    
        return count;
    }

    public int countWords(String string){
    
        StringTokenizer tokens = new StringTokenizer(string);
        return tokens.countTokens();

    }

}
