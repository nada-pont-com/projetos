package Json;

import java.util.ArrayList;

public class Objeto {
    protected boolean list = false;
    protected boolean obj = false;
    protected ArrayList<Array_js> values = new ArrayList<>();

    public Objeto(){ }

    public Objeto(ArrayList<Array_js> array_js){
        this.values = array_js;
    }

    public void setObj() {
        this.obj = true;
    }

    public void setList() {
        this.list = true;
    }

    public void setValue(Array_js value) {
        this.values.add(value);
    }

    public Array_js getLastValue() {
        if(values.size()!=0)
            return values.get(values.size()-1);
        return null;
    }

    public Array_js getValuesAsKey(String key){
        Array_js aux = null;
        for (Array_js array_js : values){
            //System.out.println(array_js);

            if(array_js.getKey().equals(key)){
                if(array_js.getValues().size()!=0){
                    aux = new Array_js(array_js.getValues(),key);
                }else{
                    aux = new Array_js(array_js.getValue(),key);
                }
            }
        }
        return aux;
    }

    public String getKey(String key){
        String retorno = null;
        for (Array_js array_js : values){
            if(array_js.getKey().equals(key)) {
                retorno = key;
                break;
            }
        }
        System.out.println(retorno);
        return retorno;
    }

    public ArrayList<String> getKeys(){
        ArrayList<String> retorno = new ArrayList<>();
        for (Array_js array_js : values){
            retorno.add(array_js.getKey());
        }
        return retorno;
    }

    public ArrayList<Array_js> getValues() {
        return values;
    }
}
