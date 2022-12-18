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
	Eveniment(string data);
	Eveniment(const Eveniment&);
	Eveniment(const char* denumireEveniment, string data, string oraIncepere, string durata, const Locatie& locatie, int idEveniment);
	char* getDenumireEveniment() const;
	void setDenumireEveniment(const char* denumireEveniment);
	string getData() const;
	void setData(string);
	string getOraIncepere() const;
	string getDurata() const;
	void setDurata(string durata);
	void setLocatie(const Locatie&);
	int getNrZone() const;
	void afisareZona(int index) const;
	int getNrRanduri(int index) const;
	int getNrLocuri(int index) const;
	float getPretBilet(int index) const;
	Locatie getLocatie() const;
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	friend ostream& operator<<(ostream&, const Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	void afisareOraSfarsit() const;
	float getPreturiEveniment(int);
	void afisareZone();
	void rezervareLoc(int index, int rand, int loc);
	bool checkLocLiber(int index, int rand, int loc) const;
	string getNumeZona(int index) const;
	int getIdEveniment() const;
	static int getNrEvenimente();
	static string getCelMaiMicPret(const Eveniment* evenimente, int nrEvenimente);
	bool operator!=(const Eveniment&);
	bool operator!();
	friend class Locatie;
	friend class Locuri;
	friend class Bilet;
};


