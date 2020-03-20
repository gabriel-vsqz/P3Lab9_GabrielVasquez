#pragma once
#include "Pieza.hpp"

class Caballo : public Pieza {
    public:
        bool validarMovimineto(int, int, char[8][8]);
};