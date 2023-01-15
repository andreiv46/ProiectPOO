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
	this->pretBilet = 0;
}
Bilet::Bilet(string numeClient, string prenumeClient, int rand, int loc, int nrZona, int dimensiuneUID, int* UID, int idBilet, float pretBilet) :idBilet(idBilet)
{
	this->numeClient = numeClient;
	this->prenumeClient = prenumeClient;
	this->rand = rand;
	this->loc = loc;
	this->pretBilet = pretBilet;
	this->nrZona = nrZona;
	this->dimensiuneUID = dimensiuneUID;
	this->UID = new int[dimensiuneUID];
	for (int i = 0; i < dimensiuneUID; i++) {
		this->UID[i] = UID[i];
	}
	this->nrBilete++;
}
Bilet::Bilet(string numeClient, string prenumeClient, int rand, int loc, int nrZona, int idEveniment, float pretBilet):idBilet(++nrBilete)
{
	this->numeClient = numeClient;
	this->prenumeClient = prenumeClient;
	this->nrZona = nrZona;
	this->rand = rand;
	this->pretBilet = pretBilet;
	this->loc = loc;
	if (this->prenumeClient.length() < 5 && this->prenumeClient.length() > 0) {
		this->dimensiuneUID = this->prenumeClient.length() + 2;
		this->UID = new int[this->dimensiuneUID];
		this->UID[0] = this->idBilet;
		for (int i = 0; i < this->dimensiuneUID - 2; i++)
			this->UID[i + 1] = (int)this->prenumeClient[i];
		this->UID[this->dimensiuneUID - 1] = idEveniment;
	}
	else if (this->prenumeClient.length() > 5 && this->prenumeClient.length() > 0) {
		this->dimensiuneUID = 6;
		this->UID = new int[6];
		this->UID[0] = this->idBilet;
		for (int i = 0; i < 4; i++)
			this->UID[i + 1] = (int)this->prenumeClient[i];
		this->UID[5] = idEveniment;
	}
}
Bilet::Bilet(const Bilet& b):idBilet(b.idBilet)
{
	this->numeClient = b.numeClient;
	this->prenumeClient = b.prenumeClient;
	this->rand = b.rand;
	this->loc = b.loc;
	this->pretBilet = b.pretBilet;
	this->nrZona = b.nrZona;
	this->dimensiuneUID = b.dimensiuneUID;
	this->UID = new int[this->dimensiuneUID];
	for (int i = 0; i < this->dimensiuneUID; i++)
		this->UID[i] = b.UID[i];
	this->nrBilete++;
}
Bilet& Bilet::operator=(const Bilet& b)
{
	this->numeClient = b.numeClient;
	this->prenumeClient = b.prenumeClient;
	this->pretBilet = b.pretBilet;
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
	out << endl;
	out << "=============================" << endl;
	out << "Biletul cu id-ul: " << bilet.idBilet << endl;
	out <<"Numele: " << bilet.numeClient << " " << bilet.prenumeClient << endl;
	out <<"Rand: " << bilet.rand << " Loc: " << bilet.loc << endl;
	out << "UID: ";
	for (int i = 0; i < bilet.dimensiuneUID; i++)
		out << bilet.UID[i];
	out << endl;
	out << "Pret: " << bilet.pretBilet << " lei" << endl;
	return out;
}
int Bilet::getNrBilete() {
	return nrBilete;
}
//istream& operator>>(istream& in, Bilet& bilet) {
//	cout << endl;
//	cout << "================" << endl; 
//	cout << "Rezervare bilet" << endl;
//	cout << "Introduceti Numele: ";
//	in >> bilet.numeClient;
//	cout << "Introduceti Prenumele: ";
//	in >> bilet.prenumeClient;
//	bilet.eveniment->afisareZone();
//	cout << "Introduceti zona: ";
//	in >> bilet.nrZona;
//	while (in.fail() || bilet.nrZona < 1 || bilet.nrZona > bilet.eveniment->getNrZone())
//	{
//		in.clear();
//		in.ignore(256, '\n');
//		cout << "Zona invalida, incercati din nou: ";
//		in >> bilet.nrZona;
//	}
//	bilet.eveniment->afisareZona(bilet.nrZona);
//	cout << "Introduceti randul: ";
//	in >> bilet.rand;
//	while (in.fail() || bilet.rand < 1 || bilet.rand > bilet.eveniment->getNrRanduri(bilet.nrZona))
//	{
//		in.clear();
//		in.ignore(256, '\n');
//		cout << "Rand invalid, incercati din nou: ";
//		in >> bilet.rand;
//	}
//	cout << "Introduceti locul: ";
//	in >> bilet.loc;
//	while (in.fail() || bilet.loc < 1 || bilet.loc > bilet.eveniment->getNrLocuri(bilet.nrZona)) 
//	{
//		in.clear();
//		in.ignore(256, '\n');
//		cout << "Loc invalid, incercati din nou: ";
//		in >> bilet.loc;
//	}
//	while (!bilet.eveniment->checkLocLiber(bilet.nrZona, bilet.rand, bilet.loc)) {
//		cout << "Locul este ocupat" << endl;
//		cout << "Introduceti randul: ";
//		in >> bilet.rand;
//		while (in.fail() || bilet.rand < 1 || bilet.rand > bilet.eveniment->getNrRanduri(bilet.nrZona))
//		{
//			in.clear();
//			in.ignore(256, '\n');
//			cout << "Introduceti un rand valid: ";
//			in >> bilet.rand;
//		}
//		cout << "Introduceti locul: ";
//		in >> bilet.loc;
//		while (in.fail() || bilet.loc < 1 || bilet.loc > bilet.eveniment->getNrLocuri(bilet.nrZona));
//		{
//			in.clear();
//			in.ignore(256, '\n');
//			cout << "Introduceti un loc valid: ";
//			in >> bilet.loc;
//		}
//	}
//	bilet.eveniment->rezervareLoc(bilet.nrZona, bilet.rand, bilet.loc);
//	if (bilet.prenumeClient.length() < 5 && bilet.prenumeClient.length() > 0) {
//		bilet.dimensiuneUID = bilet.prenumeClient.length() + 2;
//		bilet.UID = new int[bilet.dimensiuneUID];
//		bilet.UID[0] = bilet.idBilet;
//		for (int i = 0; i < bilet.dimensiuneUID - 2; i++)
//			bilet.UID[i + 1] = (int)bilet.prenumeClient[i];
//		bilet.UID[bilet.dimensiuneUID - 1] = bilet.eveniment->getIdEveniment();
//	}
//	else if(bilet.prenumeClient.length() > 5 && bilet.prenumeClient.length() > 0) {
//		bilet.dimensiuneUID = 6;
//		bilet.UID = new int[6];
//		bilet.UID[0] = bilet.idBilet;
//		for (int i = 0; i < 4; i++)
//			bilet.UID[i + 1] = (int)bilet.prenumeClient[i];
//		bilet.UID[5] = bilet.eveniment->getIdEveniment();
//	}
//	return in;
//}
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
//float operator*(int i, const Bilet& bilet) {
//	return i * bilet.eveniment.getPretBilet(bilet.nrZona);
//}
Bilet::~Bilet() {
	if (this->UID != nullptr) {
		delete[] this->UID;
		this->UID = nullptr;
	}
	this->nrBilete--;
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
float Bilet::operator+(const Bilet& bilet) {
	return this->pretBilet + bilet.pretBilet;
}
bool Bilet::verificaUID(string UID) const{
	if (UID.length() > 0) {
		string copieUID;
		for (int i = 0; i < this->dimensiuneUID; i++)
			copieUID += to_string(this->UID[i]);
		if (copieUID == UID)
			return true;
		return false;
	}
	return false;
}
void Bilet::setNumeClient(string numeClient) {
	this->numeClient = numeClient;
}
void Bilet::setPrenumeClient(string prenumeClient) {
	this->prenumeClient = prenumeClient;
}
int Bilet::getEvenimentID() const {
	if (this->dimensiuneUID > 0)
		return this->UID[this->dimensiuneUID - 1];
	return -1;
}
string Bilet::getUIDstring() const {
	string UID;
	for (int i = 0; i < this->dimensiuneUID; i++)
		UID += to_string(this->UID[i]);
	return UID;
}
float Bilet::getPretBilet() const {
	return this->pretBilet;
}







