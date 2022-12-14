#include "Locuri.h"
Locuri::Locuri() {
	this->nrRanduri = 0;
	this->nrLocuri = 0;
	this->locuri = nullptr;
}
Locuri::Locuri(int nrRanduri, int nrLocuri)
{
	this->nrRanduri = nrRanduri;
	this->nrLocuri = nrLocuri;
	this->locuri = new bool* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++){
		this->locuri[i] = new bool[nrLocuri];
		for (int j = 0; j < nrLocuri; j++)
			this->locuri[i][j] = false;
	}
}
Locuri::Locuri(const Locuri& l)
{
	this->nrRanduri = l.nrRanduri;
	this->nrLocuri = l.nrLocuri;
	this->locuri = new bool* [l.nrRanduri];
	for (int i = 0; i < l.nrRanduri; i++){
		this->locuri[i] = new bool[l.nrLocuri];
		for (int j = 0; j < l.nrLocuri; j++)
			this->locuri[i][j] = l.locuri[i][j];
	}
}
Locuri& Locuri::operator=(const Locuri& l)
{
	if (this != &l)
	{
		if (this->locuri != nullptr){
			for (int i = 0; i < this->nrRanduri; i++)
				delete[] this->locuri[i];
			delete[] this->locuri;
		}
		this->nrRanduri = l.nrRanduri;
		this->nrLocuri = l.nrLocuri;
		if (this->nrRanduri > 0 && this->nrLocuri > 0) {
			this->locuri = new bool* [l.nrRanduri];
			for (int i = 0; i < l.nrRanduri; i++) {
				this->locuri[i] = new bool[l.nrLocuri];
				for (int j = 0; j < l.nrLocuri; j++)
					this->locuri[i][j] = l.locuri[i][j];
			}
		}
		else this->locuri = nullptr;
	}
	return *this;
}
Locuri::~Locuri()
{
	if (this->locuri != nullptr){
		for (int i = 0; i < this->nrRanduri; i++)
			delete[] this->locuri[i];
		delete[] this->locuri;
	}
}
int Locuri::getNrRanduri() const
{
	return this->nrRanduri;
}
void Locuri::setNrLocuri(int nrLocuri) {
	if (this->nrRanduri > 0) {
		if (nrLocuri > 0 && nrLocuri > this->nrLocuri) {
			bool** copie = new bool* [this->nrRanduri];
			for (int i = 0; i < this->nrRanduri; i++) {
				copie[i] = new bool[this->nrLocuri];
				for (int j = 0; j < this->nrLocuri; j++)
					copie[i][j] = this->locuri[i][j];
			}
			for (int i = 0; i < this->nrRanduri; i++) {
				delete[] this->locuri[i];
			}
			delete[] this->locuri;
			this->nrLocuri = nrLocuri;
			this->locuri = new bool* [this->nrRanduri];
			for (int i = 0; i < this->nrRanduri; i++) {
				this->locuri[i] = new bool[this->nrLocuri];
				for (int j = 0; j < nrLocuri; j++)
					this->locuri[i] = copie[i];
			}
		}
	}
	else cout << "Numar se poate seta numarul de locuri";
}
void Locuri::setNrRanduri(int nrRanduri) {
	if (this->locuri != nullptr) {
		if (this->nrRanduri < nrRanduri) {
			bool** copie = new bool* [this->nrRanduri];
			for (int i = 0; i < this->nrRanduri; i++) {
				copie[i] = new bool[this->nrLocuri];
				for (int j = 0; j < this->nrLocuri; j++)
					copie[i][j] = this->locuri[i][j];
			}
			for (int i = 0; i < this->nrRanduri; i++) {
				delete[] this->locuri[i];
			}
			delete[] this->locuri;
			this->nrRanduri = nrRanduri;
			this->locuri = new bool* [this->nrRanduri];
			for (int i = 0; i < this->nrRanduri; i++) {
				this->locuri[i] = new bool[this->nrLocuri];
				for (int j = 0; j < nrLocuri; j++)
					this->locuri[i] = copie[i];
			}
		}
	}
	else cout << "Nu se poate seta numarul de randuri";
}
int Locuri::getNrLocuri() const
{
	return this->nrLocuri;
}
bool** Locuri::getLocuri() const
{
	bool** copie = new bool* [this->nrRanduri];
	for (int i = 0; i < this->nrRanduri; i++) {
		copie[i] = new bool[this->nrLocuri];
		for (int j = 0; j < this->nrLocuri; j++)
			copie[i][j] = this->locuri[i][j];
	}
	return copie;
}
void Locuri::setLocuri(bool** locuriCopie, int nrRanduri, int nrLocuri) {
	if (locuriCopie != nullptr && nrRanduri > 0 && nrLocuri > 0) {
		if (this->locuri != nullptr) {
			for (int i = 0; i < this->nrRanduri; i++) {
				delete[] this->locuri[i];
			}
			delete[] this->locuri;
		}
		this->nrRanduri = nrRanduri;
		this->nrLocuri = nrLocuri;
		this->locuri = new bool* [this->nrRanduri];
		for (int i = 0; i < this->nrRanduri; i++) {
			this->locuri[i] = new bool[this->nrLocuri];
			for (int j = 0; j < this->nrLocuri; j++)
				this->locuri[i][j] = locuriCopie[i][j];
		}
	}
}
void Locuri::rezervaLoc() {
	cout << "Rezervare loc" << endl;
	cout << "Introduceti randul";
	int rand, loc;
	cin >> rand;
	while (cin.fail() || rand < 0 || rand > this->nrRanduri) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Rand invalid, incercati din nou: ";
		cin >> rand;
	}
	cout << "Introducti locul: ";
	cin >> loc;
	while (cin.fail() || loc < 0 || loc > this->nrLocuri || this->locuri[rand][loc] == true) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Loc indisponibil, incercati din nou: ";
		cin >> loc;
	}
	this->locuri[rand][loc] = true;
}
ostream& operator<<(ostream& out, const Locuri& l)
{
	out << "Numar randuri: " << l.nrRanduri << endl;
	out << "Numar locuri: " << l.nrLocuri << endl;
	out << "Locurile disponibile: " << endl;
	out << "0-disponibil" << endl;
	out << "1-ocupat" << endl;
	for (int i = 0; i < l.nrRanduri; i++) {
		out << "Randul " << i + 1 << ": ";
		for (int j = 0; j < l.nrLocuri; j++)
			out << l.locuri[i][j] << " ";
		out << endl;
	}
	return out;
}
istream& operator>>(istream& in, Locuri& l)
{
	cout << "Introduceti numarul de randuri: ";
	in >> l.nrRanduri;
	while (cin.fail() || l.nrRanduri <= 0) {
		cout << "Numar de randuri invalid, incercati din nou: ";
		cin.clear();
		cin.ignore(256, '\n');
		in >> l.nrRanduri;
	}
	cout << "Introduceti numarul de locuri: ";
	in >> l.nrLocuri;
	while (cin.fail() || l.nrLocuri <= 0) {
		cout << "Numar de locuri invalid, incercati din nou:: ";
		cin.clear();
		cin.ignore(256, '\n');
		in >> l.nrLocuri;
	}
	if (l.locuri != nullptr) {
		for (int i = 0; i < l.nrRanduri; i++)
			delete[] l.locuri[i];
		delete[] l.locuri;
	}
	l.locuri = new bool* [l.nrRanduri];
	for (int i = 0; i < l.nrRanduri; i++)
		l.locuri[i] = new bool[l.nrLocuri];
	for (int i = 0; i < l.nrRanduri; i++)
		for (int j = 0; j < l.nrLocuri; j++)
			l.locuri[i][j] = false;
	return in;
}
int Locuri::numarLocuriTotal() const {
	return this->nrRanduri * this->nrLocuri;
}
bool Locuri::operator>(const Locuri& l) {
	return this->numarLocuriTotal() > l.numarLocuriTotal();
}
void Locuri::operator[](int index) {
	if (index >= 0 && index < this->nrRanduri) {
		cout << "Randul " << index + 1 << ": ";
		for (int j = 0; j < this->nrLocuri; j++)
			cout << this->locuri[index][j] << " ";
	}
	else
		cout << "Randul nu exista";
}
int Locuri::numarLocuriDisponibile() const{
	int suma = 0;
	for(int i=0; i<nrRanduri; i++)
		for (int j = 0; j < nrLocuri; j++)
			if (locuri[i][j] == false)
				suma++;
	return suma;
}
bool Locuri::checkLocuriDisponibile() const {
	return this->numarLocuriDisponibile() > 0;
}
void Locuri::ocupaLoc(int rand, int loc) {
	this->locuri[rand - 1][loc - 1] = true;
}
bool Locuri::checkLocLiber(int rand, int loc) const{
	if (this->locuri[rand - 1][loc - 1] == false)
		return true;
}

