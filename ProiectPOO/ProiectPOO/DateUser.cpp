#include "DateUser.h"
DateUser::DateUser() :DateAdmin(){}
DateUser::DateUser(string fisierEvenimente) : DateAdmin(fisierEvenimente){}
void DateUser::rezervaBilet() {
	cout << "==========================" << endl;
	cout << "     REZERVARE BILET      " << endl;
	cout << "==========================" << endl;
	cout << "Alegeti evenimentul: ";
	int optiune;
	cin >> optiune;
	if (this->checkExistEveniment(optiune)) {
		cout << "Introduceti numele: ";
		string nume, prenume;
		cin >> nume;
		cout << "Introdceti prenumele: ";
		cin >> prenume;
		this->ocupaLoc(optiune, nume, prenume);
	}
	else {
		cout << "Nu exista evenimentul cu id-ul " << optiune << endl;
	}
}
