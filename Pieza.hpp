#pragma once
#include <string>

using namespace std;

class Pieza {
    public:
        Pieza();
        virtual bool validarMovimineto(int, int, int, int, string[8][8]);
};

Pieza :: Pieza() {
}

bool Pieza :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string tablero[8][8]) {
    
}