package File;

import java.io.*;
import java.util.ArrayList;

public class ArquivosCvs {
    private File file;
    private File file2;

    public void init(int type){
        //file = new File("../../../ban2_sqls/trab/dados_AC.csv");
        file = new File("pasta_lx/arquivoestabelecimento_uf.sql");
        file2 = new File("pasta_lx/arquivoestabelecimento_municipio_nome.sql");
        try {
            switch (type) {
                case 1 -> rescreveArquivo();
                case 2 -> separacao();
                case 3 -> distinciList();
                case 4 -> distinciListKeyValue();
                case 5 -> unionListKeyValue();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void rescreveArquivo() throws IOException {
        PrintStream ps = new PrintStream(file2);
        BufferedReader br = new BufferedReader(new FileReader(file));
        ps.println();

        String resposta = "INSERT INTO teste (";
        String temp = br.readLine();
        resposta+=temp.replace(";",",").replace("\"","")+") VALUES";
        ps.println(resposta);
        int cont = 0;
        while(temp != null) {
            temp = br.readLine();
            cont++;
            if(temp!=null){
                temp = temp.replace("\"","'").replace(";",",").replace(",,",",NULL,").replace(",,",",NULL,");
                //System.out.println(temp);
                String[] teste = temp.split("\'");
                temp = "";
                for(int i = 0;i<teste.length;i++){
                    if(((i+1)%2)==0){
                        teste[i] = teste[i].replace(",","%virgula%");
                    }
                    temp += teste[i];
                }
                temp = temp.replace("\"","'");
                String[] a = temp.split(",");
                int length = resposta.split(",").length;
                //System.out.println(a.length);
                temp = "";
                for(int i = 0;i<length;i++){
                    String text = "";
                    if(i<a.length){
                        text = a[i].replace("%virgula%",",");
                        if(!a[i].equals("NULL")){
                            text = "\""+text+ "\"";
                        }
                    }else{
                        text = "NULL";
                    }
                    temp += ((i==0? "" : ",") + text).toUpperCase();
                }

                temp = "("+temp+")";
                ps.print(temp);
                if(cont==500){
                    ps.println(";");
                    ps.println(resposta);
                    cont=0;
                }else{
                    ps.println(",");
                }
            }
        }
        br.close();
        ps.close();
        //System.out.println(resposta);
    }

    public void separacao() throws IOException{
        BufferedReader br = new BufferedReader(new FileReader(file));
        ArrayList<PrintStream> files = new ArrayList<>();

        String resposta = "(";
        String temp = br.readLine();
        temp = temp.replace(";",",").replace("'","\"").replace("\"","");
        String[] strings = temp.split(",");
        for (String string : strings) {
            files.add(new PrintStream(new File("pasta_lx/arquivo"+string+".sql")));
        }
        teste(files,strings);
        while(temp != null) {
            temp = br.readLine();
            if(temp!=null){
                temp = temp.replace("\"","'").replace(";",",").replace(",,",",NULL,").replace(",,",",NULL,");
                //System.out.println(temp);
                String[] teste = temp.split("\'");
                temp = "";
                for(int i = 0;i<teste.length;i++){
                    if(teste[i].indexOf(',')!=0){
                        teste[i] = teste[i].replace(",","%virgula%");
                    }
                    temp += teste[i];
                }
                temp = temp.replace("\"","'");
                String[] a = temp.split(",");
                //System.out.println(a.length);
                //System.out.println(temp);
                teste(files,a);

            }
        }
        br.close();
    }

    private void teste(ArrayList<PrintStream> ps,String[] strings)throws IOException{

        for (int i = 0; i <ps.size(); i++) {
            //PrintStream ps = new PrintStream(files.get(i));
            ps.get(i).println(strings[i]);
            //ps.close();
        }
    }

    public void distinciList() throws IOException{
        BufferedReader br = new BufferedReader(new FileReader(file));
        PrintStream ps = new PrintStream("pasta_lx/arquivo.txt");
        ArrayList<String> distinct = new ArrayList<>();

        String temp = br.readLine();
        ps.println(temp);
        distinct.add(temp);
        while(temp != null) {
            temp = br.readLine();
            if(temp!=null && !distinct.contains(temp)){
                distinct.add(temp);
                ps.println(temp);
            }
        }
        ps.close();
    }

    public void distinciListKeyValue() throws IOException{
        BufferedReader key = new BufferedReader(new FileReader(file));
        BufferedReader value = new BufferedReader(new FileReader(file2));
        PrintStream ps = new PrintStream("pasta_lx/arquivo2.txt");
        ArrayList<String> distinct = new ArrayList<>();
        String keyS = key.readLine();
        String valueS = value.readLine();
        ps.println(keyS+","+valueS);
        distinct.add(keyS);
        while(keyS != null) {
            keyS = key.readLine();

            valueS = value.readLine();
            if(keyS!=null && !distinct.contains(keyS)){
                distinct.add(keyS);
                ps.println(keyS+","+valueS);
            }
        }
    }


    public void unionListKeyValue() throws IOException{
        BufferedReader key = new BufferedReader(new FileReader(file));
        BufferedReader value = new BufferedReader(new FileReader(file2));
        PrintStream ps = new PrintStream("pasta_lx/arquivo2.txt");
        ArrayList<String> distinct = new ArrayList<>();
        String keyS = key.readLine();
        String valueS = value.readLine();
        ps.println(keyS+","+valueS);
        distinct.add(keyS);
        while(keyS != null) {
            keyS = key.readLine();

            valueS = value.readLine();
            if(keyS!=null){
                distinct.add(keyS);
                ps.println(keyS+","+valueS);
            }
        }
    }
}
