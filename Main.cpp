#include <iostream>
#include <string>
#include <vector>
#include "Pieza.hpp"

using namespace std;

string tablero[8][8];
int pieza;

void llenarTablero(int pieza) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = "[ ]";
        }
    }
    tablero[7][4] = "[K]";
    tablero[0][4] = "[k]";
    switch (pieza) {
        case 1: {
            tablero[7][3] = "[Q]";
            tablero[0][3] = "[q]";
        } break;
        case 2: {
            tablero[7][0] = "[R]";
            tablero[0][7] = "[r]";
        } break;
        case 3: {
            tablero[7][2] = "[B]";
            tablero[0][5] = "[b]";
        } break;
        case 4: {
            tablero[7][1] = "[H]";
            tablero[0][6] = "[h]";
        }
        case 5: {
            tablero[6][4] = "[P]";
            tablero[1][4] = "[p]";
        }
    }
}

void dibujarTablero() {
    cout << "\n";
    for (int i = 0, k = 8; i < 8; i++, k--) {
        cout << k << " ";
        for (int j = 0; j < 8; j++) {
            cout << tablero[i][j];
        }
        cout << endl;
    }
    cout << "   a  b  c  d  e  f  g  h";
    cout << "\n";
}

int main() {
    cout << "\n----- AJEDREZ -----\n";
    bool pass = true;
    int opcion;
    while (pass) {
        cout << "\n1. Jugar Partida\n2. Recrear Partida\n3. Salir\n: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                string nombre;
                cout << "\nIngrese el nombre de la partida: ";
                cin >> nombre;
                cout << "¿Con qué pieza desea jugar?\n1. Reina\n2. Torre\n3. Alfil\n4. Caballo\n5. Peón\n: ";
                cin >> pieza;
                llenarTablero(pieza);
                cout << "\n---------- " << nombre << " ----------\n";
                dibujarTablero();
                comenzarPartida();
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