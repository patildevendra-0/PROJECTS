import java.net.*;
import java.io.*;

public class Server
{
    public static void main(String arg[])throws IOException
    {
        System.out.println("Server Application is Running ....");

        InputStreamReader iobj = new InputStreamReader(System.in);
        BufferedReader bobj = new BufferedReader(iobj);

        System.out.println("Enter the newfile to to save your chat:");
        String Filename = bobj.readLine();

        File fobj = new File(Filename);
        boolean file = fobj.createNewFile();
        if(file == true)
        {
            System.out.println("____________________________________________________________________________");
            System.out.println("File is successfully created");
        }
        else
        {
            System.out.println("Unable to create file");
            System.out.println("Pls enter file name which is not created yet");
            Filename = bobj.readLine();
            File fobj1 = new File(Filename);
            fobj1.createNewFile();
            
        }
        System.out.print("___________________________________________________________________________");
        System.out.println("");

        ServerSocket ss = new ServerSocket(2100);
        System.out.println("Server is Running at port no.2100 and waiting for client request..");

        Socket s = ss.accept();
        System.out.println("Request of client is Accepted ..");

        PrintStream ps = new PrintStream(s.getOutputStream());
        BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));
        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

        FileOutputStream outobj = new FileOutputStream(Filename);

        String client = "Client says: ";
        byte cdata[] = client.getBytes();

        String server = "Server says: ";
        byte sdata[] = server.getBytes();

        String enter = "\n";
        byte en[] = enter.getBytes();
        String str1,str2;

        while((str1=br1.readLine())!=null)
        {
            outobj.write(cdata);
            byte Data1[] = str1.getBytes();
            outobj.write(Data1);
            outobj.write(en);

            System.out.println("Client says.. "+str1);
            System.out.println("Enter message for client ..");
            str2=br2.readLine();
            ps.println(str2);

            byte Data2[] = str2.getBytes();
            outobj.write(sdata);
            outobj.write(Data2);
            outobj.write(en);
        }
    }
}