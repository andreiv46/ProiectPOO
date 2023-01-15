#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <fstream>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
#include "Locuri.h"
#include "Zona.h"
#include "DateAdmin.h"
#include "DateUser.h"
#include "MeniuAdmin.h"
#include "MeniuClient.h"


//------------------------------------------------TESTING------------------------------------------------

int main(int argc, char** argv) {
	
	MeniuClient m("evenimente.txt");
	m.optiuni();
	//MeniuAdmin m("evenimente.txt");
	//m.optiuni();
	//cout << endl << Eveniment::getNrEvenimente() << endl;
	//cout << endl << Bilet::getNrBilete() << endl;
	return 0;
}
