#include "estrategia.h"

defensa::defensa(){}
defensa::~defensa(){}

void defensa::algoritmo(){
	cout << "Modo defensa" << endl;
}

ataque::ataque(){}
ataque::~ataque(){}

void ataque::algoritmo(){
	cout << "Modo ataque" << endl;
}

respuesta::respuesta(estrategia* e) : _estrategia(e){}

void respuesta::setEstrategia(estrategia* e) { _estrategia = e; }

void respuesta::interfazRespuesta(){
	_estrategia->algoritmo();
}
