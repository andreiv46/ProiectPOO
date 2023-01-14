#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "Locuri.h"
using namespace std;
class Zona
{
private:
	string numeZona;
	float pretBilet;
	Locuri locuri;
public:
	Zona();
	Zona(string numeZona, float pretBilet, const Locuri& locuri);
	Zona(string numeZona, float pretBilet, int nrRanduri, int nrLocuri);
	Zona(const Locuri& locuri);
	Zona(const Zona& z);
	string getNumeZona() const;
	float getPretBilet() const;
	Locuri getLocuri() const;
	void setNumeZona(string numeZona);
	void setPretBilet(float pretBilet);
	void setLocuri(const Locuri&);
	void rezervaLocuri(int rand, int loc);
	int getNrLocuri() const;
	int getNrRanduri() const;
	bool checkLocLiber(int rand, int loc) const;
	bool checkLocuriLibereZona() const;
	Zona& operator=(const Zona&);
	friend ostream& operator<<(ostream&, const Zona&);
	friend istream& operator>>(istream&, Zona&);
	friend ofstream& operator<<(ofstream&, const Zona&);
	Zona& operator--();
	operator int();
	friend class Locuri;
	int numarLocuriZona() const;
	Zona& operator++();
	~Zona();
};

