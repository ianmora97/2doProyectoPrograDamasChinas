#pragma once
#include "tools.h"
#include "tablero.h"
#include "jugador.h"
#include "estrategia.h"

using namespace std;
class Juego{
private:
	tablero* _tablero;
	jugador* p1;
	respuesta* _estrategia;
public:
	Juego();
	~Juego();
	virtual void jugar();
	virtual void pideNombre();
	virtual int verificaJugada(int fm,int cm);
	virtual bool verificaDobleJugada(int fm, int cm);
	virtual void guardaPartida(ofstream& archivo);
	virtual void imprimeOpcionJuego();
};
