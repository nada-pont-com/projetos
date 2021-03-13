package Pais;

public class Cidade {
    private String nome;
    private int habitantes;
    private double renda;

    public double rendaPerCapita(){
        return  renda/habitantes;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setHabitantes(int habitantes) {
        this.habitantes = habitantes;
    }

    public int getHabitantes() {
        return habitantes;
    }

    public void setRenda(double renda) {
        this.renda = renda;
    }

    public double getRenda() {
        return renda;
    }

    @Override
    public String
    toString() {
        return "Pais.Cidade = {" +
                "nome='" + nome + '\'' +
                ", habitantes=" + habitantes +
                ", renda=" + renda +
                '}';
    }
}
