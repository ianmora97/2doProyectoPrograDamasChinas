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
							fm = checkInt(1, 8);//filas 
							cout << "Digite la columna de la ficha a mover > ";
							cm = checkInt(1, 8);//columnas
							if (_tablero->getFicha(fm - 1, cm - 1) == ' ') {// que la de la izquierda este vacia
								verif = 1;									// para columnas 1 y 8
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm + 1) == ' ') {// que la de la derecha este vacia
								verif = 2;									// para columnas 1 y 8
								tu = false;
							}
							/**/if (_tablero->getFicha(fm - 1, cm - 1) == ' ' && _tablero->getFicha(fm - 1, cm + 1) == ' ') {
								verif = 3;									// que a los 2 laterales esten vacios
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ' && cm == 1) {
								verif = 6;									// que la de la derecha esté llena y se la pueda comer
								tu = false;									// para columnas 1 y 8
							}
							if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ' && cm == 8) {
								verif = 7;									// que la de la izquierda esté llena y se la pueda comer
								tu = false;										// para columnas 1 y 8
							}
							/**/if ((_tablero->getFicha(fm - 1, cm - 1) == ' ') && (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ')) {
								verif = 4;									// que la de la izquierda este vacia y se pueda comer a la de la derecha
								tu = false;
							}
							/**/if ((_tablero->getFicha(fm - 1, cm + 1) == ' ') && (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ')) {
								verif = 5;									// que la de la derecha este vacia y se pueda comer a la de la izquierda
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O'&&cm == 1) {
								verif = 8;									//cuando la de la derecha esté llena y  NO se la pueda comer
								tu = false;									// para columnas 1 y 8
							}
							if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O'&&cm == 8) {
								verif = 9;									//cuando la de la ziqeuierda esté llena y  NO se la pueda comer
								tu = false;									// para columnas 1 y 8
							}
							if ((_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O') && (_tablero->getFicha(fm - 1, cm - 1) == 'O') && cm == 2) {
								verif = 11;// si esta atrapada entre una negra y el borde izquierdo del tablero y un bloqueo doble a la derecha
								tu = false;// usar solo cuando i-1==1
							}
							if ((_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O') && (_tablero->getFicha(fm - 1, cm + 1) == 'O') && cm == 7) {
								verif = 12;// si esta atrapada entre una negra y el borde derecho del tablero y un bloqueo doble a la izquierda
								tu = false;// usar solo cuando i+1==8
							}

							if (_tablero->getFicha(fm - 1, cm - 1) == ' ' && (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O') && cm == 2) {
								verif = 13;// que la de la izquierda este vacia  y tenga un bloqueo doble a la derecha
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm + 1) == ' ' && (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O') && cm == 7) {
								verif = 14;// que la de la derecha este vacia  y tenga un bloqueo doble a la izquierda
								tu = false;

							}
							if ((_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O') && (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ') && cm < 8) {
								verif = 15; //que a la izquierda tenga un bloqueo doble y que a la derecha  tenga una ficha y se la pueda comer
								tu = false;
							}
							if ((_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O') && (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ') && cm > 1) {
								verif = 16; //que a la derecha tenga un bloqueo doble y que a la izquierda  tenga una ficha y se la pueda comer
								tu = false;
							}

							if ((_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O') && (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O')) {
								verif = 10;//que tenga un bloqueo doble a ambos lados
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm + 1) == 'O'&& _tablero->getFicha(fm - 1, cm - 1) == 'O'&& _tablero->getFicha(fm - 2, cm - 2) == ' ' && cm == 7) {
								verif = 17;
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 1, cm - 1) == ' ' && cm == 7) {
								verif = 18;
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 1, cm + 1) == ' ' && cm == 2) {
								verif = 19;
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ' && _tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ') {
								verif = 20;
								tu = false;
							}
							if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ' && cm == 2) {
								verif = 21;
								tu = false;
							}
						}
					}

					if (_tablero->getFicha(fm, cm) == FELIZ) {
						int a = NULL;
						if ((cm != 1 && cm != 8) && _tablero->getFicha(fm - 1, cm - 1) == ' ' && _tablero->getFicha(fm - 1, cm + 1) == ' '&&contador_turnos == 0) {
							cout << "3.1 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "[2] " << fm - 1 << ", " << cm + 1 << "  > ";
							a = checkInt(1, 2);
						}
						else if (cm == 2 && verif == 11) {//////
							cout << "11 [5]  >Esta ficha no se puede mover\n";
							a = checkInt(5, 5);
							cout << endl;

						}
						else if (cm == 7 && verif == 12) {/////
							cout << "12 [5]  >Esta ficha no se puede mover\n";
							a = checkInt(5, 5);
							cout << endl;

						}
						/*else if ((cm != 1 && cm != 8) && verif == 5) {
						cout << "12 [5]  >Esta ficha no se puede mover\n";
						a = checkInt(5, 5);
						cout << endl;

						}*/

						else if ((cm != 1 && cm != 8)) {
							if (verif == 3) {
								cout << "3 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "[2] " << fm - 1 << ", " << cm + 1 << "  > ";
								a = checkInt(1, 2);
							}
							////////
							//else {    //PORQUE ESTE SE REPITE?
							//	cout << "? Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "[2] " << fm - 1 << ", " << cm + 1 << "  > ";
							//	a = checkInt(1, 2);// EN LA OPCION 1 EN VEZ DE -1 Y -1 ERA -2 Y -2
							//}
							else if (verif == 5) {// CUANDO HAY UNO VACIO Y SE PUEDE COMER EL DEL OTRO LADO
								cout << "5 Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << TAB << "[3] " << fm - 2 << ", " << cm - 2 << "  > ";
								a = checkInt(2, 3);
							}
							else if (verif == 4) {// CUANDO HAY UNO VACIO Y SE PUEDE COMER EL DEL OTRO LADO
								cout << "4 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << TAB << "[4] " << fm - 2 << ", " << cm + 2 << "  > ";
								a = checkInt(1, 4);
							}
							else if (verif == 10) {
								cout << "10 [5] > No se se puede mover esta ficha, se encuentra atrapada" << endl;
								cout << endl;
								a = checkInt(5, 5);
							}
							else if (verif == 13) {
								cout << "13 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
								a = checkInt(1, 1);
							}
							else if (verif == 14) {
								cout << "14 Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << TAB << "  > ";
								a = checkInt(2, 2);
							}
							else if (verif == 15) {
								cout << "15 Moverla hacia:\n[4] " << fm - 2 << ", " << cm + 2 << TAB << "  > ";
								a = checkInt(4, 4);
							}
							else if (verif == 16) {
								cout << "16 Moverla hacia:\n[3] " << fm - 2 << ", " << cm - 2 << TAB << "  > ";
								a = checkInt(3, 3);
							}
							else if (verif == 17) {
								cout << "Moverla hacia:\n[3] " << fm - 2 << ", " << cm - 2 << TAB << "  > ";
								a = checkInt(3, 3);
							}
							else if (verif == 18) {
								cout << "Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
								a = checkInt(1, 1);

							}
							else if (verif == 19) {
								cout << "Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << TAB << "  > ";
								a = checkInt(2, 2);
							}
							else if (verif == 20) {
								cout << "Moverla hacia:\n[3] " << fm - 2 << ", " << cm - 2 << TAB << "[4] " << fm - 2 << ", " << cm + 2 << "  > ";
								a = checkInt(3, 4);

							}
						}

						else if ((cm == 1 || cm == 8)) {
							if (cm == 1 && verif == 2) {//ahi en vez de un && es ||
								cout << "2 || Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << "  > ";
								a = checkInt(2, 2);
							}
							else

								if (cm == 8 && verif == 1) {//ahi en vez de un && es ||
									cout << "1 || Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
									a = checkInt(1, 1);
								}
								else
									if (cm == 1 || verif == 6) {
										cout << "6 || Moverla hacia:\n[4] " << fm - 2 << ", " << cm + 2 << "  > ";
										a = checkInt(4, 4);
									}
									else
										if (cm == 8 || verif == 7) {
											cout << "7 || Moverla hacia:\n[3] " << fm - 2 << ", " << cm - 2 << TAB << "  > ";
											a = checkInt(3, 3);
										}
										else
											if (cm == 1 || verif == 8) {
												cout << "8 ||[5]> ¡Esta ficha esta atrapada!\n ";
												a = checkInt(5, 5);
											}
											else
												if (cm == 8 || verif == 9) {
													cout << "9 ||[1] ¡Esta ficha esta atrapada!\n ";
													a = checkInt(5, 5);
												}


						}
						switch (a) {
						case 1:
							fp = fm - 1;
							cp = cm - 1;

							_tablero->agregar(FELIZ, fp, cp);
							_tablero->quitar(fm, cm);
							cls();
							_tablero->printTablero();
							pauseCorner();
							break;
						case 2:
							fp = fm - 1;
							cp = cm + 1;

							_tablero->agregar(FELIZ, fp, cp);
							_tablero->quitar(fm, cm);
							cls();
							_tablero->printTablero();
							pauseCorner();
							break;
						case 3:
							fp = fm - 2;
							cp = cm - 2;

							_tablero->agregar(FELIZ, fp, cp);
							_tablero->quitar(fm, cm);
							_tablero->quitar(fm - 1, cm - 1);
							cls();
							_tablero->printTablero();
							pauseCorner();
							break;
						case 4:
							fp = fm - 2;
							cp = cm + 2;

							_tablero->agregar(FELIZ, fp, cp);
							_tablero->quitar(fm, cm);
							_tablero->quitar(fm - 1, cm + 1);
							cls();
							_tablero->printTablero();
							pauseCorner();
						default: {}
								 fp = fm;
								 cp = cm;

								 _tablero->agregar(FELIZ, fp, cp);
								 //_tablero->quitar(fm, cm);
								 cls();
								 _tablero->printTablero();
								 pauseCorner();
						}
					}
					else {


					}

					/*_tablero->agregar(FELIZ, fp, cp);
					_tablero->quitar(fm, cm);
					cls();
					_tablero->printTablero();
					pauseCorner();*/
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