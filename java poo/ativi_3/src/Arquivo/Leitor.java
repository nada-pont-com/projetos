package Arquivo;

import Thread.Inversor;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Leitor {

    public void lerDoArquivo() throws IOException {
        File file = new File("texto.txt");
        if(file.exists()){
            BufferedReader br = new BufferedReader(new FileReader(file));
            String resposta = "";
            String temp = br.readLine();
            if(temp != null) {
                resposta+= temp;
                temp = br.readLine();
            }
            br.close();
            Inversor inversor = new Inversor(resposta);
            try {
                inversor.join();
                resposta = inversor.getTexto();
                System.out.println(resposta);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
