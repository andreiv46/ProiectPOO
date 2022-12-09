#include <iostream>
#include <string>
#include <chrono>
#include "Locatie.h"
#include "Eveniment.h"
//------------------------------------------------TESTING------------------------------------------------
int main() {
	cout << "Ticketing App";
	int nrOptiune = 0;
	while (nrOptiune != 2) { 
		cout << endl << "==============================";
		cout << endl << "1-Introducere Eveniment";
		cout << endl << "2-exit";
		cout << endl << "Introduceti actiunea dorita: "; cin >> nrOptiune;
		if (nrOptiune == 1) {
			int zi=0, luna=0, an=0;
			string data;
			cout << "Introduceti data evenimentului" << endl;
			cout << "Introduceti anul: "; cin >> an;
			while (an < 2023 || an > 2027) {
				cout << "An invalid, incercati din nou: ";
				cin >> an;
			}
			cout << "Introduceti luna: "; cin >> luna;
			while (luna < 1 || luna > 12) {
				cout << "Luna invalida, incercati din nou: ";
				cin >> luna;
			}
			cout << "Introduceti ziua: "; cin >> zi;
			if(luna==1 || luna==3 || luna==5 || luna==7 || luna==8 || luna==10|| luna==12)
				while (zi < 1 || zi>31) {
					cout << "Zi invalida, incercati din nou: ";
					cin >> zi;
				}
			else if (luna == 2)
				while (zi < 1 || zi>28) {
					cout << "Zi invalida, incercati din nou: ";
					cin >> zi;
				}
			else 
				while (zi < 1 || zi>30) {
					cout << "Zi invalida, incercati din nou: ";
					cin >> zi;
				}
			if (zi < 10 && luna < 10)
				data = "0" + to_string(zi) + "/0" + to_string(luna) + "/" + to_string(an);
			else if (zi < 10 && luna >= 10)
				data = "0" + to_string(zi) + "/" + to_string(luna) + "/" + to_string(an);
			else if (zi >= 10 && luna < 10)
				data = to_string(zi) + "/0" + to_string(luna) + "/" + to_string(an);
			else
				data = to_string(zi) + "/" + to_string(luna) + "/" + to_string(an);
			Eveniment* ev = new Eveniment(data);
			cout << ev->locatie;
		}
		
	}
	return 0;
}