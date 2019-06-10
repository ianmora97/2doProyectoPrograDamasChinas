#include "estrategia.h"

defensa::defensa() { tipo = "Defensa"; }
defensa::~defensa(){}
ataque::ataque() { tipo = "Ataque"; }
ataque::~ataque(){}
aleatoria::aleatoria() { tipo = "Aleatoria"; }
aleatoria::~aleatoria(){}
selectivo::selectivo() { tipo = "Selectivo"; }
selectivo::~selectivo(){}

string ataque::getEstrategia() const { return tipo; }
string selectivo::getEstrategia() const { return tipo; }
string defensa::getEstrategia() const { return tipo; }
string aleatoria::getEstrategia() const { return tipo; }

void ataque::algoritmo(tablero* _tablero){
	gotoxy(50, 3); color(15); cout << "Turno de La computadora";
	_tablero->printTablero();
}

void selectivo::algoritmo(tablero*){

}


void defensa::algoritmo(tablero* _tablero){
	gotoxy(50, 3); color(15); cout << "Turno de La computadora";
	_tablero->printTablero();
}

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
string respuesta::toString() {
	return _estrategia->getEstrategia();
}


