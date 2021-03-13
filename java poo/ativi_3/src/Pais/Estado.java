package Pais;

import java.util.ArrayList;

public class Estado {
    private String nome;
    private ArrayList<Cidade> cidades = new ArrayList<>();

    public void addCidade(Cidade cidade) {
        this.cidades.add(cidade);
    }

    public ArrayList<Cidade> filtrarRendaPerCapta(float x) {
        ArrayList<Cidade> cidades = new ArrayList<>();
        for (Cidade cidade : this.cidades){
            if(cidade.rendaPerCapita() > x) cidades.add(cidade);
        }
        return cidades;
    }

    @Override
    public String toString() {
        String retorno = "Pais.Estado{" +
                "nome='" + nome + '\'' +
                ", cidades=[";
        for (Cidade cidade : cidades){
            retorno += cidade.toString();
        }
        retorno += "]}";
        return retorno;
    }
}
