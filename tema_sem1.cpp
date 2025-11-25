#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
int main()
{

	//string str= "Salut lume";
	//string sircopy = sir;
	 //cout << "Sirul copiat este: " << sircopy << endl;
	const char* sir = "Salut lume";//char* pointer la adresa de mem a primul caracter din sir
	//char* sircopy = new char[strlen("albastru") + 1];
	char* sircopy = new char[strlen(sir) + 1];
	strcpy(sircopy, sir);
	//strcpy(sircopy, "albastru");
	cout << endl << "sirul copiat este: " << sircopy << endl;
	//delete[]sir;
	delete[] sircopy;
	return 0;
}