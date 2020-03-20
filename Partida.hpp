#pragma once
#include <string>
#include <vector>

using namespace std;

class Partida {
    private:
        string nombre, pieza;
        vector<string> movimientos;
    public:
        Partida() {}
        void guardarPartida(string, string, vector<string>);
        
};