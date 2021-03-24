package Janelas;

import Conexao.Conexao;
import Interfaces.ListenerConexao;
import Json.Array_js;
import Json.Conversor;
import Mensagem.Mensagem;

import javax.swing.*;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Vector;

public class JanelaPrincipal extends JFrame {

    private static JanelaPrincipal _this;
    JLabel mensagem_corpo = new JLabel();
    JLabel assunto = new JLabel();
    JLabel remetente = new JLabel();
    JTree pastas;
    JList<Mensagem> listMensagens = new JList<Mensagem>();
    String user_id;

    public static JanelaPrincipal getJanela(String user_id){
        if(_this==null) _this = new JanelaPrincipal();
        _this.user_id = user_id;
        return _this;
    }

    private JanelaPrincipal(){

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
            }
        });
        JPanel pastas = pastas();
        JPanel mensagems = mensagens();
        JPanel mensagem = mensagem();

        GroupLayout layout = new GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addComponent(pastas, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addGap(0, 0, 0)
                                .addComponent(mensagems, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addGap(0, 0, 0)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(mensagem, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap())
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addComponent(pastas, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(mensagems, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(mensagem, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addContainerGap())
        );

        pack();
        setSize(1280,700);
        setLocationRelativeTo(null);
    }

    private JPanel pastas(){
        DefaultMutableTreeNode root  = new DefaultMutableTreeNode("Pastas de Email");
        DefaultMutableTreeNode inbox = new DefaultMutableTreeNode("Inbox");
        DefaultMutableTreeNode sent  = new DefaultMutableTreeNode("Sent");

        root.add(inbox);
        root.add(sent);
        pastas = new JTree(root);

        pastas.getSelectionModel().addTreeSelectionListener(new TreeSelectionListener() {
            @Override
            public void valueChanged(TreeSelectionEvent e) {
                if(e.getPath().toString().contains("Inbox")) {
                    System.out.println("Selecao foi: " + e.getPath());
                    Conexao conexao = new Conexao("{\"get\":{\"user-id\": \""+user_id+"\"}}");
                    conexao.addListener(new ListenerConexao() {
                        @Override
                        public void success(String value) {
                            String a =
            "{\"mensagens\": [" +
                "{\"remetente\": \"nome do remetente\",\"assunto\": \"nononono\",\"texto\": \"teste 123\"}," +
                    "{\"remetente\": \"nome do remetente\",\"assunto\": \"nononono\",\"texto\": \"teste 4\"}," +
                    "{\"remetente\": \"nome do remetente\",\"assunto\": \"nononono\",\"texto\": \"teste 5\"}," +
                    "{\"remetente\": \"nome do remetente\",\"assunto\": \"nononono\",\"texto\": \"teste 6\"}," +
                "{\"remetente\": \"nome do outro remetente\",\"assunto\": \"abcabd\",\"texto\": \"adcadcadcadc\"}" +
            "]}";
                            Array_js aux = Conversor.getJson(a);
                            System.out.println(aux);
                            aux = aux.getValuesAsKey("mensagens");
                            aux.setValue(aux.getValuesAsKey("0"));

                            System.out.println(aux);

                            Vector<Mensagem> mensagems = new Vector<>();
                            for (String string : aux.getKeys()){
                                System.out.println(aux.getValuesAsKey(string));
                                mensagems.add(new Mensagem(aux.getValuesAsKey(string)));
                            }
                            updateLista(mensagems);
                        }

                        @Override
                        public void error(String value) {

                        }
                    });
                    conexao.start();
                }
                else {
                    //updateLista(new String[]{"ccacaacaacaa", "nbnbnbnbnbnbnb", "nnonononono 3"});
                }
            }
        });
        
        JScrollPane scrollPastas = new JScrollPane();
        scrollPastas.setViewportView(this.pastas);

        JPanel pastas = new JPanel();
        GroupLayout panelLayout = new GroupLayout(pastas);
        pastas.setLayout(panelLayout);

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
        return pastas;
    }

    private JPanel mensagens(){
        JScrollPane scrollMensagens = new JScrollPane();

        listMensagens.addListSelectionListener(e -> {
            updateEmail(listMensagens.getSelectedValue());
            System.out.println("Selecao no List foi: "+listMensagens.getSelectedValue());
        });

        scrollMensagens.setViewportView(listMensagens);

        JPanel mensagems = new JPanel();
        GroupLayout panelLayout = new GroupLayout(mensagems);
        mensagems.setLayout(panelLayout);
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
        return mensagems;
    }

    private JPanel mensagem(){

        JPanel mensagem = new JPanel();
        GroupLayout jPanel3Layout = new GroupLayout(mensagem);
        mensagem.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
                jPanel3Layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(GroupLayout.Alignment.TRAILING, jPanel3Layout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(jPanel3Layout.createParallelGroup(GroupLayout.Alignment.TRAILING)
                        .addComponent(assunto, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(remetente, GroupLayout.Alignment.LEADING, GroupLayout.DEFAULT_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(mensagem_corpo, GroupLayout.DEFAULT_SIZE, 557, Short.MAX_VALUE))
                    .addContainerGap())
        );
        jPanel3Layout.setVerticalGroup(
                jPanel3Layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                .addGroup(GroupLayout.Alignment.TRAILING, jPanel3Layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(assunto, GroupLayout.PREFERRED_SIZE, 28, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(LayoutStyle.ComponentPlacement.RELATED)
                    .addComponent(remetente, GroupLayout.PREFERRED_SIZE, 37, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(LayoutStyle.ComponentPlacement.RELATED)
                    .addComponent(mensagem_corpo, GroupLayout.DEFAULT_SIZE, 601, Short.MAX_VALUE)
                    .addContainerGap())
        );
        mensagem.setBorder(BorderFactory.createBevelBorder(1));

        mensagem_corpo.setVerticalAlignment(JLabel.TOP);
        assunto.setBorder(BorderFactory.createBevelBorder(1));
        mensagem_corpo.setBorder(BorderFactory.createBevelBorder(1));
        remetente.setBorder(BorderFactory.createBevelBorder(1));

        assunto.setVisible(false);
        remetente.setVisible(false);
        mensagem_corpo.setVisible(false);

        return mensagem;
    }

    private void updateLista(Vector<Mensagem> strings) {
        listMensagens.removeAll();
        listMensagens.setListData(strings);
        assunto.setVisible(true);
        remetente.setVisible(true);
        mensagem_corpo.setVisible(true);
    }

    private void updateEmail(Mensagem mensagem){
        mensagem_corpo.setText(mensagem.getMensagem());
        assunto.setText(mensagem.getAssunto());
        remetente.setText(mensagem.getRementente());

    }

    private void sair(){
        _this.dispatchEvent(new WindowEvent(_this, WindowEvent.WINDOW_CLOSING));
    }
}
