#include "Locatie.h"
Locatie::Locatie() {
	this->oras = "Necunoscut";
	this->strada = "Necunoscuta";
	this->capacitateTotala = 0;
	this->denumireLocatie = "Necunoscut";
}
Locatie::Locatie(string oras, string strada, int capacitateTotala, int nrMaximLocuri, string denumireLocatie):Locatie() {
	if (oras.length() > 0)
		this->oras = oras;
	if (strada.length() > 0)
		this->strada = strada;
	if (capacitateTotala > 0)
		this->capacitateTotala = capacitateTotala;
	if (denumireLocatie.length() > 0)
		this->denumireLocatie = denumireLocatie;
}
Locatie::Locatie(const Locatie& l) {
	this->oras = l.oras;
	this->strada = l.strada;
	this->capacitateTotala = l.capacitateTotala;
	this->denumireLocatie = l.denumireLocatie;
}
string Locatie::getOras() const{
    return this->oras;
}
string Locatie::getStrada() const{
    return this->strada;
}
string Locatie::getDenumireLocatie() const{
    return this->denumireLocatie;
}
int Locatie::getCapacitateTotala() const{
	return this->capacitateTotala;
}
//void Locatie::setCapacitateTotala(int capacitateaTotala) {
//	if (capacitateaTotala > 0) {
//		if (capacitateaTotala < this->nrMaximLocuri) {
//			cout << "Capacitatea este mai mica decat numarul de locuri disponibile" << endl;
//		}
//		else {
//			this->capacitateTotala = capacitateaTotala;
//		}
//	}
//}
void Locatie::setOras(string oras) {
	if (oras.length() > 0)
		this->oras = oras;
}
void Locatie::setStrada(string strada) {
	if (strada.length() > 0)
		this->strada = strada;
}
//void Locatie::setNrMaximLocuri(int nrMaximLocuri) {
//	if (nrMaximLocuri > 0)
//		this->nrMaximLocuri = nrMaximLocuri;
//}
void Locatie::setDenumireLocatie(string denumireLocatie) {
	if (denumireLocatie.length() > 0)
		this->denumireLocatie = denumireLocatie;
}
//float Locatie::rataOcupareLocatie() {
//	if (capacitateTotala > 0)
//		return ((float)this->nrMaximLocuri / this->capacitateTotala) * 100;
//}
ostream& operator<<(ostream& out,const Locatie &l) {
	out << "======================" << endl;
	out << "Locatia evenimentului" << endl;
	out << "Orasul: " << l.oras << endl;
	out << "Strada: " << l.strada << endl;
	out << "Locatia: " << l.denumireLocatie << endl;
	out << "Capacitatea locatiei: " << l.capacitateTotala << endl;
	return out;
}
istream& operator>>(istream& in, Locatie& l)
{
	cout << "Introduceti orasul: ";
	ws(in);
	getline(in, l.oras);
	cout << "Introduceti strada: ";
	ws(in);
	getline(in, l.strada);
	cout << "Introduceti denumirea locatiei: ";
	ws(in);
	getline(in, l.denumireLocatie);
	cout << "Introduceti capacitatea locatiei: ";
	in >> l.capacitateTotala;
	while (in.fail() || l.capacitateTotala <= 0)
	{
		in.clear();
		in.ignore(256, '\n');
		cout << "Numar invalid, introduceti din nou: ";
		in >> l.capacitateTotala;
	}
	return in;
}
//Locatie& Locatie::operator+=(int nrLocuri) {
//	if (this->nrMaximLocuri + nrLocuri > this->capacitateTotala)
//		cout << "Depaseste capacitatea locatiei!";
//	else nrMaximLocuri += nrLocuri;
//	return *this;
//}
bool Locatie::operator<(Locatie& l)
{
	return this->capacitateTotala-l.getCapacitateTotala();
}





