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
//overload pe of/ifstream 

//------------------------------------------------TESTING------------------------------------------------
//int main() {
//	Locatie* locatie = new Locatie[2];
//	locatie[0] = Locatie("Bucuresti", "Decebal nr 1", 120, "Hala Traian");
//	locatie[1] = Locatie("Bucuresti", "Mihai Bravu", 1200, "Arena Nationala");
//	char* numeEveniments = new char[strlen("Concert Metalica") + 1];
//	strcpy_s(numeEveniments, strlen("Concert Metalica") + 1, "Concert Metalica");
//	Eveniment *evenimente0 = new Eveniment(numeEveniments, "24/10/2023", "23:53", "03:00", 100, locatie[0]);
//	delete[] numeEveniments;
//	numeEveniments = new char[strlen("Concert Eminem") + 1];
//	strcpy_s(numeEveniments, strlen("Concert Eminem") + 1, "Concert Eminem");
//	Eveniment* evenimente1 = new Eveniment(numeEveniments, "23/12/2023", "22:30", "04:00", 900, locatie[1]);
//	cout << "Ticketing App";
//	int nrOptiune = 0;
//	//ofstream fout("evenimente.txt");
//	cout << endl << "==============================";
//	cout << endl << "1-Introducere Eveniment";
//	cout << endl << "2-Rezervare Bilet";
//	cout << endl << "3-Afisare Evenimente";
//	cout << endl << "4-exit";
//	cout << endl << "Introduceti actiunea dorita: "; cin >> nrOptiune;
//	while (cin.fail() || nrOptiune != 4) { 
//		cin.clear();
//		//getchar();
//		cin.ignore(256, '\n');
//		if (nrOptiune == 1) {
//			time_t now = time(0);
//			tm* ltm = localtime(&now);
//			int year = 1900 + ltm->tm_year;
//			int month = 1 + ltm->tm_mon;
//			int day = ltm->tm_mday;	
//			struct tm data;
//			cout << "Introduceti data evenimentului (dd/mm/yyyy): ";
//			cin >> get_time(&data, "%d/%m/%Y");
//			while (cin.fail() || data.tm_year + 1900 < year || data.tm_year + 1900 == year && data.tm_mon + 1 < month || data.tm_year + 1900 == year && data.tm_mon + 1 == month && data.tm_mday < day)
//			{
//				cin.clear();
//				cin.ignore(256, '\n');
//				cout << "Data este invalida, incercati din nou (dd/mm/yyyy): ";
//				cin >> get_time(&data, "%d/%m/%Y");
//			}
//			string dataEveniment;
//			if (data.tm_mday < 10 && data.tm_mon + 1 < 10)
//				dataEveniment = "0" + to_string(data.tm_mday) + "/0" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
//			else if (data.tm_mday < 10 && data.tm_mon + 1 >= 10)
//				dataEveniment = "0" + to_string(data.tm_mday) + "/" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
//			else if (data.tm_mday >= 10 && data.tm_mon + 1 < 10)
//				dataEveniment = to_string(data.tm_mday) + "/0" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
//			else
//				dataEveniment = to_string(data.tm_mday) + "/" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
//			Eveniment* ev = new Eveniment(dataEveniment);
//			cin >> *ev;
//			//cout << *ev;
//			ev->afisareOraSfarsit();
//
//			//rezervare bilet
//			int id = ev->getNrLocuri() + 69;
//			Bilet* b = new Bilet(ev, id);
//			cout << *b;
//			cout << endl << "Biletul a fost rezervat cu succes!" << endl;
//			//cout << ev->getNrEvenimente();
//		}
//		else if (nrOptiune == 2) {
//			cout << "===============" << endl;
//			cout << "Rezervare Bilet" << endl;
//			cout << "Introduceti evenimentul: ";
//			int nrEveniment;
//			cin >> nrEveniment;
//			while (cin.fail() || nrEveniment <= 0 || nrEveniment > 2)
//			{
//				cin.clear();
//				cin.ignore(256, '\n');
//				cout << "Numarul evenimentului este invalid, incercati din nou: ";
//				cin >> nrEveniment;
//			}
//			if (nrEveniment == 1) {
//				Bilet b(evenimente0);
//				cout << b;
//			}
//			else {
//				Bilet b(evenimente1);
//				cout << b;
//			}
//			
//		}
//		else if (nrOptiune == 3) {
//			cout << "===============";
//			cout << "Afisare Evenimente" << endl;
//			cout << *evenimente0 << *evenimente1;
//		}
//		cout << endl << "==============================";
//		cout << endl << "1-Introducere Eveniment";
//		cout << endl << "2-Modificare evenimente";
//		cout << endl << "3-exit";
//		cout << endl << "Introduceti actiunea dorita: "; cin >> nrOptiune;
//	}
//	return 0;
//}

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
	

	Eveniment* evenimente0 = new Eveniment();
	cin >> *evenimente0;
	Bilet b(*evenimente0);
	cin >> b;
	evenimente0->rezervareLoc(b.getNrZona(), b.getRand(), b.getLoc());
	cout << b;
	cout << *evenimente0;
	cout << endl << evenimente0->getIdEveniment();
	return 0;
}
