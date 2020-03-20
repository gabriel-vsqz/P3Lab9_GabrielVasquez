#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Partida {
    private:
        string nombre, pieza;
        vector<string> movimientos;
    public:
        Partida(string n, string p, vector<string> m) {
            nombre = n;
            pieza = p;
            movimientos = m;
        }
        void guardarPartida();
};

void Partida :: guardarPartida() {
    ofstream bitacora("bitacoraPartidas.txt", ios::app);
    if(!bitacora) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    } else {
        bitacora << nombre << "\n" << pieza << "\n";
        for (size_t i = 0; i < movimientos.size(); i++) {
            bitacora << movimientos[i];
            if (i < movimientos.size() - 1)
                bitacora << ";";
        }
        bitacora << "\n------------------------------------------------------------";
    }
}