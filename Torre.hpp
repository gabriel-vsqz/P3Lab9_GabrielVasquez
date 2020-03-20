#pragma once
#include "Pieza.hpp"

class Torre : public Pieza {
    public:
        bool validarMovimineto(int, int, char[8][8]);
};