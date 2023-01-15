#pragma once
#include "DateUser.h"
#include "IOptiuneMeniu.h"
class MeniuClient: public IOptiuneMeniu
{
private:
	DateUser* date;
public:
	void optiuni() override;
	MeniuClient(string numeFisier);
	MeniuClient& operator=(const MeniuClient& m);
	MeniuClient(const MeniuClient& m);
	~MeniuClient();
};


