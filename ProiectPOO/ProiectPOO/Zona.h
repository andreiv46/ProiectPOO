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
	Zona& operator=(const Zona&);
	friend ostream& operator<<(ostream&, const Zona&);
	friend istream& operator>>(istream&, Zona&);
	Zona& operator--();
	operator int();
	friend class Locuri;
	int numarLocuriZona() const;
	Zona& operator++();
};

