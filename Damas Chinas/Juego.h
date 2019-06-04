#pragma once
#include "tools.h"
#include "tablero.h"
#include "jugador.h"

using namespace std;
class Juego{
private:
	tablero* _tablero;
	jugador* p1;
public:
	Juego();
	~Juego();
	virtual void jugar();
	virtual void pideNombre();
	virtual int verificaJugada(int fm,int cm);
	virtual bool verificaDobleJugada(int fm, int cm);
	virtual void guardaPartida(ofstream& archivo);

};
