import javax.swing.*;
import java.awt.*;

public class Janela extends JFrame {
    private JLabel txt;

    public Janela(Geladeira geladeira){
        setTitle("Notepad");
        setSize(700,500);
        setLayout(new BorderLayout());
        txt = new JLabel();
        txt.setHorizontalAlignment(SwingConstants.CENTER);
        add(txt, BorderLayout.CENTER);

        getContentPane().setBackground(Color.BLACK);

        setLocationRelativeTo(null);


        txt.setForeground(Color.getHSBColor(100,100,100));

        geladeira.addListenerRefrigerador(new RefrigeradorListener(txt,"Temperatura Atual: "));
        geladeira.getRefrigerador().addListener(new RefrigeradorListener(txt,"Temperatura Atual: "));
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}