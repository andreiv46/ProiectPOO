#include "Meniu.h"
Meniu::Meniu() {
	this->fisierEvenimente = "necunoscut";
}
void Meniu::adaugaBiletFisierBinar(const Bilet& bilet) const {
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
		fout.write((char*)&bilet.dimensiuneUID, sizeof(int));
		for (int i = 0; i < bilet.dimensiuneUID; i++)
			fout.write((char*)&bilet.UID[i], sizeof(int));
		fout.close();
	}
	else
		cout << "Nu s-a putut deschide fisierul" << endl;
}
void Meniu::citesteBileteleFisierBinar() {
	ifstream fin("bilete.bin", ios::in | ios::binary);
	if (fin.is_open()) {
		string numeClientCopie, prenumeClientCopie;
		int randCopie, locCopie, nrZonaCopie, idBiletCopie, dimensiuneUIDCopie;
		int* UID = nullptr;
		int length;
		fin.read((char*)&length, sizeof(length));
		while (!fin.eof()) {
			char* readString = new char[length + 1];
			fin.read(readString, length);
			readString[length] = '\0';
			numeClientCopie = readString;
			cout << numeClientCopie << endl;
			delete[] readString;
			fin.read((char*)&length, sizeof(length));
			readString = new char[length + 1];
			fin.read(readString, length);
			readString[length] = '\0';
			prenumeClientCopie = readString;
			cout << prenumeClientCopie << endl;
			delete[] readString;
			fin.read((char*)&randCopie, sizeof(int)); cout << randCopie << endl;
			fin.read((char*)&locCopie, sizeof(int)); cout << locCopie << endl;
			fin.read((char*)&nrZonaCopie, sizeof(int));		cout << nrZonaCopie << endl;
			fin.read((char*)&idBiletCopie, sizeof(int)); cout << idBiletCopie << endl;
			fin.read((char*)&dimensiuneUIDCopie, sizeof(int)); cout << dimensiuneUIDCopie << endl;
			UID = new int[dimensiuneUIDCopie];
			for (int i = 0; i < dimensiuneUIDCopie; i++) {
				fin.read((char*)&UID[i], sizeof(int));
				cout << UID[i] << " ";
			}
			bilete.push_back(Bilet(numeClientCopie, prenumeClientCopie, randCopie, locCopie, nrZonaCopie, dimensiuneUIDCopie, UID, idBiletCopie));
			Bilet test(numeClientCopie, prenumeClientCopie, randCopie, locCopie, nrZonaCopie, dimensiuneUIDCopie, UID, idBiletCopie);
			cout << test.eveniment.getDenumireEveniment() << endl;
			fin.read((char*)&length, sizeof(length));
		}
		fin.close();
	}
	else cout << "Nu s-a putut deschide fisierul";
}
void Meniu::adaugaEvenimentFisierText(const Eveniment& eveniment) const {
	eveniment.adaugaEvenimentInFisierText(fisierEvenimente);
}
Meniu::Meniu(string fisierEvenimente) {
	this->fisierEvenimente = fisierEvenimente;
	ifstream fin(fisierEvenimente, ios::in);
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
			evenimente.push_back(Eveniment(denumireEveniment.c_str(), dataEveniment, oraIncepereEveniment, durataEveniment, locatie, idEveniment));
			zone.clear();
		}
		fin.close();
	}
	else cout << "Nu s-a putut deschide fisierul";
}
int Meniu::getNrEvenimente() const {
	return evenimente.size();
}
int Meniu::getNrBilete() const {
	return bilete.size();
}
void Meniu::afisareEvenimente() const {
	for (int i = 0; i < evenimente.size(); i++) {
		cout << "Evenimentul " << i + 1 << " este: " << endl;
		cout << evenimente[i];
	}
}
void Meniu::afisareBilete() const {
	for (int i = 0; i < bilete.size(); i++) {
		cout << "Biletul " << i + 1 << " este: " << endl;
		cout << bilete[i];
	}
}