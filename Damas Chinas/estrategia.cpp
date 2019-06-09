#include "estrategia.h"

defensa::defensa(){}
defensa::~defensa(){}

void defensa::algoritmo(tablero* _tablero){
	cout << "Modo defensa" << endl;
}

ataque::ataque(){}
ataque::~ataque(){}

void ataque::algoritmo(tablero* _tablero){
	cout << "Modo ataque" << endl;
}


aleatoria::aleatoria(){}
aleatoria::~aleatoria(){}

void aleatoria::algoritmo(tablero* _tablero){
	bool co = true;
	int cr;
	do {
		cr = 3 + rand() % 7;
		if ((cr % 2 != 0)) {
			co = false;
		}
	} while (co);
	int r;
	r = rand() % 1;
	if (r == 0) {
		r = -1;
	}
	
	color(10); gotoxy(1, 22); cout << "\nAnalizando jugada ...\n";
	Sleep(600);
	_tablero->agregar(PIEZA_O, 4, cr + r);
	_tablero->quitar(3, cr);
	cls();
	gotoxy(50, 3); color(15); cout << "Turno de La computadora";
	_tablero->printTablero();
	pauseCorner();
}

respuesta::respuesta(){}
respuesta::respuesta(estrategia* e) : _estrategia(e){}
respuesta::~respuesta(){}

void respuesta::setEstrategia(estrategia* e) { _estrategia = e; }

void respuesta::interfazRespuesta(tablero* _tablero){
	_estrategia->algoritmo(_tablero);
}
