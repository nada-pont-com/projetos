package Json;

import java.util.ArrayList;

public abstract class JsonAbstract {

    protected ArrayList<Array_js> json = new ArrayList<>();

    public boolean isKey(String key){
        boolean retorno = false;
        for (Array_js array_js : json){
            if(array_js.getKey().equals(key)) {
                retorno = true;
                break;
            }
        }
        return retorno;
    }

    public ArrayList<String> getKeys(){
        ArrayList<String> retorno = new ArrayList<>();
        for (Array_js array_js : json){
            retorno.add(array_js.getKey());
        }
        return retorno;
    }

    public String getKey(String key) throws NullPointerException{
        String retorno = null;
        for (Array_js array_js : json){
            if(array_js.getKey().equals(key)) {
                retorno = key;
                break;
            }
        }
        return retorno;
    }


    public void updateValueAsKey(String key,Array_js value){
        if(value!=null){
            for (int i = 0; i < json.size();i++){
                if(json.get(i).getKey().equals(key)){
                    json.set(i,value);
                    break;
                }
            }
        }
    }

    public void updateValueAsKey(String key,String value){
        if(value!=null){
            for (Array_js array_js : json) {
                if (array_js.getKey().equals(key)) {
                    while (!array_js.getValues().isEmpty()){
                        array_js.getValues().remove(array_js.getLastValue());
                    }
                    //this.value = value;
                    break;
                }
            }
        }
    }

    public Array_js getLastValue() {
        if(json.size()!=0)
            return json.get(json.size()-1);
        return null;
    }
}
