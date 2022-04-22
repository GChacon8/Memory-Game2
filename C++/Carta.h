//
// Created by gabriel on 21/04/22.
//

#ifndef C___CARTA_H
#define C___CARTA_H
class Carta{
private:
    int id;
    int tipo;
    bool usada;
    char img[128];

    Carta(int id, int tipo){
        this->id = id;
        this->tipo = tipo;
    }

public:
    void setTipo(int nuevoTipo){
        tipo = nuevoTipo;
    }
};

#endif //C___CARTA_H
