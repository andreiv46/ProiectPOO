#include "MeniuClientStudent.h"
MeniuClientStudent::MeniuClientStudent(string numeFisier){
	this->date = new DateUser(numeFisier);
}
MeniuClientStudent::MeniuClientStudent(const MeniuClientStudent& m) {
	this->date = new DateUser(*m.date);
}
void MeniuClientStudent::optiune() {
	cout << "==========================" << endl;
	cout << "          WELCOME" << endl;
	cout << "==========================" << endl;
	cout << "1-Afisare evenimente" << endl;
	cout << "2-Rezerva bilet" << endl;
	cout << "3-Exit" << endl;
	cout << "Introdceti optiunea: ";
	int optiune;
	cin >> optiune;
	while (optiune != 3) {
		if (!cin.fail()) {
			if (optiune == 1)
				date->afisareEvenimenteUser();
			else if (optiune == 2)
				date->rezervaBilet();
			else
				cout << "Optiune invalida" << endl;
		}
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Introduceti optiunea: ";
		cin >> optiune;
	}
}
