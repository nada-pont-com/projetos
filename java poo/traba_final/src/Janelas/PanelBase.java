package Janelas;

import javax.swing.*;

public abstract class PanelBase extends JPanel {
    public void visible(boolean visible){
        this.setVisible(visible);
    }
    public boolean visible(){
        return this.isVisible();
    }
}
