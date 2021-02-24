import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;

public class RefrigeradorListener implements ActionListener, RefrigeradorListenerInter {
    private final JLabel txt;
    private String texto = "";

    public RefrigeradorListener(JLabel txt,String texto){
        this.txt = txt;
        this.texto = texto;
    }
    public RefrigeradorListener(JLabel txt){
        this.txt = txt;
    }

    @Override
    public void actionPerformed(ActionEvent e) {}

    public void modancaTemp(float temp){
        DecimalFormat formato = new DecimalFormat("0.00");
        String temperatura = formato.format(temp);
        txt.setText(texto+temperatura);
    }
}
