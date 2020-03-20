#pragma once
#include "Pieza.hpp"

class Alfil : public Pieza {
    public:
        Alfil();
        bool validarMovimineto(int, int, char[8][8]);
};

Alfil :: Alfil() : Pieza() {
}

bool Alfil :: validarMovimineto(int x, int y, char algo[8][8]) {
    return true;
}