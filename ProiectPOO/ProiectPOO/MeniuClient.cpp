#include "MeniuClient.h"
MeniuClient::MeniuClient(string numeFisier){
	this->date = new DateUser(numeFisier);
}
MeniuClient::MeniuClient(const MeniuClient& m) {
	this->date = new DateUser(*m.date);
}
void MeniuClient::optiuni() {
	cout << "==========================" << endl;
	cout << "          WELCOME" << endl;
	cout << "==========================" << endl;
	cout << "1-Afisare evenimente" << endl;
	cout << "2-Afisare detalii eveniment" << endl;
	cout << "3-Rezerva bilet" << endl;
	cout << "4-Exit" << endl;
	cout << "Introdceti optiunea: ";
	int optiune;
	cin >> optiune;
	while (optiune != 4) {
		if (!cin.fail()) {
			if (optiune == 1)
				date->afisareEvenimenteUser();
			else if (optiune == 2)
				date->afisareDetaliiEveniment();
			else if (optiune == 3)
				date->rezervaBilet();
			else
				cout << "Optiune invalida" << endl;
		}
		cin.clear();
		cin.ignore(256, '\n');
		cout << endl;
		cout << "1-Afisare evenimente" << endl;
		cout << "2-Afisare detalii eveniment" << endl;
		cout << "3-Rezerva bilet" << endl;
		cout << "4-Exit" << endl;
		cout << "Introduceti optiunea: ";
		cin >> optiune;
	}
}
MeniuClient& MeniuClient::operator=(const MeniuClient& m) {
	if (this != &m) {
		delete this->date;
		this->date = new DateUser(*m.date);
	}
	return *this;
}
MeniuClient::~MeniuClient() {
	if (date != nullptr) {
		delete date;
		date = nullptr;
	}
}

