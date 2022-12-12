#pragma once
#include <iostream>
using namespace std;
class Locuri
{
private:
	int nrRanduri;
	int nrLocuri;
	bool** locuri;
public:
	Locuri();
	Locuri(int, int);
	Locuri(const Locuri&);
	~Locuri();
	Locuri& operator=(const Locuri&);
	int getNrRanduri() const;
	void setNrRanduri(int);
	int getNrLocuri() const;
	void setNrLocuri(int);
	bool** getLocuri() const;
	void setLocuri(bool**, int, int);
	void rezervaLoc();
	int numarLocuriTotal() const;
	int numarLocuriDisponibile() const;
	bool checkLocuriDisponibile() const;
	friend ostream& operator<<(ostream&, const Locuri&);
	friend istream& operator>>(istream&, Locuri&);
	bool operator>(const Locuri&);
	void operator[](int);
	friend class Bilet;
	friend class Eveniment;
	friend class Locatie;
};

