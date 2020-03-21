#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Rey : public Pieza {
    public:
        Rey();
        bool validarMovimineto(int, int, int, int, string[8][8]);
};

Rey :: Rey() : Pieza() {
}

bool Rey :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string algo[8][8]) {
    if ( ((destino_x == origen_x + 1) || (destino_x == origen_x - 1)) && destino_y == origen_y && (origen_x - 1 > 0 || origen_x + 1 > 0) ) {
        return true;
    } else if ( ((destino_y == origen_y + 1) || (destino_y == origen_y - 1)) && destino_x == origen_x && (origen_y - 1 > 0 || origen_y + 1 > 0) ) {
        return true;
    } else if ( (destino_y == origen_y + 1 && destino_x == origen_x + 1) && origen_x + 1 > 0 && origen_y + 1 > 0 ) {
        return true;
    } else if ( (destino_y == origen_y - 1 && destino_x == origen_x - 1) && origen_x - 1 > 0 && origen_y - 1 > 0 ) {
        return true;
    } else if ( (destino_y == origen_y - 1 && destino_x == origen_x + 1) && origen_x + 1 > 0 && origen_y - 1 > 0 ) {
        return true;
    } else if ( (destino_y == origen_y + 1 && destino_x == origen_x - 1) && origen_x - 1 > 0 && origen_y + 1 > 0 ) {
        return true;
    } else {
        return false;
    }
}