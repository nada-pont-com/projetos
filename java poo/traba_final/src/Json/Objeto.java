package Json;

import java.util.ArrayList;

public class Objeto extends JsonAbstract{
    protected boolean list = false;
    protected boolean listP = false;
    protected boolean obj = false;

    public Objeto(){ }

    public void setObj() {
        this.obj = true;
    }

    protected void setObj(boolean obj) {
        this.obj = obj;
    }

    public boolean isObj() {
        return obj;
    }

    public void setList() {
        this.list = true;
    }

    protected void setList(boolean list) {
        this.list = list;
    }

    protected void setListP(boolean listP) {
        this.listP = listP;
    }

    protected void setListP() {
        this.listP = true;
    }

    public void setValue(Array_js value) {
        if(value==null){
            return;
        }
        if(json==null){
            json = new ArrayList<>();
        }
        if(list){
            value.setValue(value.clone());
            value.setKey((json.size())+"");
            value.setListP();
        }
        setObj();
        this.json.add(value);
    }

    public Array_js getValuesAsKey(String key) throws NullPointerException{
        Array_js aux = null;
        for (Array_js array_js : json){
            if(array_js.getKey().equals(key)){
                aux = array_js.clone();
            }
        }
        return aux;
    }

    public ArrayList<Array_js> getValues() {
        return json;
    }

}