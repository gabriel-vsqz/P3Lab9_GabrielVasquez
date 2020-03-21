#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Peon : public Pieza {
    public:
        Peon();
        bool validarMovimineto(int, int, int, int, string[8][8]);
};

Peon :: Peon() : Pieza() {
}

bool Peon :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string algo[8][8]) {
    return true;
}