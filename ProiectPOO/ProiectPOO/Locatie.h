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
	Locatie(string oras, string strada, int capacitateTotala, string denumireLocatie, const Zona* zone, int nrZone);
	Locatie(const Locatie&);
	~Locatie();
    string getOras() const;
	string getStrada() const;
	int getCapacitateTotala() const;
	string getDenumireLocatie() const;
	void setOras(string oras);
	void setStrada(string strada);
	void setDenumireLocatie(string denumireLocatie);
	Zona* getZone() const;
	int getNrZone() const;
	void setZone(const Zona*, int);
	void setNrZone(int nrZone);
	bool checkCapacitate();
	bool checkLocuriLibereZona(int index);
	int getNrRanduri(int index) const;
	int getNrLocuri(int index) const;
	float rataOcupareLocatie() const;
	friend float operator/(int, Locatie&);
	friend ostream& operator<<(ostream& out,const Locatie &l);
	friend istream& operator>>(istream& in, Locatie& l);
	Locatie& operator=(const Locatie&);
	int NumardeLocuriLocatie() const;
	bool operator<(Locatie& l);
	friend class Eveniment;
	friend class Locuri;
	friend class Zona;
	friend class Bilet;
};

