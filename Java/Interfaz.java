import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Interfaz {
    JFrame frame;

    int filas;
    int columnas;
    JLabel turnoJugador;
    JLabel puntaje1;
    JLabel puntaje2;
    String rutaImg;

    public void logicaUI() {
        frame = new JFrame();
        JPanel panel = new JPanel();
        frame.setSize(1200, 800);
        frame.setVisible(true);
        frame.setResizable(false);
        panel.setLayout(new GridLayout(8, 8));

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                panel.add(new Botones(i,j));

            }
        }

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
};