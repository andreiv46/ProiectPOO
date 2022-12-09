#include <iostream>
#include <string>
#include "Locatie.h"
//------------------------------------------------TESTING------------------------------------------------
int main() {
	cout << "Ticketing App";
	int nrOptiune = 0;
	while (nrOptiune != 2) { 
		cout << endl << "==============================";
		cout << endl << "1-Introducere Locatie";
		cout << endl << "2-exit";
		cout << endl << "Introduceti actiunea dorita: "; cin >> nrOptiune;
		if (nrOptiune == 1) {
			Locatie* locatie = new Locatie;
			cout << endl;
			cin >> *locatie;
			cout << *locatie;
		}
	}
	return 0;
}