#pragma once
#include "tools.h"
#include "tablero.h"
class estrategia{
public:
	virtual void algoritmo(tablero*) = 0;
	virtual string getEstrategia() const = 0;
protected:
	string tipo;
};

class defensa : public estrategia{
public:
	defensa();
	~defensa();
	virtual void algoritmo(tablero*);
	virtual string getEstrategia() const;
};

class ataque : public estrategia{
public:
	ataque();
	~ataque();
	virtual void algoritmo(tablero*);
	virtual string getEstrategia() const;
};

class aleatoria : public estrategia{
public:
	aleatoria();
	~aleatoria();
	virtual void algoritmo(tablero*);
	virtual string getEstrategia() const;
};

class selectivo : public estrategia {
public:
	selectivo();
	~selectivo();
	virtual void algoritmo(tablero*);
	virtual string getEstrategia() const;
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
	virtual string toString();
};