#pragma once
#include "DateAdmin.h"
#include "IOptiuneMeniu.h"
class MeniuAdmin: public IOptiuneMeniu
{
private:
	DateAdmin *date;
public:
	void optiuni();
	MeniuAdmin(string numeFisier);
	MeniuAdmin& operator=(const MeniuAdmin& m);
	MeniuAdmin(const MeniuAdmin& m);
	~MeniuAdmin();
};

