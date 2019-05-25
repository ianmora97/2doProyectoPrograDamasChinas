#pragma once
#include "tools.h"


class tablero{
public:
	tablero();
	~tablero();
	virtual void printTablero();
	virtual void agregar(char,int,int);
	virtual void quitar(int,int);
	virtual bool existe(int,int);
	virtual bool movidaLegal(int,int);
	virtual char getFicha(int,int);
private:
	char fichas[8][8];
	int tam, cant;
};
