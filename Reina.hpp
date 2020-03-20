#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Reina : public Pieza {
    public:
        Reina();
        bool validarMovimineto(int, int, string[8][8]);
};

Reina :: Reina() : Pieza() {
}

bool Reina :: validarMovimineto(int x, int y, string algo[8][8]) {
    return true;
}