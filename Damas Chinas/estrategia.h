#pragma once
#include "tools.h"
#include "tablero.h"
class estrategia{
public:
	virtual void algoritmo(tablero*) = 0;
};

class defensa : public estrategia{
public:
	defensa();
	~defensa();
	virtual void algoritmo(tablero*);

private:

};

class ataque : public estrategia{
public:
	ataque();
	~ataque();
	virtual void algoritmo(tablero*);

private:

};

class aleatoria : public estrategia{
public:
	aleatoria();
	~aleatoria();
	virtual void algoritmo(tablero*);

};



class respuesta {
private:
	estrategia* _estrategia;
public:
	respuesta();
	respuesta(estrategia*);
	~respuesta();
	virtual void setEstrategia(estrategia *e);
	virtual void interfazRespuesta(tablero *_tablero);
};