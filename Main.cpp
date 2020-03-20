#include <iostream>
#include <string>
#include <vector>
#include "Pieza.hpp"
#include "Rey.hpp"
#include "Reina.hpp"
#include "Torre.hpp"
#include "Alfil.hpp"
#include "Caballo.hpp"
#include "Peon.hpp"
#include "Partida.hpp"

/* #define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define h 7 */

using namespace std;

string tablero[8][8];
int pieza;
Rey white;
Rey black;
Pieza wplayer;
Pieza bplayer;

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
        } break;
        case 5: {
            tablero[6][4] = "[P]";
            tablero[1][4] = "[p]";
        } break;
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

string definirPieza() {
    string piece;
    switch (pieza) {
        case 1: {
            piece = "Reina";
        } break;
        case 2: {
            piece = "Torre";
        } break;
        case 3: {
            piece = "Alfil";
        } break;
        case 4: {
            piece = "Caballo";
        }
        case 5: {
            piece = "Peón";
        }
    }
    return piece;
}

void crearPiezas() {
    switch (pieza) {
        case 1: {
            Reina wqueen, bqueen;
            wplayer = wqueen;
            bplayer = bqueen;
        } break;
        case 2: {
            Torre wrook, brook;
            wplayer = wrook;
            bplayer = brook;
        } break;
        case 3: {
            Alfil wbishop, bbishop;
            wplayer = wbishop;
            bplayer = bbishop;
        } break;
        case 4: {
            Caballo wknight, bknight;
            wplayer = wknight;
            bplayer = bknight;
        }
        case 5: {
            Peon wpawn, bpawn;
            wplayer = wpawn;
            bplayer = bpawn;
        }
    }
}

int obtenerNumeros(char posicion) {
    int numero;
    switch (posicion) {
        case 'a':
        case '8':
            numero = 0;
            break;
        case 'b':
        case '7':
            numero = 1;
            break;
        case 'c':
        case '6':
            numero = 2;
            break;
        case 'd':
        case '5':
            numero = 3;
            break;
        case 'e':
        case '4':
            numero = 4;
            break;
        case 'f':
        case '3':
            numero = 5;
            break;
        case 'g':
        case '2':
            numero = 6;
            break;
        case 'h':
        case '1':
            numero = 7;
            break;
        default:
            numero = -1;
    }
    return numero;
}

void JugadaA(string m) {
    int x1 = obtenerNumeros(m[1]), x2 = obtenerNumeros(m[4]), y1 = obtenerNumeros(m[2]), y2 = obtenerNumeros(m[5]);
    if (tablero[y1][x1] == "[ ]") {
        cout << "No hay nada en la posición que eligió. Turno perdido.\n";
    } else {
        if (tablero[y1][x1] == "[K]") {
            if(white.validarMovimineto(y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                tablero[y1][x1] = "[ ]";
                tablero[y2][x2] = "[K]";
            } else {
                cout << "Movimiento inválido\n";
            }
        } else {
            
        }
    }
    dibujarTablero();
    cout << endl;
}

void JugadaB(string m) {
    int x1 = obtenerNumeros(m[1]), x2 = obtenerNumeros(m[4]), y1 = obtenerNumeros(m[2]), y2 = obtenerNumeros(m[5]);
    if (tablero[y1][x1] == "[ ]") {
        cout << "No hay nada en la posición que eligió. Turno perdido.\n";
    } else {
        if (tablero[y1][x1] == "[k]") {
            if(black.validarMovimineto(y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                tablero[y1][x1] = "[ ]";
                tablero[y2][x2] = "[k]";
            } else {
                cout << "Movimiento inválido.\n";
            }
        } else {

        }
    }
    dibujarTablero();
}

void comenzarPartida(string n) {
    crearPiezas();
    vector<string> movimientos;
    char resp = 's';
    string move1, move2;
    cout << "\nLos movimientos se declararan de la siguiente manera: (origen, destino). Ex. (a1,a5).\n";
    while (resp == 's' || resp == 'S') {
        cout << "Jugador 1 - Su movida: ";
        cin >> move1;
        if (move1.length() != 7) {
            cout << "Turno Perdido\n";
        } else {
            JugadaA(move1);
            movimientos.push_back(move1);
        }
        cout << "Jugador 2 - Su movida: ";
        cin >> move2;
        if (move2.length() != 7) {
            cout << "Turno Perdido\n";
        } else {
            JugadaB(move2);
            movimientos.push_back(move2);
        }

        cout << "¿Desea continuar [S/N]: ";
        cin >> resp; 
    }
    Partida nueva(n, definirPieza(), movimientos);
    nueva.guardarPartida();
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
                getline(cin, nombre);
                getline(cin, nombre);
                cout << "¿Con qué pieza desea jugar?\n1. Reina\n2. Torre\n3. Alfil\n4. Caballo\n5. Peón\n: ";
                cin >> pieza;
                while (pieza < 1 || pieza > 5) {
                    cout << "Debe elegir entre las opciones presentadas.\n1. Reina\n2. Torre\n3. Alfil\n4. Caballo\n5. Peón\n: ";
                    cin >> pieza;
                }
                llenarTablero(pieza);
                cout << "\n---------- " << nombre << " ----------\n";
                dibujarTablero();
                comenzarPartida(nombre);
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