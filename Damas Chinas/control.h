#pragma once
#include "Juego.h"

class control{
public:
	control();
	~control();
	virtual void options();
	virtual void printMenu();
private:
	Juego* game;
};

