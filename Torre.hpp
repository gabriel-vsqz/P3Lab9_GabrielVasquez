#pragma once
#include "Pieza.hpp"
#include <string>

using namespace std;

class Torre : public Pieza {
    public:
        Torre();
        bool validarMovimineto(int, int, string[8][8]);
};

Torre :: Torre() : Pieza() {
}

bool Torre :: validarMovimineto(int x, int y, string algo[8][8]) {
    return true;
}