#pragma once
#pragma warning(disable:4996)
#include "Locatie.h"
#include <iostream>
#include <iomanip>
using namespace std;
class Eveniment
{
private:
	char* denumireEveniment;
	string data;
	string oraIncepere;
	string durata;
	Locatie locatie;
	static int nrEvenimente;
	int idEveniment;
public:
	Eveniment();
	Eveniment(string);
	Eveniment(const Eveniment&);
	Eveniment(const char*, string, string, string, const Locatie&, int);
	char* getDenumireEveniment() const;
	void setDenumireEveniment(const char*);
	string getData() const;
	void setData(string);
	string getOraIncepere() const;
	string getDurata() const;
	void setDurata(string);
	void setLocatie(const Locatie&);
	int getNrZone() const;
	void afisareZona(int) const;
	int getNrRanduri(int) const;
	int getNrLocuri(int) const;
	float getPretBilet(int) const;
	Locatie getLocatie() const;
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	friend ostream& operator<<(ostream&, const Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	void afisareOraSfarsit() const;
	float getPreturiEveniment(int);
	void afisareZone();
	void rezervareLoc(int, int, int);
	bool checkLocLiber(int, int, int) const;
	string getNumeZona(int) const;
	int getIdEveniment() const;
	int getNrEvenimente() const;
	//void scadereNrLocuri(int);
	bool operator!=(const Eveniment&);
	bool operator!();
	friend class Locatie;
	friend class Locuri;
	friend class Bilet;
};


