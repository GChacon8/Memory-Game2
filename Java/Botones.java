import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class Botones extends JButton {

    public final int fX;
    public final int fY;

    public Botones(final int x, final int y) {
        super(String.valueOf(x)+String.valueOf(y));
        fX= x;
        fY= y;

        addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    Client.getInstancia().enviar(fX,fY);
                    Client.getInstancia().recibir();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
        });
    }

}