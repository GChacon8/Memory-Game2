import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Client {
    final String HOST = "127.0.0.1";
    final int PUERTO = 5555;
    BufferedInputStream in;
    BufferedOutputStream out;
    byte[] byteArray;
    static Interfaz UI;
    static Client cliente;
    Socket sc;
    private static Client instancia = null;
    public static void main(String[] args) throws IOException {

        cliente = Client.getInstancia();
        cliente.iniciaSockets();
        UI = new Interfaz();
        UI.logicaUI();
        cliente.recibir();
        //cliente.enviar();
        //cliente.cerrarSocket();

    }
    void iniciaSockets() throws IOException {
        sc = new Socket(HOST, PUERTO);
        in = new BufferedInputStream(sc.getInputStream());
        out = new BufferedOutputStream(sc.getOutputStream());
        byteArray = new byte[1024];
        System.out.println("Se crearon los puertos");

    }
    void recibir() throws IOException {
        int n = in.read(byteArray);
        System.out.println(n);
        String mensaje1 = new String(byteArray);
        System.out.println(mensaje1);
    }
    void enviar() throws IOException {
        String mensaje2 = "Hola!";
        out.write(mensaje2.getBytes());
        out.flush();
    }
    void enviar(int i, int j) throws IOException {
        String mensaje = String.valueOf(i)+String.valueOf(j);
        out.write(mensaje.getBytes());
        out.flush();
    }
    void cerrarSocket() throws IOException {
        sc.close();
        System.out.println("Cliente desconectado");
    }
    public static Client getInstancia(){
        if (instancia == null){
            instancia = new Client();
        }
        return instancia;
    }
};

