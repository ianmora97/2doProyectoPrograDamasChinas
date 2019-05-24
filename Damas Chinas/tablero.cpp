#include "tablero.h"

tablero::tablero(){
	tam = 8;
	cant = 0;
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			if (i < 3) {
				if ((i+j)%2 == 0) {
					fichas[i][j] = 'o';
				}
				else {
					fichas[i][j] = ' ';
				}
			}
			else if (i > 4) {
				if ((i + j) % 2 != 0) {
					fichas[i][j] = 'x';
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
				color(252); cout << " " << fichas[i][j] << "  ";
			}
			else{
				color(9); cout << " " << fichas[i][j] << "  ";
			}
		}
		cout << endl<<endl;
	}
	color(15);
}
void tablero::darValor() {

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {

			fichas[i][j];
		}
	}
}