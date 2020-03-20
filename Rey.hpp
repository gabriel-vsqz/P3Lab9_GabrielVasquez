#pragma once
#include "Pieza.hpp"

class Rey : public Pieza {
    public:
        Rey();
        bool validarMovimineto(int, int, char[8][8]);
};

Rey :: Rey() : Pieza() {
}

bool Rey :: validarMovimineto(int x, int y, char algo[8][8]) {
    return true;
}