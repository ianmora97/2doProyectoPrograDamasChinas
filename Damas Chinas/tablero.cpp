#include "tablero.h"

tablero::tablero(){
	tam = 8;
	cant = 0;
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			if (i < 3) {
				if ((i+j)%2 == 0) {
					fichas[i][j] = COMPU;
				}
				else {
					fichas[i][j] = ' ';
				}
			}
			else if (i > 4) {
				if ((i + j) % 2 == 0) {
					fichas[i][j] = PLAYER_1;
				}
				else {
					fichas[i][j] = ' ';
				}
			}
			else {
				fichas[i][j] = ' ';
			}
		}
	}
}

tablero::~tablero(){}

void tablero::printTablero(){
	cout << "\n";
	cout << "    ";
	for (int i = 1; i <= 8; i++) {
		color(13); cout << "  " << i << " ";
	}
	cout << "\n\n";
	for (int i = 0; i < tam; i++) {
		color(13); cout<<"  " << i + 1<<"  ";
		color(11);
		for (int j = 0; j < tam; j++) {
			if ((j+i)%2 == 0) {
				if (fichas[i][j] == COMPU) {
					color(252); cout << " " << fichas[i][j] << "  ";
				}
				else if (fichas[i][j] == PLAYER_1) {
					color(249); cout << " " << fichas[i][j] << "  ";
				}
				else {
					color(255); cout << " " << fichas[i][j] << "  ";
				}
			}
			else{
				color(1); cout << " " << fichas[i][j] << "  ";
			}
		}
		cout << endl;
		
		cout << endl;
	}
	color(15);
}
bool tablero::existe(int f, int c) { return ((f - 1 < 8 && f - 1 >= 0) && (c-1 < 8 && c-1 >= 0)); }
bool tablero::existeDerecha(int f, int c){
	return (getFicha(f - 1, c + 1) == ' ');
}
bool tablero::existeIzquierda(int f, int c){
	return (getFicha(f - 1, c - 1) == ' ');
}
bool tablero::existeComerDerecha(char ficha, int f, int c){
	return (getFicha(f - 1, c + 1) == ficha && getFicha(f - 2, c + 2) == ' ');
}
bool tablero::existeComerIzquierda(char ficha, int f, int c){
	return (getFicha(f - 1, c - 1) == ficha && getFicha(f - 2, c - 2) == ' ');
}

char tablero::getFicha(int f, int c){
	return fichas[f-1][c-1];
}
void tablero::agregar(char f, int fila, int columna) {
	if (existe(fila,columna)) {
		if (fichas[fila-1][columna-1] == ' ') {
			fichas[fila - 1][columna - 1] = f;
		}
	}
}
void tablero::quitar(int f,int c) {
	if (existe(f,c)) {
		if (fichas[f-1][c-1] != ' ') {
			fichas[f - 1][c - 1] = ' ';
		}
	}
}