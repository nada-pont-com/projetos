package Conexao;

import Json.Conversor;
import Json.Json;
import File.Historico;
import Mensagem.Mensagem;

import java.io.*;
import java.net.Socket;

public class Conexao{
    private Socket socket;

    private static Conexao _this = null;

    public static Conexao getInstance(){
        if(_this==null) _this = new Conexao();
        return _this;
    }

    private Conexao(){}

    public String login(String user){
        String mensagem = "{ \"login\": { \"user-id\": \""+user+"\" } }";
        mensagem = conectar("login",mensagem);
        //return mensagem;
        return "{ \"okay\": { \"message\":\"login aceito” } }";
    }

    public boolean getMensagens(String user_id){
        String mensagem = ("{\"get\":{\"user-id\": \""+user_id+"\"}}");
        boolean mensagems = false;
        mensagem = conectar("get",mensagem);

        if(mensagem!=null){
            mensagems = true;
            Json mensagemsJson = Conversor.getJson(mensagem);

            Historico.getInstance().salvarMensagensRecebidas(mensagemsJson);
        }
        return mensagems;
    }

    public boolean enviarEmail(Mensagem mensagem){
        return enviarEmail(mensagem.toJson("send",true,false));
    }

    public boolean enviarEmail(Json json){
        String aux = "";
        aux = conectar("send",json.toString());

        Json info = Conversor.getJson(aux);

        return info.isKey("okay");
    }

    private String conectar(String lugar,String mensagem){
        String resposta = null;
        try {
            socket = new Socket("catolicasc-bigdata-valmor123.mybluemix.net",80);

            enviarMensagem(lugar, mensagem);
            resposta = lerDoServidor();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return resposta;
    }

    private void enviarMensagem(String lugar,String mensagem) throws IOException {
        mensagem = mensagem.replace(" ","%20");
        mensagem = mensagem.replace("\n","%0A");

        PrintStream printer = new PrintStream(socket.getOutputStream());
            //System.out.println("GET /"+lugar+"?json="+mensagem+" HTTP/1.1");
        printer.println("GET /"+lugar+"?json="+mensagem+" HTTP/1.1");
        printer.println("Accept: */*");
        printer.println("Host: catolicasc-bigdata-valmor123.mybluemix.net");
        printer.println("Connection: Close");

        //printer.println(mensagem);
        printer.println();
    }

    private String lerDoServidor() throws IOException {
        String mensagem = "";
        boolean valida = false;
        if(socket.isConnected()) {
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String msg = reader.readLine();
            while (msg!=null) {
                if(msg.isEmpty() && !valida){
                    valida = true;
                    mensagem="";
                }
                mensagem += msg;
                msg = reader.readLine();
            }
            reader.close();
        }

        System.out.println(mensagem);
        return mensagem;
    }
}
