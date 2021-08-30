package Strings;

public class Palindromo {
    public boolean validaPalindromo(String palin){
        boolean retorno = true;
        palin = palin.replaceAll(" ","").toLowerCase();
        char []chars  = palin.toCharArray();
        for (int i =0,l = chars.length-1;i!=l && i>l;i++,l--){
            if(chars[i]!=chars[l]){
                retorno = false;
                break;
            }
        }
        return retorno;
    }
}
