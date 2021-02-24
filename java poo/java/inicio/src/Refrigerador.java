import java.util.ArrayList;

public class Refrigerador {
    protected float temperaturaSelecionada;
    protected Carga ventilador;
    protected SensorDeTemperatura sensorTemperaturaAtual;
    protected float temAnterior;
    private final ArrayList<RefrigeradorListenerInter> listaDeListeners = new ArrayList<>();

    public Refrigerador(){
        ventilador = new Carga();
        sensorTemperaturaAtual = new SensorDeTemperatura();
        temAnterior = sensorTemperaturaAtual.getTemperaturaAtual();
    }

    public float getTemperatura(){ return sensorTemperaturaAtual.getTemperaturaAtual();}
    
    //Setter para temperatura (Celsius).
    public void selecionarTemperatura(float temperatura) {
        temperaturaSelecionada = temperatura;
    }
    
    public void controlarTemperatura() {
        if(temAnterior!=sensorTemperaturaAtual.getTemperaturaAtual()){
            executa();
            temAnterior = sensorTemperaturaAtual.getTemperaturaAtual();
        }
        if(sensorTemperaturaAtual.getTemperaturaAtual() > temperaturaSelecionada) {
            ventilador.ligar();
        } else {
            ventilador.desligar();
        }
    }

    private void executa(){
        for (RefrigeradorListenerInter refrigeradorListener: listaDeListeners) {
            refrigeradorListener.modancaTemp(sensorTemperaturaAtual.getTemperaturaAtual());
        }
    }

    public void addListener(RefrigeradorListenerInter a) {
        listaDeListeners.add(a);
    }
}