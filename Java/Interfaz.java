import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Interfaz implements ActionListener {
    JFrame frame;
    JButton botones[][];
    int filas;
    int columnas;
    JLabel turnoJugador;
    JLabel puntaje1;
    JLabel puntaje2;
    String rutaImg;
    int posX =0;
    int posY = 0;

    public void logicaUI()
    {
        frame = new JFrame();
        frame.setSize(1200,800);
        frame.setVisible(true);
        frame.setResizable(false);

        turnoJugador = new JLabel("Turno de:");
        turnoJugador.setBounds(50,50,100,100);
        frame.add(turnoJugador);

        puntaje1 = new JLabel("Puntaje del J1:");
        puntaje2 = new JLabel("Puntaje del J2:");
        puntaje1.setBounds(100,200,100,100);
        puntaje2.setBounds(200,200,100,100);
        frame.add(puntaje1);
        frame.add(puntaje2);


        SwingUtilities.updateComponentTreeUI(frame);


        JButton b1 = new JButton("B1");

        /*botones = new JButton[filas][columnas];
        for(int i=0; i<8; i++){
           for(int j=0;j<8;j++){
               botones[i][j].setBounds(i*60,j*60,50,50);
                frame.add(botones[i][j]);
            }
        }*/


        b1.setBounds(200,200,50, 50);
        //ImageIcon img = new ImageIcon("A.bmp");
        //b1.setIcon(new ImageIcon(img.getImage().getScaledInstance(b1.getWidth(), b1.getHeight(), Image.SCALE_SMOOTH)));

        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                System.out.println("b1 imprime");
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        System.out.println("action Ev");
    }
}