package Janelas;

import Mensagem.Mensagem;
import Usuario.Usuario;

import javax.swing.*;

public class PanelMensagem extends PanelBase{

    private JLabel mensagem_corpo = new JLabel();
    private JLabel assunto = new JLabel();
    private JLabel remetente = new JLabel();
    private JLabel destinatario = new JLabel();

    private static PanelMensagem _this;


    public static PanelMensagem getInstance(){
        if(_this==null) _this = new PanelMensagem();
        return _this;
    }

    private PanelMensagem(){
        GroupLayout jPanelLayout = new GroupLayout(this);
        this.setLayout(jPanelLayout);
        jPanelLayout.setHorizontalGroup(
            jPanelLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(jPanelLayout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(jPanelLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addComponent(remetente, GroupLayout.Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(mensagem_corpo, GroupLayout.Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 503, Short.MAX_VALUE)
                        .addComponent(destinatario, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(assunto, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addContainerGap()));

        jPanelLayout.setVerticalGroup(
            jPanelLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(GroupLayout.Alignment.TRAILING, jPanelLayout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(assunto, GroupLayout.PREFERRED_SIZE, 26, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(LayoutStyle.ComponentPlacement.RELATED)
                    .addComponent(remetente, GroupLayout.PREFERRED_SIZE, 37, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(LayoutStyle.ComponentPlacement.RELATED)
                    .addComponent(destinatario, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                    .addComponent(mensagem_corpo, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addContainerGap())
        );

        this.setBorder(BorderFactory.createBevelBorder(1));

        mensagem_corpo.setVerticalAlignment(JLabel.TOP);
        assunto.setBorder(BorderFactory.createBevelBorder(1));
        mensagem_corpo.setBorder(BorderFactory.createBevelBorder(1));
        remetente.setBorder(BorderFactory.createBevelBorder(1));
        destinatario.setBorder(BorderFactory.createBevelBorder(1));

        /*assunto.setVisible(false);
        remetente.setVisible(false);
        mensagem_corpo.setVisible(false);*/
    }

    public void updateEmail(Mensagem mensagem){
        mensagem_corpo.setText(mensagem.getMensagem());
        assunto.setText(mensagem.getAssunto());
        remetente.setText(mensagem.getRementente());
        destinatario.setText(Usuario.getIntance().getUserId());
    }

    public void clear() {
        mensagem_corpo.setText("");
        assunto.setText("");
        remetente.setText("");
    }
}
