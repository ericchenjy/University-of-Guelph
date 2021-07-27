package adventure;
 
import java.io.Serializable;

public class Item implements Serializable {
    /* you will need to add some private member variables */
    private int id;
    private String name;
    private String desc;
    
    /* required public methods */

    public String getName(){
        return name;
    }

    public String getLongDescription(){
        return desc;
    }

    public Room getContainingRoom(){
        //returns a reference to the room that contains the item
        return null;
    }
    
    @Override
    public String toString(){
        return name;
    }

    /* you may wish to add some helper methods*/
    Item(){
        this.id = 0;
        this.name = "";
        this.desc = "";
    }
    
    public Item(int id, String name, String desc) {
        this.id = id;
        this.name = name;
        this.desc = desc;
    }
    
    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }
}