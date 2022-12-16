#include "Zona.h"
Zona::Zona() {
	this->numeZona = "Necunoscuta";
	this->pretBilet = 0;
}
Zona::Zona(string numeZona, float pretBilet, const Locuri& locuri) :Zona() {
	if (numeZona.length() > 0)
		this->numeZona = numeZona;
	if (pretBilet > 0)
		this->pretBilet = pretBilet;
	this->locuri = locuri;
}
Zona::Zona(const Locuri& locuri) :Zona() {
	this->locuri = locuri;
}
Zona::Zona(const Zona& z) {
	this->numeZona = z.numeZona;
	this->pretBilet = z.pretBilet;
	this->locuri = z.locuri;
}
string Zona::getNumeZona() const {
	return this->numeZona;
}
float Zona::getPretBilet() const {
	return this->pretBilet;
}
Locuri Zona::getLocuri() const {
	return this->locuri;
}
void Zona::setNumeZona(string numeZona) {
	if (numeZona.length() > 0)
		this->numeZona = numeZona;
}
void Zona::setPretBilet(float pretBilet) {
	if (pretBilet > 0)
		this->pretBilet = round(pretBilet * 100) / 100;
}
void Zona::setLocuri(const Locuri& locuri) {
	this->locuri = locuri;
}
Zona& Zona::operator=(const Zona& z) {
	this->numeZona = z.numeZona;
	this->pretBilet = z.pretBilet;
	this->locuri = z.locuri;
	return *this;
}
ostream& operator<<(ostream& out, const Zona& z) {
	out << "Nume zona: " << z.numeZona << endl;
	out << "Pretul biletului: " << z.pretBilet << endl;
	out << "Locuri" << endl;
	out << z.locuri;
	return out;
}
istream& operator>>(istream& in, Zona& z) {
	cout << "Introduceti numele zonei: ";
	ws(in);
	getline(in, z.numeZona);
	cout << "Introduceti pretul biletului: ";
	float pret;
	in >> pret;
	while (in.fail() || pret <= 0) {
		in.clear();
		in.ignore(265, '\n');
		cout << "Pret invalid, incercati din nou: ";
		in >> pret;
	}
	z.pretBilet = round(pret * 100) / 100;
	in >> z.locuri;
	return in;
}
Zona& Zona::operator++() {
	float copie = this->pretBilet;
	copie += 0.1 * copie;
	this->pretBilet = round(copie * 100) / 100;
	return *this;
}
int Zona::numarLocuriZona() {
	return this->locuri.numarLocuriTotal();
}
void Zona::rezervaLocuri(int rand, int loc) {
	this->locuri.ocupaLoc(rand, loc);
}
int Zona::getNrLocuri() const{
	return this->locuri.nrLocuri;
}
int Zona::getNrRanduri() const{
	return this->locuri.nrRanduri;
}
bool Zona::checkLocLiber(int rand, int loc) const {
	return this->locuri.checkLocLiber(rand, loc);
}
Zona& Zona::operator--() {
	float copie = this->pretBilet;
	copie -= 0.1 * copie;
	this->pretBilet = round(copie * 100) / 100;
	return *this;
}
Zona::operator int() {
	return this->pretBilet;
}


