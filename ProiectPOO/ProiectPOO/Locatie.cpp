#include "Locatie.h"
Locatie::Locatie() {
	this->oras = "Necunoscut";
	this->strada = "Necunoscuta";
	this->capacitateTotala = 0;
	this->denumireLocatie = "Necunoscut";
	this->nrZone = 0;
	this->zone = nullptr;
}
Locatie::Locatie(string oras, string strada, int capacitateTotala, string denumireLocatie, const Zona* zone, int nrZone):Locatie() {
		this->oras = oras;
		this->strada = strada;
		this->capacitateTotala = capacitateTotala;
		this->denumireLocatie = denumireLocatie;
	if (nrZone > 0) {
		this->nrZone = nrZone;
		this->zone = new Zona[nrZone];
		for (int i = 0; i < nrZone; i++)
			this->zone[i] = zone[i];
	}
}
Locatie::Locatie(const Locatie& l) {
	this->oras = l.oras;
	this->strada = l.strada;
	this->capacitateTotala = l.capacitateTotala;
	this->denumireLocatie = l.denumireLocatie;
	this->nrZone = l.nrZone;
	if (l.nrZone > 0) {
		this->zone = new Zona[l.nrZone];
		for (int i = 0; i < l.nrZone; i++)
			this->zone[i] = l.zone[i];
	}
	else this->zone = nullptr;
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
Zona* Locatie::getZone() const {
	if (this->nrZone > 0) {
		Zona* copie = new Zona[this->nrZone];
		for (int i = 0; i < this->nrZone; i++)
			copie[i] = this->zone[i];
		return copie;
	}
	else return nullptr;
}
int Locatie::getNrZone() const {
	return this->nrZone;
}
void Locatie::setNrZone(int nrZone) {
	if (nrZone > this->nrZone) {
		Zona* copie = new Zona[nrZone];
		for (int i = 0; i < this->nrZone; i++)
			copie[i] = this->zone[i];
		for (int i = this->nrZone; i < nrZone; i++)
			copie[i] = Zona();
	}
	else cout << "Nu se poate seta numarul de zone";
}
void Locatie::setZone(const Zona* zone, int nrZone) {
	if (nrZone > 0) {
		if (this->zone != nullptr)
			delete[] this->zone;
		this->nrZone = nrZone;
		this->zone = new Zona[nrZone];
		for (int i = 0; i < nrZone; i++)
			this->zone[i] = zone[i];
	}
	else cout << "Nu se poate seta zona";
}
void Locatie::setOras(string oras) {
	if (oras.length() > 0)
		this->oras = oras;
}
void Locatie::setStrada(string strada) {
	if (strada.length() > 0)
		this->strada = strada;
}
void Locatie::setDenumireLocatie(string denumireLocatie) {
	if (denumireLocatie.length() > 0)
		this->denumireLocatie = denumireLocatie;
}
ostream& operator<<(ostream& out,const Locatie &l) {
	out << "======================" << endl;
	out << "Locatia evenimentului" << endl;
	out << "Orasul: " << l.oras << endl;
	out << "Strada: " << l.strada << endl;
	out << "Locatia: " << l.denumireLocatie << endl;
	out << "Capacitatea locatiei: " << l.capacitateTotala << endl;
	for (int i = 0; i < l.nrZone; i++) {
		out << endl;
		cout << "Zona " << i + 1 << endl;
		out << l.zone[i];
	}
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
	cout << "Introduceti numarul de zone: ";
	in >> l.nrZone;
	while (in.fail() || l.nrZone <= 0)
	{
		in.clear();
		in.ignore(256, '\n');
		cout << "Numar invalid, introduceti din nou: ";
		in >> l.nrZone;
	}
	l.zone = new Zona[l.nrZone];
	for (int i = 0; i < l.nrZone; i++) {
		cout << "Zona " << i + 1 << endl;
		in >> l.zone[i];
	}
	int suma = 0;
	for (int i = 0; i < l.nrZone; i++) {
		suma += l.zone[i].numarLocuriZona();
	}
	while (suma > l.capacitateTotala) {
		delete[] l.zone;
		cout << "Numarul de locuri este mai mare decat capacitatea locatiei, introduceti din nou numarul de zone: ";
		in >> l.nrZone;
		while (in.fail() || l.nrZone <= 0)
		{
			in.clear();
			in.ignore(256, '\n');
			cout << "Numar invalid, introduceti din nou: ";
			in >> l.nrZone;
		}
		l.zone = new Zona[l.nrZone];
		for (int i = 0; i < l.nrZone; i++) {
			cout << "Zona " << i + 1 << endl;
			in >> l.zone[i];
		}
		suma = 0;
		for (int i = 0; i < l.nrZone; i++) {
			suma += l.zone[i].numarLocuriZona();
		}
	}
	return in;
}
bool Locatie::operator<(Locatie& l)
{
	return this->capacitateTotala-l.getCapacitateTotala();
}
Locatie::~Locatie() {
	if (this->zone != nullptr)
		delete[] this->zone;
}
Locatie& Locatie::operator=(const Locatie& l) {
	if (this != &l) {
		this->oras = l.oras;
		this->strada = l.strada;
		this->capacitateTotala = l.capacitateTotala;
		this->denumireLocatie = l.denumireLocatie;
		if (this->zone != nullptr) {
			delete[] this->zone;
			this->nrZone = l.nrZone;
			if (l.nrZone > 0) {
				this->zone = new Zona[l.nrZone];
				for (int i = 0; i < l.nrZone; i++)
					this->zone[i] = l.zone[i];
			}
			else this->zone = nullptr;
		}
		else {
			this->nrZone = l.nrZone;
			if (l.nrZone > 0) {
				this->zone = new Zona[l.nrZone];
				for (int i = 0; i < l.nrZone; i++)
					this->zone[i] = l.zone[i];
			}
			else this->zone = nullptr;
		}
	}
	return *this;
}
bool Locatie::checkCapacitate() {
	int suma = 0;
	for (int i = 0; i < this->nrZone; i++)
		suma += this->zone[i].numarLocuriZona();
	if (suma > this->capacitateTotala)
		return false;
	return true;
}
int Locatie::NumardeLocuriLocatie() const{
	int suma = 0;
	for (int i = 0; i < this->nrZone; i++)
		suma += this->zone[i].numarLocuriZona();
	return suma;
}
int Locatie::getNrLocuri(int index) const {
	return this->zone[index - 1].getNrLocuri();
}
int Locatie::getNrRanduri(int index) const {
	return this->zone[index - 1].getNrRanduri();
}
float operator/(int i, Locatie& l) {
	return (float)i / l.NumardeLocuriLocatie();
}
float Locatie::rataOcupareLocatie() const{
	return (float)this->NumardeLocuriLocatie() / this->capacitateTotala;
}




