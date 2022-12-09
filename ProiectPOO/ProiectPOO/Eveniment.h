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
	int* oraSfarsit;
	int* minutSfarsit;
	Locatie locatie;
public:
	Eveniment();
	Eveniment(string);
	Eveniment(const Eveniment&);
	char* getDenumireEveniment() const;
	void setDenumireEveniment(const char*);
	string getData() const;
	//void setData(string);
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	friend class Locatie;
};

