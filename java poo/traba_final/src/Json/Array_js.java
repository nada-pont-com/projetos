package Json;

public class Array_js extends Objeto{
    private String key;
    private String value;

    public Array_js(){

    }

    public Array_js(String key,String value){
        setKey(key);
        setValue(value);
    }

    public Array_js(String key,Array_js value){
        setObj();
        setKey(key);
        setValue(value);
    }

    private Array_js newArray_js(String key,String value){
        Array_js aux = new Array_js();
        aux.setKey(key);
        aux.setValue(value);
        return aux;
    }

    private Array_js newArray_js(String key,Array_js value){
        Array_js aux = new Array_js();
        aux.setObj();
        aux.setKey(key);
        aux.setValue(value);
        return aux;
    }

    public void setKey(String key) {
        if(!listP)
            this.key = key;
    }

    public String getKey() {
        return key;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public void updateValueAsKey(String key,String value){
        boolean valida = false;
        if(value!=null){
            for (Array_js array_js : json) {
                if (array_js.getKey().equals(key)) {
                    while (!array_js.getValues().isEmpty()){
                        array_js.getValues().remove(array_js.getLastValue());
                    }
                    array_js.setList(false);
                    array_js.setObj(false);
                    this.value = value;
                    valida = true;
                    break;
                }
            }
            if(!valida){
                setValue(this.newArray_js(key,value));
            }
        }
    }

    public void updateValueAsKey(String key,Array_js value){
        boolean existe = false;
        if(value!=null){
            for (int i = 0; i < json.size();i++){
                if(json.get(i).getKey().equals(key)){
                    json.set(i,value);
                    existe =  true;
                    break;
                }
            }
            if(!existe){
                setValue(this.newArray_js(key,value));
            }
        }
    }

    public String getValue() {
        return value;
    }

    @Override
    protected Array_js clone(){
        Array_js clone = new Array_js();

        clone.setKey(this.getKey());
        clone.setList(list);
        clone.setListP(listP);
        clone.setObj(obj);

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

            for (int i = 0;i<json.size();i++){
                toString = toString + (i!=0? "," : "") +  json.get(i).toString();
            }

            toString+= (list ? "]" : "}");
        }else{
            toString += "\"" + value + "\"";
        }
        return toString;
    }
}
