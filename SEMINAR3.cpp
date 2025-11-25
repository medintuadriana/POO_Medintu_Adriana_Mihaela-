#include <iostream>
using namespace std;
enum Facultate {
	CSIE, FABIZ, MK, MN  //MULTIMI, VALORI CONSTANTE, GLOBALE, csie e 0, fabiz e 1 etc acesteas sunt coduri implicite, daca nu le dam alte VALORI DAR CRESCATOARE

};
enum FormaInvatamant {
	IF, ID, IFR
};



class Student {
public:
	//char* nume;
	string nume;
	char* prenume;
	Facultate facultate;
	FormaInvatamant formaInvatamant;
	int CNP;
	bool arebursa;
	bool EsteAngajat;
	//vector alocat dinamic
	// cbhar*materiaFacultate
	int* note;
	int nrNote;
	//vector numeric alocate static
	bool fraudaExamen[100];// 100 este nr 

};
class Masina {
	//sir de caractere alocat static
	char VIN[19];
	char nrInmatriculare[9];

};
int main() {
	//char* facultate;//sir de caractere alocat dinamic, adica marime dinamica data de utilizator
	char facultate2[20];//sir de caractere alocat static,adica marime fixa
		//string facultate;
	Facultate facultate;
	//facultate = Facultate::CSIE;
	//facultate = CSIE;
	//cout << "/nAfisare facultate prin enumerare: " << facultate;
	cout << "/nIntroduceti facultate: ";
	//cin >> facultate;// cin pt a gestiona fluxul cu coonsola stie sa recunoasca date de tip char, int etc predefinite
	int x;
	cin >> x;
	facultate = (Facultate)x;//cast explicit
	cout << "/nAfisare facultate prin enumerare: " << facultate;
	string text;
	text = "ABC";
	cout << endl << "text";
	cout << "/nafisati text: " << text;
	cin >> text;
	Student s;
	s.CNP = 1235;

	return 0;
}
//operatul lucreaza cu operanzi 