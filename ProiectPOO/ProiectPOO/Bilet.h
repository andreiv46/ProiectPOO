#pragma once
#include <iostream>
#include "Locatie.h"
#include "Eveniment.h"
class Bilet
{
private:
	const int idBilet;
	static int nrBilete;
	float pretBilet;
	Eveniment* eveniment = nullptr;
public:
	Bilet();
	Bilet(Eveniment*, int);
	Bilet(const Bilet&);
	Bilet& operator=(const Bilet&);
	~Bilet();
	friend ostream& operator<<(ostream&, const Bilet&);
	friend class Locuri;
};

