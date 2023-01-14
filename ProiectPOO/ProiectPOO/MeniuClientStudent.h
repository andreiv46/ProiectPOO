#pragma once
#include "DateUser.h"
#include "IDiscount.h"
class MeniuClientStudent
{
private:
	DateUser* date;
public:
	void optiune();
	MeniuClientStudent(string numeFisier);
	MeniuClientStudent& operator=(const MeniuClientStudent& m);
	MeniuClientStudent(const MeniuClientStudent& m);
	//~MeniuClientStudent();
	//void aplicareDiscount();
};


