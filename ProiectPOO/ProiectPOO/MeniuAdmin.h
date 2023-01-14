#pragma once
#include "DateAdmin.h"
class MeniuAdmin
{
private:
	DateAdmin *date;
public:
	void optiune();
	MeniuAdmin(string numeFisier);
	MeniuAdmin& operator=(const MeniuAdmin& m);
	MeniuAdmin(const MeniuAdmin& m);
	~MeniuAdmin();
};

