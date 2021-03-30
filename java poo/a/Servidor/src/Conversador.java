import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public class Conversador extends Thread {
    private Socket cliente;
    private boolean isRunning = false;
    private BufferedReader reader;

    public Conversador(Socket alguem) {
        cliente = alguem;
        System.out.println("Conversador" + this.getName());
        isRunning = true;
    }
    // Aqui vamos fazer a leitura e a escrita... a conversa acontece aqui.
    public void run() {
        try {
            conversar();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void conversar() throws Exception {
        String mensagem = "";
        InputStreamReader inputStreamReader = new InputStreamReader(cliente.getInputStream());
        reader = new BufferedReader(inputStreamReader);
        int contador = 0;
        String msg = reader.readLine();
        System.out.println("Mensagem " + (++contador) + " eh: " + msg);
        while(!msg.equals("")) {
            mensagem += msg;
            msg = reader.readLine();
            System.out.println("Mensagem " + (++contador) + " eh: " + msg);
        }
        System.out.println("Mensagem eh: " + mensagem);

        //reader.close();
        PrintStream printStream = new PrintStream(cliente.getOutputStream());
        printStream.println("{\"okay\": {\"user-id\":\"jose-42\"}}");
        /*printStream.println("{ \"login\": { \"user-id\": \"colocar aqui o nome do usuario\"," +
                "\"user-id-2\": \"colocar aqui\" },\"msg\": \"teste\" }");*/
        printStream.println();
        // System.out.println("Conversador fechando..." + this.getName());
        cliente.close();
    }
}
