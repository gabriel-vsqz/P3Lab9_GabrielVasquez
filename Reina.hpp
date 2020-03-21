#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Reina : public Pieza {
    public:
        Reina();
        bool validarMovimineto(int, int, int, int, string[8][8]);
};

Reina :: Reina() : Pieza() {
}

bool Reina :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string algo[8][8]) {
    if ( (destino_y >= 0 && destino_y <= 7)  && destino_x == origen_x ) {
        return true;
    } else if ( (destino_x >= 0 && destino_x <= 7)  && destino_y == origen_y ) {
        return true;
    } else if ( (destino_x + destino_y == origen_x + origen_y) ) {
        return true;
    } else if ( (destino_x + destino_y >= origen_x + origen_y + 2) ) {
        return true;
    } else if ( ((destino_x + destino_y <= origen_x + origen_y - 2)) ) {
        return true;
    }
    else {
        return false;
    }
}