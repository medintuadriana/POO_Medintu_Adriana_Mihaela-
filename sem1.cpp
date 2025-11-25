#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct Masina
{
	char* marca;
	char* culoare;
	int anulFabricatiei;
};
int sumaprimelennr(int n, int numere[]) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += numere[i];
	}
	return suma;
}
void afisareMasina(Masina masina) {
	cout << endl << "Masina " << masina.marca << " este de culoare " << masina.culoare << " si a fost fabricata in anul " << masina.anulFabricatiei << ".";
}
int sumanr(int a, int b, int c)
{
	int suma = 0;
	suma = a + b + c;
	return suma;
}
int max(int d, int e) {
	if (d > e) {
		return d;
	}
	else {
		return e;
	}
}
float mediaNumere(int dim, int numereIntregi[]) {
	float medie = 0.0f;
	int suma = 0;
	
	for (int i = 0; i < dim; i++) {
		/*suma = suma + numereIntregi[i];*/
		suma += numereIntregi[i];
	}
	medie = suma / dim;
	return medie;
}

void main() {
	cout << endl << "Mesaj la consola!";

	Masina masina;
	masina.anulFabricatiei = 2021;
	masina.marca = new char[strlen("Ford") + 1];
	strcpy(masina.marca, "Ford");
	masina.culoare = new char[strlen("Albastru") + 1];
	strcpy(masina.culoare, "Albastru");

	afisareMasina(masina);

	int n;
	cout <<endl<< "introduceti cate numere doriti: "<<endl;
	cin >> n;
	int* numere = new int[n];
	cout << endl << "introduceti nr: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> numere[i];
	} 
	cout << endl << "Suma primelor" << n << "numere este; " << sumaprimelennr(n, numere);
	delete[] numere;
	cout << endl << "introduceti doua numere: " << endl;
	int d;
	int e;
	cin >> d >> e;
	cout << endl << "Nr max este: " << max(d, e) << endl;
	int a = 5;
    int b = 10;
	int c = 14;
	cout << endl << "Suma este: " << sumanr(a, b, c) << endl;
	int dim = 5;
	int numereIntregi[] = { 22, 19, 5, 28, 49 };

	cout << endl << "Media este: " << mediaNumere(dim, numereIntregi);

	//dezalocari
	delete[] masina.marca;
	delete[] masina.culoare;
}