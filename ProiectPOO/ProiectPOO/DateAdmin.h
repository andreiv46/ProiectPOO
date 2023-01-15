#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <iterator>
#include "Bilet.h"
#include "Eveniment.h"
using namespace std;
class DateAdmin
{
private:
	vector<Bilet> bilete;
	map<int, Eveniment> evenimente;
	string fisierEvenimente;
public:
	DateAdmin();
	DateAdmin(string fisierEvenimente);
	void adaugaBiletFisierBinar(const Bilet& bilet) const;
	void citesteBileteleFisierBinar();
	int getNrEvenimente() const;
	int getNrBilete() const;
	void afisareBilete() const;
	void adaugaEvenimentFisierText();
	void afisareEvenimente() const;
	void ocupaLoc(int idEveniment, string nume, string prenume);
	bool checkExistEveniment(int idEveniment) const;
	void stergeEvenimentDinFisier(int idEveniment);
	void afisareEvenimenteUser() const;
	void afisareDetaliiEveniment();
	friend class Bilet;
	friend class DateAdmin;
	//void citesteEvenimenteleFisierText(string fisierText);
	//~DateAdmin();
};

