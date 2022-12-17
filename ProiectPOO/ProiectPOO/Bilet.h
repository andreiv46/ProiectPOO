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
	int* UID;
	int dimensiuneUID;  
	static int nrBilete;
	Eveniment eveniment;
public:
	Bilet();
	Bilet(string numeClient, string prenumeClient, const Eveniment& eveniment, int rand, int loc, int nrZona, int idBilet);
	Bilet(const Eveniment& eveniment);
	Bilet(const Bilet&);
	~Bilet();
	Bilet& operator=(const Bilet&);
	friend ostream& operator<<(ostream&, const Bilet&);
	friend istream& operator>>(istream&, Bilet&);
	friend class Locuri;
	int getNrBilete() const;
	int getRand() const;
	int getLoc() const;
	int getNrZona() const;
	int getdimensiuneUID() const;
	int* getUID() const;
	string getNumeClient() const;
	string getPrenumeClient() const;
	float operator+(const Bilet&);
	friend float operator*(int, const Bilet&);
	//float getPretBilet() const;
};

