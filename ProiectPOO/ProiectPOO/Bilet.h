#pragma once
#include <iostream>
#include "Locatie.h"
#include "Eveniment.h"
class Bilet
{
private:
	string numeClient;
	string prenumeClient;
	int rand;
	int loc;
	int nrZona;
	const int idBilet;
	static int nrBilete;
	Eveniment eveniment;
public:
	Bilet();
	Bilet(string numeClient, string prenumeClient,const Eveniment&, int, int, int);
	Bilet(const Eveniment& eveniment);
	Bilet(const Bilet&);
	Bilet& operator=(const Bilet&);
	friend ostream& operator<<(ostream&, const Bilet&);
	friend istream& operator>>(istream&, Bilet&);
	friend class Locuri;
	//int getNrZone();
	int getNrLocuri(int) const;
	int getNrBilete();
};

