#pragma once
#include "Pieza.hpp"

class Caballo : public Pieza {
    public:
        Caballo();
        bool validarMovimineto(int, int, char[8][8]);
};

Caballo :: Caballo() : Pieza() {
}

bool Caballo :: validarMovimineto(int x, int y, char algo[8][8]) {
    return true;
}