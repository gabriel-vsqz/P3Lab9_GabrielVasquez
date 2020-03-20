#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Rey : public Pieza {
    public:
        Rey();
        bool validarMovimineto(int, int, string[8][8]);
};

Rey :: Rey() : Pieza() {
}

bool Rey :: validarMovimineto(int x, int y, string algo[8][8]) {
    if (algo[y][x]) {
        
    } else {
        return false;
    }
}