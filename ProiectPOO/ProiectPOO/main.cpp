#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
#include "Locuri.h"
#include "Zona.h"
#include "DateAdmin.h"
#include "DateUser.h"
#include "MeniuAdmin.h"
#include "MeniuClient.h"

int main(int argc, char** argv) {
	string fisierTextEvenimente;
	if(argc > 1)
		fisierTextEvenimente = argv[1];
	else 
		fisierTextEvenimente = "invalid";
	cout << "==========================" << endl;
	cout << "      TICKETING APP       " << endl;	
	cout << "==========================" << endl;
	cout << "1-Meniu Admin" << endl;
	cout << "2-Meniu Client" << endl;
	cout << "3-Exit" << endl;
	cout << "Introduceti optiunea: ";
	int optiune;
	cin >> optiune;
	while (optiune != 3) {
		if (!cin.fail()) {
			if (optiune == 1) {
				MeniuAdmin* m = new MeniuAdmin(fisierTextEvenimente);
				m->optiuni();
				delete m;
			}
			else if (optiune == 2) {
				MeniuClient* m = new MeniuClient(fisierTextEvenimente);
				m->optiuni();
				delete m;
			}
			else
				cout << "Optiune invalida" << endl;
		}
		cin.clear();
		cin.ignore(256, '\n');
		cout << endl;
		cout << "1-Meniu Admin" << endl;
		cout << "2-Meniu Client" << endl;
		cout << "3-Exit" << endl;
		cout << "Introduceti optiunea: ";
		cin >> optiune;
	}
	return 0;
}
