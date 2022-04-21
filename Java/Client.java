import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        final String HOST = "127.0.0.1";
        final int PUERTO = 5555;
        BufferedInputStream in;
        BufferedOutputStream out;
        byte[] byteArray;
        Interfaz UI = new Interfaz();
        UI.logicaUI();
        try{
            Socket sc = new Socket(HOST, PUERTO);
            in = new BufferedInputStream(sc.getInputStream());
            out = new BufferedOutputStream(sc.getOutputStream());
            byteArray = new byte[1024];
            System.out.println("Se crearon los puertos");

            int n = in.read(byteArray);
            System.out.println(n);
            String mensaje1 = new String(byteArray);
            System.out.println(mensaje1);
            String mensaje2 = "Hola!";
            out.write(mensaje2.getBytes());
            //out.write(byteArray);
            out.flush();
            System.out.println(mensaje2);
            sc.close();
            System.out.println("Cliente desconectado");
        }
        catch (IOException ex){
            System.out.println(ex);

        }
    }
}