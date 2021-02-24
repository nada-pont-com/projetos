public class Geladeira extends  Thread{
    private int nivelDaTemperatura;
    private Congelador   congelador;
    private Refrigerador refrigerador;
    private int time = 1_000;

    private static Geladeira _this;

    private Geladeira() {
        super();
        nivelDaTemperatura = 0;
        congelador = new Congelador();
        refrigerador = new Refrigerador();
        this.start();
    }

    public static Geladeira getInstance(){
        if (_this==null){
            _this = new Geladeira();
        }
        return _this;
    }

    @Override
    public void run() {
        while (true){
            try {
                controlarTemperatura();
                sleep(time);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    
    //Setter o valor para o nivelDaTemperatura.
    public void selecionarTemperatura(int nivel) {
        nivelDaTemperatura = nivel;
        refrigerador.selecionarTemperatura((nivel+1) * 5);
        congelador.selecionarTemperatura((nivel+1) * - 10);
    }
    //
    public void controlarTemperatura() {
        congelador.controlarTemperatura();
        refrigerador.controlarTemperatura();
    }

    public void addListenerRefrigerador(RefrigeradorListenerInter listener) {
         refrigerador.addListener(listener);
    }

    public void addListenerCongelador(RefrigeradorListenerInter listener) {
        congelador.addListener(listener);
    }

    public Refrigerador getRefrigerador() {
        return refrigerador;
    }
}
