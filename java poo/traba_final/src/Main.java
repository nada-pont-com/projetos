import Janelas.JanelaInicial;
import Json.Conversor;
import Json.Json;

public class Main {
    public static void main(String[] args) {
        Json a =  Conversor.getJson("{\"mensagens\":[]}");
        System.out.println(a.getArray_js("mensagens").getKeys());
        JanelaInicial b = new JanelaInicial();
    }
}
