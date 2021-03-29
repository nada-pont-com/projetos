package Janelas;

import Mensagem.Mensagem;

import javax.swing.*;
import javax.swing.event.ListSelectionListener;
import java.util.Vector;

public class PanelMensagens extends JPanel{
    private JList<Mensagem> listMensagens = new JList<>();

    private static PanelMensagens _this;

    public static PanelMensagens getInstance(){
        if(_this==null) _this = new PanelMensagens();
        return _this;
    }

    private PanelMensagens(){
        JScrollPane scrollMensagens = new JScrollPane();

        scrollMensagens.setViewportView(listMensagens);

        GroupLayout panelLayout = new GroupLayout(this);
        this.setLayout(panelLayout);
        panelLayout.setHorizontalGroup(
                panelLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addGroup(panelLayout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(scrollMensagens, GroupLayout.DEFAULT_SIZE, 180, Short.MAX_VALUE)
                                .addContainerGap())
        );
        panelLayout.setVerticalGroup(
                panelLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addGroup(panelLayout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(scrollMensagens)
                                .addContainerGap())
        );
    }

    public void addListener(ListSelectionListener listSelectionListener){
        listMensagens.addListSelectionListener(listSelectionListener);
    }

    public void updateLista(Vector<Mensagem> strings) {
        listMensagens.removeAll();
        listMensagens.setListData(strings);
        /*assunto.setVisible(true);
        remetente.setVisible(true);
        mensagem_corpo.setVisible(true);*/
    }
}
