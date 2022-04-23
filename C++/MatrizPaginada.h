//
// Created by gabriel on 20/04/22.
//

#ifndef C___MATRIZPAGINADA_H
#define C___MATRIZPAGINADA_H

#include "Carta.h"
#include <vector>

class MatrizPaginada {
private:
    int matrizInts[8][8];
    const char *rutas[16] = {"/home/gabriel/Documents/Memory-Game2/Black.png","/home/gabriel/Documents/Memory-Game2/White.png","/home/gabriel/Documents/Memory-Game2/Gray.png","/home/gabriel/Documents/Memory-Game2/Red.png","/home/gabriel/Documents/Memory-Game2/Indigo.png","/home/gabriel/Documents/Memory-Game2/Turquoise.png","/home/gabriel/Documents/Memory-Game2/Green.png","/home/gabriel/Documents/Memory-Game2/Yellow.png","/home/gabriel/Documents/Memory-Game2/Purple.png","/home/gabriel/Documents/Memory-Game2/Orange.png","/home/gabriel/Documents/Memory-Game2/LightTurquoise.png","/home/gabriel/Documents/Memory-Game2/LightGray.png","/home/gabriel/Documents/Memory-Game2/Brown.png","/home/gabriel/Documents/Memory-Game2/Rose.png","/home/gabriel/Documents/Memory-Game2/DarkRed.png","/home/gabriel/Documents/Memory-Game2/LightYellow.png"};
    std::vector<Carta> vctCartas;
    /*
    char rutaImg1[128] = "/home/gabriel/Documents/Memory-Game2/Black.png";
    char rutaImg2[128] = "/home/gabriel/Documents/Memory-Game2/White.png";
    char rutaImg3[128] = "/home/gabriel/Documents/Memory-Game2/Gray.png";
    char rutaImg4[128] = "/home/gabriel/Documents/Memory-Game2/Red.png";
    char rutaImg5[128] = "/home/gabriel/Documents/Memory-Game2/Indigo.png";
    char rutaImg6[128] = "/home/gabriel/Documents/Memory-Game2/Turquoise.png";
    char rutaImg7[128] = "/home/gabriel/Documents/Memory-Game2/Green.png";
    char rutaImg8[128] = "/home/gabriel/Documents/Memory-Game2/Yellow.png";
    char rutaImg9[128] = "/home/gabriel/Documents/Memory-Game2/Purple.png";
    char rutaImg10[128] = "/home/gabriel/Documents/Memory-Game2/Orange.png";
    char rutaImg11[128] = "/home/gabriel/Documents/Memory-Game2/LightTurquoise.png";
    char rutaImg12[128] = "/home/gabriel/Documents/Memory-Game2/LightGray.png";
    char rutaImg13[128] = "/home/gabriel/Documents/Memory-Game2/Brown.png";
    char rutaImg14[128] = "/home/gabriel/Documents/Memory-Game2/Rose.png";
    char rutaImg15[128] = "/home/gabriel/Documents/Memory-Game2/DarkRed.png";
    char rutaImg16[128] = "/home/gabriel/Documents/Memory-Game2/LightYellow.png";
    */
public:
    void cargarMatrizInts() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; ++j) {
                matrizInts[i][j] = (i + 1) + (j * 8);
            }
        }
    }

    int getID(int i,int j){
        return matrizInts[i][j];
    }

    void cargarVector(){
        for(int i =0; i<4; i++){
            for(int j =0; j<16;j++){
               Carta carta((j+1)+(16*i), i+1,rutas[j]);
               vctCartas.push_back(carta);
            }

        }
    }

    char* darImg(int id) {
        for (int i = 0; i < 64; i++) {
            if (vctCartas[i].getID() == id){
                return vctCartas[i].getImg();
            }

        }
    };

};

#endif //C___MATRIZPAGINADA_H
