package Usuario;

public class Usuario {
    private String userId;
    private static Usuario _this = null;

    private Usuario(){}

    public static Usuario getIntance(){
        if(_this==null) _this = new Usuario();
        return _this;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }
}