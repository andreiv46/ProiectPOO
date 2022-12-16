#pragma once
#include <iostream>
#include <string>
#include "Zona.h"
#include "Locuri.h"
using namespace std;
class Locatie
{
private:
	string oras;
	string strada;
	int capacitateTotala;
	Zona* zone;
	int nrZone;
	string denumireLocatie;
public:
	Locatie();
	Locatie(string, string, int, string, const Zona*, int);
	Locatie(const Locatie&);
	~Locatie();
    string getOras() const;
	string getStrada() const;
	int getCapacitateTotala() const;
	string getDenumireLocatie() const;
	void setOras(string);
	void setStrada(string);
	void setDenumireLocatie(string);
	Zona* getZone() const;
	int getNrZone() const;
	void setZone(const Zona*, int);
	void setNrZone(int);
	bool checkCapacitate();
	int getNrRanduri(int) const;
	int getNrLocuri(int) const;
	//void setCapacitateTotala(int);
	//float rataOcupareLocatie();
	friend float operator/(int, Locatie&);
	friend ostream& operator<<(ostream& out,const Locatie &l);
	friend istream& operator>>(istream& in, Locatie& l);
	Locatie& operator=(const Locatie&);
	int NumardeLocuriLocatie();
	bool operator<(Locatie& l);
	friend class Eveniment;
	friend class Locuri;
	friend class Zona;
	friend class Bilet;
};

