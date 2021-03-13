import Arquivo.Leitor;
import Moeda.Moeda;
import Moeda.MoedaFactory;
import Moeda.Moedas;
import Pais.Cidade;
import Pais.Estado;
import Strings.Palindromo;

import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        Cidade cidade;
        Estado estado = new Estado();
        System.out.println(estado);

        for (int i =0 ;i<5;i++){
            cidade = new Cidade();
            cidade.setNome("Pais.Cidade "+(i+1));
            cidade.setRenda(((i*100 + 25)*250 +(-10*i)+25*i));
            cidade.setHabitantes(i*100 + 1);
            System.out.println(cidade.rendaPerCapita());
            System.out.println( Numero.verificaPar(cidade.rendaPerCapita()));
            estado.addCidade(cidade);
        }
        System.out.println(estado);
        System.out.println(estado.filtrarRendaPerCapta(50));

        System.out.println(Numero.verificaPar(2.2));

        System.out.println(new Palindromo().validaPalindromo("Roma me tem amor"));


        Leitor leitor = new Leitor();
        try {
            leitor.lerDoArquivo();
        } catch (IOException e) {
            e.printStackTrace();
        }

        Moeda moeda = MoedaFactory.getFactory().create(Moedas.Guarani,10000);
        System.out.println(moeda.converterDolar());
        moeda = MoedaFactory.getFactory().create(Moedas.Real,10000);
        System.out.println(moeda.converterDolar());
    }
}
