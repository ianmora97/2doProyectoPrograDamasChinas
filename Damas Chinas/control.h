#pragma once
#include "tablero.h"
#include "jugador.h"

class control{
public:
	control();
	~control();
	virtual void options();
	virtual void printMenu();
};

