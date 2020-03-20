#pragma once
#include "Pieza.hpp"

class Rey : public Pieza {
    public:
        bool validarMovimineto(int, int, char[8][8]);
};