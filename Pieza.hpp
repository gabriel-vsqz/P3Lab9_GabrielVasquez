#pragma once
#include <string>

using namespace std;

class Pieza {
    public:
        Pieza();
        virtual bool validarMovimineto(int, int, char[8][8]);
};

Pieza :: Pieza() {
}

bool Pieza :: validarMovimineto(int origen, int destino, char tablero[8][8]) {
    
}