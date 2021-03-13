package Arquivo;

import java.io.*;

public class GerenciadorArquivos {

    private File file;
    public GerenciadorArquivos(String nome) {
        file = new File(nome+".txt");
    }

    public void escreverNoArquivo(String texto) throws IOException {
        PrintStream ps = new PrintStream(file);
        ps.println(texto);
        ps.close();
    }

    public boolean existe(){
        return file.exists();
    }

    public String lerDoArquivo() throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(file));
        String resposta = "";
        String temp = br.readLine();
        if(temp != null) {
            resposta+= temp;
            temp = br.readLine();
        }
        br.close();
        return resposta;
    }

}
