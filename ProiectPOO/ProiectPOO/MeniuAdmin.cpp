#include "MeniuAdmin.h"
void MeniuAdmin::optiuni() {
	if (date->getNumeFisierEvenimente() != "invalid") {
		cout << "==========================" << endl;
		cout << "          WELCOME" << endl;
		cout << "==========================" << endl;
		cout << "1-Afisare evenimente" << endl;
		cout << "2-Adaugare eveniment" << endl;
		cout << "3-Afisare bilete" << endl;
		cout << "4-Afisare incasari" << endl;
		cout << "5-Exit" << endl;
		cout << "Introdceti optiunea: ";
		int optiune;
		cin >> optiune;
		while (optiune != 5) {
			if (!cin.fail()) {
				if (optiune == 1)
					date->afisareEvenimente();
				else if (optiune == 2)
					date->adaugaEvenimentFisierText();
				else if (optiune == 3) {
					cout << endl;
					date->afisareBilete();
				}
				else if (optiune == 4)
					cout << endl << "Incasarile totale sunt de: " << date->valoareTotalaBilete() << " lei" << endl << endl;
				else
					cout << "Optiune invalida" << endl;
			}
			cin.clear();
			cin.ignore(256, '\n');
			cout << "1-Afisare evenimente" << endl;
			cout << "2-Adaugare eveniment" << endl;
			cout << "3-Afisare bilete" << endl;
			cout << "4-Afisare incasari" << endl;
			cout << "5-Exit" << endl;
			cout << "Introduceti optiunea: ";
			cin >> optiune;
		}
	}
}
MeniuAdmin::MeniuAdmin(string numeFisier) {
	date = new DateAdmin(numeFisier);
}
MeniuAdmin::~MeniuAdmin() {
	if (date != nullptr) {
		delete date;
		date = nullptr;
	}
}
MeniuAdmin& MeniuAdmin::operator=(const MeniuAdmin& m) {
	if (this != &m) {
		if (date != nullptr) {
			delete date;
			date = nullptr;
		}
		date = new DateAdmin(*m.date);
	}
	return *this;
}
MeniuAdmin::MeniuAdmin(const MeniuAdmin& m) {
	date = new DateAdmin(*m.date); 
}
