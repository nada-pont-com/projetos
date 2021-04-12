package Janelas;

import Conexao.Conexao;
import File.Historico;
import JFramesPersos.PlaceholderTextField;
import Json.Array_js;
import Json.Json;
import Mensagem.Mensagem;
import Usuario.Usuario;

import javax.swing.*;


public class PanelEnviar extends PanelBase{

    private JButton enviar;
    private JButton cancelar;
    private JTextArea conteudo;
    private PlaceholderTextField assunto;
    private PlaceholderTextField destinatario;
    private JLabel remetente;
    private String _id;

    private static PanelEnviar _this;

    public static PanelEnviar getInstance() {
        if(_this==null) _this = new PanelEnviar();
        return _this;
    }

    private PanelEnviar(){

        setVisible(false);

        enviar = new JButton("Enviar");
        cancelar = new JButton("Descartar");
        conteudo = new JTextArea();
        assunto = new PlaceholderTextField();
        destinatario = new PlaceholderTextField();
        remetente = new JLabel();

        assunto.setPlaceholder("Assunto");
        destinatario.setPlaceholder("Destinatario");

        addActionEnviar();
        addActionDescartarEmail();

        JScrollPane jScrollPane = new javax.swing.JScrollPane();
        jScrollPane.setViewportView(conteudo);

        remetente.setBorder(BorderFactory.createBevelBorder(1));

        GroupLayout layout = new GroupLayout(this);

        this.setLayout(layout);

        {
            layout.setHorizontalGroup(
                    layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                    .addContainerGap()
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(remetente, javax.swing.GroupLayout.DEFAULT_SIZE,
                                                    javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(jScrollPane, javax.swing.GroupLayout.DEFAULT_SIZE, 567, Short.MAX_VALUE)
                                            .addComponent(destinatario, javax.swing.GroupLayout.Alignment.TRAILING)
                                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                                    .addGap(0, 0, Short.MAX_VALUE)
                                                    .addComponent(cancelar)
                                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                    .addComponent(enviar))
                                            .addComponent(assunto, javax.swing.GroupLayout.Alignment.TRAILING))
                                    .addContainerGap())
            );
            layout.setVerticalGroup(
                    layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                            .addComponent(enviar)
                                            .addComponent(cancelar))
                                    .addGap(7, 7, 7)
                                    .addComponent(remetente, javax.swing.GroupLayout.PREFERRED_SIZE, 19,
                                            javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(destinatario, javax.swing.GroupLayout.PREFERRED_SIZE,
                                            javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(assunto, javax.swing.GroupLayout.PREFERRED_SIZE,
                                            javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(jScrollPane, javax.swing.GroupLayout.DEFAULT_SIZE, 205, Short.MAX_VALUE))
            );
        }
    }

    private void addActionDescartarEmail(){
        cancelar.addActionListener(e -> {
            if(_id!=null){
                Mensagem mensagem = new Mensagem();
                mensagem.setId(_id);
                Historico.getInstance().removeRascunho(mensagem.toJson("mensagens",true,true));
            }
            clear();
            JanelaPrincipal.getJanela().resetView();
        });
    }

    public void salvarRascunho(){
        Json rascunho;

        Mensagem mensagem = new Mensagem();

        mensagem.setAssunto(assunto.getText());
        mensagem.setMensagem(conteudo.getText());
        mensagem.setDestinatario(destinatario.getText());
        mensagem.setRementente(remetente.getText());
        mensagem.setId(_id);

        rascunho = mensagem.toJson("mensagens",true,true);
        Historico.getInstance().salvarRascunhos(rascunho);
        System.out.println(rascunho);
    }

    private void addActionEnviar(){
        enviar.addActionListener(e ->{
            Mensagem mensagem = new Mensagem();

            mensagem.setAssunto(assunto.getText());
            mensagem.setMensagem(conteudo.getText());
            mensagem.setDestinatario(destinatario.getText());
            mensagem.setRementente(remetente.getText());

            if(Conexao.getInstance().enviarEmail(mensagem)){
                Historico.getInstance().salvarMensagensEnviadas(mensagem.toJson("mensagens",true,true));
                if(_id!=null){
                    mensagem.setId(_id);
                    Historico.getInstance().removeRascunho(mensagem.toJson("mensagens",true,true));
                }
                clear();
                JanelaPrincipal.getJanela().resetView();
            }
        });
    }

    public void setRemetente() {
        System.out.println(Usuario.getIntance().getUserId());
        remetente.setText(Usuario.getIntance().getUserId());
    }

    public void clear() {
        assunto.setText("");
        conteudo.setText("");
        destinatario.setText("");
        remetente.setText("");
        _id = null;
    }

    public void updateRascunho(Mensagem mensagem) {
        conteudo.setText(mensagem.getMensagem());
        remetente.setText(mensagem.getRementente());
        assunto.setText(mensagem.getAssunto());
        destinatario.setText(mensagem.getDestinatario());
        _id = mensagem.getId();
    }
}
