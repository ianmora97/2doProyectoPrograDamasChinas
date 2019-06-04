#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <conio.h>

#define TAB '\t'
#define END '\n'
#define DAMA_X 'B'
#define DAMA_O 'N'
#define PIEZA_O 'O'
#define PIEZA_X 'X'

enum MyEnum {
	Arriba = 72,
	Abajo = 80,
	Izquierda =75,
	Derecha = 77
};

using namespace std;

void gotoxy(int, int);
void color(int);
void pause();
void cls();
int mueveFlechas();
int checkInt(int, int);
void pauseCorner();
void dibujaRectangulo(int x, int y, int l, int a, int c);