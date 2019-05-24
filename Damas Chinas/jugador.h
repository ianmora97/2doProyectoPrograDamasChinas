#pragma once

#include "tools.h"


class jugador {
public:
	jugador(string n);
	virtual ~jugador();
	virtual void setNombre(string n);
	virtual void setPuntaje(int p);
	virtual string getNombre() const;
	virtual int getPuntaje() const;
private:
	string nombre;
	int puntaje;

};