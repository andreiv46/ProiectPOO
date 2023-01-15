#include "DateAdmin.h"
DateAdmin::DateAdmin() {
	this->fisierEvenimente = "invalid";
}
void DateAdmin::adaugaBiletFisierBinar(const Bilet& bilet) const {
	ofstream fout("bilete.bin", ios::out | ios::binary | ios::app);
	if (fout.is_open()) {
		int length = bilet.numeClient.length();
		fout.write((char*)&length, sizeof(length));
		fout.write(bilet.numeClient.c_str(), length);
		length = bilet.prenumeClient.length();
		fout.write((char*)&length, sizeof(length));
		fout.write(bilet.prenumeClient.c_str(), length);
		fout.write((char*)&bilet.rand, sizeof(int));
		fout.write((char*)&bilet.loc, sizeof(int));
		fout.write((char*)&bilet.nrZona, sizeof(int));
		fout.write((char*)&bilet.idBilet, sizeof(int));
		fout.write((char*)&bilet.pretBilet, sizeof(float));
		fout.write((char*)&bilet.dimensiuneUID, sizeof(int));
		for (int i = 0; i < bilet.dimensiuneUID; i++)
			fout.write((char*)&bilet.UID[i], sizeof(int));
		fout.close();
	}
	else
		cout << "Nu s-a putut deschide fisierul cu biletele" << endl;
}
void DateAdmin::citesteBileteleFisierBinar() {
	ifstream fin("bilete.bin", ios::in | ios::binary);
	if (fin.is_open()) {
		string numeClientCopie, prenumeClientCopie;
		int randCopie, locCopie, nrZonaCopie, idBiletCopie, dimensiuneUIDCopie;
		float pretbilet;
		int* UID = nullptr;
		int length;
		fin.read((char*)&length, sizeof(length));
		while (!fin.eof()) {
			char* readString = new char[length + 1];
			fin.read(readString, length);
			readString[length] = '\0';
			numeClientCopie = readString;
			delete[] readString;
			fin.read((char*)&length, sizeof(length));
			readString = new char[length + 1];
			fin.read(readString, length);
			readString[length] = '\0';
			prenumeClientCopie = readString;
			delete[] readString;
			fin.read((char*)&randCopie, sizeof(int)); 
			fin.read((char*)&locCopie, sizeof(int)); 
			fin.read((char*)&nrZonaCopie, sizeof(int));		
			fin.read((char*)&idBiletCopie, sizeof(int));
			fin.read((char*)&pretbilet, sizeof(float));
			fin.read((char*)&dimensiuneUIDCopie, sizeof(int)); 
			UID = new int[dimensiuneUIDCopie];
			for (int i = 0; i < dimensiuneUIDCopie; i++) {
				fin.read((char*)&UID[i], sizeof(int));
			}
			bilete.push_back(Bilet(numeClientCopie, prenumeClientCopie, randCopie, locCopie, nrZonaCopie, dimensiuneUIDCopie, UID, idBiletCopie, pretbilet));
			//Bilet test(numeClientCopie, prenumeClientCopie, randCopie, locCopie, nrZonaCopie, dimensiuneUIDCopie, UID, idBiletCopie);
			fin.read((char*)&length, sizeof(length));
		}
		fin.close();
	}
	else cout << "Nu s-a putut deschide fisierul cu biletele" << endl;
}
void DateAdmin::adaugaEvenimentFisierText() {
	Eveniment eveniment;
	cin >> eveniment;
	evenimente.insert(pair<int, Eveniment>(eveniment.getIdEveniment(), eveniment));
	eveniment.adaugaEvenimentInFisierText(this->fisierEvenimente);
}
DateAdmin::DateAdmin(string fisierEvenimente) {
	this->fisierEvenimente = fisierEvenimente;
	ifstream fin(fisierEvenimente, ios::in | ios::_Nocreate);
	if (fin.is_open()) {
		string denumireEveniment, dataEveniment, denumireLocatieEveniment, orasEveniment, stradaEveniment, oraIncepereEveniment, numeZona, durataEveniment;
		float pretZona;
		int nrZoneEveniment, nrRanduriEveniment, nrLocuriEveniment, capacitateTotalaEveniment, idEveniment;
		vector<Zona> zone;
		Locatie locatie;
		Locuri locuri;
		string linie;
		while (getline(fin, linie) && !linie.empty()) {
			idEveniment = stoi(linie); 
			getline(fin, denumireEveniment);
			getline(fin, dataEveniment);
			getline(fin, oraIncepereEveniment);
			getline(fin, durataEveniment);
			getline(fin, orasEveniment);
			getline(fin, stradaEveniment);
			fin >> nrZoneEveniment;
			fin >> capacitateTotalaEveniment;
			for (int i = 0; i < nrZoneEveniment; i++) {
				fin.ignore();
				getline(fin, numeZona);
				fin >> nrRanduriEveniment;
				fin >> nrLocuriEveniment;
				locuri = Locuri(nrRanduriEveniment, nrLocuriEveniment);
				fin >> pretZona;
				zone.push_back(Zona(numeZona, pretZona, locuri));
			}
			fin.ignore();
			getline(fin, denumireLocatieEveniment);
			locatie = Locatie(orasEveniment, stradaEveniment, capacitateTotalaEveniment, denumireLocatieEveniment, &zone[0], nrZoneEveniment);
			evenimente.insert(make_pair(idEveniment, Eveniment(denumireEveniment.c_str(), dataEveniment, oraIncepereEveniment, durataEveniment, locatie, idEveniment)));
			zone.clear();
		}
		fin.close();
		DateAdmin::citesteBileteleFisierBinar();
		if (bilete.size() > 0) {
			for (size_t i = 0; i < bilete.size(); i++) {
				evenimente[bilete[i].getEvenimentID()].rezervareLoc(bilete[i].getNrZona(), bilete[i].getRand(), bilete[i].getLoc());
			}
		}
	}
	else {
		this->fisierEvenimente = "invalid";
		cout << "Nu s-a putut deschide fisierul cu evenimentele";
	}
}
int DateAdmin::getNrEvenimente() const {
	return evenimente.size();
}
int DateAdmin::getNrBilete() const {
	return bilete.size();
}
void DateAdmin::afisareEvenimente() const {
	for (auto it = evenimente.begin(); it != evenimente.end(); it++) {
		cout << it->second << endl;
	}
}
void DateAdmin::afisareBilete() const {
	for (size_t i = 0; i < bilete.size(); i++) {
		cout << "Biletul " << i + 1 << endl;
		//cout << evenimente[bilete[i].UID[bilete[i].dimensiuneUID - 1]].getDenumireEveniment() << endl;
		cout << bilete[i];
		cout << endl << endl;
	}
}
bool DateAdmin::checkExistEveniment(int idEveniment) const {
	if (evenimente.find(idEveniment) != evenimente.end())
		return true;
	return false;
}
void DateAdmin::ocupaLoc(int idEveniment, string nume, string prenume) {
	evenimente[idEveniment].afisareZone();
	cout << "Introduceti numarul zonei: ";
	int nrZona;
	cin >> nrZona;
	while (cin.fail() || nrZona <1 || nrZona > evenimente[idEveniment].getLocatie().getNrZone()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Zona invalida, incercati din nou: ";
		cin >> nrZona;
	}
	evenimente[idEveniment].afisareZona(nrZona);
	cout << "Introduceti randul: ";
	int rand;
	cin >> rand;
	while (cin.fail() || rand < 1 || rand > evenimente[idEveniment].getNrRanduri(nrZona)) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Rand invalid, incercati din nou: ";
		cin >> rand;
	}
	cout << "Introduceti locul: ";
	int loc;
	cin >> loc;
	while (cin.fail() || loc < 1 || loc > evenimente[idEveniment].getNrLocuri(nrZona)) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Loc invalid, incercati din nou: ";
		cin >> loc;
	}
	while (!evenimente[idEveniment].checkLocLiber(nrZona, rand, loc)) {
		cout << "Locul este ocupat" << endl;
		cout << "Introduceti randul: ";
		cin >> rand;
		while (cin.fail() || rand < 1 || rand > evenimente[idEveniment].getNrRanduri(nrZona))
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Introduceti un rand valid: ";
			cin >> rand;
		}
		cout << "Introduceti locul: ";
		cin >> loc;
		while (cin.fail() || loc < 1 || loc > evenimente[idEveniment].getNrLocuri(nrZona)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Loc invalid, incercati din nou: ";
			cin >> loc;
		}
	}
	evenimente[idEveniment].rezervareLoc(nrZona, rand, loc);
	bilete.push_back(Bilet(nume, prenume, rand, loc, nrZona, idEveniment, evenimente[idEveniment].getPretBilet(nrZona)));
	this->adaugaBiletFisierBinar(bilete[bilete.size() - 1]);
	cout << endl;
	cout << "Locul a fost rezervat cu succes" << endl;
	cout << bilete[bilete.size() - 1];
	cout << endl;
	cout << "Evenimentul: " << evenimente[idEveniment].getDenumireEveniment() << endl;
	cout << "Data: " << evenimente[idEveniment].getData() << endl;
	cout << "Ora: " << evenimente[idEveniment].getOraIncepere() << endl;
}
void DateAdmin::afisareEvenimenteUser() const{
	for (auto it = evenimente.begin(); it != evenimente.end(); it++) {
		cout << it->second.getIdEveniment();
		cout << " - " << it->second.getDenumireEveniment() << " " << it->second.getData()
			<< " " << it->second.getOras() << " " << it->second.getOraIncepere() << endl;
	}
}
void DateAdmin::afisareDetaliiEveniment() {
	afisareEvenimenteUser();
	cout << endl;
	cout << "Introduceti id-ul evenimentului: ";
	int idEveniment;
	cin >> idEveniment;
	while (cin.fail() || !checkExistEveniment(idEveniment)) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Id-ul evenimentului este invalid, incercati din nou: ";
		cin >> idEveniment;
	}
	cout << evenimente[idEveniment];
}
void DateAdmin::afisareBilet(string UID) {
	for (size_t i = 0; i < bilete.size(); i++) {
		if (bilete[i].getUIDstring() == UID) {
			cout << bilete[i];
			cout << evenimente[bilete[i].UID[bilete[i].dimensiuneUID - 1]].getDenumireEveniment() << endl;
			cout << "Stare bilet: valid" << endl;
			return;
		}
	}
	cout << endl << "Bilet invalid";
}
string DateAdmin::getNumeFisierEvenimente() const {
	return this->fisierEvenimente;
}
float DateAdmin::valoareTotalaBilete() {
	float suma = 0;
	for (size_t i = 0; i < bilete.size(); i++) {
		suma += bilete[i].getPretBilet();
	}
	return suma;
}