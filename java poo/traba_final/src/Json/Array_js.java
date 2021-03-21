package Json;

import java.util.ArrayList;

public class Array_js extends Objeto{
    private String key;
    private String value;

    public Array_js(){

    }

    public Array_js(ArrayList<Array_js> array_js,String key){
        super(array_js);
        this.key = key;
    }

    public Array_js(String value,String key){
        this.value = value;
        this.key = key;
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

    @Override
    public String toString() {
        String toString = "" +
                        (key!=null ? "\"" + key + "\":" : "");

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
