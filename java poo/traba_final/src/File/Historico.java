package File;

import Json.Array_js;
import Json.Conversor;
import Json.Json;
import Mensagem.Mensagem;

import java.io.IOException;
import java.util.ArrayList;
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

    private boolean salvar(GerenciadorArquivos file,Json novas, boolean id){
        if(validaArquivo(file)){
            try {
                if(novas.isKey("mensagens")){
                    Json json = Conversor.getJson(file.lerDoArquivo());

                    Array_js mensagens = json.getArray_js("mensagens");
                    Array_js novasMensagens = novas.getArray_js("mensagens");

                    if(novasMensagens.getKeys().size()==0){
                        return true;
                    }

                    int idNumber = 0;
                    if(mensagens==null){
                        mensagens = novasMensagens;
                        if(mensagens.getLastValue().getValuesAsKey("_id").getValue()==null){
                            mensagens.getLastValue().updateValueAsKey("_id",idNumber+"");
                        }
                    }else{
                        boolean valida;
                        ArrayList<String> keys =  mensagens.getKeys();

                        for (String key : novasMensagens.getKeys()){
                            Array_js aux = novasMensagens.getValuesAsKey(key);
                            valida = true;
                            int i =0;
                            if(id){
                                if(aux.getValuesAsKey("_id").getValue()==null){
                                    Array_js aux2 =  mensagens.getLastValue();
                                    idNumber = Integer.parseInt(aux2.getValuesAsKey("_id").getValue()) + 1;
                                    aux.updateValueAsKey("_id",idNumber+"");
                                }else{
                                    for (i = 0; i < keys.size();i++){
                                        String temp = mensagens.getValuesAsKey(keys.get(i)).getValuesAsKey("_id").getValue();
                                        if(temp.equals(aux.getValuesAsKey("_id").getValue())){
                                            valida = false;
                                            break;
                                        }
                                    }
                                }
                            }

                            if(valida)
                                mensagens.setValue(aux);
                            else{
                                mensagens.updateValueAsKey(keys.get(i),aux);
                                keys.remove(i);
                            }
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
        return salvar(gerenciadorArquivos,rascunho,true);
    }

    public boolean salvarMensagensRecebidas(Json novas){
        GerenciadorArquivos gerenciadorArquivos = new GerenciadorArquivos("recebidos");
        return salvar(gerenciadorArquivos,novas,true);
    }

    public boolean salvarMensagensEnviadas(Json novas){
        GerenciadorArquivos gerenciadorArquivos = new GerenciadorArquivos("enviadas");
        return salvar(gerenciadorArquivos,novas,false);
    }

    public Vector<Mensagem> getMensagesRascunhos(){
        GerenciadorArquivos gerenciadorArquivos = new GerenciadorArquivos("rascunhos");
        return getMensagens(gerenciadorArquivos);
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
                //System.out.println(json);

                mensagensJson = json.getArray_js("mensagens");
                //mensagensJson = mensagensJson.getValuesAsKey("mensagens");

                if(mensagensJson!=null){
                    //System.out.println(mensagensJson);
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

    public void removeRascunho(Json novas){
        GerenciadorArquivos file = new GerenciadorArquivos("rascunhos");
        if(validaArquivo(file)){
            boolean id = true;
            try {
                if(novas.isKey("mensagens")){
                    Json json = Conversor.getJson(file.lerDoArquivo());

                    Array_js mensagens = json.getArray_js("mensagens");
                    Array_js novasMensagens = novas.getArray_js("mensagens");
                    if(novasMensagens.getKeys()==null || mensagens==null){
                        return;
                    }

                    ArrayList<String> keys =  mensagens.getKeys();

                    for (String key : novasMensagens.getKeys()){
                        Array_js aux = novasMensagens.getValuesAsKey(key);
                        int i;
                        if(aux.getValuesAsKey("_id").getValue()!=null)
                            for (i = 0; i < keys.size();i++){
                                if(mensagens.getValuesAsKey(keys.get(i)).getValuesAsKey("_id").getValue().equals(aux.getValuesAsKey("_id").getValue())){
                                    mensagens.removeArrayByKey(keys.get(i));
                                }
                            }
                    }

                    json.updateValueAsKey("mensagens",mensagens);
                    file.escreverNoArquivo(json.toString());
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
