import java.net.*;
import java.io.*;

public class Client
{
    public static void main(String arg[])throws IOException
    {
        System.out.println("Client application is Running...");

        Socket s = new Socket("localhost",2100);   // 127.0.0.1
        System.out.println("Client is waiting for server to accept the request ");

        PrintStream ps = new PrintStream(s.getOutputStream());
        BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));
        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

        String str1,str2;
        System.out.println("Enter message for server ..");
        while(!(str1 = br2.readLine()).equals("end"))
        {
            ps.println(str1);
            str2=br1.readLine();
            System.out.println("Server says.. "+str2);
            System.out.println("Enter message for server ..");
        }
    }
}