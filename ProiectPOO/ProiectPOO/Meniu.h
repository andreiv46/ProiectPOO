#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include "Bilet.h"
#include "Eveniment.h"
using namespace std;
class Meniu
{
private:
	vector<Bilet> bilete;
	vector<Eveniment> evenimente;
	string fisierEvenimente;
public:
	Meniu();
	Meniu(string fisierEvenimente);
	void adaugaBiletFisierBinar(const Bilet& bilet) const;
	void citesteBileteleFisierBinar();
	int getNrEvenimente() const;
	int getNrBilete() const;
	void afisareBilete() const;
	void adaugaEvenimentFisierText(const Eveniment& eveniment) const;
	void afisareEvenimente() const;
	//void citesteEvenimenteleFisierText(string fisierText);
};

