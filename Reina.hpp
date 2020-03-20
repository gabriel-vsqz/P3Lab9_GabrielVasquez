#pragma once
#include "Pieza.hpp"

class Reina : public Pieza {
    public:
        Reina();
        bool validarMovimineto(int, int, char[8][8]);
};

Reina :: Reina() : Pieza() {
}

bool Reina :: validarMovimineto(int x, int y, char algo[8][8]) {
    return true;
}