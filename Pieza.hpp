#pragma once
#include <string>

using namespace std;

class Pieza {
    public:
        Pieza();
        virtual bool validarMovimineto(int, int, string[8][8]);
};

Pieza :: Pieza() {
}

bool Pieza :: validarMovimineto(int origen, int destino, string tablero[8][8]) {
    
}