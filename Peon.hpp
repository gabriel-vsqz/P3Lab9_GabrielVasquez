#pragma once
#include "Pieza.hpp"

class Peon : public Pieza {
    public:
        bool validarMovimineto(int, int, char[8][8]);
};