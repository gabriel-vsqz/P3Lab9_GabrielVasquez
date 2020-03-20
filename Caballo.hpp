#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Caballo : public Pieza {
    public:
        Caballo();
        bool validarMovimineto(int, int, string[8][8]);
};

Caballo :: Caballo() : Pieza() {
}

bool Caballo :: validarMovimineto(int x, int y, string algo[8][8]) {
    return true;
}