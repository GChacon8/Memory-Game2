import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Botones {
    int i;
    int j;
    JButton boton;

    public Botones(int i, int j){
        this.i = i;
        this.j = j;
        boton = new JButton();
        ActionListener evento = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {

            }
        };
    }

}
