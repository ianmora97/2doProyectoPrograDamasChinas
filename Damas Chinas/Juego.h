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
	defensa* _defensa;
	ataque* _ataque;
	estrategia* _aleatoria;
	selectivo* _selectivo;
	
public:
	Juego();
	~Juego();
	virtual void jugar();
	virtual void pideNombre();
	virtual int verificaJugada(int fm,int cm);
	virtual bool verificaDobleJugada(int fm, int cm);
	virtual void guardaPartida();
	virtual bool cargarPartida();
	virtual int imprimeOpcionJuego();
	virtual void seleccionarEstrategia();
};
