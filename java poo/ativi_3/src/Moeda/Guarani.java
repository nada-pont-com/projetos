package Moeda;

public class Guarani extends Moeda {
    public Guarani(double valor) {
        super("₲", valor);
    }

    @Override
    public double converterDolar() {
        return valor*0.00015;
    }
}
