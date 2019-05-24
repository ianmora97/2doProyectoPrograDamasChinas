#include "control.h"

int main() {
	color(15);
	srand(time(NULL));
	SetConsoleTitleA("Damas Chinas - Segundo Proyecto de Programacion 2");
	system("mode con: cols=110 lines=40");
	control* c = new control;
	c->options();
	return 0;
}