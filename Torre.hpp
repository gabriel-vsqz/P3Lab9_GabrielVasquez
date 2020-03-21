#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Torre : public Pieza {
    public:
        Torre();
        bool validarMovimineto(int, int, int, int, string[8][8]);
};

Torre :: Torre() : Pieza() {
}

bool Torre :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string algo[8][8]) {
    if ( (destino_y >= 0 && destino_y <= 7)  && destino_x == origen_x ) {
        return true;
    } else if ( (destino_x >= 0 && destino_x <= 7)  && destino_y == origen_y ) {
        return true;
    } else {
        return false;
    }
}