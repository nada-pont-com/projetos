package Programas;

import java.util.ArrayList;

public class Contador {
    private int valor;
    private ArrayList<Interface.Contador> listenerContador = new ArrayList<>();

    public void incrementar(){
        valor++;
        executa();
    }

    public void decrementar(){
        valor--;
        executa();
    }

    private void executa(){
        for (Interface.Contador contador : listenerContador) {
            contador.oValorMudou(valor);
        }
    }

    public void addListener(Interface.Contador contadorListener){
        listenerContador.add(contadorListener);
    }
}
