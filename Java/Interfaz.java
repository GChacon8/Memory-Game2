import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Interfaz implements ActionListener {
    JFrame frame;
    JButton b1;

    public void logicaUI()
    {
        frame = new JFrame();
        frame.setSize(700,500);
        frame.setVisible(true);
        frame.setResizable(false);

        b1 = new JButton();
        b1.setBounds(200,200,150, 150);
        ImageIcon img = new ImageIcon("A.bmp");
        b1.setIcon(new ImageIcon(img.getImage().getScaledInstance(b1.getWidth(), b1.getHeight(), Image.SCALE_SMOOTH)));
        frame.add(b1);
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