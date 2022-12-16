#include "Bilet.h"
int Bilet::nrBilete = 0;
Bilet::Bilet() :idBilet(++nrBilete)
{
	this->numeClient = "Necunoscut";
	this->prenumeClient = "Necunoscut";
	this->rand = 0;
	this->loc = 0;
	this->UID = nullptr;
	this->dimensiuneUID = 0;
}
Bilet::Bilet(string numeClient, string prenumeClient,const Eveniment& eveniment, int rand, int loc, int nrZona, int idBilet):idBilet(idBilet)
{
	this->numeClient = numeClient;
	this->prenumeClient = prenumeClient;
	this->nrZona = nrZona;
	this->rand = rand;
	this->loc = loc;
	this->eveniment = eveniment;
	nrBilete++;
}
Bilet::Bilet(const Eveniment& eveniment) :idBilet(++nrBilete)
{
	this->numeClient = "Necunoscut";
	this->prenumeClient = "Necunoscut";
	this->rand = 0;
	this->loc = 0;
	this->eveniment = eveniment;
}
Bilet::Bilet(const Bilet& b):idBilet(b.idBilet)
{
	this->numeClient = b.numeClient;
	this->prenumeClient = b.prenumeClient;
	this->eveniment = b.eveniment;
	this->rand = b.rand;
	this->loc = b.loc;
	this->nrZona = b.nrZona;
	this->dimensiuneUID = b.dimensiuneUID;
	this->UID = new int[this->dimensiuneUID];
	for (int i = 0; i < this->dimensiuneUID; i++)
		this->UID[i] = b.UID[i];
}
Bilet& Bilet::operator=(const Bilet& b)
{
	this->numeClient = b.numeClient;
	this->prenumeClient = b.prenumeClient;
	this->eveniment = b.eveniment;
	this->rand = b.rand;
	this->loc = b.loc;
	this->nrZona = b.nrZona;
	if (this->dimensiuneUID > 0 && this->UID != nullptr)
		delete[] this->UID;
	this->dimensiuneUID = b.dimensiuneUID;
	if (this->dimensiuneUID > 0)
	{
		this->UID = new int[this->dimensiuneUID];
		for (int i = 0; i < this->dimensiuneUID; i++)
			this->UID[i] = b.UID[i];
	}
	else
		this->UID = nullptr;
	return *this;
}
ostream& operator<<(ostream& out, const Bilet& bilet) {
	out << "=============================" << endl;
	out << "Biletul cu id-ul: " << bilet.idBilet << endl;
	out <<"Numele: " << bilet.numeClient << " " << bilet.prenumeClient << endl;
	if (bilet.nrZona > 0) {
		cout << "Zona: " << bilet.eveniment.getNumeZona(bilet.nrZona) << endl;
		out << "Pretul biletului: " << bilet.eveniment.getPretBilet(bilet.nrZona) << endl;
	}
	out <<"Rand: " << bilet.rand << " Loc: " << bilet.loc << endl;
	out << "UID: ";
	for (int i = 0; i < bilet.dimensiuneUID; i++)
		out << bilet.UID[i];
	//out << bilet.eveniment << endl;
	return out;
}
int Bilet::getNrBilete() const{
	return nrBilete;
}
istream& operator>>(istream& in, Bilet& bilet) {
	cout << endl;
	cout << "================" << endl;
	cout << "Rezervare bilet" << endl;
	cout << "Introduceti Numele: ";
	in >> bilet.numeClient;
	cout << "Introduceti Prenumele: ";
	in >> bilet.prenumeClient;
	bilet.eveniment.afisareZone();
	cout << "Introduceti zona: ";
	in >> bilet.nrZona;
	while (in.fail() || bilet.nrZona < 1 || bilet.nrZona > bilet.eveniment.getNrZone())
	{
		in.clear();
		in.ignore(256, '\n');
		cout << "Zona invalida, incercati din nou: ";
		in >> bilet.nrZona;
	}
	bilet.eveniment.afisareZona(bilet.nrZona);
	cout << "Introduceti randul: ";
	in >> bilet.rand;
	while (in.fail() || bilet.rand < 1 || bilet.rand > bilet.eveniment.getNrRanduri(bilet.nrZona))
	{
		in.clear();
		in.ignore(256, '\n');
		cout << "Rand invalid, incercati din nou: ";
		in >> bilet.rand;
	}
	cout << "Introduceti locul: ";
	in >> bilet.loc;
	while (in.fail() || bilet.loc < 1 || bilet.loc > bilet.eveniment.getNrLocuri(bilet.nrZona))
	{
		in.clear();
		in.ignore(256, '\n');
		cout << "Loc invalid, incercati din nou: ";
		in >> bilet.loc;
	}
	while (!bilet.eveniment.checkLocLiber(bilet.nrZona, bilet.rand, bilet.loc)) {
		cout << "Locul este ocupat" << endl;
		cout << "Introduceti randul: ";
		in >> bilet.rand;
		while (in.fail() || bilet.rand < 1 || bilet.rand > bilet.eveniment.getNrRanduri(bilet.nrZona))
		{
			in.clear();
			in.ignore(256, '\n');
			cout << "Introduceti un rand valid: ";
			in >> bilet.rand;
		}
		cout << "Introduceti locul: ";
		in >> bilet.loc;
		while (in.fail() || bilet.loc < 1 || bilet.loc > bilet.eveniment.getNrLocuri(bilet.nrZona));
		{
			in.clear();
			in.ignore(256, '\n');
			cout << "Introduceti un loc valid: ";
			in >> bilet.loc;
		}
	}
	bilet.eveniment.rezervareLoc(bilet.nrZona, bilet.rand, bilet.loc);
	bilet.dimensiuneUID = bilet.prenumeClient.length();
	bilet.UID = new int[bilet.dimensiuneUID + 2];
	if (bilet.prenumeClient.length() < 5) {
		bilet.dimensiuneUID = bilet.prenumeClient.length();
		bilet.UID = new int[bilet.dimensiuneUID + 2];
		bilet.UID[0] = bilet.idBilet;
		for (int i = 0; i < bilet.dimensiuneUID; i++)
			bilet.UID[i + 1] = (int)bilet.prenumeClient[i];
		bilet.UID[bilet.dimensiuneUID + 1] = bilet.eveniment.getIdEveniment();
	}
	else {
		bilet.dimensiuneUID = 4;
		bilet.UID = new int[6];
		bilet.UID[0] = bilet.idBilet;
		for (int i = 0; i < 4; i++)
			bilet.UID[i + 1] = (int)bilet.prenumeClient[i];
		bilet.UID[5] = bilet.eveniment.getIdEveniment();
	}
	return in;
}
int Bilet::getLoc() const {
	return this->loc;
}
int Bilet::getRand() const {
	return this->rand;
}
int Bilet::getNrZona() const {
	return this->nrZona;
}
string Bilet::getNumeClient() const {
	return this->numeClient;
}
string Bilet::getPrenumeClient() const {
	return this->prenumeClient;
}
float Bilet::operator+(const Bilet& bilet) {
	return this->eveniment.getPretBilet(this->nrZona) + bilet.eveniment.getPretBilet(bilet.nrZona);
}
float operator*(int i, const Bilet& bilet) {
	return i * bilet.eveniment.getPretBilet(bilet.nrZona);
}
Bilet::~Bilet() {
	if (this->UID != nullptr)
		delete[] this->UID;
}
int Bilet::getdimensiuneUID() const {
	return this->dimensiuneUID;
}
int* Bilet::getUID() const {
	int* copie = new int[this->dimensiuneUID];
	for (int i = 0; i < this->dimensiuneUID; i++)
		copie[i] = this->UID[i];
	return copie;
}


