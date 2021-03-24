package Json;

import java.util.ArrayList;

public class Array_js extends Objeto{
    private String key;
    private String value;

    public Array_js(){

    }

    public void setKey(String key) {
        this.key = key;
    }

    public String getKey() {
        return key;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }

    protected Array_js clone(){
        Array_js clone = new Array_js();

        clone.setKey(this.getKey());
        clone.setList(list);
        clone.setListP(listP);

        if(this.obj || listP || list){
            for (Array_js array_js : this.getValues()){
                clone.setValue(array_js.clone());
            }
        }else{
            clone.setValue(this.getValue());
        }
        return clone;
    }

    @Override
    public String toString() {
        String toString = "" +
                        (key!=null && !listP ? "\"" + key + "\":" : "");

        if(getLastValue()!=null){

            toString += (list ? "[" : "{");

            for (int i = 0;i<values.size();i++){
                toString = toString + (i!=0? "," : "") +  values.get(i).toString();
            }

            toString+= (list ? "]" : "}");
        }else{
            toString += "\"" + value + "\"";
        }
        return toString;
    }
}
