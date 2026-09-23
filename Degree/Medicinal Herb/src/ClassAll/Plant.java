
package ClassAll;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import malaysiaherb.MAIN_WINDOW;

/**
 *
 * @author Hani Hamizah
 */
public class Plant {
       private int id;
    private String Name;
    private String Scientific_name;
    private String Description;
    private String Plant_Usage;
    private byte[] plantimg;
    private String plantype;
    private double price;
    Connection connect;

    public Plant(int pid, String pName, String pSN, String pD, String pUse, String pT, byte[] pimg, double pprice) {
        this.id = pid;
        this.Name = pName;
        this.Scientific_name = pSN;
        this.Plant_Usage = pUse;
        this.Description = pD;
        this.plantimg = pimg;
        this.plantype = pT;
        this.price=pprice;
    }
    public Plant(){}

    // Getters and setters for all fields
     public double getPrice() {
        return price;
    }

    public void setprice(double price) {
        this.price = price;
    }
    
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return Name;
    }

    public void setName(String Name) {
        this.Name = Name;
    }

    public String getSN() {
        return Scientific_name;
    }

    public void setSN(String Scientific_name) {
        this.Scientific_name = Scientific_name;
    }

    public String getDesc() {
        return Description;
    }

    public void setDesc(String Description) {
        this.Description = Description;
    }

    public String getPS() {
        return Plant_Usage;
    }

    public void setPS(String Plant_Usage) {
        this.Plant_Usage = Plant_Usage;
    }

    public String getPT() {
        return plantype;
    }

    public void setPT(String plantype) {
        this.plantype = plantype;
    }

    public byte[] getImage() {
        return plantimg;
    }

    public void setImage(byte[] plantimg) {
        this.plantimg = plantimg;
    }

    public ArrayList<Plant> getPlantlist(String plantname){
        
        ArrayList<Plant> plant_list = new ArrayList<>();
       
       connect = database.getConnection();
        ResultSet rs;
        PreparedStatement ps;

               String query = "SELECT `ID`, `Name`, `Scientific_Name`, `Description`, `Plant_Usage`,`Plant_type`,`Plant_Image` FROM `plants`";
        
        try {
            ps = connect.prepareStatement(query);
            rs = ps.executeQuery();
           
            Plant plant;
           
            while(rs.next()){
                plant = new Plant(rs.getInt("id"), 
                                 rs.getString("Name"),
                                 rs.getString("Scientfic_name"),
                                 rs.getString("Description"),
                                 rs.getString("Plant_Usage"),
                               
                                rs.getString("plantype"),
                                 rs.getBytes("plantimg"),
                        rs.getDouble("price")
                        
                        
                                 );
                
                plant_list.add(plant);
            }
        
        } catch (SQLException ex) {
            Logger.getLogger(Plant.class.getName()).log(Level.SEVERE, null, ex);
        }
        return plant_list;
         
        
    }
      
    }
          
         /*public void ShowPlant(int index, String planttype)
         {
             malaysiaherb.MAIN_WINDOW mainwindow=new malaysiaherb.MAIN_WINDOW();
             mainwindow.jTextField_commonname.setString(getPlantlist().get(index).getName(),plantype);
         }*/

