#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class ExceptieCustom : public exception
{
public:
	ExceptieCustom(const char* mesaj) :exception(mesaj) {}
};

class Masina {
 private:
	string model;
	const string serie;
	int anProductie;
	float kmParcusi;
	float consum;
	int capacitateRezervor;
	float volumCombustibilCurent;
	float static capacitateMotor;



 public:
	//constr implicit/default
	Masina():serie("default") {
		this->model = "model de baza";
		this->anProductie = 0;
		//int const anProductie;nu se initialieaza in constr cu param
		this->kmParcusi = 0;
		this->consum = 0;
		this->capacitateRezervor = 0;
		this->volumCombustibilCurent = 0;
		//const cu toti param
	}
	Masina(string model, int anProductie, float kmParcusi, float consum, int capacitateRezervor, float volumCombustibilCurent):serie("edc000") {
		this->model=model;
		this->anProductie=anProductie;
		//int const anProductie;nu se initialieaza in constr cu param
		if (kmParcusi >= 0) {
			this->kmParcusi = kmParcusi;
		}
		else {
			//cout << endl << "Numar invalid de km" << endl;
			throw ExceptieCustom("Nr km negativ");

		}
		this->consum=consum;
		if (capacitateRezervor > 0 && capacitateRezervor < 100) {
			this->capacitateRezervor = capacitateRezervor;
		}
		else {
			cout << endl << "Capacitate rezervor depasita" << endl;
		}
		if (volumCombustibilCurent >= 0 && volumCombustibilCurent <= capacitateRezervor) {

			this->volumCombustibilCurent = volumCombustibilCurent;
		}
		else { cout<<endl << "Capacitate depasita" << endl; }
		//float static capacitateMotor;nu se initialieaza in constr cu param

}
	Masina(const Masina& sursa) :serie(sursa.serie) {
		this->model = sursa.model;
		this->anProductie = sursa.anProductie;
		this->kmParcusi = sursa.kmParcusi;
		this->consum =sursa.consum;
	    this->capacitateRezervor =sursa.capacitateRezervor;
       this->volumCombustibilCurent =sursa.volumCombustibilCurent;
	}
	Masina& operator=(const Masina& sursa) {
		if (this != &sursa) {
			this->model = sursa.model;
			this->anProductie = sursa.anProductie;
			this->kmParcusi = sursa.kmParcusi;
			this->consum = sursa.consum;
			this->capacitateRezervor = sursa.capacitateRezervor;
			this->volumCombustibilCurent = sursa.volumCombustibilCurent;

		}
		return *this;
	}
	void afisareMasina() {
		cout << endl << "Modelul masinii este: " << this->model << endl;
		cout << endl << "Anul productiei masinii este: " << this->anProductie << endl;
		cout << endl << "Km parcusi de masina: " << this->kmParcusi << endl;
		cout << endl << "Consumul masinii este: " << this->consum << endl;
		cout << endl << "Capacitatea rezervorului masinii este: " << this->capacitateRezervor << endl;
		cout << endl << "Volumul combustiilului curent al masinii este: " << this->volumCombustibilCurent << endl;
		cout << "Serie: " << serie << endl;
		cout << "Capacitate motor: " << Masina::capacitateMotor << endl;
	}
	~Masina() {}
	void setkmParcusi(int kmdati) {
		if (kmdati > 0) {
			this->kmParcusi = kmdati;
		}
		else throw "km negativ";
		
	}
	int getkmParcusi() {
		return this->kmParcusi;
	}
	void setanProductie(int andat) {
		if (andat > 2000 && andat <= 2025) {
			this->anProductie = andat;
		}
	}
	int getanProductie() {
		return this->anProductie;
	}
	string getserie() { 
		return this->serie;
	}
	static void setCapacitateMotor(int cap) {
		if (cap > 0) Masina::capacitateMotor = cap;
	}
	static int getCapacitateMotor() { 
		return Masina::capacitateMotor;
	}

	float operator()() {
		if (this->consum > 0) {
			return (this->volumCombustibilCurent / this->consum) * 100;//consum de l/100km
		}
		else return -1 ;
	}
	explicit operator int()
	{ int impozit = 0;
	if (this->anProductie >= 2000 && this->anProductie < 2010) {
		impozit += 300;

	  }
	else if (this->anProductie >= 2010 && this->anProductie < 2020) {
		impozit += 200;
	}
	else if (this->anProductie >= 2020 && this->anProductie <= 2025) {
		impozit += 100;

	}
	if (Masina::capacitateMotor < 1000) {
		impozit += 100;
	}
	else if (Masina::capacitateMotor >= 1000 && Masina::capacitateMotor < 2000) {
		impozit += 150;
	}
	else if (Masina::capacitateMotor >= 2000 && Masina::capacitateMotor < 3000) {
		impozit += 200;
	}
	else if (Masina::capacitateMotor >= 3000) {
		impozit += 300;
	}
		return impozit ;
	}
	Masina& operator+=(float combustibilAdaugat)
	{
		if (combustibilAdaugat >= 0 && this->volumCombustibilCurent > 0) {
			this->volumCombustibilCurent += combustibilAdaugat;
		}
		return*this;
	}
	float getCombustibilVolum() {
		return this->volumCombustibilCurent;
	}
	Masina operator-( float consumNou) {
		Masina copie(*this);
	copie.consum -= consumNou;
	return copie;
	}
	float getConsum() {
		return this->consum;
	}
	bool operator !=(const Masina& sursa) {
		if (this->kmParcusi != sursa.kmParcusi) {
			return true;

		}
		else { return false; }
	}
	bool operator!() {
		return this->kmParcusi > 0;
	}
	
	float operator[](float kmAdaugati) {
		if (kmAdaugati > 0)
			return this->kmParcusi += kmAdaugati;
		else throw exception();

	}
	friend ostream& operator<<(ostream& out,const Masina& sursa);

	friend istream& operator>>(istream& in,  Masina& sursa);

	Masina& operator++()//pre incrementare
	{
		this->consum++;
		return *this;//returnare referinta

	}
	Masina operator++(int) {
		Masina copie = *this;
		this->consum++;
		return copie;

	}
	operator string() {//cast implicit la string
		return this->model;
	}
	/*explicit operator int() {
	return this->anProductie;
	}*/
	Masina operator+( int km) {
		if (km > 0) {
			Masina copie = *this;
			copie += km;
			return copie;
		}
		else throw ExceptieCustom("nr neg");

	}
	int operator/(int perioadaFolosire) {
		if (perioadaFolosire > 0)
		{
			this->anProductie / perioadaFolosire;
		}
		else throw exception();
	}
	friend Masina& operator-=(Masina& sursa, float x);
	
};
 

float Masina::capacitateMotor = 600;


ostream& operator<<(ostream& out, const Masina& sursa) {// friend ostream& operator<<
	out << endl << "Modelul masinii este: " << sursa.model << endl;
	out << endl << "Anul productiei masinii este: " << sursa.anProductie << endl;
	cout << endl << "Km parcusi de masina: " << sursa.kmParcusi << endl;
	out << endl << "Consumul masinii este: " << sursa.consum << endl;
	out << endl << "Capacitatea rezervorului masinii este: " << sursa.capacitateRezervor << endl;
	out << endl << "Volumul combustiilului curent al masinii este: " << sursa.volumCombustibilCurent << endl;
	out << "Serie: " << sursa.serie << endl;
	out << "Capacitate motor: " << Masina::capacitateMotor << endl;
	return out;
}
	istream& operator>>(istream& in,  Masina& sursa) {

		cout << endl << "Modelul masinii este: ";
		in >> sursa.model;
		cout << endl << "Anul productiei masinii este: ";
		in >> sursa.anProductie;
		cout << endl << "Km parcusi de masina: ";
		if (sursa.kmParcusi > 0)
			in >> sursa.kmParcusi;
		else throw exception();
		cout << endl << "Consumul masinii este: ";
		in >> sursa.consum;
		cout << endl << "Capacitatea rezervorului masinii este: ";
		if (sursa.capacitateRezervor > 0 && sursa.capacitateRezervor < 100)
			in >> sursa.capacitateRezervor;
		else throw exception();
		cout << endl << "Volumul combustiilului curent al masinii este: ";
		if (sursa.volumCombustibilCurent >= 0 && sursa.volumCombustibilCurent <= sursa.capacitateRezervor)
			in >> sursa.volumCombustibilCurent;
		else throw exception();
		//cout << "Serie: "; 
		//in >> sursa.serie; 
		//cout << "Capacitate motor: ";
		//in >> Masina::capacitateMotor;
		return in;
	}
	Masina& operator-=(Masina&sursa, float x) {
		sursa.consum -= x;
		return sursa;  
	}


int main(){
	
	Masina m1("FORD", 2020, 45.5, 6.7, 40, 20);
	Masina m3("DACIA", 2021, 39.8, 7.8, 50, 47);
	Masina m2(m1);

	m1.afisareMasina();
	m2.afisareMasina();
	m3.afisareMasina();
	m1 = m3;
	m1.setkmParcusi(20);
    m3.setanProductie(2024);
	cout<<endl<<"Km parcusi: "<< m1.getkmParcusi()<<endl;
	cout << endl << "An productie: " << m3.getanProductie() << endl;
	Masina::setCapacitateMotor(1400);
	cout << endl << "Capaciate motor: " << Masina::getCapacitateMotor() << endl;
	float distanta = m1();

	cout << endl << "Distanta ce poate fi parcursa de masina este: " << m1() << "km" << endl;
	int impozit = (int)m1;
	cout << "Impozitul platiti de masina este: " << (int)m1 << endl;

	m2 += (13);
	cout << endl << "Volum combustibil: " << m2.getCombustibilVolum() << endl;
	m2=m3 - 2;
	cout << endl << "consum: " << m2.getConsum() << endl;//trb apelat pt noul obiect;
	if (m1 != m3) {
		cout << endl << "Masini diferite";
	}
	else cout << endl << "Masini identice";
	
	!(m2);
	m3[20];
	m3.afisareMasina();
	/*try {
		Masina m1("FORD", 2020, -2, 6.7, 40, 20);
	}
	catch (ExceptieCustom e) {
		cout << endl << e.what();
	}*/
	try {
		m1.setkmParcusi(-2);
	}
	catch (const char* mesaj) {
		cout << endl << "km negativ";
	}
	cout << m2;
	cin >> m1;
	cout << m1;
	/*catch (int cod) {
		cout << endl << cod;
	}
	catch (...) {
		cout << endl << "Valoare negativa sau 0!";
	}
	cout << endl << "Nr ingrediente nou: " << sushi->getNrIngrediente();*/
	m2=++m1;
	m3 = m2++;
	string model=m2;
	int anProductie=(int)m3;
	m1 + (-3);
	m2 / (12);
	operator-=(m1, 10);
	return 0;
}
