package adventure;

import java.util.ArrayList;

public class Parser {
    
    Command command;
    private ArrayList<Command> commands = new ArrayList<>();
    
    Parser(){
        this.command = null;
    }
    
    Parser(Command command){
        this.command = command;
    }
    
    public void setCommand(Command command){
        this.command = command;
    }
    
    public void setCommands(ArrayList<Command> commands){
        this.commands = commands;
    }
    
    
    public Command parseUserCommand(String userCommand) throws InvalidCommandException {
        String action = userCommand.split(" ")[0];
        String noun = userCommand.split(" ")[1];
        Command c = new Command(action, noun);
        commands.add(c);
        return c;
    }
    
    public String allCommands(){
        String c = "";
        for (int a = 0; a < commands.size(); a++) {
            c += commands.get(a).getActionWord()+" "+commands.get(a).getNoun() +"\n";
        }
        return c;
    }
    
    @Override
    public String toString(){
        return command.toString();
    }
}