import java.io.*;
import java.net.InetAddress;
import java.net.Socket;

public class Main {
    public static void main(String[] args) {
        try {
//            Socket socket = new Socket("25.81.21.225", 7070);
//            PrintStream a = new PrintStream(socket.getOutputStream());
//            a.println("teste - testando");
//            a.println("sair");
//            System.out.println("Criando o socket...");
//            System.out.println("Conectado... " + socket.isConnected());
//            socket.close();
            Socket s = new Socket(InetAddress.getByName("www.google.com"), 80);
            System.out.println("Conectado... " + s.isConnected());

            PrintStream pw = new PrintStream(s.getOutputStream());
            pw.println("GET / HTTP/1.1");
            pw.println();
            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));

            String t;
            while((t = br.readLine()) != null){
                System.out.println(t);
            }

            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
