#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Alfil : public Pieza {
    public:
        Alfil();
        bool validarMovimineto(int, int, int, int, string[8][8]);
};

Alfil :: Alfil() : Pieza() {
}

bool Alfil :: validarMovimineto(int origen_y, int origen_x, int destino_y, int destino_x, string algo[8][8]) {
    return true;
}