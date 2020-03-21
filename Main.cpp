#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Pieza.hpp"
#include "Rey.hpp"
#include "Reina.hpp"
#include "Torre.hpp"
#include "Alfil.hpp"
#include "Caballo.hpp"
#include "Peon.hpp"
#include "Partida.hpp"

using namespace std;

string tablero[8][8];
int pieza;
Rey white;
Rey black;
vector<string> moves;

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
            if(white.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                tablero[y1][x1] = "[ ]";
                tablero[y2][x2] = "[K]";
            } else {
                cout << "Movimiento inválido\n";
            }
        } else {
            if (tablero[y1][x1] == "[Q]") {
                Reina wqueen;
                if(wqueen.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[Q]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
            
            else if (tablero[y1][x1] == "[R]") {
                Torre wrook;
                if(wrook.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[R]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
            
            else if (tablero[y1][x1] == "[B]") {
                Alfil wbishop("white");
                if(wbishop.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[B]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
            
            else if (tablero[y1][x1] == "[H]") {
                Caballo wknight;
                if(wknight.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[H]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
            
            else if (tablero[y1][x1] == "[P]") {
                Peon wpawn("white");
                if(wpawn.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[P]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
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
            if(black.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                tablero[y1][x1] = "[ ]";
                tablero[y2][x2] = "[k]";
            } else {
                cout << "Movimiento inválido\n";
            }
        } else {
            if (tablero[y1][x1] == "[q]") {
                Reina bqueen;
                if(bqueen.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[q]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
            
            else if (tablero[y1][x1] == "[r]") {
                Torre brook;
                if(brook.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[r]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
            
            else if (tablero[y1][x1] == "[b]") {
                Alfil bbishop("black");
                if(bbishop.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[b]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
            
            else if (tablero[y1][x1] == "[h]") {
                Caballo bknight;
                if(bknight.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[h]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
            
            else if (tablero[y1][x1] == "[p]") {
                Peon bpawn("black");
                if(bpawn.validarMovimineto(y1, x1, y2, x2, tablero) && tablero[y2][x2] == "[ ]") {
                    tablero[y1][x1] = "[ ]";
                    tablero[y2][x2] = "[p]";
                } else {
                    cout << "Movimiento inválido\n";
                }
            }
        }
    }
    dibujarTablero();
    cout << endl;
}

void comenzarPartida(string n) {
    vector<string> movimientos;
    char resp = 's';
    string move1, move2;
    cout << "\nLos movimientos se declararán de la siguiente manera: (origen, destino). Ex. (a1,a5).\n\n";
    while (resp == 's' || resp == 'S') {
        cout << "Jugador 1 - Su movida: ";
        cin >> move1;
        if (move1.length() != 7) {
            cout << "Turno Perdido\n";
            movimientos.push_back("LOST_TURN");
        } else {
            JugadaA(move1);
            movimientos.push_back(move1);
        }
        cout << "Jugador 2 - Su movida: ";
        cin >> move2;
        if (move2.length() != 7) {
            cout << "Turno Perdido\n";
            movimientos.push_back("LOST_TURN");
        } else {
            JugadaB(move2);
            movimientos.push_back(move2);
        }

        cout << "\n¿Desea continuar [S/N]: ";
        cin >> resp;
        cout << endl;
    }
    Partida nueva(n, definirPieza(), movimientos);
    nueva.guardarPartida();
}

void listarPartidas() {
    cout << "\n------------------------- Lista de Partidas -------------------------\n";
    ifstream bitacora("bitacoraPartidas.txt", ios::in);
    if(!bitacora) {
        cerr << "No se pudo abrir el archivo, probablemente no has jugado :P\n\n";
        exit(1);
    }
    string nombre, piece;
    vector<string> movimientos;
    while(bitacora >> nombre >> piece) {
        cout << nombre << endl << piece << endl;
        for (int i = 0; i < movimientos.size(); i++) {
            cout << movimientos[i];
            moves.push_back(movimientos[i]);
        }
        
    }
    cout << endl;
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
                cout << "\nLas piezas se representan de la siguiente manera: Rey - R, Reina - Q, Torre - R, Alfil - B, Caballo - H, Peon - P.\n";
                cout << "Mayúsculas para las piezas negras y minúsculas para las piezas blancas.\n";
                cout << "\n---------- " << nombre << " ----------\n";
                dibujarTablero();
                comenzarPartida(nombre);
            } break;
            
            case 2: {
                listarPartidas();
                int pos;
                cout << "¿Qué partida desea recrear?: ";
                cin >> pos;
                cout << "As far as I got :(" << endl;
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