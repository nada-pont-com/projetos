package File;

import Json.Array_js;
import Json.Conversor;
import Json.Json;
import Mensagem.Mensagem;

import javax.print.attribute.standard.Sides;
import java.io.IOException;
import java.util.Vector;

public class Historico {
    private static Historico _this = null;

    private Historico(){}

    public static Historico getInstance(){
        if(_this==null) _this = new Historico();
        return _this;
    }

    private boolean validaArquivo(GerenciadorArquivos file){
        if(!file.existe()){
            try {
                file.escreverNoArquivo("");
            } catch (IOException e) {
                e.printStackTrace();
                return false;
            }
        }
        return true;
    }

    private boolean salvar(GerenciadorArquivos file,Json novas){
        if(validaArquivo(file)){
            try {
                if(novas.isKey("mensagens")){
                    Json json = Conversor.getJson(file.lerDoArquivo());

                    Array_js mensagens = json.getArray_js("mensagens");
                    Array_js novasMensagens = novas.getArray_js("mensagens");
                    if(novasMensagens.getKeys()==null){
                        return true;
                    }
                    if(mensagens==null){
                        mensagens = novasMensagens;
                    }else{
                        Mensagem msg = null;
                        for (String key : novasMensagens.getKeys()){
                            msg = new Mensagem(novasMensagens.getValuesAsKey(key));
                            mensagens.setValue(msg.toJson("key").getArray_js("key"));
                        }
                    }

                    json.updateValueAsKey("mensagens",mensagens);
                    file.escreverNoArquivo(json.toString());
                }

            } catch (IOException e) {
                e.printStackTrace();
                return false;
            }
            return true;
        }
        return false;
    }

    public boolean salvarRascunhos(Json rascunho) {
        GerenciadorArquivos gerenciadorArquivos = new GerenciadorArquivos("rascunhos");
        return salvar(gerenciadorArquivos,rascunho);
    }

    public boolean salvarMensagensRecebidas(Json novas){
        GerenciadorArquivos gerenciadorArquivos = new GerenciadorArquivos("recebidos");
        return salvar(gerenciadorArquivos,novas);
    }

    public boolean salvarMensagensEnviadas(Json novas){
        GerenciadorArquivos gerenciadorArquivos = new GerenciadorArquivos("enviadas");
        return salvar(gerenciadorArquivos,novas);
    }

    public Vector<Mensagem> getMensagesRecebidas(){
        GerenciadorArquivos gerenciadorArquivos = new GerenciadorArquivos("recebidos");
        return getMensagens(gerenciadorArquivos);
    }

    public Vector<Mensagem> getMensagesEnviadas() {
        GerenciadorArquivos gerenciadorArquivos = new GerenciadorArquivos("enviadas");
        return getMensagens(gerenciadorArquivos);
    }

    private Vector<Mensagem> getMensagens(GerenciadorArquivos gerenciadorArquivos){

        Array_js mensagensJson;
        Vector<Mensagem> mensagems = new Vector<>();
        if(validaArquivo(gerenciadorArquivos)){
            try {
                String test = gerenciadorArquivos.lerDoArquivo();
                Json json = Conversor.getJson(test);

                mensagensJson = json.getArray_js("mensagens");
                //mensagensJson = mensagensJson.getValuesAsKey("mensagens");

                if(mensagensJson!=null){
                    System.out.println(mensagensJson);
                    for (String string : mensagensJson.getKeys()){

                        mensagems.add(new Mensagem(mensagensJson.getValuesAsKey(string)));
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        return mensagems;
    }
}
