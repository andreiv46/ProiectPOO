#include "Eveniment.h"
Eveniment::Eveniment() {
	this->denumireEveniment = new char[strlen("Necunoscut") + 1];
	strcpy_s(denumireEveniment, strlen("Necunoscut") + 1, "Necunoscut");
	this->data = "Necunoscuta";
	this->oraIncepere = 0;
	this->minut = 0;
	this->durata = 0;
}
//Eveniment::Eveniment(const char* denumireEveniment, string data, int oraIncepere, int minut, int* oraSfarsit, int* minutSfarsit) {
//	if (denumireEveniment != nullptr && strlen(denumireEveniment) > 0)
//		strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
//	this->data = data;
//	
//}
Eveniment::Eveniment(string data):Eveniment() {
	this->data = data;
}
Eveniment::Eveniment(const Eveniment& e) {
	this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
	strcpy_s(this->denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
	this->data = e.data;
	this->oraIncepere = e.oraIncepere;
	this->minut = e.minut;
	this->durata = 0;
	this->locatie = e.locatie;
}
char* Eveniment::getDenumireEveniment() const {
	char* copie = new char[strlen(this->denumireEveniment) + 1];
	strcpy_s(copie, strlen(this->denumireEveniment) + 1, this->denumireEveniment);
	return copie;
}
void Eveniment::setDenumireEveniment(const char* denumireEveniment) {
	if (denumireEveniment != nullptr) {
		if (this->denumireEveniment != nullptr) 
			delete[] this->denumireEveniment;
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
	}
	else {
		delete[] this->denumireEveniment;
		denumireEveniment = nullptr;
	}
}
string Eveniment::getData() const{
	return this->data;
}
//void Eveniment::setData(string data) {
//	if(data.length() > 0)
//}
int Eveniment::getOraIncepere() const {
	return this->oraIncepere;
}
void Eveniment::setOraIncepere(int oraIncepere) {
	if (oraIncepere >= 0 && oraIncepere <= 24)
		this->oraIncepere = oraIncepere;
}

Eveniment& Eveniment::operator=(const Eveniment& e) {
	if (this != &e) {
		if (this->denumireEveniment != NULL)
			delete[] this->denumireEveniment;
		this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
		this->data = e.data;
		this->oraIncepere = e.oraIncepere;
		this->minut = e.minut;
		this->durata = e.durata;
		this->locatie = e.locatie;
	}
	return *this;
}
Eveniment::~Eveniment() {
	if (this->denumireEveniment != nullptr) {
		delete[] this->denumireEveniment;
		this->denumireEveniment = nullptr;
	}
}
int Eveniment::getDurata() const {
	return this->durata;
}
void Eveniment::setDurata(int durata) {
	if (durata >= 0 && durata <= 1440)
		this->durata = durata;
}
int Eveniment::getMinut() const {
	return this->minut;
}
void Eveniment::setMinut(int minut) {
	if (minut >= 0 && minut <= 60)
		this->minut = minut;
}
void Eveniment::afisareOraSfarsit() const {
	int oraInMinute = this->oraIncepere * 60 + this->minut;
	int oraSfarsit = 0;
	if (oraInMinute + this->durata > 1440)
		oraSfarsit = oraInMinute + this->durata - 1440;
	else
		oraSfarsit = oraInMinute + this->durata;
	//cout << "Ora de sfarsit a evenimentului este: " << oraSfarsit / 60 << ":" << oraSfarsit % 60 << endl;
	if (oraSfarsit/60 == 0 && oraSfarsit % 60 == 0)
		cout << "Ora incepere: 00:00" << endl;
	else if (oraSfarsit / 60 < 10 && oraSfarsit % 60 < 10)
		cout << "Ora incepere: 0" << oraSfarsit / 60 << ":0" << oraSfarsit % 60 << endl;
	else if (oraSfarsit / 60 < 10 && oraSfarsit % 60 >= 10)
		cout << "Ora incepere: 0" << oraSfarsit / 60 << ":" << oraSfarsit % 60 << endl;
	else if (oraSfarsit / 60 >= 10 && oraSfarsit % 60 < 10)
		cout << "Ora incepere: " << oraSfarsit / 60 << ":0" << oraSfarsit % 60 << endl;
	else
		cout << "Ora incepere: " << oraSfarsit / 60 << ":" << oraSfarsit % 60 << endl;
}
ostream& operator<<(ostream& out, const Eveniment& e) {
	out << endl;
	out << "===================" << endl;
	out << "Evenimentul" << endl;
	out << "Denumire eveniment: " << e.denumireEveniment << endl;
	out << "Data: " << e.data << endl;
	if (e.oraIncepere == 0 && e.minut == 0)
		out << "Ora incepere: 00:00" << endl;
	else if (e.oraIncepere < 10 && e.minut < 10)
		out << "Ora incepere: 0" << e.oraIncepere << ":0" << e.minut << endl;
	else if (e.oraIncepere < 10 && e.minut >= 10)
		out << "Ora incepere: 0" << e.oraIncepere << ":" << e.minut << endl;
	else if (e.oraIncepere >= 10 && e.minut < 10)
		out << "Ora incepere: " << e.oraIncepere << ":0" << e.minut << endl;
	else
		out << "Ora incepere: " << e.oraIncepere << ":" << e.minut << endl;
	if (e.durata > 60 && e.durata % 60 == 0)
		out << "Durata: " << e.durata / 60 << " ore" << endl;
	else if (e.durata > 60 && e.durata % 60 != 0)
		out << "Durata: " << e.durata / 60 << " ore si " << e.durata % 60 << " minute" << endl;
	else if(e.durata < 60)
		out << "Durata: " << e.durata << " minute" << endl;
	out << endl;
	out << e.locatie;
	return out;
}
istream& operator>>(istream& in, Eveniment& e) {
	cout << "Introduceti numele evenimentului: "; 
	ws(in);
	string denEvent;
	getline(in, denEvent);
	e.setDenumireEveniment(denEvent.c_str());
	cout << "Introduceti ora incepere (HH:MM): ";
	in >> e.oraIncepere >> e.minut;
	while (e.oraIncepere < 0 || e.oraIncepere > 24 || e.minut < 0 || e.minut > 60) {
		cout << "Ora incepere invalida, incercati din nou (HH:MM):  ";
		in >> e.oraIncepere >> e.minut;
	}
	int ore, minute;
	cout << "Introduceti durata evenimentului (ore:minute): ";
	in >> ore >> minute;
	e.durata = ore * 60 + minute;
	while (e.durata < 0 || e.durata > 1440 || ore < 0 || minute < 0 || minute > 60 || ore > 24) {
		cout << "Durata invalida, incercati din nou (ore:minute): ";
		in >> ore >> minute;
		e.durata = ore * 60 + minute;
	}
	in >> e.locatie;
	return in;
}
