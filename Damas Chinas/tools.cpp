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
	color(12); gotoxy(90, 38); cout << "Continuar..."; getchar();
}
