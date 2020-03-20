#pragma once
#include "Pieza.hpp"

class Alfil : public Pieza {
    public:
        bool validarMovimineto(int, int, char[8][8]);
};