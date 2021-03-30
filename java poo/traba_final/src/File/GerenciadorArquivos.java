package File;

import java.io.*;

public class GerenciadorArquivos {

    private File file;

    public GerenciadorArquivos(String nome) {
        file = new File(nome+".json");
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
        while(temp != null) {
            resposta+= temp;
            temp = br.readLine();
        }
        br.close();
        //System.out.println(resposta);
        return resposta;
    }



}
