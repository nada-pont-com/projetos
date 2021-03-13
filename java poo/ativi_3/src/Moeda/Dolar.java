package Moeda;

public class Dolar extends Moeda{

    public Dolar(double valor) {
        super("US$", valor);
    }

    @Override
    public double converterDolar() {
        return valor;
    }
}
