package ClassAll;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


/**
 *
 * @author Hani Hamizah
 */
public class database {
    
    private static String databasename = "malaysiaherbs";
    private static String username = "root";
    private static String passwd= "";
    
    static Connection connect=null;
    public static Connection getConnection()
    {
        if (connect != null)
            return connect;
        return getConnection(databasename,username,passwd);
    }
    
    private static Connection getConnection(String database_name, String user_name, String password)
    {
     try{
         Class.forName("com.mysql.cj.jdbc.Driver");
         connect = DriverManager.getConnection("jdbc:mysql://localhost/"+database_name+"?user="+user_name+"&password="+password);
         System.out.println("connected");
     }
     catch (Exception e)
             {
                 e.printStackTrace();
             }
     return connect;
    }
    
}
