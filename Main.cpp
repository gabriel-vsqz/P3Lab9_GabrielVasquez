#include <iostream>
#include <string>
#include "Pieza.hpp"

using namespace std;

int main() {
    cout << "\n----- AJEDREZ -----\n";
    bool pass = true;
    int opcion;
    while (pass) {
        cout << "\n1. Jugar Partida\n2. Recrear Partida\n: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {

            } break;
            
            case 2: {

            } break;

            case 3 : {
                pass = false;
            } break;

            default: {
                cout << "\nDebe seleccionar una de las opciones que se le presentan.\n";
            }
        }
    }
}