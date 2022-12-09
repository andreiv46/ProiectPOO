#include "Locatie.h"
Locatie::Locatie() {
	this->oras = "Necunoscut";
	this->strada = "Necunoscuta";
	this->nrMaximLocuri = 0;
	this->denumireLocatie = "Necunoscut";
}
Locatie::Locatie(string oras, string strada, int nrMaximLocuri, string denumireLocatie):Locatie() {
	if (oras.length() > 0)
		this->oras = oras;
	if (strada.length() > 0)
		this->strada = strada;
	if (nrMaximLocuri > 0)
		this->nrMaximLocuri = nrMaximLocuri;
	if (denumireLocatie.length() > 0)
		this->denumireLocatie = denumireLocatie;
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
Locatie::Locatie(const Locatie& l) {
	this->oras = l.oras;
	this->strada = l.strada;
	this->nrMaximLocuri = l.nrMaximLocuri;
	this->denumireLocatie = l.denumireLocatie;
}
ostream& operator<<(ostream& out,const Locatie &l) {
	out << "Locatia evenimentului" << endl;
	out << "Orasul: " << l.oras << endl;
	out << "Strada: " << l.strada << endl;
	out << "Locatia: " << l.denumireLocatie << endl;
	out << "Capacitatea: " << l.nrMaximLocuri << endl;
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
	cout << "Introduceti numarul maxim de locuri: ";
	in >> l.nrMaximLocuri;
	return in;
}




