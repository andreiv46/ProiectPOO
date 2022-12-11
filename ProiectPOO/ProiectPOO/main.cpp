#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
//------------------------------------------------TESTING------------------------------------------------
int main() {
	cout << "Ticketing App";
	int nrOptiune = 0;
	ofstream fout("evenimente.txt");
	cout << endl << "==============================";
	cout << endl << "1-Introducere Eveniment";
	cout << endl << "2-Rezervare Bilet";
	cout << endl << "3-exit";
	cout << endl << "Introduceti actiunea dorita: "; cin >> nrOptiune;
	while (cin.fail() || nrOptiune != 3) { 
		cin.clear();
		//getchar();
		cin.ignore(256, '\n');
		if (nrOptiune == 1) {
			time_t now = time(0);
			tm* ltm = localtime(&now);
			int year = 1900 + ltm->tm_year;
			int month = 1 + ltm->tm_mon;
			int day = ltm->tm_mday;
			struct tm data;
			cout << "Introduceti data evenimentului (dd/mm/yyyy): ";
			cin >> get_time(&data, "%d/%m/%Y");
			while (cin.fail() || data.tm_year + 1900 < year || data.tm_year + 1900 == year && data.tm_mon + 1 < month || data.tm_year + 1900 == year && data.tm_mon + 1 == month && data.tm_mday < day)
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Data este invalida, incercati din nou (dd/mm/yyyy): ";
				cin >> get_time(&data, "%d/%m/%Y");
			}
			string dataEveniment;
			if (data.tm_mday < 10 && data.tm_mon + 1 < 10)
				dataEveniment = "0" + to_string(data.tm_mday) + "/0" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
			else if (data.tm_mday < 10 && data.tm_mon + 1 >= 10)
				dataEveniment = "0" + to_string(data.tm_mday) + "/" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
			else if (data.tm_mday >= 10 && data.tm_mon + 1 < 10)
				dataEveniment = to_string(data.tm_mday) + "/0" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
			else
				dataEveniment = to_string(data.tm_mday) + "/" + to_string(data.tm_mon + 1) + "/" + to_string(data.tm_year + 1900);
			Eveniment* ev = new Eveniment(dataEveniment);
			cin >> *ev;
			//cout << *ev;
			ev->afisareOraSfarsit();

			//rezervare bilet
			int id = ev->getNrLocuri() + 69;
			Bilet* b = new Bilet(ev, id);
			cout << *b;
			cout << endl << "Biletul a fost rezervat cu succes!" << endl;
			//cout << ev->getNrEvenimente();
		}
		else if (nrOptiune == 2) {
			cout << "===============";
			cout << "Rezervare Bilet" << endl;
			cout << "Introduceti evenimentul: ";
			
		}
		cout << endl << "==============================";
		cout << endl << "1-Introducere Eveniment";
		cout << endl << "2-Modificare evenimente";
		cout << endl << "3-exit";
		cout << endl << "Introduceti actiunea dorita: "; cin >> nrOptiune;
	}
	return 0;
}