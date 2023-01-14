#pragma once
#include <iostream>
#include "Locatie.h"
#include "Eveniment.h"
#include "DateAdmin.h"
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
public:
	Bilet();
	Bilet(string numeClient, string prenumeClient, int rand, int loc, int nrZona, int idEveniment);
	Bilet(string numeClient, string prenumeClient, int rand, int loc, int nrZona, int dimensiuneUID, int* UID, int idBilet);
	Bilet(const Bilet&);
	~Bilet();
	Bilet& operator=(const Bilet&);
	friend ostream& operator<<(ostream&, const Bilet&);
	friend istream& operator>>(istream&, Bilet&);
	friend class Locuri;
	static int getNrBilete();
	int getRand() const;
	int getLoc() const;
	int getNrZona() const;
	int getdimensiuneUID() const;
	int* getUID() const;
	string getNumeClient() const;
	string getPrenumeClient() const;
	Eveniment getEveniment() const;
	float operator+(const Bilet&);
	friend float operator*(int, const Bilet&);
	bool verificaUID(string UID) const;
	void setNumeClient(string numeClient);
	void setPrenumeClient(string prenumeClient);
	int getEvenimentID() const;
	//bool checkData();
	friend class DateAdmin;
	//float getPretBilet() const;
};

