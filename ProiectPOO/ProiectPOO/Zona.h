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
	Zona(string, float, const Locuri&);
	Zona(const Locuri& locuri);
	Zona(const Zona& z);
	string getNumeZona() const;
	float getPretBilet() const;
	Locuri getLocuri() const;
	void setNumeZona(string);
	void setPretBilet(float);
	void setLocuri(const Locuri&);
	void rezervaLocuri(int, int);
	int getNrLocuri() const;
	int getNrRanduri() const;
	bool checkLocLiber(int, int) const;
	Zona& operator=(const Zona&);
	friend ostream& operator<<(ostream&, const Zona&);
	friend istream& operator>>(istream&, Zona&);
	friend class Locuri;
	int numarLocuriZona();
	Zona& operator++();
};

