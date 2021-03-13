public class Numero {

    public static boolean verificaPar(int n){
        return n%2==0;
    }
    public static boolean verificaPar(double n){
        String s = "";
        String []ss = (n+"").split("\\.");
        for (String a : ss){
            s += a;
        }
        return Double.parseDouble(s)%2==0;
    }

    public void numerosPares(int inicio,int quantidade){
        while (quantidade==0){
            if(verificaPar(inicio)){
                System.out.println(inicio);
                quantidade--;
            }
            inicio++;
        }
    }
}
