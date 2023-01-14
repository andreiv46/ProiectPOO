// write in binary file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Bilet
{
    string numeClient;
    string prenumeClient;
    int rand;
    int loc;
    int nrZona;
    const int idBilet;
    int* UID;
    int dimensiuneUID;
    static int nrBilete;
    // Eveniment eveniment;
public:
    Bilet() : idBilet(nrBilete++)
    {
        numeClient = " ";
        prenumeClient = " ";
        rand = 0;
        loc = 0;
        nrZona = 0;
        UID = new int(3);
        dimensiuneUID = 1;
    }
    // write into binary file
    void writeBinaryFile()
    {
        ofstream fout("bilete.dat", ios::binary);
        if (fout.is_open())
        {
            fout.write((char*)&numeClient, sizeof(string));
            fout.write((char*)&prenumeClient, sizeof(string));
            fout.write((char*)&rand, sizeof(int));
            fout.write((char*)&loc, sizeof(int));
            fout.write((char*)&nrZona, sizeof(int));
            fout.write((char*)&idBilet, sizeof(int));
            fout.write((char*)&dimensiuneUID, sizeof(int));
            for (int i = 0; i < dimensiuneUID; i++)
            {
                fout.write((char*)&UID[i], sizeof(int));
            }
        }
        fout.close();
    }
    // read from binary file
    void readBinaryFile()
    {
        ifstream fin("bilete.dat", ios::binary);
        if (fin.is_open())
        {
            string numeClientCopie;
            string prenumeClientCopie;
            int randCopie = 0;
            int locCopie = 0;
            int nrZonaCopie = 0;
            int idBiletCopie = 0;
            int dimensiuneUIDCopie = 0;
            fin.read((char*)&numeClientCopie, sizeof(string));
            fin.read((char*)&prenumeClientCopie, sizeof(string));
            fin.read((char*)&randCopie, sizeof(int));
            fin.read((char*)&locCopie, sizeof(int));
            fin.read((char*)&nrZonaCopie, sizeof(int));
            fin.read((char*)&idBiletCopie, sizeof(int));
            fin.read((char*)&dimensiuneUIDCopie, sizeof(int));
            int* UIDCopie = new int[dimensiuneUIDCopie];
            for (int i = 0; i < dimensiuneUIDCopie; i++)
            {
                fin.read((char*)&UIDCopie[i], sizeof(int));
            }
            cout << "Nume client: " << numeClientCopie << endl;
            cout << "Prenume client: " << prenumeClientCopie << endl;
            cout << "Rand: " << randCopie << endl;
            cout << "Loc: " << locCopie << endl;
            cout << "Numar zona: " << nrZonaCopie << endl;
            cout << "ID bilet: " << idBiletCopie << endl;
            cout << "Dimensiune UID: " << dimensiuneUIDCopie << endl;
            cout << "UID: ";
            for (int i = 0; i < dimensiuneUIDCopie; i++)
            {
                cout << UIDCopie[i] << " ";
            }
        }
        fin.close();
    }
};
int Bilet::nrBilete = 0;
int main()
{
    Bilet bilet;
    bilet.writeBinaryFile();
    bilet.readBinaryFile();
    return 0;
}