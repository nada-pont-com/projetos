package Moeda;

public class Real extends Moeda {

    public Real(double valor) {
        super("R$", valor);
    }

    @Override
    public double converterDolar() {
        return valor*1/5.55;
    }
}
