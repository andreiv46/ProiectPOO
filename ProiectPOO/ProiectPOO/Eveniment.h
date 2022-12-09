#pragma once
#include "Locatie.h"
#include <iostream>
using namespace std;
class Eveniment
{
public:
	char* denumireEveniment;
	string data;
	int oraIncepere;
	int minut;
	int durata;
	Locatie locatie;
public:
	Eveniment();
	Eveniment(string);
	Eveniment(const Eveniment&);
	char* getDenumireEveniment() const;
	void setDenumireEveniment(const char*);
	string getData() const;
	//void setData(string);
	int getOraIncepere() const;
	void setOraIncepere(int);
	int getDurata() const;
	void setDurata(int);
	int getMinut() const;
	void setMinut(int);
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	friend ostream& operator<<(ostream&, const Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	void afisareOraSfarsit() const;
	friend class Locatie;
};

