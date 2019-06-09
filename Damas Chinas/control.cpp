#include "control.h"

control::control() : game(new Juego) {}
control::~control() {}
void control::printMenu() {
	system("cls");
	cout << "\n\n\n\n\n\n";

	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186) << endl;

	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [1]";
	color(15);
	cout << "   Jugar\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [2]";
	color(15);
	cout << "   Instrucciones\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [3]";
	color(15);
	cout << "   Cargar Partida\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [4]";
	color(15);
	cout << "   HighScores\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [0]";
	color(15);
	cout << "   Salir del programa\n";
	cout << "\t\t\t";
	cout << char(186);

	cout << "\n\t\t\t" << char(204);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(185) << endl;
	cout << "\t\t\t" << char(186) << endl;
	cout << "\t\t\t" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "\n\t\t\t" << char(200);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(188) << endl;
	for (int i = 0; i < 11; i++) {
		gotoxy(71, 7 + i); cout << char(186);
	}
	gotoxy(71, 19); cout << char(186);
	gotoxy(71, 20); cout << char(186);
	gotoxy(71, 21); cout << char(186);
	cout << endl << endl << endl << endl;
}

void control::options() {
	bool menu = true;
	int opc;
	int contador_turnos = 0;
	bool juego = true;


	while (menu) {
		printMenu();
		fstream archivo;
		color(15); opc = mueveFlechas();
		switch (opc) {
		case 1:
			cls();
			game->pideNombre();
			archivo.open("contadorTurnos.txt", ios::out);
			archivo << "0";
			archivo.close();
			pauseCorner();
			cls();
			game->seleccionarEstrategia();
			pauseCorner();
			cls();
			game->jugar();
			cls();
			break;
		case 2:
			cls();
			cout << "\t********************MODO DE JUEGO NORMAL********************** " << endl;
			cout << "\n";
			cout << "INSTRUCCIONES PARA JUGAR A DAMAS - LA PARTIDA COMENZARA CON LAS FICHAS 'X'" << endl;
			cout << "PARA HACER UN MOVIMIENTO DEBE SELECCIONAR PRIMERO LA COORDENADA VERTICAL, Y " << endl;
			cout << "DESPUES LA COORDENADA HORIZONTAL, CASO DE NO HABER FICHA SE TE VOLVERA A PEDIR" << endl;
			cout << "QUE VUELVAS A TIRAR PARA SELECCIONAR EL MOVIMIENTO DE LA FICHA PERSIONA [1]" << endl;
			cout << "PARA MOVERLA DIAGONALMENTE IZQUIERDA O [2] PARA DIAGONAL DERECHA" << endl;
			cout << "EL JUEGO TERMINA CUANDO YA NO HAIGA FICHAS CONTRARIAS QUE COMER." << endl;
			cout << "\n";

			cout << "\t********************MODO VS COMPUTADORA ******************** " << endl;
			cout << "\n";
			cout << "SI NO TIENES CON QUIEN JUGAR EN ESTE MODO PODRAS SIMULAR UN JUEGO " << endl;
			cout << "CONTRA LA COMPUTADORA PARA PRACTICAR TUS JUGADAS " << endl;
			pauseCorner();
			cls();
			break;
		case 3:
			cls();
			if (game->cargarPartida()) {
				gotoxy(45, 15); color(10); cout << "Cargando partida... " << endl;

				Sleep(2000);
				cls();
				game->jugar();
			}
			cls();
			break;
		case 4:
			cls();

			cls();
			break;
		default:
			menu = false;
			break;
		}
	}
	cls();
}