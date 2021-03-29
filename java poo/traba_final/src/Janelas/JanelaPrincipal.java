package Janelas;

import Conexao.Conexao;
import File.Historico;
import Json.Json;
import Mensagem.Mensagem;
import Usuario.Usuario;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class JanelaPrincipal extends JFrame {

    private static JanelaPrincipal _this;
    private PanelPastas pastas = PanelPastas.getInstance();
    private PanelMensagens mensagens = PanelMensagens.getInstance();
    private PanelMensagem mensagem = PanelMensagem.getInstance();
    private PanelEnviar enviar = PanelEnviar.getInstance();

    private JButton escrever;


    public static JanelaPrincipal getJanela() {
        if (_this == null) _this = new JanelaPrincipal();

        return _this;
    }

    private JanelaPrincipal() {
        escrever = new JButton();
        escrever.setText("Escrever");

        escrever.addActionListener(e -> {
            enviar.setVisible(true);
            mensagem.setVisible(false);
        });

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
            }
        });


        GroupLayout layout = new GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                                        .addComponent(pastas, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addGroup(layout.createSequentialGroup()
                                                .addContainerGap()
                                                .addComponent(escrever, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                .addPreferredGap(LayoutStyle.ComponentPlacement.RELATED)))
                                .addComponent(mensagens, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addGap(0, 0, 0)
                                .addPreferredGap(LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(mensagem, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(enviar, javax.swing.GroupLayout.PREFERRED_SIZE,
                                        javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap())
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addComponent(mensagens, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(escrever)
                                .addGap(0, 0, 0)
                                .addComponent(pastas, javax.swing.GroupLayout.DEFAULT_SIZE,
                                        javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                        .addComponent(enviar, javax.swing.GroupLayout.Alignment.LEADING,
                                                javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(mensagem, javax.swing.GroupLayout.DEFAULT_SIZE,
                                                javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addContainerGap())
        );

        pack();
        setSize(1280, 700);
        setLocationRelativeTo(null);
        addUpdateEmail();
        addUpdateMensagens();
    }

    private void addUpdateEmail() {
        mensagens.addListener(e -> {
            mensagem.updateEmail((Mensagem) ( ((JList) e.getSource()) .getSelectedValue()) );

            System.out.println("Selecao no List foi: " + ((JList) e.getSource()).getSelectedValue());
        });
    }

    private String tempPasta = "";
    private void addUpdateMensagens() {
        pastas.addListener(e -> {
            enviar.salvarRascunho();
            if (e.getPath().toString().contains("Inbox")) {

                if(!e.getPath().toString().contains(tempPasta)){
                    if(!enviar.isVisible()){
                        Historico.getInstance().salvarRascunhos(new Json());
                    }
                    enviar.setVisible(false);
                    mensagem.setVisible(true);
                    mensagem.clear();
                }
                System.out.println("Selecao foi: " + e.getPath());
                Conexao conexao = Conexao.getInstance();
                if (conexao.getMensagens(Usuario.getIntance().getUserId())) {
                    mensagens.updateLista(Historico.getInstance().getMensagesRecebidas());
                }
            } else {
                mensagens.updateLista(Historico.getInstance().getMensagesEnviadas());
            }
        });
    }

    private void sair() {
        _this.dispatchEvent(new WindowEvent(_this, WindowEvent.WINDOW_CLOSING));
    }
}
