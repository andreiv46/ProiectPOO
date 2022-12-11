#include "Bilet.h"
Bilet::Bilet():idBilet(0)
{
	this->pretBilet = 0;
}
Bilet::Bilet(Eveniment* e, int idBilet):idBilet(idBilet)
{
	this->pretBilet = 0;
	this->eveniment = e;
}
Bilet::Bilet(const Bilet& b) :idBilet(b.idBilet)
{
	this->pretBilet = b.pretBilet;
	this->eveniment = new Eveniment(*b.eveniment);
}
Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b) {
		this->pretBilet = b.pretBilet;
		this->eveniment = new Eveniment(*b.eveniment);
	}
	return *this;
}
Bilet::~Bilet()
{
	if (this->eveniment != nullptr)
		delete this->eveniment;
}
ostream& operator<<(ostream& out, const Bilet& b)
{
	out << "=============" << endl;
	out << "Id bilet: " << b.idBilet << endl;
	out << "Pret bilet: " << b.pretBilet << endl;
	out << *b.eveniment << endl;
	return out;
}
int Bilet::nrBilete = 0;

