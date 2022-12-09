#include "Eveniment.h"
Eveniment::Eveniment() {
	this->denumireEveniment = new char[strlen("Necunoscut") + 1];
	strcpy_s(denumireEveniment, strlen("Necunoscut") + 1, "Necunoscut");
	this->data = "Necunoscuta";
	this->oraIncepere = 0;
	this->minut = 0;
	this->oraSfarsit = nullptr;
	this->minutSfarsit = nullptr;
}
//Eveniment::Eveniment(const char* denumireEveniment, string data, int oraIncepere, int minut, int* oraSfarsit, int* minutSfarsit) {
//	if (denumireEveniment != nullptr && strlen(denumireEveniment) > 0)
//		strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
//	this->data = data;
//	
//}
Eveniment::Eveniment(string data):Eveniment() {
	this->data = data;
}
Eveniment::Eveniment(const Eveniment& e) {
	this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
	strcpy_s(this->denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
	this->data = e.data;
	this->oraIncepere = e.oraIncepere;
	this->minut = e.minut;
	this->oraSfarsit = new int;
	*this->oraSfarsit = *e.oraSfarsit;
	this->minutSfarsit = new int;
	*this->minutSfarsit = *e.minutSfarsit;
	this->locatie = e.locatie;
}
char* Eveniment::getDenumireEveniment() const {
	char* copie = new char[strlen(this->denumireEveniment) + 1];
	strcpy_s(copie, strlen(this->denumireEveniment) + 1, this->denumireEveniment);
	return copie;
}
void Eveniment::setDenumireEveniment(const char* denumireEveniment) {
	if (denumireEveniment != nullptr) {
		if (this->denumireEveniment != nullptr) 
			delete[] this->denumireEveniment;
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
	}
	else {
		delete[] this->denumireEveniment;
		denumireEveniment = nullptr;
	}
}
string Eveniment::getData() const{
	return this->data;
}
//void Eveniment::setData(string data) {
//	if(data.length() > 0)
//}
Eveniment& Eveniment::operator=(const Eveniment& e) {
	if (this != &e) {
		if (this->denumireEveniment != NULL)
			delete[] this->denumireEveniment;
		this->denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
		this->data = e.data;
		this->oraIncepere = e.oraIncepere;
		this->minut = e.minut;
		if (this->oraSfarsit != NULL)
			delete this->oraSfarsit;
		this->oraSfarsit = new int;
		*this->oraSfarsit = *e.oraSfarsit;
		if (this->minutSfarsit != NULL)
			delete this->minutSfarsit;
		this->minutSfarsit = new int;
		*this->minutSfarsit = *e.minutSfarsit;
		this->locatie = e.locatie;
	}
	return *this;
}
Eveniment::~Eveniment() {
	if (this->denumireEveniment != nullptr) {
		delete[] this->denumireEveniment;
		this->denumireEveniment = nullptr;
	}
	if (this->oraSfarsit != nullptr) {
		delete[] this->oraSfarsit;
		this->oraSfarsit = nullptr;
	}
	if (this->minutSfarsit != nullptr) {
		delete[] this->minutSfarsit;
		this->minutSfarsit = nullptr;
	}
}