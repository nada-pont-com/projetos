package Json;

public class Conversor {

    private static Conversor _this;
    private Conversor(){ }

    public static Json getJson(String json){
        if(_this==null) _this = new Conversor();
        return _this.converter(json);
    }

    private Json converter(String jsonString){
        char[] b = jsonString.toCharArray();
        Array_js list = new Array_js();
        list.setObj();
        for (int i = 0;i<b.length;i++) {
            if(b[i]=='{'){
                validaChave(b,i+1,list);
                break;
            }
            if(b[i]=='['){
                validaList(b,i+1,list);
                break;
            }
        }
        Json json = new Json();
        for(String key : list.getKeys()){
            json.setArray_js(list.getValuesAsKey(key));
        }
        return json;
    }

    private int validaChave(char[] string,int ini,Array_js list){
        Array_js aux = new Array_js();

        String key_s = "",valeu_s = "";
        boolean key = true,text = false,valeu = false;
        int chaves_abertas = 1;
        int i,j = 0;
        for (i = ini;i<string.length;i++) {
            if(j>i) continue;
            if(string[i]=='{'){
                aux.setKey(key_s);
                valeu_s = "";
                key_s = "";
                key = true;
                valeu = false;
                aux.setObj();
                list.setValue(aux);
                aux = new Array_js();
                j = validaChave(string,i+1,list.getLastValue());
                chaves_abertas++;
                continue;
            }
            if(string[i]=='['){
                aux.setKey(key_s);
                valeu_s = "";
                key_s = "";
                aux.setList();
                list.setValue(aux);
                aux = new Array_js();
                j = validaList(string,i+1,list.getLastValue());
                chaves_abertas++;
                continue;
            }

            if(string[i]=='}' || string[i]==']'){
                chaves_abertas--;
            }

            if(chaves_abertas==0) break;

            if(string[i]==',' && !text && valeu){
                aux.setValue(valeu_s);
                aux.setKey(key_s);
                valeu_s = "";
                key_s = "";
                key = true;
                valeu = false;
                list.setValue(aux);
                aux = new Array_js();
                continue;
            }

            if(string[i]=='"'){
                text = !text;
                continue;
            }

            if(key && text){
                key_s += string[i];
                continue;
            }
            if(string[i]==':' && !text){
                key = false;
                valeu = true;
                continue;
            }
            if(valeu && text){
                valeu_s += string[i];
                //continue;
            }

        }
        if(!valeu_s.equals("")){
            aux.setValue(valeu_s);
            aux.setKey(key_s);
            list.setValue(aux);
        }
        return i;
    }

    private int validaList(char[] string,int ini,Array_js list){
        Array_js aux = new Array_js();
        String valeu_s = "";
        boolean text = false,value = false;
        int chaves_abertas = 1;
        int i,j = 0;

        for (i = ini;i<string.length;i++) {
            if(j>i) continue;

            if(string[i]=='['){

                value = true;
                valeu_s = "";
                aux.setList();
                list.setValue(aux);
                aux = new Array_js();
                j = validaList(string,i+1,list.getLastValue());
                chaves_abertas++;
                continue;
            }

            if(string[i]=='{'){
                value = true;
                valeu_s = "";
                list.setValue(aux);
                aux.setObj();
                aux = new Array_js();
                j = validaChave(string,i+1,list.getLastValue());
                chaves_abertas++;
                continue;
            }

            if(string[i]==']' || string[i]=='}'){
                chaves_abertas--;
            }
            if(chaves_abertas==0) break;

            if(string[i]==',' && !text && value){
                value = false;
                continue;
            }
            if(string[i]==',' && !text && !value){
                aux.setValue(valeu_s);
                valeu_s = "";
                list.setValue(aux);
                aux = new Array_js();
                continue;
            }

            if(string[i]=='"'){
                text = !text;
                continue;
            }

            if(text){
                valeu_s += string[i];
            }
        }
        if(!valeu_s.equals("")){
            aux.setValue(valeu_s);
            list.setValue(aux);
        }
        return i;
    }
}
