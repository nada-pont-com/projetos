package Conexao;

import Json.Conversor;
import Json.Json;
import File.Historico;
import Mensagem.Mensagem;

import java.io.*;
import java.net.Socket;

public class Conexao{
    private PrintStream printer;
    private Socket socket;

    private static Conexao _this = null;

    public static Conexao getInstance(){
        if(_this==null) _this = new Conexao();
        return _this;
    }

    private Conexao(){}

    public String login(String user){
        String mensagem = "{ \"login\": { \"user-id\": \""+user+"\" } }";
        //conectar(mensagem);
        return "{\"okay\": {\"user-id\":\"jose\"}}";
    }

    public boolean getMensagens(String user_id){
        String mensagem = ("{\"get\":{\"user-id\": \""+user_id+"\"}}");
        boolean mensagems = false;
        mensagem = conectar(mensagem);

        if(mensagem!=null){
            mensagems = true;
            mensagem = "{\"mensagens\": []}";
            Json mensagemsJson = Conversor.getJson(mensagem);

            Historico.getInstance().salvarMensagensRecebidas(mensagemsJson);
        }
        return mensagems;
    }

    public boolean enviarEmail(Mensagem mensagem){
        return enviarEmail(mensagem.toJson("send",true));
    }

    public boolean enviarEmail(Json json){
        String aux = "{\n" +
            " \"send\": {\n" +
            " \"remetente\": \"nome do remetente\",\n" +
            " \"destinatario\": \"nome do destinatario\",\n" +
            " \"assunto\": \"nononono\",\n" +
            " \"texto\": \"nononononononono\"\n" +
        " }";
        aux = conectar(json.toString());

        Json info = Conversor.getJson(aux);

        return info.isKey("okay");
    }


    private String conectar(String mensagem){
        String resposta = null;
        try {
            socket = new Socket("25.81.21.225",80);
            //socket = new Socket("catolicasc-bigdata-valmor123.mybluemix.net",80);

            //socket = new Socket("viacep.com.br",80);
            enviarMensagem(mensagem);
            resposta = lerDoServidor();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return resposta;
    }

    private void enviarMensagem(String mensagem) throws IOException {
        //mensagem = "{\"login\"={\"user-id\":\"user\"}}";
        //mensagem = mensagem.replace(" ","%20");

        PrintStream printer = new PrintStream(socket.getOutputStream());

        //printer.println("GET /mensagem?valor="+mensagem+" HTTP/1.1");
        //printer.println("Accept: */*");
        /*printer.println("Host: catolicasc-bigdata-valmor123.mybluemix.net");
        printer.println("Connection: Close");*/

        printer.println(mensagem);
        printer.println();
    }

    private String lerDoServidor() throws IOException {
        String mensagem = "";
        if(socket.isConnected()) {
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String msg = reader.readLine();
            System.out.println(msg);
            while (msg!=null) {
                System.out.println(msg);
                mensagem += msg;
                msg = reader.readLine();
            }
            reader.close();
        }
        /*BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String line;
        StringBuilder response = new StringBuilder();
        boolean headerDone = false;
        Map<String, String> responseMap = new HashMap<>();
        System.out.println("Fetching response. Please wait...");
        while ((line = bufferedReader.readLine()) != null) {
            response.append(line + "\n");
            if (line.isEmpty() && !headerDone) {
                responseMap.put("header", response.toString());
                headerDone = true;
                response = new StringBuilder();
            }
        }
        responseMap.put("content", response.toString());
        System.out.println(response.toString());*/
        return mensagem;
    }
}
