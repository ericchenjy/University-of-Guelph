package adventure;
 
import java.util.ArrayList;
import java.io.Serializable;

public class Adventure implements Serializable{
    /* you will need to add some private member variables */
    private int current = 0;
    private ArrayList<Room> rooms = new ArrayList<>();
    private ArrayList<Item> items = new ArrayList<>();
    /* ======== Required public methods ========== */
        /* note,  you don't have to USE all of these
        methods but you do have to provide them.
        We will be using them to test your code */

    public ArrayList<Room> listAllRooms(){
        return rooms;
    }

    public ArrayList<Item> listAllItems(){
        return items;
    }
    
    public void setCurrent(int current){
        this.current = current;
    }
    
    public void setRooms(ArrayList<Room> rooms){
        this.rooms = rooms;
    }
    
    public void setItems(ArrayList<Item> items){
        this.items = items;
    }

    public String getCurrentRoomDescription(){
        return rooms.get(current).getLongDescription();
    }

    /* you may wish to add additional methods*/
    public void addItem(Item item){
        items.add(item);
    }
    
    public void addRoom(Room room){
        rooms.add(room);
    }
    
    public String getCurrentRoomName(){
        return rooms.get(current).getName();
    }
    
    public Room getConnectedRoom(String direction){
        return rooms.get(current).getConnectedRoom(direction);
    }
    
    @Override
    public String toString(){
        return "";
    }
}