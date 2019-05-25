#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include <fstream>

#define TAB '\t'
#define END '\n'
#define DAMA_X 'B'
#define DAMA_O 'N'
#define TRISTE 'O'
#define FELIZ 'X'

enum MyEnum{

};

using namespace std;

void gotoxy(int, int);
void color(int);
void pause();
void cls();
int checkInt(int, int);
void pauseCorner();