public class Main {
    public static void main(String[] args) {
        Geladeira geladeira = Geladeira.getInstance();
        geladeira.selecionarTemperatura(1);
        Janela jp = new Janela(geladeira);
        jp.setVisible(true);
    }
}
