#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Peon : public Pieza {
    private:
        string color;
    public:
        Peon();
        Peon(string);
        bool validarMovimineto(int, int, int, int, string[8][8]);
};

Peon :: Peon() : Pieza() {
}

Peon :: Peon(string c) : Pieza() {
    color = c;
}

bool Peon :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string algo[8][8]) {
    if ( (destino_y == origen_y + 1) && destino_y >= 0 && color == "black" && (destino_x == origen_x) ) {
        return true;
    } else if ( (destino_y == origen_y - 1) && destino_y >= 0 && color == "white" && (destino_x == origen_x) ) {
        return true;
    } else {
        return false;
    }
}