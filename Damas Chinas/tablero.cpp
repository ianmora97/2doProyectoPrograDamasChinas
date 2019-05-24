#include "tablero.h"

tablero::tablero(){
	tam = 8;
	cant = 0;
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			fichas[i][j] = '0';
		}
	}
}
tablero::~tablero(){}

string tablero::printTablero(){
	stringstream s;
	s << "   ";
	for (int i = 1; i <= 8; i++) {
		s <<"  "<< i << " ";
	}	
	s << endl;
	for (int i = 0; i < tam; i++) {
		s << " " << i + 1 << " |";
		for (int j = 0; j < tam; j++) {
			s << " " << fichas[i][j] << " |";
		}
		s << endl<<endl;
	}
	return s.str();
}
void tablero::darValor() {

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {

			fichas[i][j];
		}
	}
}