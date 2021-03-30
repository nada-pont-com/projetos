package Mensagem;

import java.util.ArrayList;

public class Mensagens {

    private static ArrayList<Mensagem> mesagens = new ArrayList<Mensagem>();
    private static Mensagens _this;

    public static Mensagens getInstencia(){
        if(_this==null) _this = new Mensagens();
        return _this;
    }

    private Mensagens(){}

    public void addMensagem(Mensagem mensagem){
        mesagens.add(mensagem);
    }
}
