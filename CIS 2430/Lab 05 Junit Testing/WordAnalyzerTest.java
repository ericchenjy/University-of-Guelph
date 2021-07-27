import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;
import static org.junit.Assert.assertTrue;
import org.junit.Test;
import org.junit.Before;

public class WordAnalyzerTest{
private WordAnalyzer testerOne;
private WordAnalyzer testerTwo;
int outputCount;
int expectedCount;
String outputString;
String expectedString;

public WordAnalyzerTest(){


}

@Before
public void setup(){
    testerOne = new WordAnalyzer();
    testerTwo = new WordAnalyzer("one two three one");
    outputCount = 0;
    expectedCount = 0;
    outputString = "";
    expectedString = "Wherever you go, there you are";
}

@Test
public void testDefaultConstructor(){
    System.out.println("Testing default constructor");
    outputString = testerOne.getWords();
    assertTrue(outputString.equals(expectedString));

}

@Test
public void testgetWords(){
    
        System.out.println("Testing get words");
        
        testerOne.setWords("Wherever you go, there you are");
        testerTwo.setWords("one two three one");
        
        assertEquals("Wherever you go, there you are", testerOne.getWords());
        assertEquals("one two three one", testerTwo.getWords());
	
}

@Test
public void testParameterConstructorOne(){
    
        
        System.out.println("Testing parameter constructor one");
        
        outputString = testerTwo.getWords();
        
        assertTrue(outputString.equals("one two three one")); 
}

@Test
public void testParameterConstructorTwo(){
    
        System.out.println("Testing Parameter constructor two");
        
        outputString = testerTwo.getWords();
        
        assertTrue(outputString.equals("one two three one")); 
    
}

@Test
public void testsetWordsOne(){
    
        System.out.println("Testing set words one");
        
        testerOne.setWords("Wherever you go, there you are");
    
        assertEquals(testerOne.getWords(), "Wherever you go, there you are");
}

@Test
public void testsetWordsTwo(){
    
        System.out.println("Testing set words two");
    
        testerTwo.setWords("one two three one");
    
        assertEquals(testerTwo.getWords(), "one two three one");
}

@Test
public void testscountLetters(){
    
        System.out.println("Testing count letters");
        
        outputString = testerOne.getWords();
        
        expectedCount = 24;
        
        outputCount = testerOne.countLetters();
    
        assertEquals(expectedCount, outputCount);
}
@Test
public void testscountWords(){
    
        System.out.println("Testing count words");
    
        outputString = testerOne.getWords();
        
        expectedCount = 6;
        
        outputCount = testerOne.countWords(outputString);
    
        assertEquals(expectedCount, outputCount);
}


}