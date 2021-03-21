package Interfaces;

import Conexao.Conexao;

public interface ListenerConexao {
    public void success(String value);
    public void error(String value);
}
