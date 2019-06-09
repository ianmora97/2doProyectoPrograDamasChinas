#include "tools.h"
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void color(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
void pause() { system("pause"); }
void cls() { system("cls"); }


int mueveFlechas() {
	char flecha = ' ';
	bool salir = true;
	int cont = 1;

	while (salir) {
		switch (cont){
		case 1:

			gotoxy(27,8); color(253); cout << "> [1]"; color(240); cout << "   Jugar\n";

			gotoxy(27,10); color(13);  cout << "  [2]"; color(15);  cout << "   Instrucciones\n";

			gotoxy(27,12); color(13);  cout << "  [3]"; color(15);  cout << "   Cargar Partida\n";
			
			gotoxy(27,14); color(13);  cout << "  [4]"; color(15);  cout << "   HighScores\n";
		
			gotoxy(27,16); color(13);  cout << "  [0]"; color(15);  cout << "   Salir del programa\n";

			gotoxy(28, 20); color(13); cout << "Opcion : "; color(15); cout <<"[" << cont << "] Jugar            ";

			break;
		case 2:

			gotoxy(27, 8); color(13); cout << "  [1]"; color(15); cout << "   Jugar\n";

			gotoxy(27, 10); color(253);  cout << "> [2]"; color(240);  cout << "   Instrucciones\n";

			gotoxy(27, 12); color(13);  cout << "  [3]"; color(15);  cout << "   Cargar Partida\n";

			gotoxy(27, 14); color(13);  cout << "  [4]"; color(15);  cout << "   HighScores\n";

			gotoxy(27, 16); color(13);  cout << "  [0]"; color(15);  cout << "   Salir del programa\n";

			gotoxy(28, 20); color(13); cout << "Opcion : "; color(15); cout << "[" << cont << "] Instrucciones          ";

			break;
		case 3:

			gotoxy(27, 8); color(13); cout << "  [1]"; color(15); cout << "   Jugar\n";

			gotoxy(27, 10); color(13);  cout << "  [2]"; color(15);  cout << "   Instrucciones\n";

			gotoxy(27, 12); color(253);  cout << "> [3]"; color(240);  cout << "   Cargar Partida\n";

			gotoxy(27, 14); color(13);  cout << "  [4]"; color(15);  cout << "   HighScores\n";

			gotoxy(27, 16); color(13);  cout << "  [0]"; color(15);  cout << "   Salir del programa\n";

			gotoxy(28, 20); color(13); cout << "Opcion : "; color(15); cout << "[" << cont << "] Cargar Partida       ";

			break;
		case 4:

			gotoxy(27, 8); color(13); cout << "  [1]"; color(15); cout << "   Jugar\n";

			gotoxy(27, 10); color(13);  cout << "  [2]"; color(15);  cout << "   Instrucciones\n";

			gotoxy(27, 12); color(13);  cout << "  [3]"; color(15);  cout << "   Cargar Partida\n";

			gotoxy(27, 14); color(253);  cout << "> [4]"; color(240);  cout << "   HighScores\n";

			gotoxy(27, 16); color(13);  cout << "  [0]"; color(15);  cout << "   Salir del programa\n";

			gotoxy(28, 20); color(13); cout << "Opcion : "; color(15); cout << "[" << cont << "] Highscores          ";

			break;
		case 5:

			gotoxy(27, 8); color(13); cout << "  [1]"; color(15); cout << "   Jugar\n";

			gotoxy(27, 10); color(13);  cout << "  [2]"; color(15);  cout << "   Instrucciones\n";

			gotoxy(27, 12); color(13);  cout << "  [3]"; color(15);  cout << "   Cargar Partida\n";

			gotoxy(27, 14); color(13);  cout << "  [4]"; color(15);  cout << "   HighScores\n";

			gotoxy(27, 16); color(253);  cout << "> [0]"; color(240);  cout << "   Salir del programa\n";

			gotoxy(28, 20); color(13); cout << "Opcion : "; color(15); cout << "[0] Salir               ";


			break;
		default:
			break;
		}

		flecha = _getch();
		switch (flecha){
		case Arriba:
			if (cont == 1 ) {
				cont = 5;
			}
			else{
				cont--;
			}
			break;
		case Abajo:
			if (cont == 5) {
				cont = 1;
			}
			else{
				cont++;
			}
			break;
		case 13:
			salir = false;
			break;
		default:
			break;
		}
	}
	if (cont == 5) {
		cont = 0;
	}
	return cont;
}

int checkInt(int min, int max) {
	int opc = 0;
	bool ban = true;
	while (ban) {
		if (!(cin>>opc)) {
			cin.clear();
			cin.ignore();
		}
		else {
			if (opc >= min && opc <= max) {
				cin.clear();
				cin.ignore();
				ban = false;
			}
			else {
				cin.clear();
				cin.ignore();
			}
		}
	}
	return opc;
}

void pauseCorner() {
	color(12); gotoxy(90, 38); cout << "Continuar..."; getchar(); color(15);
}
void dibujaRectangulo(int x, int y, int l, int a, int c) { //x de donde comienza, y donde termina || l de donde comienza , a de donde termina / c = color
	color(c);
	for (int i = x; i < y; i++) { //el ancho
		gotoxy(i, l); cout << char(205);
		gotoxy(i, a); cout << char(205);
	}
	for (int i = l; i < a; i++) { //el alto
		gotoxy(x, i); cout << char(186);
		gotoxy(y, i); cout << char(186);
	}
	gotoxy(x, l); cout << char(201); //esquina superior izquierda

	gotoxy(y, l); cout << char(187); //esquina superior derecha

	gotoxy(x, a); cout << char(200); //esquina inferior izquierda

	gotoxy(y, a); cout << char(188); //esquina inferior derecha
	color(15);
}
char stringXchar(string line) {
	stringstream s;
	char c;
	s << line;
	s >> c;
	return c;
}
int stringXint(string line) {
	stringstream s;
	int c;
	s << line;
	s >> c;
	return c;
}