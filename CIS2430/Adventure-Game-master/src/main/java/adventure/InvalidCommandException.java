package adventure;
public class InvalidCommandException extends Exception{
    
    InvalidCommandException(String msg){
        super(msg);
    }
}
