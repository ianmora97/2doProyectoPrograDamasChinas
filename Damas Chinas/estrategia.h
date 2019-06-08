#pragma once
#include "tools.h"
class estrategia{
public:
	virtual void algoritmo() = 0;
};

class defensa : public estrategia{
public:
	defensa();
	~defensa();
	virtual void algoritmo();

private:

};

class ataque : public estrategia{
public:
	ataque();
	~ataque();
	virtual void algoritmo();

private:

};

class respuesta {
private:
	estrategia* _estrategia;
public:
	respuesta(estrategia*);
	virtual void setEstrategia(estrategia *e);
	virtual void interfazRespuesta();
};