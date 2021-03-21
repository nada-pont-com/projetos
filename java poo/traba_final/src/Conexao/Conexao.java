package Conexao;

import Interfaces.ListenerConexao;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.util.ArrayList;

public class Conexao extends Thread{
    private PrintStream printer;
    private Socket socket;
    private String mensagem;
    private ArrayList<ListenerConexao> listeners = new ArrayList();

    public Conexao(String mensagem){
        super();
        this.mensagem = mensagem;
    }

    @Override
    public void run() {
        try {
            socket = new Socket("25.81.21.225",7070);
            enviarMansagem(mensagem);
            lerDoServidor();
            excutaListeners();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
            falhaConexao();
        }
    }

    private void enviarMansagem(String mensagem) throws IOException {
        //mensagem = "{ \"login\": { \"user-id\": \"colocar aqui o nome do usuario\" } }";
        PrintStream printer = new PrintStream(socket.getOutputStream());
        printer.println(mensagem);
        printer.println();
    }

    private void lerDoServidor() throws IOException {
        String mensagem = "";
        if(socket.isConnected()) {
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String msg = reader.readLine();
            while (!msg.equals("")) {
                mensagem += msg;
                msg = reader.readLine();
            }
            reader.close();
        }
        this.mensagem = mensagem;
    }

    private void falhaConexao(){
        String mensagem = "{ \"falha\": { \"message\":\"Falha ao conectar no servidor\"} }";
        for (ListenerConexao listenerConexao :listeners){
            listenerConexao.error(mensagem);
        }
    }

    private void excutaListeners(){
        for (ListenerConexao listenerConexao :listeners){
            listenerConexao.success(mensagem);
        }
    }

    public void addListener(ListenerConexao listenerConexao) {
        listeners.add(listenerConexao);
    }
}
