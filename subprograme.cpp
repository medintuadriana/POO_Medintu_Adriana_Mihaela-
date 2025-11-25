#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//1. Să se facă un subprogram care returnează suma unui vector de numere întregi. să se folosească transfer de pâram doar prin pointer.
int sumavector(int* v, int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += v[i];
	}
	return suma;
}

//2. Să se facă un subprogram care Inter schimbă valorile a 2 variabile. să se facă variantă prin referință și pointer.
int interschimbare_ref(int& x, int& y) {
	int aux = 0;
	x = aux;
	x = y;
	y = aux;
	return x, y;
}


int main() {

	int n; 
	cout << endl << "n= ";
	cin >> n;
	int* v = new int[n];
	cout <<endl<< "Introduceti elementele vectorului: ";
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		
	}
	int x;
	cout << endl << "introduceti valoarea lui x: ";
	cin >> x;
	int y;
	cout << endl << "introduceti valoarea lui y: ";
	cin >> y;

	sumavector(v, n);
	interschimbare_ref(x, y);
	cout << interschimbare_ref(x, y);
	cout << endl << "Suma elementelor vectorului este: " << sumavector(v, n) << endl;
	return 0;

}
