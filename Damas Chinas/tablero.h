#pragma once
#include "tools.h"


class tablero{
public:
	tablero();
	~tablero();
	virtual string printTablero();
	virtual void darValor();
private:
	char fichas[8][8];
	int tam, cant;
};
