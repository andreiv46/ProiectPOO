#include "Eveniment.h"
int Eveniment::nrEvenimente = 0;
Eveniment::Eveniment() {
	this->denumireEveniment = new char[strlen("Necunoscut") + 1];
	strcpy_s(denumireEveniment, strlen("Necunoscut") + 1, "Necunoscut");
	this->data = "Necunoscuta";
	this->oraIncepere = "Necunoscuta";
	this->durata = "Necunoscuta";
	this->idEveniment = 0;
}
Eveniment::Eveniment(string data):Eveniment() {
	this->data = data;
	this->idEveniment = ++nrEvenimente;
}
Eveniment::Eveniment(const char* denumireEveniment, string data, string oraIncepere, string durata, const Locatie& locatie, int idEveniment) {
	this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
	strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
	this->data = data;
	this->oraIncepere = oraIncepere;
	this->durata = durata;
	this->locatie = locatie;
	this->idEveniment = idEveniment;
	nrEvenimente++;
}
Eveniment::Eveniment(const Eveniment& e) {
	this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
	strcpy_s(this->denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
	this->data = e.data;
	this->oraIncepere = e.oraIncepere;
	this->durata = "Necunoscuta";
	this->locatie = e.locatie;
	this->idEveniment = e.idEveniment;
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
void Eveniment::setData(string data) {
	if(data.length() > 0)
		this->data = data;
}
string Eveniment::getOraIncepere() const {
	return this->oraIncepere;
}
Eveniment& Eveniment::operator=(const Eveniment& e) {
	if (this != &e) {
		if (this->denumireEveniment != NULL)
			delete[] this->denumireEveniment;
		this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
		this->data = e.data;
		this->oraIncepere = e.oraIncepere;
		this->durata = e.durata;
		this->locatie = e.locatie;
		this->idEveniment = e.idEveniment;
	}
	return *this;
}
Eveniment::~Eveniment() {
	if (this->denumireEveniment != nullptr) {
		delete[] this->denumireEveniment;
		this->denumireEveniment = nullptr;
	}
	this->nrEvenimente--;
}
string Eveniment::getDurata() const {
	return this->durata;
}
void Eveniment::setDurata(string durata) {
	this->durata = durata;
}
Locatie Eveniment::getLocatie() const {
	return this->locatie;
}
void Eveniment::setLocatie(const Locatie& locatie) {
	this->locatie = locatie;
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
	cout << endl;
	out << "Locatie" << endl;
	out << e.locatie;
	return out;
}
istream& operator>>(istream& in, Eveniment& e) {
	in >> e.locatie;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	struct tm data;
	cout << "Introduceti data evenimentului (dd/mm/yyyy): ";
	in >> get_time(&data, "%d/%m/%Y");
	while (in.fail() || data.tm_year + 1900 < year || data.tm_year + 1900 == year && data.tm_mon + 1 < month || data.tm_year + 1900 == year && data.tm_mon + 1 == month && data.tm_mday < day)
	{
		in.clear();
		in.ignore(256, '\n');
		cout << "Data este invalida, incercati din nou (dd/mm/yyyy): ";
		in >> get_time(&data, "%d/%m/%Y");
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
	e.data = dataEveniment;
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
	e.idEveniment = ++e.nrEvenimente;
	return in;
}
bool Eveniment::operator!=(const Eveniment& e) {
	return this->data != e.data;
}
bool Eveniment::operator!() {
	return this->data == "Necunoscuta";
}
float Eveniment::getPreturiEveniment(int index) {
	if (index > 0 && index <= this->locatie.getNrZone())
		return this->locatie.zone[index - 1].getPretBilet();
	else
		return -1;
}
void Eveniment::afisareZone() {
	for (int i = 0; i < locatie.nrZone; i++) {
		cout << locatie.zone[i];
	}
}
void Eveniment::rezervareLoc(int index, int rand, int loc) {
	this->locatie.zone[index - 1].rezervaLocuri(rand, loc);
}
int Eveniment::getNrZone() const {
	return this->locatie.nrZone;
}
void Eveniment::afisareZona(int index) const{
	cout << this->locatie.zone[index - 1];
}
int Eveniment::getNrRanduri(int index) const {
	return this->locatie.zone[index - 1].getNrRanduri();
}
int Eveniment::getNrLocuri(int index) const {
	return this->locatie.zone[index - 1].getNrLocuri();
}
bool Eveniment::checkLocLiber(int index, int rand, int loc) const {
	return this->locatie.zone[index - 1].checkLocLiber(rand, loc);
}
string Eveniment::getNumeZona(int index) const {
	return this->locatie.zone[index - 1].getNumeZona();
}
float Eveniment::getPretBilet(int index) const {
	return this->locatie.zone[index - 1].getPretBilet();
}
int Eveniment::getIdEveniment() const {
	return this->idEveniment;
}
int Eveniment::getNrEvenimente(){
	return nrEvenimente;
}
string Eveniment::getCelMaiMicPret(const Eveniment* evenimente, int nrEvenimente) {
	if (evenimente != nullptr && nrEvenimente > 0 && evenimente->locatie.getNrZone() > 0) {
		float celMaiMicPret = evenimente[0].locatie.zone[0].getPretBilet();
		string denumireEveniment = evenimente[0].getDenumireEveniment();
		for (int i = 0; i < nrEvenimente; i++) {
			for (int j = 0; j < evenimente[i].locatie.getNrZone(); j++) {
				if (evenimente[i].locatie.zone[j].getPretBilet() < celMaiMicPret) {
					celMaiMicPret = evenimente[i].locatie.zone[j].getPretBilet();
					denumireEveniment = evenimente[i].getDenumireEveniment();
				}
			}
		}
		return denumireEveniment;
	}
	else
		return "Nu exista evenimente";
}
void Eveniment::setIdEveniment(int idEveniment) {
	this->idEveniment = idEveniment;
}
void Eveniment::adaugaEvenimentInFisierText(string numeFisier) const{
	ofstream fout(numeFisier, ios::app);
	fout << this->idEveniment << endl;
	fout << this->denumireEveniment << endl;
	fout << this->data << endl;
	fout << this->oraIncepere << endl;
	fout << this->durata << endl;
	fout << this->locatie.getOras() << endl;
	fout << this->locatie.getStrada() << endl;
	fout << this->locatie.getNrZone() << endl;
	fout << this->locatie.getCapacitateTotala() << endl;
	for (int i = 0; i < this->locatie.getNrZone(); i++) {
		fout << this->locatie.zone[i].getNumeZona() << endl;
		fout << this->locatie.zone[i].getNrRanduri() << endl;
		fout << this->locatie.zone[i].getNrLocuri() << endl;
		fout << this->locatie.zone[i].getPretBilet() << endl;
	}
	fout << this->locatie.getDenumireLocatie() << endl;
	fout.close();
}


