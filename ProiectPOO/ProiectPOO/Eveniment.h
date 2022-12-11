#pragma once
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
	int nrLocuri;
	Locatie* locatie = nullptr;
public:
	Eveniment();
	Eveniment(string);
	Eveniment(const Eveniment&);
	char* getDenumireEveniment() const;
	void setDenumireEveniment(const char*);
	string getData() const;
	//void setData(string);
	string getOraIncepere() const;
	//void setOraIncepere(int);
	string getDurata() const;
	//void setDurata(int);
	int getNrLocuri() const;
	void setNrLocuri(int);
	Locatie* getLocatie() const;
	void setLocatie(Locatie*);
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	friend ostream& operator<<(ostream&, const Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	void afisareOraSfarsit() const;
	//void scadereNrLocuri(int);
	bool operator!=(const Eveniment&);
	bool operator!();
	friend class Locatie;
};


