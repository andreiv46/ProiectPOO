#include "Locatie.h"
Locatie::Locatie() {
	this->oras = "Necunoscut";
	this->strada = "Necunoscuta";
	this->capacitateTotala = 0;
	this->nrMaximLocuri = 0;
	this->denumireLocatie = "Necunoscut";
}
Locatie::Locatie(string oras, string strada, int capacitateTotala, int nrMaximLocuri, string denumireLocatie):Locatie() {
	if (oras.length() > 0)
		this->oras = oras;
	if (strada.length() > 0)
		this->strada = strada;
	if (capacitateTotala > 0)
		this->capacitateTotala = capacitateTotala;
	if (nrMaximLocuri > 0 && nrMaximLocuri <= capacitateTotala)
		this->nrMaximLocuri = nrMaximLocuri;
	if (denumireLocatie.length() > 0)
		this->denumireLocatie = denumireLocatie;
}
Locatie::Locatie(const Locatie& l) {
	this->oras = l.oras;
	this->strada = l.strada;
	this->capacitateTotala = l.capacitateTotala;
	this->nrMaximLocuri = l.nrMaximLocuri;
	this->denumireLocatie = l.denumireLocatie;
}
string Locatie::getOras() {
    return this->oras;
}
string Locatie::getStrada() {
    return this->strada;
}
int Locatie::getNrMaximLocuri() {
	return this->nrMaximLocuri;
}
string Locatie::getDenumireLocatie() {
    return this->denumireLocatie;
}
int Locatie::getCapacitateTotala() {
	return this->capacitateTotala;
}
void Locatie::setCapacitateTotala(int capacitateaTotala) {
	this->capacitateTotala = capacitateaTotala;
}
void Locatie::setOras(string oras) {
	if (oras.length() > 0)
		this->oras = oras;
}
void Locatie::setStrada(string strada) {
	if (strada.length() > 0)
		this->strada = strada;
}
void Locatie::setNrMaximLocuri(int nrMaximLocuri) {
	if (nrMaximLocuri > 0)
		this->nrMaximLocuri = nrMaximLocuri;
}
void Locatie::setDenumireLocatie(string denumireLocatie) {
	if (denumireLocatie.length() > 0)
		this->denumireLocatie = denumireLocatie;
}
float Locatie::rataOcupareLocatie() {
	if (capacitateTotala > 0)
		return ((float)this->nrMaximLocuri / this->capacitateTotala) * 100;
}
ostream& operator<<(ostream& out,const Locatie &l) {
	out << "Locatia evenimentului" << endl;
	out << "Orasul: " << l.oras << endl;
	out << "Strada: " << l.strada << endl;
	out << "Locatia: " << l.denumireLocatie << endl;
	out << "Capacitatea locatiei: " << l.capacitateTotala << endl;
	out << "Numar locuri eveniment: " << l.nrMaximLocuri << endl;
	return out;
}
istream& operator>>(istream& in, Locatie& l)
{
	cout << "Introduceti orasul: ";
	in >> l.oras;
	cout << "Introduceti strada: ";
	ws(in);
	getline(in, l.strada);
	cout << "Introduceti denumirea locatiei: ";
	ws(in);
	getline(in, l.denumireLocatie);
	cout << "Introduceti capacitatea locatiei: ";
	in >> l.capacitateTotala;
	l.nrMaximLocuri = 0;
	cout << "Introduceti numarul maxim de locuri: ";
	in >> l.nrMaximLocuri;
	if (l.nrMaximLocuri > l.capacitateTotala)
		while (l.nrMaximLocuri > l.capacitateTotala) {
			cout << "Depaseste capacitatea totala! ";
			cout << endl << "Introduceti numarul maxim de locuri: ";
			in >> l.nrMaximLocuri;
		}
	return in;
}
Locatie& Locatie::operator+=(int nrLocuri) {
	if (this->nrMaximLocuri + nrLocuri > this->capacitateTotala)
		cout << "Depaseste capacitatea locatiei!";
	else nrMaximLocuri += nrLocuri;
	return *this;
}
bool Locatie::operator<(Locatie& l)
{
	return this->capacitateTotala-l.getCapacitateTotala();
}





