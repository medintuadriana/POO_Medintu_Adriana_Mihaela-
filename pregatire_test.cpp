#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class  ExceptieCustom :public exception {
public: 
	ExceptieCustom(const char* mesaj):exception(mesaj) {}
};


class Prajitura {
private:
	char* denumire;
	int nrCalorii;
	int nrIngrediente;
	float* gramajIngrediente;
	bool esteVegana;
	const int id;
	static int NrPrajituri;





public:
	//constr faram param
	Prajitura() :id(++NrPrajituri) {///
		{
			this->denumire = new char[strlen("n/a") + 1];
			strcpy(this->denumire, "n/a");
		}
		this->nrCalorii = 0;
		this->nrIngrediente = 0;
		this->gramajIngrediente = nullptr;
		this->esteVegana = false;
		NrPrajituri++;///ATENTIE
		//this->NrPrajituri = 0;
	}
	//constr cu toti param 
	Prajitura(char* denumireData, int nrCaloriiDate, int nrIngredienteDate, float* gramajIngredienteDat, bool Vegan) :id(++NrPrajituri) {
		if (denumireData != nullptr&& strlen(denumireData) > 2) {
			this->denumire = new char[strlen(denumireData) + 1];
			strcpy(this->denumire, denumireData);
		}
		else {
			this->denumire = new char[strlen("n/a") + 1];
			strcpy(this->denumire, "n/a");
		}
		if (nrCaloriiDate > 0)
			this->nrCalorii = nrCaloriiDate;
		else this->nrCalorii = 0;
		if (nrIngredienteDate > 0)
			this->nrIngrediente = nrIngredienteDate;
		else this->nrIngrediente = 0;
		if (nrIngredienteDate > 0 && gramajIngredienteDat != nullptr) {
			this->nrIngrediente = nrIngredienteDate;
			this->gramajIngrediente = new float[nrIngrediente];
			for (int i = 0; i < nrIngrediente; i++)///
			{
				this->gramajIngrediente[i] = gramajIngredienteDat[i];
			}
		}
		else this->gramajIngrediente = nullptr;
		this->esteVegana = false;
		NrPrajituri++;
	}
	//destructor
	~Prajitura() {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		if (this->gramajIngrediente != nullptr) {
			delete[] this->gramajIngrediente;
			this->gramajIngrediente = nullptr;
		}
		NrPrajituri--;////ATENTIE

	}
	void setDenumire(char* denumireData) {
		if (strlen(denumireData) > 2) {
			if (this->denumire != nullptr)
				delete[] this->denumire;
			this->denumire = new char[strlen(denumireData) + 1];
			strcpy(this->denumire, denumireData);
		} 

	}
	char* getDenumire() {
		if(this->denumire == nullptr) return nullptr;
		char* copie = new char[strlen(this->denumire) + 1];///ATENTIE
		strcpy(copie, this->denumire);
		return copie;
	}
	void 	setnrCalorii(int nrCaloriiDate) {
		if (nrCaloriiDate > 0)
			this->nrCalorii = nrCaloriiDate;
		else throw  ExceptieCustom("nr neg");
	}
	int getnrCalorii() {
		return this->nrCalorii;
	}
	void setnrIngrediente(int nrIngredienteDate) {
		if (nrIngredienteDate > 0)
			this->nrIngrediente = nrIngredienteDate;
		else throw  ExceptieCustom("nr neg");
	}
	int getnrIngrediente() {
		return this->nrIngrediente;
	}
	void setgramajIngrediente(int nrIngredienteDate, float* gramajIngredienteDat) {
		if (nrIngredienteDate > 0 && gramajIngredienteDat != nullptr) {
			delete[]this->gramajIngrediente;
			this->nrIngrediente = nrIngredienteDate;
			this->gramajIngrediente = new float[nrIngrediente];
			for (int i = 0; i < nrIngredienteDate; i++)
			{
				this->gramajIngrediente[i] = gramajIngredienteDat[i];
			}
		} delete[]gramajIngredienteDat;

	}
	float* getgramajIngrediente() {
		float* copie = new float[nrIngrediente];
		this->gramajIngrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++)
		{
			copie[i] = gramajIngrediente[i];//ATENTIE
		} return copie;
	}
	void setEsteVegana(bool stare) {
		this->esteVegana = stare;

	}
	bool getEsteVegana() {
		return this->esteVegana;
	}

	float getGramajTotal() {
		float GramajTotal = 0;
		for (int i = 0; i < this->nrIngrediente; i++)///
		{
			GramajTotal += this->gramajIngrediente[i];
		} return GramajTotal;
	}
	Prajitura(const Prajitura& sursa) :id(++NrPrajituri) {
		if (sursa.denumire != nullptr) {
			this->denumire = new char[strlen(sursa.denumire) + 1];
			strcpy(this->denumire, sursa.denumire);
		}
		else this->denumire = nullptr;
		this->nrCalorii = sursa.nrCalorii;
		this->nrIngrediente = sursa.nrIngrediente;
		if (sursa.nrIngrediente > 0 && sursa.gramajIngrediente != nullptr) {
			this->gramajIngrediente = new float[sursa.nrIngrediente];
			for (int i = 0; i < sursa.nrIngrediente; i++)///
			{
				this->gramajIngrediente[i] = sursa.gramajIngrediente[i];
			}
		}
		else this->gramajIngrediente = nullptr;
		this->esteVegana = sursa.esteVegana;
	}
	Prajitura& operator=(const Prajitura& sursa) {
		if (this != &sursa) {//ATENTIEEE
			delete[] this->denumire;
			delete[] this->gramajIngrediente;
			if (sursa.denumire != nullptr) {
				this->denumire = new char[strlen(sursa.denumire) + 1];
				strcpy(this->denumire, sursa.denumire);
			}
			else this->denumire = nullptr;
			this->nrCalorii =sursa.nrCalorii;
			this->nrIngrediente = sursa.nrIngrediente;
			if (sursa.nrIngrediente > 0 && sursa.gramajIngrediente != nullptr) {
				this->gramajIngrediente = new float[sursa.nrIngrediente];
				for (int i = 0; i < sursa.nrIngrediente; i++) {
					this->gramajIngrediente[i] = sursa.gramajIngrediente[i];
				}
			}
			else {
				this->gramajIngrediente = nullptr;
			}
			this->esteVegana = false;
		}return*this;
	}
	Prajitura& operator*=(int valoare) {
		if (valoare <= 0) {
			throw  ExceptieCustom("nr neg");
		}
		for (int i = 0; i < nrIngrediente; i++)
		{
			this->gramajIngrediente[i] *= valoare;
		} return*this;
	}
	friend ostream& operator<<(ostream& out, const Prajitura& sursa);
	friend istream& operator>>(istream& in, Prajitura& sursa);


	friend Prajitura operator+(float gramajNou, Prajitura sursa);//ATENTIE
	
	
	bool operator!=(const Prajitura& sursa) { ///
		if (strcmp(this->denumire, sursa.denumire) != 0)/////ATENTIE
			return true;
		if (this->nrCalorii != sursa.nrCalorii)
			return true;
		if (this->nrIngrediente != sursa.nrIngrediente)
			return true;
		if (this->esteVegana != sursa.esteVegana)
			return true;
		if (this->nrIngrediente > 0 && sursa.nrIngrediente > 0) {///
			for (int i = 0; i < this->nrIngrediente; i++) {
				if (this->gramajIngrediente[i] != sursa.gramajIngrediente[i])
					return true;
			}
		}
		return false;
	}

};

 int Prajitura::NrPrajituri = 0;//NU UITA TIPUL RETURNAT
 ostream& operator<<(ostream& out, const Prajitura& sursa) {
	 out << endl << "Denumire data: " << sursa.denumire << endl;
	 out << endl << "Nr calorii: " << sursa.nrCalorii << endl;
	 out << endl << "Nr ingrediente: " << sursa.nrIngrediente << endl;
	 for (int i = 0; i < sursa.nrIngrediente; i++) {
		 out << endl << "Gramaj: " << sursa.gramajIngrediente[i]<<" " << endl;///
	 }
	 out << endl << "Vegan: " << sursa.esteVegana<< endl;
	 out << endl << "Id: " << sursa.id << endl;
	 out << endl << "Nr prajituri: " << Prajitura::NrPrajituri << endl;
	 return out;
 }
 istream& operator>>(istream& in, Prajitura& sursa) {
	 cout << "Introduceti denumire: ";
	 char buffer[100];
	 in >> buffer;

	 if (sursa.denumire != nullptr) delete[] sursa.denumire;
	sursa.denumire = new char[strlen(buffer) + 1];
	 strcpy(sursa.denumire, buffer);

	 cout << "Nr Calorii: ";
	 in >> sursa.nrCalorii;

	 cout << "Este Vegana (1/0): ";
	 in >> sursa.esteVegana;

	 cout << "Nr Ingrediente: ";
	 if (sursa.nrIngrediente > 0)
	 in >> sursa.nrIngrdiente;

	 if (sursa.gramajIngrediente != nullptr) delete[] sursa.gramajIngrediente;
		 sursa.gramajIngrediente = new float[sursa.nrIngrediente];
		 for (int i = 0; i < sursa.nrIngrediente; i++) {
			 cout << "Gramaj ingr " << i + 1 << ": ";///
			 in >> sursa.gramajIngrediente[i];
		 }
	 
	 else {
		 p.nrIngrediente = 0;
		 p.gramajIngrediente = nullptr;
	 }

	 return in;
}

 Prajitura operator+(float gramajNou, Prajitura sursa) {///
	 if (gramajNou > 0) {///
		 Prajitura copie = sursa;
		 float* vectorNou = new float[sursa.nrIngrediente + 1];////ATENTIE
		 for (int i = 0; i < sursa.nrIngrediente; i++) {///
			 vectorNou[i] = sursa.gramajIngrediente[i];
		 }
		 vectorNou[sursa.nrIngrediente] = gramajNou;///ATENTIE
		 delete[] sursa.gramajIngrediente;
		 sursa.gramajIngrediente = vectorNou;///ATENTIE
		 sursa.nrIngrediente++;//ATENTIEE

		 return sursa;//
	 }else throw  ExceptieCustom("nr neg");
 }   
 





int main() {

	
// Testare
float gramaje[] = { 100.5, 50.0, 25.5 };
Prajitura p1((char*)"Ecler", 450, 3, gramaje, false);

cout <<p1;

Prajitura p2;

Prajitura p3(p1); 
cout  << p3;

p1.setnrCalorii(500);
p1 *= 2; 
cout  << p1;

try {
	Prajitura p4 = 50.0f + p1; // Test operator +
	cout << "P4 (P1 + 50g):" << endl << p4;
}
catch (exception& e) {
	cout << e.what() << endl;
}

if (p1 != p3) {
	cout << "P1 si P3 sunt diferite " << endl;
}
else {
	cout << "P1 si P3 sunt la fel." << endl;
}

return 0;
}












	