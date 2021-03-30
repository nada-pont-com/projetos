package Json;

public class Json extends JsonAbstract{

    public Array_js getArray_js(String key){
        Array_js retorno = null;
        for (Array_js array_js : json){
            if(array_js.getKey().equals(key)) {
                retorno = array_js.clone();
                break;
            }
        }
        return retorno;
    }

    public void setArray_js(Array_js value) {
        if(isKey(value.getKey())){
            updateValueAsKey(value.getKey(),value);
        }else
            json.add(value);
    }

    @Override
    public String toString() {
        String toString = "";
        for (Array_js array_js : json){
            toString += array_js.toString();
        }
        toString+="";
        return toString;
    }
}
