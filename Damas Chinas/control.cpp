#include "control.h"

control::control(){}
control::~control(){}
void control::printMenu() {
	system("cls");
	color(15);
	cout << endl << endl << endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } //imprime una linea de =
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	color(11);
	cout << "        Damas Chinas          ";
	color(15);
	cout << char(186) << endl;
	color(15);
	cout << "\t\t\t\t" << char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(188) << endl;

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

	tablero* _tablero = new tablero;
	
	jugador* p1;

	
	string nombre;


	while (menu) {
		printMenu();
		opc = checkInt(0,4);
		switch (opc){
		case 1:
			cls();

			cout << "Digite el nombre del Jugador 1 \n> ";
			getline(cin, nombre, END);
			p1 = new jugador(nombre);
			
			pauseCorner();
			while (juego) {
				if (contador_turnos % 2 == 0) {
					cls();
					_tablero->printTablero();
					cout << endl << endl;
					int fp = 0, cp = 0;
					int fm, cm;
					bool tu = true;
					int verif = 0;
					while (tu) {
						if (contador_turnos == 0) {
							fm = 6;
							cout << "Digite la columna de la ficha a mover > ";
							cm = checkInt(1, 8);
							tu = false;
						}
						else {
							cout << "Digite la fila de la ficha a mover > ";
							fm = checkInt(1, 8);
							cout << "Digite la columna de la ficha a mover > ";
							cm = checkInt(1, 8);
							if (_tablero->getFicha(fm - 1, cm - 1) == ' ') {
								verif = 1;
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm + 1) == ' ') {
								verif = 2;
								tu = false;
							}
							if(_tablero->getFicha(fm - 1, cm - 1) == ' ' && _tablero->getFicha(fm - 1, cm + 1) == ' '){
								verif = 3;
								tu = false;
							}
						}
					}
					if (_tablero->getFicha(fm,cm) == FELIZ) {
						int a;
						if ((cm != 1 && cm != 8) && verif == 3) {
							cout << "Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "[2] " << fm - 1 << ", " << cm + 1 << "  > ";
							a = checkInt(1, 2);
						}
						else if ((cm != 1 && cm != 8)) {
							if (verif == 2) {
								cout << "Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << "  > ";
								a = checkInt(2, 2);
							}
							else if (verif == 1) {
								cout << "Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
								a = checkInt(1, 1);
							}
							else {
								cout << "Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "[2] " << fm - 1 << ", " << cm + 1 << "  > ";
								a = checkInt(1, 2);
							}
						}
						else if((cm == 1 || cm == 8)){
							if (cm == 1 || verif == 2) {
								cout << "Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << "  > ";
								a = checkInt(2, 2);
							}
							if (cm == 1 && verif == 1) {
								cout << "Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
								a = checkInt(1, 1);
							}
							if(cm == 8 || verif == 1){
								cout << "Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
								a = checkInt(1, 1);
							}
							if (cm == 8 && verif == 2) {
								cout << "Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << "  > ";
								a = checkInt(2, 2);
							}
						}
						
						switch (a){
						case 1:
							fp = fm - 1;
							cp = cm - 1;
							break;
						default:
							fp = fm - 1;
							cp = cm + 1;
							break;
						}
					}
					else {
						
					
					}

					_tablero->agregar(FELIZ, fp, cp);
					_tablero->quitar(fm, cm);
					cls();
					_tablero->printTablero();
					pauseCorner();
				}
				else {
					//computadora
					if (contador_turnos == 1) {
						bool co = true;
						int cr;
						do {
							cr = 1 + rand() % 8;
							if ((cr % 2 != 0)) {
								co = false;
							}
						} while (co);
						int r;
						co = true;
						do {
							r = 1 + rand() % 8;
							if ((r % 2 == 0) && (r - 1 == cr || r + 1 == cr)) {
								co = false;
							}
						} while (co);
						color(10); gotoxy(1,20); cout << "\nAnalizando jugada ...\n";
						for (int i = 0; i < 3; i++) {
							Sleep(1000);
						}
						_tablero->agregar(TRISTE, 4, r);
						_tablero->quitar(3,cr);
						cls();
						_tablero->printTablero();
						pauseCorner();
					}
					else {

					}
				}
				contador_turnos++;
			}
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