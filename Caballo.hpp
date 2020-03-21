#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Caballo : public Pieza {
    public:
        Caballo();
        bool validarMovimineto(int, int, int, int, string[8][8]);
};

Caballo :: Caballo() : Pieza() {
}

bool Caballo :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string algo[8][8]) {
    if ( (destino_y == origen_y + 2) && (destino_x = origen_x + 1) ) {
        return true;
    } else if ( (destino_y == origen_y + 2) && (destino_x = origen_x - 1) ) {
        return true;
    } else if ( (destino_y == origen_y - 2) && (destino_x = origen_x - 1) ) {
        return true;
    } else if ( (destino_y == origen_y + 2) && (destino_x = origen_x + 1) ) {
        return true;
    } else if ( (destino_x == origen_x + 2) && (destino_y = origen_y + 1) ) {
        return true;
    } else if ( (destino_x == origen_x + 2) && (destino_y = origen_y - 1) ) {
        return true;
    } else if ( (destino_x == origen_x - 2) && (destino_y = origen_y - 1) ) {
        return true;
    } else if ( (destino_x == origen_x + 2) && (destino_y = origen_y + 1) ) {
        return true;
    } else {
        return false;
    }
}