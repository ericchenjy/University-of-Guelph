package adventure;

import java.util.ArrayList;
import java.io.Serializable;

public class Player implements Serializable {
    
    private String name;
    private Room currentRoom;
    private String saveGame;
    private ArrayList<Item> items;
    
    Player(){
        name = "";
        currentRoom = null;
        saveGame = "";
        items = new ArrayList<>();
    }

    public Player(String name, Room currentRoom, String saveGame) {
        this.name = name;
        this.currentRoom = currentRoom;
        this.saveGame = saveGame;
        items = new ArrayList<>();
    }
    
    public String getName(){
        return name;
    }
    
    public ArrayList<Item> getInventory(){
        return items;
    }
    
    public Room getCurrentRoom(){
        return currentRoom;
    }
    
    public String getSaveGameName(){
        return saveGame;
    }
    
    public void setName(String name) {
        this.name = name;
    }

    public void setCurrentRoom(Room currentRoom) {
        this.currentRoom = currentRoom;
    }

    public void setSaveGame(String saveGame) {
        this.saveGame = saveGame;
    }

    public void setItems(ArrayList<Item> items) {
        this.items = items;
    }
    
    @Override
    public String toString() {
        return "Name: " + name + ", Current Room: " + currentRoom + ", Save Game Name: " + saveGame;
    }
}