package Moeda;

public class MoedaFactory {
    private static MoedaFactory _this = null;

    public static MoedaFactory getFactory() {
        if(_this==null) _this = new MoedaFactory();
        return _this;
    }

    public Moeda create(Moedas moeda,double valor){

        Moeda a;
        switch (moeda){
            case Euro -> a = new Euro(valor);
            case Guarani -> a = new Guarani(valor);
            case Libra -> a = new Libra(valor);
            case Real -> a = new Real(valor);
            default -> a = new Dolar(valor);
        }
        return a;
    }
}
