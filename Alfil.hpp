#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Alfil : public Pieza {
    public:
        Alfil();
        bool validarMovimineto(int, int, string[8][8]);
};

Alfil :: Alfil() : Pieza() {
}

bool Alfil :: validarMovimineto(int x, int y, string algo[8][8]) {
    return true;
}