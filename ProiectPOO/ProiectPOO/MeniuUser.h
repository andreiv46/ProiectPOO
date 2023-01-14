#pragma once
#include "Meniu.h"
class MeniuUser: public Meniu
{
private:
	string nume;
public:
	MeniuUser(string nume, string fisierEvenimente);
};


