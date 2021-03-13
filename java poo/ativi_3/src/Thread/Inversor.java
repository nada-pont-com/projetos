package Thread;

public class Inversor  extends  Thread{
    private String texto;
    public Inversor(String texto){
        super();
        this.texto = texto;
        this.start();
    }

    public String getTexto() {
        return texto;
    }

    @Override
    public void run() {
        super.run();
        char []texto = this.texto.toCharArray();
        String a = "";

        for (int i = texto.length-1;i>=0;i--) {
            a += texto[i];
        }

        this.texto = a;
    }
}
