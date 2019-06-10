#include "Juego.h"

Juego::Juego() {
	_tablero = new tablero;
	p1 = NULL;
	_estrategia = new respuesta;
	_defensa = new defensa;
	_ataque = new ataque;
	_aleatoria = new aleatoria;
	_selectivo = new selectivo;
	
}
Juego::~Juego(){}
int Juego::imprimeOpcionJuego() {
	dibujaRectangulo(50,75,5,18,15);
	gotoxy(55, 6); cout << "MENU DE JUEGO";
	gotoxy(52, 8);  cout << "[1] Jugar";
	gotoxy(52, 10); cout << "[2] Terminar y salir";
	gotoxy(52, 12); cout << "[3] Terminar y guardar";
	gotoxy(52, 14); cout << "[4] Reiniciar partida";
	int opc;
	gotoxy(54, 16); opc = checkInt(1, 4);
	return opc;
}
void Juego::seleccionarEstrategia() {
	
	gotoxy(25, 6); cout << "Seleccione la estrategia de la Computadora" << endl;
	gotoxy(30, 8); cout << "[1] Aleatoria";
	gotoxy(30, 9); cout << "[2] Defensivo";
	gotoxy(30, 10);cout << "[3] Ataque";
	gotoxy(30, 11); cout << "[4] Selectivo";
	gotoxy(30, 13); int opc; cout << "> ";	opc = checkInt(1, 4);
	switch (opc){
	case 1:
		_estrategia->setEstrategia(_aleatoria);
		break;
	case 2:
		_estrategia->setEstrategia(_defensa);
		break;
	case 3:
		_estrategia->setEstrategia(_ataque);
		break;
	case 4:
		_estrategia->setEstrategia(_selectivo);
		break;
	default:
		break;
	}
	
}
void Juego::jugar(){
	string datoContador;
	int contador_turnos = 0;
	ifstream archivo;
	archivo.open("save/contadorTurnos.txt", ios::in);
	if (archivo.is_open()) {
		while (!(archivo.eof())) {
			getline(archivo, datoContador);
			contador_turnos = stringXint(datoContador);
		}
	}
	archivo.close();
	bool juego = true;
	while (juego) {
		if (contador_turnos % 2 == 0) {
			cls();
			
			gotoxy(50, 3); color(15); cout << "Turno de " << p1->getNombre();
			_tablero->printTablero();
			int opcJuego = imprimeOpcionJuego();
			int fp = 0, cp = 0;
			int fm, cm;
			bool tu = true;
			int verif = 0;
			int verificaOtraMovida = false;
			fstream archivo;
			switch (opcJuego) {
			case 1:
				gotoxy(1, 21);
				cout << endl << endl;
				
				do {
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
							verif = verificaJugada(fm, cm);
							if (verif != 0) {
								tu = false;
							}

						}
					}
					bool inserto = false;
					if (_tablero->getFicha(fm, cm) == PIEZA_X) {
						int a = NULL;
						if ((cm != 1 && cm != 8) && _tablero->getFicha(fm - 1, cm - 1) == ' ' && _tablero->getFicha(fm - 1, cm + 1) == ' ' && contador_turnos == 0) {
							cout << "3.1 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "[2] " << fm - 1 << ", " << cm + 1 << "  > ";
							a = checkInt(1, 2);
						}
						else if ((cm > 1 && cm < 8)) {
							if (verif == 3) {
								cout << "3 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "[2] " << fm - 1 << ", " << cm + 1 << "  > ";
								a = checkInt(1, 2);
							}
							else if (verif == 4) {// CUANDO HAY UNO VACIO Y SE PUEDE COMER EL DEL OTRO LADO
								cout << "4 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << TAB << "[4] " << fm - 2 << ", " << cm + 2 << "  > ";
								a = checkInt(1, 4);
							}
							else if (verif == 5) {// CUANDO HAY UNO VACIO Y SE PUEDE COMER EL DEL OTRO LADO
								cout << "5 Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << TAB << "[3] " << fm - 2 << ", " << cm - 2 << "  > ";
								a = checkInt(2, 3);
							}
							else if (verif == 10) {
								cout << "10 [5] > No se se puede mover esta ficha, se encuentra atrapada" << endl;
								a = checkInt(5, 5);
							}
							else if (verif == 11) {
								cout << "11 [5] > Esta ficha esta atrapada, no se puede mover" << endl;
								a = checkInt(5, 5);
							}
							else if (verif == 12) {
								cout << "12 [5] > Esta ficha esta atrapada, no se puede mover" << endl;
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
								cout << "17 Moverla hacia:\n[3] " << fm - 2 << ", " << cm - 2 << TAB << "  > ";
								a = checkInt(3, 3);
							}
							else if (verif == 18) {
								cout << "18 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
								a = checkInt(1, 1);
							}
							else if (verif == 19) {
								cout << "19 Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << TAB << "  > ";
								a = checkInt(2, 2);
							}
							else if (verif == 20) {
								cout << "20 Moverla hacia:\n[3] " << fm - 2 << ", " << cm - 2 << TAB << "[4] " << fm - 2 << ", " << cm + 2 << "  > ";
								a = checkInt(3, 4);
							}
							else if (verif == 21) {
								cout << "21 Moverla hacia:\n[4] " << fm - 2 << ", " << cm + 2 << TAB << "[4] " << "  > ";
								a = checkInt(3, 4);
							}
							else if (verif == 22) {
								cout << "22 No se se puede mover esta ficha, se encuentra atrapada \n[5]" << TAB << "  > ";
								a = checkInt(5, 5);
							}
							else if (verif == 23) {
								cout << "23 Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
								a = checkInt(1, 1);
							}
							else if (verif == 24) {
								cout << "24  Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << TAB << "  > ";
								a = checkInt(2, 2);
							}
						}
						else if ((cm == 1 || cm == 8)) {
							if (verif == 6) {
								cout << "6 || Moverla hacia:\n[4] " << fm - 2 << ", " << cm + 2 << "  > ";
								a = checkInt(4, 4);
							}
							else if (verif == 7) {
								cout << "7 || Moverla hacia:\n[3] " << fm - 2 << ", " << cm - 2 << TAB << "  > ";
								a = checkInt(3, 3);
							}
							else if (verif == 8) {
								cout << "8 ||[5]> �Esta ficha esta atrapada!\n ";
								a = checkInt(5, 5);
							}
							else if (verif == 9) {
								cout << "9 ||[1] �Esta ficha esta atrapada!\n ";
								a = checkInt(5, 5);
							}
							else if (verif == 25) {
								cout << "25 ||[5] �Esta ficha esta atrapada!\n ";
								a = checkInt(5, 5);
							}
							else if (verif == 26) {
								cout << "26 ||[5] �Esta ficha esta atrapada!\n ";
								a = checkInt(5, 5);
							}
							else if (verif == 1 || cm == 8) {//ahi en vez de un && es ||
								cout << "1 || Moverla hacia:\n[1] " << fm - 1 << ", " << cm - 1 << TAB << "  > ";
								a = checkInt(1, 1);
							}
							else if (verif == 2 || cm == 1) {//ahi en vez de un && es ||
								cout << "2 || Moverla hacia:\n[2] " << fm - 1 << ", " << cm + 1 << TAB << "  > ";
								a = checkInt(2, 2);
							}

						}

						switch (a) {
						case 1:
							fp = fm - 1;
							cp = cm - 1;
							if (cp == 0) {
								_tablero->agregar(DAMA_X, fp, cp);
								inserto = true;
							}
							else {
								_tablero->agregar(PIEZA_X, fp, cp);
								_tablero->quitar(fm, cm);
								cls();
								gotoxy(50, 3); color(15); cout << "Turno de " << p1->getNombre();
								_tablero->printTablero();
								pauseCorner();
								inserto = true;
							}
							break;
						case 2:
							fp = fm - 1;
							cp = cm + 1;
							if (cp == 0) {
								_tablero->agregar(DAMA_X, fp, cp);
								inserto = true;
							}
							else {
								_tablero->agregar(PIEZA_X, fp, cp);
								_tablero->quitar(fm, cm);
								cls();
								gotoxy(50, 3); color(15); cout << "Turno de " << p1->getNombre();
								_tablero->printTablero();
								pauseCorner();
								inserto = true;
							}
							break;
						case 3:
							fp = fm - 2;
							cp = cm - 2;
							if (cp == 0) {
								_tablero->agregar(DAMA_X, fp, cp);
								inserto = true;
							}
							else {
								_tablero->agregar(PIEZA_X, fp, cp);
								_tablero->quitar(fm, cm);
								_tablero->quitar(fm - 1, cm - 1);
								cls();
								gotoxy(50, 3); color(15); cout << "Turno de " << p1->getNombre();
								_tablero->printTablero();
								pauseCorner();
								inserto = true;
							}
							break;
						case 4:
							fp = fm - 2;
							cp = cm + 2;
							if (cp == 0) {
								_tablero->agregar(DAMA_X, fp, cp);
								inserto = true;
							}
							else {
								_tablero->agregar(PIEZA_X, fp, cp);
								_tablero->quitar(fm, cm);
								_tablero->quitar(fm - 1, cm + 1);
								cls();
								gotoxy(50, 3); color(15); cout << "Turno de " << p1->getNombre();
								_tablero->printTablero();
								pauseCorner();
								inserto = true;
							}
							break;
						default:
							//fp = fm;
							//cp = cm;

							//_tablero->agregar(PIEZA_X, fp, cp);
							////_tablero->quitar(fm, cm);
							//cls();
							//gotoxy(50, 3); color(15); cout << "Turno de " << p1->getNombre();
							//_tablero->printTablero();
							//pauseCorner();
							//inserto = true;
							break;
						}
					}
					else if (_tablero->getFicha(fm, cm) == DAMA_X) { //SI ES REINA


					}
					if (verificaDobleJugada(fp, cp) && inserto) {
						verificaOtraMovida = true;
					}

				} while (verificaOtraMovida);
				break;
				case 2:
					archivo.open("save/contadorTurnos.txt", ios::out);
					archivo << "0";
					archivo.close();
					juego = false;
					break;

				case 3:
					archivo.open("save/partidaGuardada.txt", ios::in);
					if (archivo.good()) {
						gotoxy(0,22);
						cout << "Ya existe una partida guardada!"<<endl;
						cout << "Desea continuar jugando? (1)Si - (0)No";
						int continuar = checkInt(0,1);
						if (continuar == 0) {
							juego = false;
						}
					}
					else {
						guardaPartida();
						contador_turnos++;
						
						archivo.open("save/contadorTurnos.txt", ios::out);
						archivo << contador_turnos;
						archivo.close();
						juego = false;
					}
					archivo.close();
					break;
				case 4:
					gotoxy(0, 22);
					cout << "Reiniciando Partida...";
					Sleep(800);
					contador_turnos = -1;
					_tablero->reiniciar();
					break;
				default: break;
			}
		}
		else {
			if (juego != false) {
				_estrategia->interfazRespuesta(_tablero);
			}
		}
		contador_turnos++;
	}
}
void Juego::pideNombre(){
	string nombre;
	gotoxy(30, 14); cout << "Digite el nombre del Jugador";
	gotoxy(25, 16); color(15); cout << "> "; color(15); getline(cin, nombre, END);
	p1 = new jugador(nombre);
}

int Juego::verificaJugada(int fm, int cm){
	int verif = 0;
	if (_tablero->getFicha(fm - 1, cm - 1) == ' ' && cm == 8) {// que la de la izquierda este vacia
		verif = 1;		
	}
	if (_tablero->getFicha(fm - 1, cm + 1) == ' ' && cm == 1) {// que la de la derecha este vacia
		verif = 2;		
	}
	if (_tablero->getFicha(fm - 1, cm - 1) == ' ' && _tablero->getFicha(fm - 1, cm + 1) == ' ' && cm >= 2 && cm <= 7) {
		verif = 3;		
	}
	if ((_tablero->getFicha(fm - 1, cm - 1) == ' ') && (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ') && cm >= 2 && cm <= 6) {
		verif = 4;		
	}
	if ((_tablero->getFicha(fm - 1, cm + 1) == ' ') && (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ') && cm >= 3 && cm <= 7) {
		verif = 5;	
	}
	if (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ' && cm == 1) {
		verif = 6;									// para columnas 1 y 8
	}
	if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ' && cm == 8) {
		verif = 7;										// para columnas 1 y 8
	}
	if (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O' && cm == 1) {
		verif = 8;									// para columnas 1 y 8
	}
	if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O' && cm == 8) {
		verif = 9;								// para columnas 1 y 8
	}
	if ((_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O') && (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O') && cm >= 3 && cm <= 6) {
		verif = 10;
	}
	if ((_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O') && (_tablero->getFicha(fm - 1, cm - 1) == 'O') && cm == 2) {
		verif = 11;// usar solo cuando i-1==1
	}
	if ((_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O') && (_tablero->getFicha(fm - 1, cm + 1) == 'O') && cm == 7) {
		verif = 12;// usar solo cuando i+1==8
	}

	if (_tablero->getFicha(fm - 1, cm - 1) == ' ' && (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O') && cm >= 2 && cm <= 6) {
		verif = 13;// que la de la izquierda este vacia  y tenga un bloqueo doble a la derecha
	}
	if (_tablero->getFicha(fm - 1, cm + 1) == ' ' && (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O') && cm <= 7 && cm >= 3) {
		verif = 14;// que la de la derecha este vacia  y tenga un bloqueo doble a la izquierda

	}
	if ((_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == 'O') && (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ') && cm >= 3 && cm <= 6) {
		verif = 15; //que a la izquierda tenga un bloqueo doble y que a la derecha  tenga una ficha y se la pueda comer
	}
	if ((_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == 'O') && (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ') && cm >= 3 && cm <= 6) {
		verif = 16; //que a la derecha tenga un bloqueo doble y que a la izquierda  tenga una ficha y se la pueda comer
	}
	if (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ' && cm == 7) {
		verif = 17;
	}
	if (_tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 1, cm - 1) == ' ' && cm == 7) {
		verif = 18;
	}
	if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 1, cm + 1) == ' ' && cm == 2) {
		verif = 19;
	}
	if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 2, cm - 2) == ' ' && _tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ' && cm >= 3 && cm <= 6) {
		verif = 20;
	}
	if (_tablero->getFicha(fm - 1, cm - 1) == 'O' && _tablero->getFicha(fm - 1, cm + 1) == 'O' && _tablero->getFicha(fm - 2, cm + 2) == ' ' && cm == 2) {
		verif = 21;
	}
	if (_tablero->getFicha(fm - 1, cm - 1) == 'X' && _tablero->getFicha(fm - 1, cm + 1) == 'X' && cm >= 2 && cm <= 7) {
		verif = 22; /// nuevos sabado 1 de junio
	}
	if ((_tablero->getFicha(fm - 1, cm - 1) == ' ') && (_tablero->getFicha(fm - 1, cm + 1) == 'X') && cm >= 2 && cm <= 7) {
		verif = 23; /// nuevos sabado 1 de junio
	}
	if ((_tablero->getFicha(fm - 1, cm - 1) == 'X') && (_tablero->getFicha(fm - 1, cm + 1) == ' ') && cm >= 2 && cm <= 7) {
		verif = 24; /// nuevos sabado 1 de junio
	}
	if (_tablero->getFicha(fm - 1, cm + 1) == 'X' && cm == 1) {
		verif = 25; /// nuevos sabado 1 de junio
	}
	if (_tablero->getFicha(fm - 1, cm - 1) == 'X' && cm == 8) {
		verif = 26; /// nuevos sabado 1 de junio
	}
	return verif;
}

bool Juego::verificaDobleJugada(int fp, int cp){
	int verificar2 = 0;
	{ //bloque de codigo que vuelve a verificar si puede mover otra vez

		if ((_tablero->getFicha(fp - 1, cp - 1) == ' ') && (_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == ' ') && cp >= 2 && cp <= 6) {
			verificar2 = 1;									// que la de la izquierda este vacia y se pueda comer a la de la derecha

		}
		if ((_tablero->getFicha(fp - 1, cp + 1) == ' ') && (_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == ' ') && cp >= 3 && cp <= 7) {
			verificar2 = 1;									// que la de la derecha este vacia y se pueda comer a la de la izquierda

		}
		if (_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == ' ' && cp == 1) {
			verificar2 = 1;									// que la de la derecha est� llena y se la pueda comer
												// para columnas 1 y 8
		}
		if (_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == ' ' && cp == 8) {
			verificar2 = 1;									// que la de la izquierda est� llena y se la pueda comer
													// para columnas 1 y 8
		}
		if (_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == 'O' && cp == 1) {
			verificar2 = 1;									//cuando la de la derecha est� llena y  NO se la pueda comer
											// para columnas 1 y 8
		}
		if (_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == 'O' && cp == 8) {
			verificar2 = 1;									//cuando la de la ziqeuierda est� llena y  NO se la pueda comer
											// para columnas 1 y 8
		}
		if ((_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == 'O') && (_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == 'O') && cp >= 3 && cp <= 6) {
			verificar2 = 1;//que tenga un bloqueo doble a ambos lados

		}
		if ((_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == 'O') && (_tablero->getFicha(fp - 1, cp - 1) == 'O') && cp == 2) {
			verificar2 = 1;// si esta atrapada entre una negra y el borde izquierdo del tablero y un bloqueo doble a la derecha
						// usar solo cuando i-1==1
		}
		if ((_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == 'O') && (_tablero->getFicha(fp - 1, cp + 1) == 'O') && cp == 7) {
			verificar2 = 1;// si esta atrapada entre una negra y el borde derecho del tablero y un bloqueo doble a la izquierda
				// usar solo cuando i+1==8
		}

		if (_tablero->getFicha(fp - 1, cp - 1) == ' ' && (_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == 'O') && cp >= 2 && cp <= 6) {
			verificar2 = 1;// que la de la izquierda este vacia  y tenga un bloqueo doble a la derecha

		}
		if (_tablero->getFicha(fp - 1, cp + 1) == ' ' && (_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == 'O') && cp <= 7 && cp >= 3) {
			verificar2 = 1;// que la de la derecha este vacia  y tenga un bloqueo doble a la izquierda


		}
		if ((_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == 'O') && (_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == ' ') && cp >= 3 && cp <= 6) {
			verificar2 = 1; //que a la izquierda tenga un bloqueo doble y que a la derecha  tenga una ficha y se la pueda comer

		}
		if ((_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == 'O') && (_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == ' ') && cp >= 3 && cp <= 6) {
			verificar2 = 1; //que a la derecha tenga un bloqueo doble y que a la izquierda  tenga una ficha y se la pueda comer

		}
		if (_tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == ' ' && cp == 7) {
			verificar2 = 1;

		}

		if (_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 2, cp - 2) == ' ' && _tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == ' ' && cp >= 3 && cp <= 6) {
			verificar2 = 1;

		}
		if (_tablero->getFicha(fp - 1, cp - 1) == 'O' && _tablero->getFicha(fp - 1, cp + 1) == 'O' && _tablero->getFicha(fp - 2, cp + 2) == ' ' && cp == 2) {
			verificar2 = 1;

		}
	}
	if (verificar2 == 1) {
		return true;
	}
	return false;
}

void Juego::guardaPartida(){
	ofstream archivo;
	archivo.open("save/partidaGuardada.txt", ios::out);
	archivo << _tablero->toString();
	archivo.close();

	archivo.open("save/nombreGuardado.txt", ios::out);
	archivo << p1->getNombre();
	archivo.close();

	archivo.open("save/estrategiaSeleccionada.txt", ios::out);
	archivo << _estrategia->toString();
	archivo.close();
}

bool Juego::cargarPartida(){
	fstream archivo;
	string dato;
	char ficha;
	int fila, columna;
	archivo.open("save/partidaGuardada.txt", ios::in);
	bool y = false;
	if (archivo.good()) {
		y = true;
	}
	archivo.close();
	if (!y) {
		gotoxy(0, 22);
		cout << "No hay partidas guardadas aun!" << endl;
		pauseCorner();
		return false;
	}
	else {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				_tablero->quitar(i + 1, j + 1);
			}
		}
		archivo.open("save/partidaGuardada.txt", ios::in);
		if (archivo.is_open()) {
			while (!(archivo.eof())) {
				getline(archivo, dato, TAB);
				if (dato == " ") {
					ficha = ' ';
				}
				else {
					ficha = stringXchar(dato);
				}
				getline(archivo, dato, TAB);
				fila = stringXint(dato);
				getline(archivo, dato, END);
				columna = stringXint(dato);
				_tablero->agregar(ficha, fila + 1, columna + 1);
			}
		}
		archivo.close();

		archivo.open("save/nombreGuardado.txt", ios::in);
		if (archivo.is_open()) {
			while (!(archivo.eof())) {
				getline(archivo, dato);
				p1 = new jugador(dato);
			}
		}
		archivo.close();
		
		return true;
	}
	string est;
	archivo.open("save/estrategiaSeleccionada.txt", ios::in);
	if (archivo.is_open()) {
		while (!(archivo.eof())) {
			getline(archivo, est);
			if (est == "Aleatoria") {
				_estrategia->setEstrategia(_aleatoria);
			}
			else if (est == "Ataque") {
				_estrategia->setEstrategia(_ataque);
			}
			else if (est == "Defensa") {
				_estrategia->setEstrategia(_defensa);
			}
			else if (est == "Selectivo") {
				_estrategia->setEstrategia(_selectivo);
			}
		}
	}
	else {
		cout << "No se ha podido abrir el archivo"<<endl;
	}
	
	archivo.close();
	remove("save/partidaGuardada.txt");
}
