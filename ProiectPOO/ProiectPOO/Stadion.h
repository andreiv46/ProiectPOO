#pragma once
#include <iostream>
#include "Locatie.h"
using namespace std;
class Stadion:Locatie
{
private:
	int nrRanduriPeluza1;
	int nrRanduriPeluza2;
	int nrLocuriRandPeluza;
	int nrRanduriTribuna1;
	int nrRanduriTribuna2;
	int nrLocuriRandTribuna;
	bool** locuriDisponibilePeluza;
	bool** locuriDispobileTribuna;
};

