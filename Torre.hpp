#pragma once
#include "Pieza.hpp"

class Torre : public Pieza {
    public:
        Torre();
        bool validarMovimineto(int, int, char[8][8]);
};

Torre :: Torre() : Pieza() {
}

bool Torre :: validarMovimineto(int x, int y, char algo[8][8]) {
    return true;
}