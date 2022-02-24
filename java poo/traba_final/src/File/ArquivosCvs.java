package File;

import java.io.*;
import java.util.ArrayList;
import java.util.Objects;

;

public class ArquivosCvs {
    private File file;
    private File file2;
    private String saida;

    public void init(funcoes type,String file1,String file2,String saida){
        init(type,file1,file2,saida,"tabela");
    }

    public void init(funcoes type,String file1,String file2,String saida,String table){
        this.saida = saida;
        //file = new File("../../../ban2_sqls/trab/dados_AC.csv");
        this.file = new File(file1);
        this.file2 = new File(file2);
        try {
            switch (type.ordinal()) {
                case 0 -> rescreveArquivo(table);
                case 1 -> separacao();
                case 2 -> distinciList();
                case 3 -> distinciListKeyValue();
                case 4 -> unionListKeyValue();
                case 5 -> crieKey();
                case 6 -> subistuicaoKeyValue();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void rescreveArquivo(String tabela) throws IOException {
        PrintStream ps = new PrintStream("sql/"+saida);
        BufferedReader br = new BufferedReader(new FileReader(file));
        ps.println();

        String resposta = "INSERT INTO "+tabela+" (";
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

        String temp = br.readLine();
        temp = temp.replace(";",",").replace("'","\"").replace("\"","");
        String[] strings = temp.split(",");
        for (String string : strings) {
            files.add(new PrintStream(new File("pasta_lx/arquivo_"+string+".txt")));
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
                    if(teste[i].indexOf(',')!=0 && i!=0){
                        teste[i] = teste[i].replace(",","%virgula%");
                    }
                    temp += teste[i];
                }
                temp = temp.replace("\"","'");
                String[] a = temp.split(",");

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
        PrintStream ps = new PrintStream("pasta_lx/"+saida);
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
        PrintStream ps = new PrintStream("pasta_lx/"+saida);
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
        PrintStream ps = new PrintStream("pasta_lx/"+saida);
        String keyS = key.readLine();
        String valueS = value.readLine();
        ps.println(keyS+","+valueS);
        while(keyS != null) {
            keyS = key.readLine();
            valueS = value.readLine();
            if(keyS!=null){
                if(Objects.equals(valueS, "")) valueS = "null";
                if(Objects.equals(keyS, "")) keyS = "null";
                ps.println(keyS+","+valueS);
            }
        }

        value.close();
        key.close();
        ps.close();
    }

    public void crieKey() throws IOException{
        BufferedReader value = new BufferedReader(new FileReader(file));
        PrintStream ps = new PrintStream("pasta_lx/"+saida);
        ArrayList<String> values = new ArrayList();

        int key = 0;
        String valueS = value.readLine();
        values.add(valueS);
        ps.println("id,"+valueS);
        int tamanho = 0;
        while(valueS != null) {
            valueS = value.readLine();
            int aux = values.indexOf(valueS);
            if(aux==-1){
                values.add(valueS);
                tamanho++;
                key = tamanho;
            }else  key = aux;
            if(valueS!=null){
                ps.println(key+","+valueS);
            }
        }
        value.close();
        ps.close();
    }

    void subistuicaoKeyValue()throws IOException{
        BufferedReader key = new BufferedReader(new FileReader(file));
        BufferedReader value = new BufferedReader(new FileReader(file2));
        PrintStream ps = new PrintStream("pasta_lx/"+saida);
        ArrayList<String> values = new ArrayList<String>();
        ArrayList<String> keys = new ArrayList<String>();

        String valueS = value.readLine();
        String keyS = key.readLine();
        String[] aux = keyS.split(",");
        values.add(aux[1]);
        keys.add(aux[0]);
        //values.add(valueS);
        ps.println(""+valueS);
        while(keyS != null) {
            keyS = key.readLine();
            if(keyS!=null){
                aux = keyS.split(",");
                keys.add(aux[0]);
                values.add(aux[1]);
            }
        }

        while(valueS != null) {
            valueS = value.readLine();
            if(valueS!=null){
                if(values.contains(valueS)){
                    ps.println(keys.get(values.indexOf(valueS)));
                }else ps.println("null");
            }
        }

        value.close();
        key.close();
        ps.close();
    }
}
