#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Locuri
{
private:
	int nrRanduri;
	int nrLocuri;
	bool** locuri;
public:
	Locuri();
	Locuri(int nrRanduri, int nrLocuri);
	Locuri(const Locuri&);
	~Locuri();
	Locuri& operator=(const Locuri&);
	int getNrRanduri() const;
	void setNrRanduri(int nrRanduri);
	int getNrLocuri() const;
	void setNrLocuri(int nrLocuri);
	bool** getLocuri() const;
	void setLocuri(bool** locuriCopie, int nrRanduri, int nrLocuri);
	void setLocuri(int nrRanduri, int nrLocuri);
	void rezervaLoc();
	int numarLocuriTotal() const;
	int numarLocuriDisponibile() const;
	bool checkLocuriDisponibile() const;
	bool checkLocLiber(int rand, int loc) const;
	void ocupaLoc(int rand, int loc);
	friend ostream& operator<<(ostream&, const Locuri&);
	friend istream& operator>>(istream&, Locuri&);
	bool operator>(const Locuri&);
	void operator[](int index);
	friend class Bilet;
	friend class Eveniment;
	friend class Locatie;
	friend class Zona;
};

