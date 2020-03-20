#pragma once
#include "Pieza.hpp"

class Reina : public Pieza {
    public:
        bool validarMovimineto(int, int, char[8][8]);
};