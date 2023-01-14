#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
#include "Locuri.h"
#include "Zona.h"
#include "Meniu.h"

//de facut 
//clasa meniu cu vector stl
//overload pe of/ifstream maybe
//???

//------------------------------------------------TESTING------------------------------------------------

int main() {
	//locuri
	Locuri locuri0(3, 4);
	Locuri locuri1(2, 3);
	Locuri locuri2(5, 6);
	Zona* z0 = new Zona("normal", 123.23f, locuri0);
	Zona* z1 = new Zona("average", 23.98f, locuri1);
	Zona* z2 = new Zona("Sala 10", 69.23f, locuri2);
	//locatie
	Locatie locatie0("Bucuresti", "Strada gaming", 1200, "Gaming cave", z0, 1);
	Locatie locatie1("Bucuresti", "Strada Margherita", 130, "Park Lake", z1, 1);
	Locatie locatie2("Bucuresti", "Strada Stalinskaya", 120, "Cinema City", z2, 1);
	//eveniment
	char* denumireEv0 = new char[strlen("Concert Eminem") + 1];
	strcpy(denumireEv0, "Concert Eminem");
	Eveniment ev0(denumireEv0, "24/12/2023", "20:00", "Necunoscuta", locatie0, 1);
	char* denumireEv1 = new char[strlen("Concert Metallica") + 1];
	strcpy(denumireEv1, "Concert Metallica");
	Eveniment ev1(denumireEv1, "25/12/2023", "21:00", "04:25", locatie1, 2);
	char* denumireEv2 = new char[strlen("Avatar 2") + 1];
	strcpy(denumireEv2, "Avatar 2");
	Eveniment ev2(denumireEv2, "26/12/2023", "22:00", "03:30", locatie2, 3);
	ev2.rezervareLoc(1, 1, 1);
	//cout << ev0 << ev1 << ev2;
	//cout << endl << Eveniment::getNrEvenimente() << endl;
	
	//cout << "Alegeti evenimentul: ";
	//int optiune;
	//cin >> optiune;
	//if (optiune == 1) {
	//	Bilet b(ev0);
	//	cin >> b;
	//	cout << b;
	//	ev0.rezervareLoc(b.getNrZona(), b.getRand(), b.getLoc());
	//	cout << ev0;
	//}
	//else if (optiune == 2) {
	//	Bilet b(ev1);
	//	cin >> b;
	//	cout << b;
	//	ev1.rezervareLoc(b.getNrZona(), b.getRand(), b.getLoc());
	//	cout << ev1;
	//}
	//else if (optiune == 3) {
	//	Bilet b(ev2);
	//	cin >> b;
	//	cout << b;
	//	ev2.rezervareLoc(b.getNrZona(), b.getRand(), b.getLoc());
	//	cout << ev2;
	//}
	//else {
	//	cout << "Optiune invalida";
	//}

	//cout << "Introduceti evenimentul" << endl;
	//Eveniment ev;
	//cin >> ev;
	//cout << Eveniment::getNrEvenimente() << endl;

	//Locuri l1(12, 10);
	//Locuri l2;
	//l2 = l1;
	//cout << l2;
	Meniu m("evenimente.txt");
	//Bilet b(ev0);
	//cin >> b;
	//m.adaugaBiletFisierBinar(b);
	////cout << b;
	//cout << endl;
	//cout << "===========================================";
	//cout << endl;
	//m.citesteBileteleFisierBinar();
	////m.afisareBilete();
	//m.adaugaEvenimentFisierText(ev2);
	//m.adaugaEvenimentFisierText(ev1);
	//m.adaugaEvenimentFisierText(ev0);
	cout << m.getNrEvenimente() << endl;
	m.afisareEvenimente();
	
	return 0;
}
