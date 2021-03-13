package Moeda;

public class Libra extends Moeda {

    public Libra    (double valor) {
        super("£", valor);
    }

    @Override
    // Libra esterlina
    public double converterDolar() {
        return valor*1.39;
    }
}
