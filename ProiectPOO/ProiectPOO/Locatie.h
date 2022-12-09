#pragma once
#include <iostream>
#include <string>
using namespace std;
class Locatie
{
private:
	string oras;
	string strada;
	int nrMaximLocuri;
	string denumireLocatie;
public:
	Locatie();
	Locatie(string, string, int, string);
	Locatie(const Locatie&);
    string getOras();
	string getStrada();
	int getNrMaximLocuri();
	string getDenumireLocatie();
	void setOras(string);
	void setStrada(string);
	void setNrMaximLocuri(int);
	void setDenumireLocatie(string);
	friend ostream& operator<<(ostream& out,const Locatie &l);
	friend istream& operator>>(istream& in, Locatie& l);
	friend class Eveniment;
};

