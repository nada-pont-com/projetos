package Moeda;

public abstract class Moeda {
    protected String simbulo;
    protected double valor;
    public Moeda(String simbulo,double valor){
        this.valor = valor;
        this.simbulo = simbulo;
    }
    // @return cotação 13 de mar. 08:18 UTC
    public abstract double converterDolar();
}
