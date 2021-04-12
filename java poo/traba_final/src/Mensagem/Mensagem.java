package Mensagem;

import Json.Array_js;
import Json.Json;

public class Mensagem {
    private String id;
    private String mensagem;
    private String assunto;
    private String rementente;
    private String destinatario;
    private boolean enviar = false;

    public Mensagem(){}

    public Mensagem(Array_js mensagem){
        Array_js aux = mensagem.getValuesAsKey("texto");
        System.out.println(mensagem);
        if(aux!=null){
            this.mensagem = aux.getValue();
            this.assunto = mensagem.getValuesAsKey("assunto").getValue();
            this.rementente = mensagem.getValuesAsKey("remetente").getValue();
            this.destinatario = mensagem.getValuesAsKey("destinatario") != null ? mensagem.getValuesAsKey(
                    "destinatario").getValue() : null;
            this.id = mensagem.getValuesAsKey("_id") != null ? mensagem.getValuesAsKey(
                    "_id").getValue() : null;
        }
    }

    public String getAssunto() {
        return assunto;
    }

    public void setAssunto(String assunto) {
        this.assunto = assunto;
    }

    public String getMensagem() {
        return mensagem;
    }

    public void setMensagem(String mensagem) {
        this.mensagem = mensagem;
    }

    public String getRementente() {
        return rementente;
    }

    public void setRementente(String rementente) {
        this.rementente = rementente;
    }

    public String getDestinatario() {
        return destinatario;
    }

    public void setDestinatario(String destinatario) {
        this.destinatario = destinatario;
    }

    public boolean isEnviar() {
        return enviar;
    }

    public void setEnviar(boolean enviar) {
        this.enviar = enviar;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Json toJson(String key, boolean enviar, boolean lista){
        setEnviar(enviar);
        return toJson(key,lista);
    }

    public Json toJson(String key,boolean lista){

        Json json = new Json();

        Array_js aux = new Array_js(key,"");

        aux.setValue(new Array_js("texto",mensagem));
        aux.setValue(new Array_js("assunto",assunto));
        aux.setValue(new Array_js("remetente",rementente));
        if(enviar){
            aux.setValue(new Array_js("destinatario",destinatario));
        }
        if(lista){
            aux.setValue(new Array_js("_id",id));
            Array_js extra =  new Array_js(key,"");
            extra.setList();
            extra.setValue(aux);
            aux = extra;
        }
        json.setArray_js(aux);
        System.out.println(json);

        return json;
    }

    @Override
    public String toString() {
        return mensagem.equals("")? "Sem Mensagem" :  mensagem;
    }
}
