//
// Created by gabriel on 11/4/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "MatrizPaginada.h"

class Server{
public:
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    MatrizPaginada matrizPaginada;
    int puntaje1,puntaje2;
    char byteX;
    char byteY;
    int cartaID;
    Server(){
        sockfd = socket(AF_INET,SOCK_STREAM,0);
        matrizPaginada.cargarMatrizInts();
        matrizPaginada.cargarVector();

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(5555);

        if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof (serv_addr))>=0){
            std::cout <<"Escuchando para conexiones entrantes..."<< std::endl;
        }
        listen(sockfd,0);
        clilen = sizeof (cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd>=0) {
            std::cout << "Cliente conectado" << std::endl;
        }

    }
    void Recibir(){
        read(newsockfd, buffer, 1023);
        std::cout <<"El cliente dice:"<< buffer << std::endl;
        byteX = buffer[0];
        byteY = buffer[1];
        cartaID = matrizPaginada.getID(byteX,byteY);
        memset(buffer, 0, sizeof (buffer));
    }
    void Enviar(){
        std::cout << "Escribe el mensaje a enviar" << std::endl;
        //std::cin>>this->buffer;
        write(newsockfd, buffer, 1023);
        memset(buffer, 0, sizeof (buffer));
        std::cout << "Mensaje Enviado desde el server:)" << std::endl;
    }
    void Enviar(char imgRuta[128]){
        strcpy(buffer, imgRuta);
        write(newsockfd, buffer, 1023);
        memset(buffer, 0, sizeof (buffer));
        std::cout << "Mensaje Enviado desde el server: " << buffer << std::endl;
    }
    void Enviar(char img[50], int puntaje){
        std::cout << "Escribe el mensaje a enviar" << std::endl;
        std::cin>>this->buffer;
        write(newsockfd, buffer, 1023);
        memset(buffer, 0, sizeof (buffer));
        std::cout << "Mensaje Enviado desde el server:)" << std::endl;
    }
    void cerrarSocket(){
        close(newsockfd);
        std::cout << "Cliente desconectado" << std::endl;

    }
};

int main(){
    Server *Servidor = new Server();
    char rutaImg[128];
    memset(rutaImg, 0, sizeof (rutaImg));


    while(true) {
        Servidor->Enviar(rutaImg);
        Servidor->Recibir();
        strcpy(rutaImg,Servidor->matrizPaginada.darImg(Servidor->cartaID));
    }

    Servidor->cerrarSocket();

}
void error(char *msg){
    perror(msg);
    exit(1);
}
