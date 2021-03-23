package Mensagem;

import Json.Array_js;

public class Mensagem {
    private String mensagem;
    private String assunto;
    private String rementente;

    public Mensagem(){

    }

    public Mensagem(Array_js mensagem){
        this.mensagem = mensagem.getValuesAsKey("texto").getValue();
        this.assunto = mensagem.getValuesAsKey("assunto").getValue();
        this.rementente = mensagem.getValuesAsKey("remetente").getValue();
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

    @Override
    public String toString() {
        return mensagem;
    }
}
