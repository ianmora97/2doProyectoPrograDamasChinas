#include "jugador.h"

jugador::jugador(string n) : nombre(n), puntaje(0) {}
jugador::~jugador(){}

void jugador::setNombre(string n){
	nombre = n;
}

void jugador::setPuntaje(int p){
	puntaje = p;
}

string jugador::getNombre() const{
	return nombre;
}

int jugador::getPuntaje() const{
	return puntaje;
}
string jugador::toString() {
	stringstream s;
	s << nombre << endl;
	s << puntaje << endl;
	return s.str();
}