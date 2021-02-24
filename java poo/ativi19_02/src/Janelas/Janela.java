package Janelas;

//import Interface.Programas.Contador;

import Programas.Contador;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Janela extends JFrame {
    public Janela(){
        setTitle("Janelas.Janela");
        setSize(400,200);
        setLocationRelativeTo(null);
//        setLayout(new BorderLayout());
        FlowLayout layout = new FlowLayout();

        layout.setAlignment(FlowLayout.CENTER);
        setLayout(layout);

        setDefaultCloseOperation(EXIT_ON_CLOSE);

        ArrayList<JButton> buttons = new ArrayList<>();
        String[] names = {"BOTAO#1", "BOTAO#2", "Incrementa", "Decrementa"};
        
        JPanel panel = null;
        for (int i=0;i<4;i++){
            buttons.add(new JButton());
            buttons.get(i).setSize(200,100);
            buttons.get(i).setText(names[i]);

            if(i%2==0){
                panel = new JPanel();
                add(panel);
            }
            panel.add(buttons.get(i));

        }

        buttons.get(0).addActionListener(e -> System.out.println("Botão 1 foi precionando"));
        buttons.get(1).addActionListener(e -> System.out.println("Botão 2 foi precionando"));

        Contador contador = new Contador();
        contador.addListener(novoValor -> System.out.println("O novo Valor do Contador e:"+novoValor ));

        buttons.get(2).addActionListener(e -> contador.incrementar());
        buttons.get(3).addActionListener(e -> contador.decrementar());

        setVisible(true);
    }
}
