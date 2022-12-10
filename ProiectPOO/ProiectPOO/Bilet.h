#pragma once
#include <iostream>
#include "Locatie.h"
#include "Eveniment.h"
class Bilet
{
private:
	int idBilet;
	static int nrBilete;
	//int tipEveniment;
	float pretBilet;
	Eveniment* eveniment = nullptr;
public:
	Bilet();
};
int Bilet::nrBilete = 0;

