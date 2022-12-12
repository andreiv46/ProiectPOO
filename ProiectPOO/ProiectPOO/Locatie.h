#pragma once
#include <iostream>
#include <string>
using namespace std;
class Locatie
{
private:
	string oras;
	string strada;
	int capacitateTotala;
	string denumireLocatie;
public:
	Locatie();
	Locatie(string, string, int, string);
	Locatie(const Locatie&);
    string getOras() const;
	string getStrada() const;
	int getCapacitateTotala() const;
	int*** gettipNrRanduriNrLocuri() const;
	string getDenumireLocatie() const;
	void setOras(string);
	void setStrada(string);
	void setDenumireLocatie(string);
	//void setCapacitateTotala(int);
	//float rataOcupareLocatie();
	friend ostream& operator<<(ostream& out,const Locatie &l);
	friend istream& operator>>(istream& in, Locatie& l);
	//Locatie& operator+=(int);
	bool operator<(Locatie& l);
	friend class Eveniment;
	friend class Locuri;
};

