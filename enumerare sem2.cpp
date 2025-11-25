#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

enum FormaStudiu{IF, ID, IFR};
enum Facultate { MRK, MNG, CSIE };
enum TipProdus { pizza, sushi, ciocolata };
enum TipMasina { duba, camion, deTeren };
enum Meserie { inginer, programator, mecanic, doctor };



string formaStudiuToString(FormaStudiu f) {
	switch (f) {
	case IF:  return "Invatamant cu frecventa";
	case ID:  return "Invatamant la distanta";
	case IFR: return "Invatamant cu frecventa redusa";
	default:  return "Necunoscut";
	}
}

string TipProdustoString(TipProdus p) {
	switch (p) {
	case pizza: return "Produsul este pizza";
	case sushi: return "Produsul este sushi";
	case ciocolata: return "Produsul este ciocolata";
	default: return "cod invalid";
	}
}
int main() {
	//Pas1. Initializez

	FormaStudiu fstudiu;
	Facultate facultate;
	TipProdus p;
	TipMasina m;
	Meserie meserie;


	//Pas2 atribui valori
	facultate = Facultate::CSIE;
	fstudiu = IF;
	p = pizza;
	m = TipMasina::duba;
	meserie = Meserie::doctor;

	//Pas3. afisez

	cout << endl << "Forma de studiu este: " << fstudiu << endl;
	cout << endl << "Facultatea este: " << facultate<< endl;
	cout << endl << "Produsul este: " << p << endl;
	cout << endl << "Masina este: " << m << endl;
	cout << endl << "Meseria este: " << meserie << endl;

   //dau valori de la tastatura
   
//intx=2;
	int x;
	cout << endl << "Introduceti codul pt forma de studiu: " << endl;
	cin >> x;
	if (x >= 0 && x <= 2) {
		fstudiu = (FormaStudiu)x;
		cout << endl << "Forma de studiu: " << formaStudiuToString(fstudiu) << endl;
	}
	else {
		cout << endl << "Cod invalid!" << endl;
	}
	
	int z;
	cout << endl << "Introduceti codul produsului dorit: " << endl;
	cin >> z;
	if (z >= 0 && z <= 2) {
		p = (TipProdus)z;
		cout << endl << "Produs: " << TipProdustoString(p) << endl;
	}
	else {
		cout << endl << "cod invalid" << endl;
	}

	int y;
	cout << endl << "Introduceti cod faculate: " << endl;
	cin >> y;
	if (y == 0)
		cout << endl << "Facultatea este MRK" << endl;
	else if (y == 1)
		cout << endl << "Facultatea este MNG" << endl;
	else if (y == 2)
		cout << endl << "Facultatea este CSIE" << endl;
	else
		cout << endl << "Cod invalid!!" << endl;


	//afisare valori interne
	for (int i = inginer; i <= doctor; i++) {
		cout << endl << "Codurile sunt:" << i << " ";
	}

	



	return 0;
}