#include "Eveniment.h"
Eveniment::Eveniment() {
	this->denumireEveniment = new char[strlen("Necunoscut") + 1];
	strcpy_s(denumireEveniment, strlen("Necunoscut") + 1, "Necunoscut");
	this->data = "Necunoscuta";
	this->oraIncepere = "Necunoscuta";
	this->durata = "Necunoscuta";
	this->nrLocuri = 0;
	this->locatie = new Locatie();
}
Eveniment::Eveniment(string data):Eveniment() {
	this->data = data;
	locatie = new Locatie();
}
Eveniment::Eveniment(char* denumireEveniment, string data, string oraIncepere, string durata, int nrLocuri, Locatie locatie) {
	this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
	strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
	this->data = data;
	this->oraIncepere = oraIncepere;
	this->durata = durata;
	this->nrLocuri = nrLocuri;
	this->locatie = new Locatie(locatie);
}
Eveniment::Eveniment(const Eveniment& e) {
	this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
	strcpy_s(this->denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
	this->data = e.data;
	this->nrLocuri = e.nrLocuri;
	this->oraIncepere = e.oraIncepere;
	this->durata = "Necunoscuta";
	this->locatie = new Locatie(*e.locatie);
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
string Eveniment::getOraIncepere() const {
	return this->oraIncepere;
}
//void Eveniment::setOraIncepere(int oraIncepere) {
//	if (oraIncepere >= 0 && oraIncepere <= 24)
//		this->oraIncepere = oraIncepere;
//}
int Eveniment::getNrLocuri() const {
	return this->nrLocuri;
}
void Eveniment::setNrLocuri(int nrLocuri) {
	if (nrLocuri >= 0 && nrLocuri <= locatie->getCapacitateTotala())
		this->nrLocuri = nrLocuri;
}
Eveniment& Eveniment::operator=(const Eveniment& e) {
	if (this != &e) {
		if (this->denumireEveniment != NULL)
			delete[] this->denumireEveniment;
		this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
		this->data = e.data;
		this->oraIncepere = e.oraIncepere;
		this->nrLocuri = e.nrLocuri;
		this->durata = e.durata;
		if (this->locatie != NULL)
			delete this->locatie;
		this->locatie = new Locatie(*e.locatie);
	}
	return *this;
}
Eveniment::~Eveniment() {
	if (this->denumireEveniment != nullptr) {
		delete[] this->denumireEveniment;
		this->denumireEveniment = nullptr;
	}
	if (this->locatie != nullptr) {
		delete this->locatie;
		this->locatie = nullptr;
	}
}
string Eveniment::getDurata() const {
	return this->durata;
}
//void Eveniment::setDurata(int durata) {
//	if (durata >= 0 && durata <= 1440)
//		this->durata = durata;
//}
Locatie* Eveniment::getLocatie() const {
	if (this->locatie != nullptr) {
		Locatie* copie = new Locatie(*this->locatie);
		return copie;
	}
	else
		return nullptr;
}
void Eveniment::setLocatie(Locatie* locatie) {
	if (locatie != nullptr) {
		if (this->locatie != nullptr)
			delete this->locatie;
		this->locatie = new Locatie(*locatie);
	}
	else {
		delete this->locatie;
		this->locatie = nullptr;
	}
}
void Eveniment::afisareOraSfarsit() const {
	int oraIncepere = stoi(this->oraIncepere.substr(0, 2));
	int minuteIncepere = stoi(this->oraIncepere.substr(3, 2));
	if (this->durata == "Necunoscuta") 
		cout << "Ora de sfarsit este necunoscuta" << endl;
	else {
		int durata = stoi(this->durata.substr(0, 2));
		int minuteDurata = stoi(this->durata.substr(3, 2));
		int durataMinute = durata * 60 + minuteDurata;
		int oraIncepereMinute = oraIncepere * 60 + minuteIncepere;
		int oraSfarsitMinute = 0;
		if (durataMinute + oraIncepereMinute > 1440)
			oraSfarsitMinute = durataMinute + oraIncepereMinute - 1440;
		else
			oraSfarsitMinute = durataMinute + oraIncepereMinute;
		if (oraSfarsitMinute / 60 == 0 && oraSfarsitMinute % 60 == 0)
			cout << "Ora de sfarsit a evenimentului: 00:00" << endl;
		else if (oraSfarsitMinute / 60 < 10 && oraSfarsitMinute % 60 < 10)
			cout << "Ora de sfarsit a evenimentului: 0" << oraSfarsitMinute / 60 << ":0" << oraSfarsitMinute % 60 << endl;
		else if (oraSfarsitMinute / 60 < 10 && oraSfarsitMinute % 60 >= 10)
			cout << "Ora de sfarsit a evenimentului: 0" << oraSfarsitMinute / 60 << ":" << oraSfarsitMinute % 60 << endl;
		else if (oraSfarsitMinute / 60 >= 10 && oraSfarsitMinute % 60 < 10)
			cout << "Ora de sfarsit a evenimentului: " << oraSfarsitMinute / 60 << ":0" << oraSfarsitMinute % 60 << endl;
		else
			cout << "Ora de sfarsit a evenimentului: " << oraSfarsitMinute / 60 << ":" << oraSfarsitMinute % 60 << endl;
	}

}
ostream& operator<<(ostream& out, const Eveniment& e) {
	out << endl;
	out << "===================" << endl;
	out << "Evenimentul" << endl;
	out << "Denumire eveniment: " << e.denumireEveniment << endl;
	out << "Data: " << e.data << endl;
	out << "Ora incepere: " << e.oraIncepere << endl;
	out << "Durata: " << e.durata << endl;
	out << "Numar locuri: " << e.nrLocuri << endl;
	out << endl;
	out << *e.locatie;
	return out;
}
istream& operator>>(istream& in, Eveniment& e) {
	in >> *e.locatie;
	cout << "Introduceti numele evenimentului: "; 
	ws(in);
	string denEvent;
	getline(in, denEvent);
	e.setDenumireEveniment(denEvent.c_str());
	struct tm ora;
	cout << "Introduceti ora incepere (HH:MM): ";
	in >> get_time(&ora, "%H:%M");
	while (in.fail()) {
		in.clear();
		in.ignore(256, '\n');
		cout << "Ora sau format invalid, introduceti din nou (HH:MM): ";
		in >> get_time(&ora, "%H:%M");
	}
	string copieOra;
	if (ora.tm_hour < 10 && ora.tm_min < 10)
		copieOra = "0" + to_string(ora.tm_hour) + ":0" + to_string(ora.tm_min);
	else if (ora.tm_hour < 10 && ora.tm_min >= 10)
		copieOra = "0" + to_string(ora.tm_hour) + ":" + to_string(ora.tm_min);
	else if (ora.tm_hour >= 10 && ora.tm_min < 10)
		copieOra = to_string(ora.tm_hour) + ":0" + to_string(ora.tm_min);
	else
		copieOra = to_string(ora.tm_hour) + ":" + to_string(ora.tm_min);
	e.oraIncepere = copieOra;
	cout << "Introduceti durata evenimentului (HH:MM)" << endl << "Daca aceasta este necunoscuta, introduceti 00:00: ";
	in >> get_time(&ora, "%H:%M");
	while (in.fail()) {
		in.clear();
		in.ignore(256, '\n');
		cout << "Ora sau format invalid, introduceti din nou (HH:MM): ";
		in >> get_time(&ora, "%H:%M");
	}
	if(ora.tm_hour == 0 && ora.tm_min == 0)
		e.durata = "Necunoscuta";
	else {
		if (ora.tm_hour < 10 && ora.tm_min < 10)
			copieOra = "0" + to_string(ora.tm_hour) + ":0" + to_string(ora.tm_min);
		else if (ora.tm_hour < 10 && ora.tm_min >= 10)
			copieOra = "0" + to_string(ora.tm_hour) + ":" + to_string(ora.tm_min);
		else if (ora.tm_hour >= 10 && ora.tm_min < 10)
			copieOra = to_string(ora.tm_hour) + ":0" + to_string(ora.tm_min);
		else
			copieOra = to_string(ora.tm_hour) + ":" + to_string(ora.tm_min);
		e.durata = copieOra;
	}
	cout << "Introduceti numarul de locuri: ";
	in >> e.nrLocuri;
	while (in.fail() || e.nrLocuri <= 0 || e.nrLocuri > e.locatie->getCapacitateTotala()) {
		in.clear();
		in.ignore(256, '\n');
		cout << "Numar invalid, introduceti din nou: ";
		in >> e.nrLocuri;
	}
	return in;
}
bool Eveniment::operator!=(const Eveniment& e) {
	return this->data != e.data;
}
bool Eveniment::operator!() {
	return this->data == "Necunoscuta";
}


