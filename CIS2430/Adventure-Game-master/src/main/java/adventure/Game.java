package adventure;
 
import java.util.ArrayList;
import java.util.Scanner;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import java.io.ByteArrayInputStream;
import java.io.FileReader;
import java.io.InputStream;

public class Game {
    
    /* this is the class that runs the game.
    You may need some member variables */
    private Adventure adv = new Adventure();
    private Parser parser = new Parser();
    private ArrayList<Item> carriedItems = new ArrayList<>();
    
    Game(){
        adv = new Adventure();
        parser = new Parser();
        carriedItems = new ArrayList<>();
    }
    
    public static void main(String args[]) throws InvalidCommandException {
        new Game().setup();
    }
    
    public void setup() throws InvalidCommandException {
        Game theGame = new Game();
        System.out.println("==WELCOME TO THE ADVENTURE GAME==");
        // 2. Ask the user if they want to load a json file.
        Scanner in = new Scanner(System.in);
        System.out.print("Do you want to load the json File? (yes/no): ");
        String choice = in.next();
        System.out.println("");
      //  try {
            if (choice.toLowerCase().charAt(0) == 'n') {
                //theGame.loadAdventureJson(InputStream stream = new ByteArrayInputStream(sampleString.getBytes()));
                InputStream inpSt = new ByteArrayInputStream("example_adventure.json".getBytes());
                theGame.loadAdventureJson(inpSt);
            } else {
                System.out.print("Enter filename: ");
                String name = in.next();
                theGame.loadAdventureJson(name);
            }
//        } catch (FileNotFoundException ex) {
  //              Logger.getLogger(Game.class.getName()).log(Level.SEVERE, null, ex);
    //        }

        /* 3. Parse the file the user specified to create the
        adventure, or load your default adventure*/
        // 4. Print the beginning of the adventure
        // 5. Begin game loop here
        // 6. Get the user input. You'll need a Scanner
        System.out.println(adv.getCurrentRoomName());
        //System.out.println("This: "+adv.getConnectedRoom("S"));
        ArrayList<Item> items = adv.listAllItems();
        
        for (int a = 0; a < items.size(); a++) {
            System.out.print(items.get(a) + ", ");
        }
        
        System.out.println("");
        
        while (true) {
            System.out.println("Enter Input: ");
            String input = in.nextLine();
            String inp[] = input.split(" ");
            if (inp[0].equals("go")) {
                String direction = inp[1];
                if (direction.equals("N")) {
                    Room r = adv.getConnectedRoom("N");
                    if (r != null) {
                        System.out.println(r.getName());
                        items = adv.listAllItems();
                        for (int a = 0; a < items.size(); a++) {
                            System.out.print(items.get(a) + ", ");
                        }
                    }
                } else if (direction.equals("S")) {
                    Room r = adv.getConnectedRoom("S");
                    if (r != null) {
                        System.out.println(r.getName());
                        items = adv.listAllItems();
                        for (int a = 0; a < items.size(); a++) {
                            System.out.print(items.get(a) + ", ");
                        }
                    }
                } else if (direction.equals("W")) {
                    Room r = adv.getConnectedRoom("W");
                    if (r != null) {
                        System.out.println(r.getName());
                        items = adv.listAllItems();
                        for (int a = 0; a < items.size(); a++) {
                            System.out.print(items.get(a) + ", ");
                        }
                    }
                } else if (direction.equals("E")) {
                    Room r = adv.getConnectedRoom("E");
                    if (r != null) {
                        System.out.println(r.getName());
                        items = adv.listAllItems();
                        for (int a = 0; a < items.size(); a++) {
                            System.out.print(items.get(a) + ", ");
                        }
                    }
                } else if (direction.equals("E")) {
                    Room r = adv.getConnectedRoom("E");
                    if (r != null) {
                        System.out.println(r.getName());
                        items = adv.listAllItems();
                        for (int a = 0; a < items.size(); a++) {
                            System.out.print(items.get(a) + ", ");
                        }
                    }
                }
            } else if (inp[0].equals("look")) {
                System.out.println(adv.getCurrentRoomDescription());
            } else if (inp[0].equals("look") && inp[1] != null) {
                ArrayList<Item> itemsList = adv.listAllItems();
                for (int a = 0; a < itemsList.size(); a++) {
                    if(itemsList.get(a).equals(inp[1])){
                        System.out.println(itemsList.get(a).getLongDescription());
                    }
                }
            }
            else if (input.equalsIgnoreCase("quit")) {
                System.exit(0);
            }
            else if(inp[0].equals("take") && inp[1] != null){
                ArrayList<Item> itemsList = adv.listAllItems();
                for (int a = 0; a < items.size(); a++) {
                    if(itemsList.get(a).getName().equals(inp[1])){
                        carriedItems.add(itemsList.get(a));
                    }
                }
            }
            else if(input.equals("inventory")){
                for (int a = 0; a < carriedItems.size(); a++) {
                    System.out.println(carriedItems.get(a).getName());
                }
            }
            
            parser.parseUserCommand(input);

        }

        /* 7+. Use a game instance method to parse the user
        input to learn what the user wishes to do*/
        //use a game instance method to execute the users wishes*/

        /* if the user doesn't wish to quit,
        repeat the steps above*/
    }

    /* you must have these instance methods and may need more*/
    public JSONObject loadAdventureJson(InputStream inputStream) {
        return null;
    }
    
    public JSONObject loadAdventureJson(String filename) {    
        JSONParser parser = new JSONParser();
        JSONObject jsonObject = null;
        
        try {
            Object obj = parser.parse(new FileReader(filename));

            // A JSON object. Key value pairs are unordered. JSONObject supports java.util.Map interface.
            jsonObject = (JSONObject) obj;
            JSONObject adventure = (JSONObject) jsonObject.get("adventure");
            JSONArray rooms = (JSONArray) adventure.get("room");
            JSONArray items = (JSONArray) adventure.get("item");

            for (int a = 0; a < items.size(); a++) {
                JSONObject i = (JSONObject) items.get(a);
                int id = Integer.parseInt(i.get("id") + "");
                String name = String.valueOf(i.get("name"));
                String desc = String.valueOf(i.get("desc"));
                Item item = new Item(id, name, desc);
                adv.addItem(item);
            }
            
            for (int a = 0; a < rooms.size(); a++) {
                JSONObject r = (JSONObject) rooms.get(a);
                int id = Integer.parseInt(r.get("id") + "");
                boolean start = Boolean.parseBoolean(r.get("start") + "");
                String name = String.valueOf(r.get("name"));
                String shortdesc = String.valueOf(r.get("short_description"));
                String longdesc = String.valueOf(r.get("long_description"));
                Room room = new Room(id, start, name, shortdesc, longdesc);

                JSONArray entranceArray = (JSONArray) r.get("entrance");
                
                for (int b = 0; b < entranceArray.size(); b++) {
                    JSONObject ent = (JSONObject) entranceArray.get(b);
                    room.addEntrance(String.valueOf(ent.get("dir")), getRoom(Integer.parseInt("" + ent.get("id"))));
                    //System.out.println(name+", "+String.valueOf(ent.get("dir"))+": :"+getRoom(Integer.parseInt("" + ent.get("id"))));
                }
                
                adv.addRoom(room);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
        
        return jsonObject;
    }

    public Room getRoom(int id) {
        //System.out.println("ID: "+id);
        ArrayList<Room> rooms = adv.listAllRooms();
        for (int a = 0; a < rooms.size(); a++) {
            if (rooms.get(a).getId() == id) {
                //System.out.println("Get Room: "+id+" "+rooms.get(a).getName());
                return rooms.get(a);
            }
        }
        return null;
    }

    public Adventure generateAdventure(JSONObject obj) {

        return null;
    }

    public void setAdv(Adventure adv) {
        this.adv = adv;
    }

    public void setParser(Parser parser) {
        this.parser = parser;
    }

    public void setCarriedItems(ArrayList<Item> carriedItems) {
        this.carriedItems = carriedItems;
    }
    
    @Override 
    public String toString(){
        return "";
    }
}