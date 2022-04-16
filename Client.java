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
        try{
            Socket sc = new Socket(HOST, PUERTO);
            in = new BufferedInputStream(sc.getInputStream());
            out = new BufferedOutputStream(sc.getOutputStream());
            byteArray = new byte[1024];
            Scanner scanner = new Scanner(System.in);
            System.out.println("Se crearon los puertos");

            //String mensaje = in.readUTF();
            //System.out.println(mensaje);

            int n = in.read(byteArray);
            System.out.println(n);
            //out.writeUTF("Hola desde el cliente");
            //String mensaje = "Hola!";
            String mensaje = scanner.nextLine();
            out.write(mensaje.getBytes());
            //out.write(byteArray);
            out.flush();
            //out.write(97);
            for (byte b:mensaje.getBytes()){
                if(b==0){
                    break;
                }
                System.out.println((char)b+":"+b);
            }
            System.out.println(mensaje);
            sc.close();
            System.out.println("Cliente desconectado");
        }
        catch (IOException ex){
            System.out.println(ex);

        }
    }
}