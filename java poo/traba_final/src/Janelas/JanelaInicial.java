package Janelas;

import Conexao.Conexao;
import JFramesPersos.PlaceholderTextField;
import Json.Conversor;
import Json.Json;
import Usuario.Usuario;

import javax.swing.*;
import java.awt.*;

public class JanelaInicial extends JFrame{
    private JButton login;
    private PlaceholderTextField user;
    private JLabel image;
    private JLabel msgAlert;

    public JanelaInicial(){
        setTitle("Login");
        JanelaInicial _this = this;

        setSize(500,500);
        setResizable(false);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        login = new JButton("login");
        user = new PlaceholderTextField();
        user.setPlaceholder("login");

        ImageIcon img = new ImageIcon("src\\imgs\\inicio2.png");
        image = new JLabel(img);
        msgAlert = new JLabel("",JLabel.CENTER);
        msgAlert.setForeground(Color.red);

        login.addActionListener(e -> {

            Conexao conexao = Conexao.getInstance();
            String value = conexao.login(user.getText());
            Json json = Conversor.getJson(value);

            if (validaLogin(json)) {
                _this.setVisible(false);
                Usuario.getIntance().setUserId(user.getText());
                JanelaPrincipal.getJanela().setVisible(true);
                msgAlert.setText("");
            } else{
                msgAlert.setText("Login invalido");
            }


        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);

        {
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addGap(154, 154, 154)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addComponent(login, javax.swing.GroupLayout.DEFAULT_SIZE, 150, Short.MAX_VALUE)
                                        .addComponent(user)
                                        .addComponent(msgAlert, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(image, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addContainerGap(153, Short.MAX_VALUE))
        );
        }
        {layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addContainerGap(64, Short.MAX_VALUE)
                                .addComponent(image, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(msgAlert)
                                .addGap(5, 5, 5)
                                .addComponent(user, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(login)
                                .addGap(45, 45, 45))
        );
        }

        pack();
        setVisible(true);
    }

    private boolean validaLogin(Json json){
        return (json.isKey("okay"));
    }
}
