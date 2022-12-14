#include "Bilet.h"
int Bilet::nrBilete = 0;
Bilet::Bilet() :idBilet(++nrBilete)
{
	this->numeClient = "Necunoscut";
	this->prenumeClient = "Necunoscut";
	this->rand = 0;
	this->loc = 0;
}
Bilet::Bilet(string numeClient, string prenumeClient,const Eveniment& eveniment, int rand, int loc, int nrZona):idBilet(++nrBilete)
{
	this->numeClient = numeClient;
	this->prenumeClient = prenumeClient;
	this->nrZona = nrZona;
	this->rand = rand;
	this->loc = loc;
	this->eveniment = eveniment;
	//eveniment.rezervareLoc(nrZona, rand, loc);
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
}
Bilet& Bilet::operator=(const Bilet& b)
{
	this->numeClient = b.numeClient;
	this->prenumeClient = b.prenumeClient;
	this->eveniment = b.eveniment;
	this->rand = b.rand;
	this->loc = b.loc;
	this->nrZona = b.nrZona;
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
	bilet.eveniment.afisareZona(bilet.nrZona);
	out << bilet.eveniment << endl;
	return out;
}
int Bilet::getNrBilete() {
	return nrBilete;
}
istream& operator>>(istream& in, Bilet& bilet) {
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
		cout << "Zona invalida, incercati din nou: "; cout << bilet.eveniment.getNrZone();
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
	return in;
}
//int Bilet::getNrZone() {
//	return this->eveniment.getNrZone();
//}c
int Bilet::getNrLocuri(int nrZona) const{
	return this->eveniment.getNrLocuri(nrZona);
}
