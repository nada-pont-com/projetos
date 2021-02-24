import java.util.Random;

public class SensorDeTemperatura extends Thread{
    private float temperaturaAtual;

    public SensorDeTemperatura(){
        super();
        this.start();
    }

    @Override
    public void run() {
        Random random = new Random();
        while (true){
            this.setTemperaturaAtual(random.nextInt(100) + random.nextFloat());
            try {
                sleep(1_000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    public float getTemperaturaAtual() {
        return temperaturaAtual;
    }

    public void setTemperaturaAtual(float temperaturaAtual) {
        this.temperaturaAtual = temperaturaAtual;
    }
}
