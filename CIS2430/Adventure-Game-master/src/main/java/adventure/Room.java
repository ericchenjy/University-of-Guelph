package adventure;

import java.util.ArrayList;
import java.util.HashMap;
import java.io.Serializable;

public class Room implements Serializable {
    /* you will need to add some private member variables */
    private int id;
    private boolean start;
    private String name;
    private String shortDesc;
    private String longDesc;
    ArrayList<Item> items = new ArrayList<>();
    HashMap<String, Room> entrance = new HashMap<>();
    
    Room(){
        id = 0;
        start = false;
        name = "";
        shortDesc = "";
        longDesc = "";
        items = new ArrayList<>();
        entrance = new HashMap<>();
    }
    
    /* required public methods */

    public ArrayList<Item> listItems(){
        //lists all the items in the room
        return items;
    }

    public String getName(){
        return name;
    }

    public String getLongDescription(){
        return longDesc;
    }

    public Room getConnectedRoom(String direction) {
        
        if(entrance.containsKey(direction)){
            return entrance.get(direction);
        }
        return null;
    }

    /* you may wish to add some helper methods*/

    public Room(int id, boolean start, String name, String shortDesc, String longDesc) {
        this.id = id;
        this.start = start;
        this.name = name;
        this.shortDesc = shortDesc;
        this.longDesc = longDesc;
    }
    
    public void addEntrance(String direction, Room room){
        entrance.put(direction, room);
    }
    
    public void addItem(Item item){
        items.add(item);
    }

    public int getId() {
        return id;
    }
    
    public void setId(int id){
        this.id = id;
    }
    
    public void setStart(boolean start) {
        this.start = start;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setShortDesc(String shortDesc) {
        this.shortDesc = shortDesc;
    }

    public void setLongDesc(String longDesc) {
        this.longDesc = longDesc;
    }
    
    public void setItems(ArrayList<Item> items) {
        this.items = items;
    }

    public void setEntrance(HashMap<String, Room> entrance) {
        this.entrance = entrance;
    }
    
    @Override
    public String toString() {
        return "ID: " + id + ", Start: " + start + ", Name: " + name + ", Short Desc: " + shortDesc + ", Long Desc: " + longDesc;
    }
    
}