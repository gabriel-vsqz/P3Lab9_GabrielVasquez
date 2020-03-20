#pragma once
#include "Pieza.hpp"

class Peon : public Pieza {
    public:
        Peon();
        bool validarMovimineto(int, int, char[8][8]);
};

Peon :: Peon() : Pieza() {
}

bool Peon :: validarMovimineto(int x, int y, char algo[8][8]) {
    return true;
}