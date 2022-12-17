#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
#include "Locuri.h"
#include "Zona.h"
#include "functiimain.h"

//clasa meniu cu vector stl
//overload pe of/ifstream maybe


//------------------------------------------------TESTING------------------------------------------------

int main() {
	////eveniment
	//Eveniment* evenimente0 = new Eveniment("01/01/2024");
	//Eveniment* evenimente1 = new Eveniment("02/02/2024");
	//cin >> *evenimente0;
	//cin >> *evenimente1;
	//cout << "Evenimente: " << endl;
	//cout << *evenimente0 << *evenimente1;
	////bilet
	//cout << "Alegeti evenimentul: ";
	//int nrEveniment;
	//cin >> nrEveniment;
	//while (cin.fail() || nrEveniment <= 0 || nrEveniment > 2)
	//{
	//	cin.clear();
	//	cin.ignore(256, '\n');
	//	cout << "Numarul evenimentului este invalid, incercati din nou: ";
	//	cin >> nrEveniment;
	//}
	//if (nrEveniment == 1) {
	//	cout << "Alegeti zona: ";
	//	int nrZona;
	//	cin >> nrZona;
	//	while (cin.fail() || nrZona <= 0 || nrZona > evenimente0->getNrZone())
	//	{
	//		cin.clear();
	//		cin.ignore(256, '\n');
	//		cout << "Numarul zonei este invalid, incercati din nou: ";
	//		cin >> nrZona;
	//	}
	//	cout << "Alegeti randul: ";
	//	int nrRand;
	//	cin >> nrRand;
	//	while (cin.fail() || nrRand <= 0 || nrRand > evenimente0->getNrRanduri(nrZona))
	//	{
	//		cin.clear();
	//		cin.ignore(256, '\n');
	//		cout << "Numarul randului este invalid, incercati din nou: ";
	//		cin >> nrRand;
	//	}
	//	cout << "Alegeti locul: ";
	//	int nrLoc;
	//	cin >> nrLoc;
	//	while (cin.fail() || nrLoc <= 0 || nrLoc > evenimente0->getNrLocuri(nrZona))
	//	{
	//		cin.clear();
	//		cin.ignore(256, '\n');
	//		cout << "Numarul locului este invalid, incercati din nou: ";
	//		cin >> nrLoc;
	//	}
	//	Bilet b("Daniel", "Andrei", *evenimente0, nrRand, nrLoc, nrZona);
	//	cout << b;
	//}
	//else {
	//	cout << "Alegeti zona: ";
	//	int nrZona;
	//	cin >> nrZona;
	//	while (cin.fail() || nrZona <= 0 || nrZona > evenimente1->getNrZone())
	//	{
	//		cin.clear();
	//		cin.ignore(256, '\n');
	//		cout << "Numarul zonei este invalid, incercati din nou: ";
	//		cin >> nrZona;
	//	}
	//	cout << "Alegeti randul: ";
	//	int nrRand;
	//	cin >> nrRand;
	//	while (cin.fail() || nrRand <= 0 || nrRand > evenimente1->getNrRanduri(nrZona))
	//	{
	//		cin.clear();
	//		cin.ignore(256, '\n');
	//		cout << "Numarul randului este invalid, incercati din nou: ";
	//		cin >> nrRand;
	//	}
	//	cout << "Alegeti locul: ";
	//	int nrLoc;
	//	cin >> nrLoc;
	//	while (cin.fail() || nrLoc <= 0 || nrLoc > evenimente1->getNrLocuri(nrZona))
	//	{
	//		cin.clear();
	//		cin.ignore(256, '\n');
	//		cout << "Numarul locului este invalid, incercati din nou: ";
	//		cin >> nrLoc;
	//	}
	//	Bilet b("Daniel", "Andrei", *evenimente1, nrRand, nrLoc, nrZona);
	//	cout << b;
	//}
	//return 0;
	

	//Eveniment* evenimente0 = new Eveniment();
	//cin >> *evenimente0;
	//Bilet b(*evenimente0);
	//cin >> b;
	//evenimente0->rezervareLoc(b.getNrZona(), b.getRand(), b.getLoc());
	//cout << b;
	//cout << *evenimente0;
	//cout << endl << evenimente0->getIdEveniment();
	//return 0;

	//locuri
	Locuri locuri0(3, 4);
	Locuri locuri1(2, 3);
	Locuri locuri2(5, 6);
	Zona* z0 = new Zona("VIP", 123.23, locuri0);
	Zona* z1 = new Zona("SARAKIE", 23.98, locuri1);
	Zona* z2 = new Zona("DAB", 69.23, locuri2);
	//locatie
	Locatie locatie0("Bucuresti", "Strada gaming", 1200, "Gaming cave", z0, 1);
	Locatie locatie1("Bucuresti", "Strada maaai", 1200, "sarakie cave", z1, 1);
	Locatie locatie2("Bucuresti", "Strada flaore", 1200, "mui cave", z2, 1);
	//eveniment
	char* denumireEv0 = new char[strlen("Concert Eminem") + 1];
	strcpy(denumireEv0, "Concert Eminem");
	Eveniment ev0(denumireEv0, "24/12/2023", "20:00", "Necunoscuta", locatie0, 1);
	char* denumireEv1 = new char[strlen("Concert Metalica") + 1];
	strcpy(denumireEv1, "Concert Metalica");
	Eveniment ev1(denumireEv1, "25/12/2023", "21:00", "04:25", locatie1, 2);
	char* denumireEv2 = new char[strlen("Concert Green Day") + 1];
	strcpy(denumireEv2, "Concert Green Day");
	Eveniment ev2(denumireEv2, "26/12/2023", "22:00", "03:30", locatie2, 3);
	ev2.rezervareLoc(1, 1, 1);
	cout << ev2;
	cout << endl << ev2.getNrEvenimente();
}
