#include<iostream>
using namespace std;
#pragma warning ( disable:4996) // ca sa nu va mai dea eroare la strcpy 


class Magazin
{
private:


	// atribute 
	char* nume; // numele magazinului 
	bool stare; //  1 este deschis, 0 este inchis. 
	int nrVenituri;// nr de produse vandute de magazin  care fiecare produs reprezinta un venit 
	float* venituri; // lista cu venituri magazinului 
	double cheltuieli;// cheltuieli totale 
	const int anInfiintare = 2004;// trebuie sa fie neaparat intializat in constructori. odata initializat nu se mai poate modifica valaorea

	// static 
	static int anCurent;// acest an curent descrie toate obiectele de tip magazin cu aceasi valoarea, acesta se declara in clasa si se initializeaza in afara clasei.
	// atentie sa il initializati ca altfel primiti erori de link editare , deci neaparat trebuie initializat.
	// atentie acest camp static nu tine de un obiect anume, adica nu tine de this.. tine de clasa
	// el se acceseaza asa: Magazin::anCurent;

	// generarea unui id(id ul asta poate fi si constant... in majoritatea cazurilor) unic pe baza unui camp static. 
	const int id;
	static int contor;



	// incapsulare - este prop poo de atine datele membre(atribule) in zona privata
	// si de a da acces la ele prin fucntii publice care aceste fctt publice ofera un acces restrictionat in asa fel incat sa nu altereze cineva datele din clasa cu ajutorul functiilor din public 

public:


	// Metode - sunt niste functii specifice doar clasei voastre. 
	// aceste metode sunt implementate de voi programatorii. 
	// si au proprietatea de a se apela doar pentru obiectele de tip magaizn. 
	// /// aceste metode se sscriu doar in interiorul clasei.
	// acestea mai au proprietatea de a primi ca prim parametru implicit pointerul this 
	// this este un pointer ce retine adresa de memorie a obiectului pentru care s a apelat o functie. 


	// am declarat o metoda care dorim sa afiseze numele unui obiect. 
	void afisareNume()
	{
		cout << "Numele este: " << this->nume << endl;
	}


	void afisare()
	{
		cout << "Numele este: " << this->nume << endl;
		cout << "An infiintare  : " << this->anInfiintare << endl;
		cout << "chel   : " << this->cheltuieli << endl;

	}


	// Un cosntructor este o metoda ce are rolul de a construi obiecte.
	// a construi inseamna a declara un obiect si al initializa. 
	// nu se specifica tipul returnat pentru cosntructor, numele lor de metoda  este numele CLASEI si lista de parametri care paote fi goala daca nu are parametri sau poate avea oricati parametri vrei tu.
	// cum se apelaza: numeleClasei numeleOb si lista de param daca e nevoie.
	// EX: Magazin z;  sau Magazin z1("La Costel"); Magazin m2("La un pas",600);


	// constructorul fara parametri 
	Magazin() :id(Magazin::contor++)
	{
		this->cheltuieli = 0;
		this->stare = false;
		this->nume = new char[strlen("na") + 1];
		strcpy(this->nume, "na");
		this->nrVenituri = 0;
		this->venituri = NULL;
	}




	// constructor cu toti parametri
	// Magazin z2(        "La 2 pasi", 2005,    true,          400.0,              3,  venituri_db );
	Magazin(const char* numeDat, int anInfiintareDat, bool stareData, double chelDat, int nrVenituriDate, float* venituriDate) :anInfiintare(anInfiintareDat), id(Magazin::contor++)
	{

		if (chelDat >= 0) {
			this->cheltuieli = chelDat;
		}
		else {
			this->cheltuieli = 0;
		}

		// la stare pt ca e bool ... poti lasa asa... 
		this->stare = stareData;


		if (strlen(numeDat) > 2) {
			this->nume = new char[strlen(numeDat) + 1];
			strcpy(this->nume, numeDat);
		}
		else {
			this->nume = new char[strlen("na") + 1];
			strcpy(this->nume, "na");
		}


		if (nrVenituriDate > 0 && venituriDate != NULL) {
			this->nrVenituri = nrVenituriDate;
			this->venituri = new float[nrVenituriDate];
			for (int i = 0; i < nrVenituriDate; i++)
			{
				if (venituriDate[i] >= 0) {
					this->venituri[i] = venituriDate[i];
				}
				else {
					this->venituri[i] = 0;
				}

			}
		}
		else {
			this->nrVenituri = 0;
			this->venituri = NULL;
		}



	}



	Magazin(const char* numeDat, double chelDat) :id(Magazin::contor++)
	{
		this->stare = false;

		if (strlen(numeDat) > 2) {
			this->nume = new char[strlen(numeDat) + 1];
			strcpy(this->nume, numeDat);
		}
		else {
			this->nume = new char[strlen("na") + 1];
			strcpy(this->nume, "na");
		}
		if (chelDat >= 0) {
			this->cheltuieli = chelDat;
		}
		else {
			this->cheltuieli = 0;
		}

		this->nrVenituri = 0;
		this->venituri = NULL;

	}








	// Destructor - este o metoda ce ne ajuta sa stergem obiecte din memorie.
	// atentie trebuie sa stergem memoria alocata dinamic.
	// acest destructor se apeleaza automat daca obiectele sunt puse in stiva/\
	// explicit daca ob sunt puse in heap

	~Magazin()
	{
		Magazin::contor--;
		delete[] this->nume;
		delete[] this->venituri;
	}




	// constructor de copiere - este o metoda care creaza in memorie un nou obiect si il intitalizeaza cu datele dintr un alt obiect deja existent 
	// deep copy -> deoarece ai explicitat  cum se gestioneaza memoria alocata dinamic.
	// shallow copy-> este o copiere facuta de compilator automata, dar aceasta nu stie sa gestioneze memoria alocata dinamic.
	//Magazin z4(z2);
	Magazin(const Magazin& sursa) :anInfiintare(sursa.anInfiintare), id(Magazin::contor++)
	{
		this->stare = sursa.stare;
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);
		this->cheltuieli = sursa.cheltuieli;
		this->nrVenituri = sursa.nrVenituri;
		this->venituri = new float[sursa.nrVenituri];
		for (int i = 0; i < sursa.nrVenituri; i++)
		{
			this->venituri[i] = sursa.venituri[i];
		}
	}








	// op=
	// z=z2;  //  z este ob pt care s a apelat fct si intra in this si z2 intra in sursa
	Magazin& operator=   (const Magazin& sursa)
	{

		if (this != &sursa) {// test de auto asignare 
			delete[] this->nume;
			delete[] this->venituri;
			this->stare = sursa.stare;
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
			this->cheltuieli = sursa.cheltuieli;
			this->nrVenituri = sursa.nrVenituri;
			this->venituri = new float[sursa.nrVenituri];
			for (int i = 0; i < sursa.nrVenituri; i++)
			{
				this->venituri[i] = sursa.venituri[i];
			}
		}



		return *this;
	}
	// Magazin&  si *this ne ajuta sa returnam ob pt care s a apelat fct 
	// returnarea asta te ajuta la apel in cascada:  z=z2=z3=z4 toata lumea e ca z4 




	// functii accesor de tip get 
	float getCheltuieli() {
		return this->cheltuieli;
	}

	bool getStare() {
		return this->stare;
	}


	// z3.getNume();
	char* getNume()
	{
		char* copie_nume;
		copie_nume = new char[strlen(this->nume) + 1];
		strcpy(copie_nume, this->nume);
		return copie_nume;
	}


	char* getNumeEasy() {
		return this->nume;
	}

	int getAnInfiintare()
	{
		return this->anInfiintare;
	}



	// am declaarat un get pt campul static, atentie acest get er este o metoda putin mai speciala deoarece este una static... 
	// o metoda statica se apleaza pentru clasa... NU PENTRU OB... atentie nu primeste this ca prim parametru.
	// Magazin::getAnCUrent();
	static int getAnCurent() {
		return Magazin::anCurent;
	}





	// sett eri care ne ajuta sa schimbam valorile atributelor private 

	// z3.setNume("SRL MEGA");
	void setNume(const char* numeNou)
	{
		if (strlen(numeNou) > 2)
		{
			delete[] this->nume;
			this->nume = new char[strlen(numeNou) + 1];
			strcpy(this->nume, numeNou);
		}

	}




	// set pentru celalt camp dinamic. 
	void setVenituri(int nrVenituriDate, float* venituriDate)
	{
		if (nrVenituriDate > 0 && venituriDate != NULL) {
			delete[]this->venituri;
			this->nrVenituri = nrVenituriDate;
			this->venituri = new float[nrVenituriDate];
			for (int i = 0; i < nrVenituriDate; i++)
			{
				if (venituriDate[i] >= 0) {
					this->venituri[i] = venituriDate[i];
				}
				else {
					this->venituri[i] = 0;
				}

			}
		}
	}






	void setCheltuieli(double chelNoi)
	{
		if (chelNoi >= 0) {
			this->cheltuieli = chelNoi;
		}
	}

	void setStare(bool s) {
		this->stare = s; // nu prea are sens conditii validari ca bool e doar 0 sau 1 .
	}


	// seter - nu face seteter am zis mai sus odata initializat in cosntructorii nu mai poate fi modificat.!


	// set pt campul static
	static void setAnCurent(int anNou)
	{
		if (anNou >= 2000) {
			Magazin::anCurent = anNou;
		}
	}



	friend ostream& operator<< (ostream& out, Magazin sursa);
	friend istream& operator>> (istream& in, Magazin& sursa);





	// m1.maresteCheluieli(200.0);
	void maresteCheluieli( float val)
	{
		this->cheltuieli += val;
	}



	//  operatori aritmetici compusi += -= /=  *=  %= 
	// tipul returnat sa fie o referinta la tipul clasei, sa aiba doar 2 param, la final sa returneze *this si sa faca modificari pe this.
	Magazin& operator+= (float val)
	{
		this->cheltuieli += val;
		return *this;
	}





	// operatori aritmetici  + - * / % 
	// returnam o copie la tipul clasei, primeste 2 parametri,  face o copie , modifica copia returneaza copia ... copia este copia ob pt care s a apelat functia... bineitneles iti trebuie const copiere.
	// m1+200.0;
	Magazin operator+ (float val)
	{
		Magazin copie(*this);
		copie.cheltuieli += val;
		return copie;
	}




	// operatori de incrementare si decrementare ++ -- 
	// cu formele post si pre 

	// fomar pre !!!
	// returneaza o referinta, si modifica obiectul cu o valoare in mod implicit.
	//  ++m1;
	// sa se mareasca m1 cu 100 atunci cand zicem ++m1;
	Magazin& operator++()
	{
		this->cheltuieli += 100;
		return *this;
	}

	// forma ++ post  z2++;
	// returnam o copie, facem o copie, modifica THIS, returnzi copia nemodificata intacta, ATENTIE sa nu modifici copia
	Magazin operator++ (int)
	{
		Magazin copie(*this);
		this->cheltuieli += 100;
		return copie;
	}




	// operatori relationali > < == != >=  <= 
	// returneaza o valoare booleana pe baza comparatiei unui obiect cu ceva anume ce vrei tu. un param dat de tine.
	// z2>=200; 
	bool operator>= (float val)
	{
		if (this->cheltuieli >= val) {
			return true;
		}
		else {
			return false;
		}
	}



	// operatorul index..[]
	// z2[-2]
	// & la tipul returnat da rol de modificare 
	float operator[] (int index)
	{
		if (index >= 0 && index < this->nrVenituri)
		{
			return this->venituri[index];
		}
		else {
		     throw new exception();// blocam executia programului 
		}

	}




	// operator ()  
	// acest op ()  face ce vrei tu sa faca si are ce regului vrei tu sa aibe.
	// sa se faca operatorul () care mareste cheluiala cu o valoare data ca param
	// x2(200);
	void operator() (float val)
	{
		this->cheltuieli += val;
	}




	// operator cast  / de conversie 
	// atunci cand incercam sa punem un magazin intr un float defapt sa se puna  cheltuiala magazinului in acel float.
	explicit operator float()
	{
		return this->cheltuieli;
	}

 


	// operator ! de negatie...
	// returneaza un bool negat.
	bool operator! ()
	{
		return !this->stare;
	}




	// operator  ~
	// asta face ce vrei tu sa faca,... doar ca
	// primeste ca parametru doar ob pt care s a apelat fct. 
	// schimba starea obiectului din false in true si din true in false/
	void operator~ ()
	{
		if (this->stare == 1) {
			this->stare = false;
		}
		else {
			this->stare = true;
		}
	}
	












};
int Magazin::anCurent = 2025;// initializarea campului static. 
int Magazin::contor = 0;



////                        cout <<       z3;
ostream& operator<< (ostream& out, Magazin sursa) // sursa este copia obiectului Z3.
{

	out << "Nume : " << sursa.nume << endl;
	out << "id : " << sursa.id << endl;
	out << "an : " << sursa.anInfiintare << endl;
	out << "stare : " << sursa.stare << endl;
	out << "chel : " << sursa.cheltuieli << endl;
	out << "nr veni : " << sursa.nrVenituri << endl;
	out << "veniturile: ";
	for (int i = 0; i < sursa.nrVenituri; i++) {
		out << sursa.venituri[i] << " ";
	}
	out << endl << endl;

	return out; // te ajuta la cascada: cout<<z3<<z2<<endl;
}

// cin>> z3;
istream& operator>> (istream& in, Magazin& sursa) // sursa se transmite mereu prin referinta. 
{

	// sa facem citirea fiecauri atribut.

	cout << "Das numele: ";
	char buffer[200];
	in >> buffer; // kaufland 
	sursa.setNume(buffer);

	//cout << "Da starea: ";
	//bool s;
	//in >> s;
	//sursa.setStare(s);

	cout << "Da starea: ";
	in >> sursa.stare;


	cout << "Da chel: ";
	float chel;
	in >> chel;
	sursa.setCheltuieli(chel);

	int nr;
	float aux[200];
	cout << "Da nr de venituri: ";
	in >> nr;
	for (int i = 0; i < nr; i++) {
		cout << "Da venitul pt incasarea " << i + 1 << ": ";
		in >> aux[i];
	}
	sursa.setVenituri(nr, aux);

	// campul static nu are sens sa ils etezi
	// ca pul constant nu merege citit. 



	return in;
}


int main()
{

	// char int float double bool 

	int x;  // int x=6;
	x = 6;

	Magazin y;

	float  venituri_db[3] = { 100,500,300 };
	// acum nu mai scriem asa ca avem csontructor cu toti parametyri 
	//y.stare = true;
	//y.nume = new char[strlen("Mega") + 1];
	//strcpy(y.nume, "Mega");
	//y.cheltuieli = 600;
	//y.nrVenituri = 3;
	//y.venituri = new float[y.nrVenituri];
	//
	////                     0   1   2 <3


	//for (int i = 0; i < y.nrVenituri; i++)
	//{
	//	y.venituri[i] = venituri_db[i];
	//}

	// acum putem sa zicem ca am initializat obiectul y.

	Magazin z;



	// am apelat metoda afisaerNume pntru un magazin
 


	Magazin z2("La 2 pasi", 2005, true, 400.0, 3, venituri_db);

	Magazin z3("Mega", 2008, false, 500.0, 3, venituri_db);


	float sumaZ2_Z3 = z2.getCheltuieli() + z3.getCheltuieli();


	// daca zice profesorul cum se apealza destructorul in mod explicit 
	// faci asta 
	// de aici
	Magazin* pm;
	pm = new Magazin();
	//pm->afisareNume();// asta cu afisare nu e musai sa o faci.
	delete pm;// s a apelat destructorul 
	pm = NULL;
	//pana aici 
	//daca profesorul nu zici aceasta cerinta, atuci e suficienta implemetare destructorului in clasa


 

	Magazin z4(z2);// apel cosntructor copiere.


	// operator= 
	z = z2;


	// vreau sa vad cat a cheluit z3 si z4 imrpeuna 

	float totalCheluieli_Z4_z3;
	totalCheluieli_Z4_z3 = z3.getCheltuieli() + z4.getCheltuieli();

	z3.setNume("SRL MEHA IMAGE");


	char* numeZ3 = z3.getNume();

//	cout << numeZ3 << endl;

	delete[] numeZ3;


//	cout << z3.getNumeEasy() << endl;


	z3.setNume("SRL MEGA");


	//cout << Magazin::getAnCurent() << endl;
	Magazin::setAnCurent(2026);

	// cout << endl;
	// cout << z3 << z << z2;



	// >>    cin>> z3;  citeste date de la tastatura.
	/// noi bagam niste date de la tastatura 
	// si le setam in obiectul z3. 


	// cin >> z3;
	// cout << z3;


	cout << z2;
	z2 += 200.0;

 
	z2 = z2 + 200.0;// op+ creaza un obiect nou pe baza lui z2 care are animute valori marite cu ce valoare dati voi ca param. apoi il returneaza pe acest obiect5 
	// z2 =100;
	 ++z2 ;

	 //
	 z2++ ;

	cout << z2;


	if (z2 >= 200) {
		cout << "z2 intra in faliment ca are chel mai amre de 200" << endl;
	}
	else {
		cout << "Z2 e barosan nu cheluie banii ii pune la ciorap" << endl;
	}
 

	// apel op []

	// index cu rol de modificare 

	// z2[2] = 400; aici [] are rol de mdofiicare dar treebuie & la tipulk returnat 

	z2(200.0);
	cout << z2;
	cout << z2[2] << endl;
	 
	// cast implicit la float 
	// float xyz = z2;

	// sa faceti cast explicit la float 
	float xyz = (float)z2;

	~z2; // am schimbat starea lui z2./ 


	cout << (!z2);






	return 0;
}







