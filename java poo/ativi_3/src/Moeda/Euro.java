package Moeda;

public class Euro extends Moeda {
    public Euro(double valor) {
        super("€", valor);
    }

    @Override
    // @info cotação 13 de mar. 08:18 UTC
    public double converterDolar() {
        return valor*1.2;
    }
}
