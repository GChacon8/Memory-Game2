//
// Created by gabriel on 21/04/22.
//

#ifndef C___CARTA_H
#define C___CARTA_H

#include <cstddef>
#include <cstring>

class Carta{
private:
    int id;
    int tipo;
    bool usada;
    char img[128];

public:
    void setTipo(int nuevoTipo){
        tipo = nuevoTipo;
    }
    void setID(int nuevoTipo){
        tipo = nuevoTipo;
    }

    void setImg(char img[]){
        size_t sz = std::strlen(img);

    }
    int getTipo(){
        return tipo;
    }
    char* getImg(){
            return img;
    }

    int getID(){
        return id;
    }

    Carta(int id, int tipo, const char imgRuta[128]){
        this->id = id;
        this->tipo = tipo;
        usada = false;
        strcpy(img,imgRuta);

    }
};

#endif //C___CARTA_H
