//
// Created by gabriel on 11/4/22.
//

#include "Server.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>

//int sockfd, newsockfd, portno;
//socklen_t clilen;
//char buffer[256];
//struct sockaddr_in serv_addr, cli_addr;

class Server{
public:
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[1024]{};
    struct sockaddr_in serv_addr, cli_addr;
    Server(){
        sockfd = socket(AF_INET,SOCK_STREAM,0);

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
        memset(buffer, 0, sizeof (buffer));
    }
    void Enviar(){
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

    Servidor->Enviar();
    Servidor->Recibir();
    Servidor->cerrarSocket();
}
void error(char *msg){
    perror(msg);
    exit(1);
}
