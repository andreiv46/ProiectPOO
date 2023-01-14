#pragma once
#include "DateAdmin.h"
class DateUser: public DateAdmin
{
public:
	DateUser();
	DateUser(string fisierEvenimente);
	void rezervaBilet();
};


