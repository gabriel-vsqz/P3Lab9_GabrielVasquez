#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Alfil : public Pieza {
    private:
        string color;
    public:
        Alfil();
        Alfil(string);
        bool validarMovimineto(int, int, int, int, string[8][8]);
};

Alfil :: Alfil() : Pieza() {
}

Alfil :: Alfil(string c) : Pieza() {
    color = c;
}

bool Alfil :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string algo[8][8]) {
    if ( color == "white" && ((destino_y + destino_x == 9) || (destino_y + destino_x == 8)) ) {
        return true;
    } else if ( color == "white" && ((destino_y + destino_x <= origen_y + origen_x - 2) || (destino_y + destino_x >= origen_y + origen_x + 2)) ) {
        return true;
    } else if ( color == "black" && (destino_y + destino_x == 5) ) {
        return true;
    } else if ( color == "black" && ((destino_y + destino_x <= origen_y + origen_x - 2) || (destino_y + destino_x >= origen_y + origen_x + 2)) ) {
        return true;
    } else {
        return false;
    }
}