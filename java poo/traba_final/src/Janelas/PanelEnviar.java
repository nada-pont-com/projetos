package Janelas;

import JFramesPersos.PlaceholderTextField;
import Json.Array_js;
import Json.Json;

import javax.swing.*;


public class PanelEnviar extends JPanel {

    private JButton enviar;
    private JButton cancelar;
    private JTextArea conteudo;
    private PlaceholderTextField assunto;
    private PlaceholderTextField destinatario;
    private JLabel remetente;

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
        JScrollPane jScrollPane = new javax.swing.JScrollPane();

        assunto.setPlaceholder("Assunto");
        destinatario.setPlaceholder("Destinatario");

        jScrollPane.setViewportView(conteudo);

        GroupLayout layout = new GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(jScrollPane, javax.swing.GroupLayout.DEFAULT_SIZE, 567, Short.MAX_VALUE)
                                        .addComponent(remetente, javax.swing.GroupLayout.Alignment.TRAILING)
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
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(remetente, javax.swing.GroupLayout.PREFERRED_SIZE,
                                        javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(assunto, javax.swing.GroupLayout.PREFERRED_SIZE,
                                        javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jScrollPane, javax.swing.GroupLayout.DEFAULT_SIZE, 231, Short.MAX_VALUE))
        );
    }

    public void salvarRascunho(){
        Json rascunho = new Json();
        System.out.println(rascunho);
        Array_js aux = new Array_js("mensagens","");
        aux.setList();

        aux.setValue(new Array_js("texto",conteudo.getText()));
        aux.setValue(new Array_js("assunto",assunto.getText()));
        aux.setValue(new Array_js("remetente",remetente.getText()));
        aux.setValue(new Array_js("destinatario",destinatario.getText()));

        rascunho.setArray_js(aux);
        System.out.println(rascunho);

    }


}
