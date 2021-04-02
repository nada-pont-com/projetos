package Mensagem;

import Json.Array_js;
import Json.Json;

public class Mensagem {
    private String mensagem;
    private String assunto;
    private String rementente;
    private String destinatario;
    private boolean enviar = false;

    public Mensagem(){}

    public Mensagem(Array_js mensagem){
        Array_js aux = mensagem.getValuesAsKey("texto");
        if(aux!=null){
            this.mensagem = aux.getValue();
            this.assunto = mensagem.getValuesAsKey("assunto").getValue();
            this.rementente = mensagem.getValuesAsKey("remetente").getValue();
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

    public Json toJson(String key, boolean enviar){
        setEnviar(enviar);
        return toJson(key);
    }

    public Json toJson(String key){
        Json json = new Json();

        Array_js aux = new Array_js(key,"");

        aux.setValue(new Array_js("texto",mensagem));
        aux.setValue(new Array_js("assunto",assunto));
        aux.setValue(new Array_js("remetente",rementente));
        if(enviar){
            aux.setValue(new Array_js("destinatario",destinatario));
        }

        json.setArray_js(aux);
        System.out.println(json);

        return json;
    }

    @Override
    public String toString() {
        return mensagem;
    }
}
