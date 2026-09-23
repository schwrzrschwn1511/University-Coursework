
package ClassAll;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
/**
 *
 * @author Hani Hamizah
 */
public class Plant_User{
    Connection connect;
    private String name;
   private String username;
   private String passwd;
   private int ID;
   private String usertype;
    public Plant_User (int id, String FName, String UName, String Pass, String user_type)
    {
        this.name=FName;
        this.ID=id;
        this.username=UName;
        this.passwd=Pass;
        this.usertype=user_type;
    }

    public Plant_User(Object object, String name, String username, String password, String user) {
        
        throw new UnsupportedOperationException("Not supported yet."); 
    }
    
    public int getID()
    {
        return ID;
    }
    public String getName(String name)
    {
        return name;
    }
    public String getName()
    {
        return name;
    }
    
     public String getUName(String username)
    {
        return username;
        
    }
     
      public String getUName()
    {
        return username;
        
    }
      public String getPass(String passwd)
    {
        return passwd;
    }
     
       public String getPass()
    {
        return passwd;
    }
      public static void insertuser(Plant_User user)
      {
         Connection c = database.getConnection();
    PreparedStatement PS;

    try {
        // Exclude the ID column from the INSERT statement
        PS = c.prepareStatement("INSERT INTO `users`(`NAME`, `Username`, `Password`, `Usertype`) VALUES (?,?,?,?)");
        PS.setString(1, user.name);
        PS.setString(2, user.username);
        PS.setString(3, user.passwd);
        PS.setString(4, user.usertype);

        if (PS.executeUpdate() != 0) {
            JOptionPane.showMessageDialog(null, "New User Added");
        } else {
            JOptionPane.showMessageDialog(null, "Something Wrong");
        }
    } catch (SQLException ex) {
        Logger.getLogger(Plant_User.class.getName()).log(Level.SEVERE, null, ex);
    }
          
      }
      
       public static void deleteuser(int id)
      {
         Connection c = database.getConnection();
    PreparedStatement PS;

    try {
        // Exclude the ID column from the INSERT statement
        PS = c.prepareStatement("DELETE FROM `users` WHERE `id`=?");
        PS.setInt(1,id);
        int confirmation = JOptionPane.showConfirmDialog(null, "Do you want to delete this user?", "Deleting User", JOptionPane.YES_NO_CANCEL_OPTION);
       if (confirmation ==0)
       {
        if (PS.executeUpdate() != 0) {
            JOptionPane.showMessageDialog(null, "User Deleted");
        } else {
            JOptionPane.showMessageDialog(null, "Something Wrong");
        }
       }
    } catch (SQLException ex) {
        Logger.getLogger(Plant_User.class.getName()).log(Level.SEVERE, null, ex);
    }
          
      }
}
