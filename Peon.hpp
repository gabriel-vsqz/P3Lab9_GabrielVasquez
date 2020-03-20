#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Peon : public Pieza {
    public:
        Peon();
        bool validarMovimineto(int, int, string[8][8]);
};

Peon :: Peon() : Pieza() {
}

bool Peon :: validarMovimineto(int x, int y, string algo[8][8]) {
    return true;
}