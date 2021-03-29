package Mensagem;

import Json.Array_js;

public class Mensagem {
    private String mensagem;
    private String assunto;
    private String rementente;
    private String destinatario;

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

    @Override
    public String toString() {
        return mensagem;
    }
}
