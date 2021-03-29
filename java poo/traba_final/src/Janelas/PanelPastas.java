package Janelas;

import Conexao.Conexao;
import Mensagem.Mensagem;
import Usuario.Usuario;

import javax.swing.*;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.TreePath;
import java.util.Vector;

public class PanelPastas extends JPanel{
    private JTree pastas;

    private static PanelPastas _this;

    public static PanelPastas getInstance(){
        if(_this==null) _this = new PanelPastas();
        return _this;
    }

    private PanelPastas(){
        DefaultMutableTreeNode root  = new DefaultMutableTreeNode("Pastas de Email");
        DefaultMutableTreeNode inbox = new DefaultMutableTreeNode("Inbox");
        DefaultMutableTreeNode sent  = new DefaultMutableTreeNode("Sent");
        DefaultMutableTreeNode rascunhos  = new DefaultMutableTreeNode("Rascunhos");

        root.add(inbox);
        root.add(sent);
        root.add(rascunhos);

        pastas = new JTree(root);
        JScrollPane scrollPastas = new JScrollPane();
        scrollPastas.setViewportView(this.pastas);

        GroupLayout panelLayout = new GroupLayout(this);
        this.setLayout(panelLayout);

        panelLayout.setHorizontalGroup(
                panelLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addGroup(panelLayout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(scrollPastas, GroupLayout.DEFAULT_SIZE, 203, Short.MAX_VALUE)
                                .addContainerGap())
        );
        panelLayout.setVerticalGroup(
                panelLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addGroup(panelLayout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(scrollPastas, GroupLayout.DEFAULT_SIZE, 678, Short.MAX_VALUE)
                                .addContainerGap())
        );
    }

    public void addListener(TreeSelectionListener treeSelectionListener){
        pastas.getSelectionModel().addTreeSelectionListener(treeSelectionListener);
    }


}
