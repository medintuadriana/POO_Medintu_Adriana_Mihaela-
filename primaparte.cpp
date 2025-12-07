#include<iostream>
using namespace std;
#pragma warning (disable:4996)



void afisare(char* numeDat, char genDat, bool bugetDat, float bursaDat, int nrNoteDat, int * noteDat)
{
	 
	cout << "Numele este: " << numeDat << endl;
	cout << "gen este: " << numeDat << endl;
	cout << "buget este: " << numeDat << endl;
	cout << "bursa este: " << numeDat << endl;
	cout << "nrNote este: " << numeDat << endl;
	cout << "notele sunt : ";
	for (int i = 0; i < nrNoteDat; i++)
	{
		cout << noteDat[i] << " ";
	}
	cout << endl << endl;
 


}



void modificaGen(char* pgen, char genDat)
{
	*pgen = genDat;
}





void modificaNume( char** pnume, const char* numeDat )
{

	  delete [] * pnume;
	*pnume = new char[strlen(numeDat) + 1];
	strcpy(*pnume, numeDat);

}





class Student
{
private:

	char* nume;
	char gen;
	bool buget;
	float bursa;
	int nrNote;
	int* note;

	

public:



	
	void metodaLaMisto()
	{
		cout << " Sunt facuta la misto" << endl;
	}


	// afisare()

	// s.afisare();
	void afisare()
	{
 
		cout << "Numele este: " << this->nume << endl;
		cout << "gen este: " << this->gen << endl;
		cout << "buget este: " << this->buget << endl;
		cout << "bursa este: " << this->bursa << endl;
		cout << "nrNote este: " << this->nrNote << endl;
		cout << "notele sunt : ";
		for (int i = 0; i < this->nrNote; i++)
		{
			cout << this->note[i] << " ";
		}
		cout << endl << endl;


	}





	
	Student()
	{
		this->buget = false;
		this->bursa = 0;
		this->nume = new char[strlen("na") + 1];
		strcpy(this->nume, "na");
		this->note = NULL;
		this->nrNote = 0;
		this->gen = '-';

	}
  

	
	Student(const char* numeDat, char genDat, bool bugetDat, float bursaData, int nrNoteDate, int * noteDate)
	{
		if (strlen(numeDat) > 2)
		{
			this->nume = new char[strlen(numeDat) + 1];
			strcpy(this->nume, numeDat);
		}
		else {
			this->nume = new char[strlen("na") + 1];
			strcpy(this->nume, "na");
		}
		if (genDat == 'f' || genDat == 'm') {
			this->gen = genDat;

		}
		else {
			this->gen = '-';
		}
		this->buget = bugetDat;

		if (bursaData >=0 ) {
			this->bursa = bursaData;

		}
		else {
			this->bursa = 0;
		}

		if (nrNoteDate >= 1 && note != NULL) {
			this->nrNote = nrNoteDate;
			this->note = new int[nrNoteDate];
			for (int i = 0; i < nrNoteDate; i++)
			{
				this->note[i] = noteDate[i];
			}
		}
		else {
			this->note = NULL;
			this->nrNote = 0;
		}



	}


	Student(const char* numeDat, char genDat )
	{
		if (strlen(numeDat) > 2)
		{
			this->nume = new char[strlen(numeDat) + 1];
			strcpy(this->nume, numeDat);
		}
		else {
			this->nume = new char[strlen("na") + 1];
			strcpy(this->nume, "na");
		}
		if (genDat == 'f' || genDat == 'm') {
			this->gen = genDat;

		}
		else {
			this->gen = '-';
		}
		this->buget = false;
		this->bursa = 0;
		this->nrNote = 0;
		this->note = NULL;

	}




	
	~Student()
	{
		delete[] this->nume;
		delete[] this->note;
	}
	

	
	Student( const  Student & sursa)  //  
	{
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);
		this->gen = sursa.gen;
		this->buget = sursa.gen;
		this->bursa = sursa.bursa;
		this->nrNote = sursa.nrNote;
		this->note = new int[sursa.nrNote];
		for (int i = 0; i < sursa.nrNote; i++)
		{
			this->note[i] = sursa.note[i];
		}

	}




	
	Student& operator= (const  Student& sursa)  
	{
		if (this != &sursa) // test de auto asignare
		{
			delete[] this->nume;
			delete[] this->note;
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
			this->gen = sursa.gen;
			this->buget = sursa.gen;
			this->bursa = sursa.bursa;
			this->nrNote = sursa.nrNote;
			this->note = new int[sursa.nrNote];
			for (int i = 0; i < sursa.nrNote; i++)
			{
				this->note[i] = sursa.note[i];
			}
		}
    
		return *this; 
	}




	
	void setNume(const char* numeDat)
	{
		if (strlen(numeDat) > 2) 
		{
			delete[] this->nume;
			this->nume = new char[strlen(numeDat) + 1];
			strcpy(this->nume, numeDat);
		}
	}


	void setGen(char genDat)
	{
		if (genDat == 'f' || genDat == 'm') {
			this->gen = genDat;

		}
	}

	void setBuget(bool b)
	{
		this->buget = b;
	}

	void setBursa(float bursaData)
	{
		if (bursaData >= 0) {
			this->bursa = bursaData;

		}

	}


	void setNote(int nrNoteDate, int* noteDate)
	{
		if (nrNoteDate >= 1 && note != NULL) {
			delete[] this->note;
			this->nrNote = nrNoteDate;
			this->note = new int[nrNoteDate];
			for (int i = 0; i < nrNoteDate; i++)
			{
				this->note[i] = noteDate[i];
			}
		}
	}

	
	
	
	
	

	float getBursa()
	{
		return this->bursa;
	}

	bool  getBuget() {
		return this->buget;
	}

	char  getGen() {
		return this->gen;
	}

	char* getNume() {

		char* vn = new char[strlen(this->nume) + 1];
		strcpy(vn, this->nume);
		return vn ;
	}

	int getNrNote() {
		return this->nrNote;
	}


	int* getNote()
	{
		int* vn = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
		{
			vn[i] = this->note[i];
		}

		return vn;
	}



};

 




int main()
{
	int vectorAux[100] = { 6,7,4 };
	char * nume;
	char gen;
	bool buget;
	float bursa;
	int nrNote;
	int* note;
 

	nume = new char[ strlen("Gigel")+1];
	strcpy(nume, "Gigel");
	gen = 'm';
	buget = true;
	bursa = 100;
	nrNote = 3;
	note = new int[nrNote];
	for (int i = 0; i < nrNote; i++)
	{
		note[i] = vectorAux[i];
	}

	char* nume1;
	char gen1;
	bool buget1;
	float bursa1;
	int nrNote1;
	int* note1;

	nume1 = new char[strlen("Gigela") + 1];
	strcpy(nume1, "Gigela");
	gen1 = 'f';
	buget1 = true;
	bursa1 = 100;
	nrNote1 = 3;
	note1 = new int[nrNote1];
	for (int i = 0; i < nrNote1; i++)
	{
		note1[i] = vectorAux[i]+1;
	}


	modificaGen(&gen, 'f');
	modificaNume(&nume, "Ana");


	afisare(nume, gen,buget,bursa,nrNote,note );
	afisare(nume1, gen1,buget1,bursa1,nrNote1,note1 );


	
	Student s ("Mrian",'m',false,  900, 3, vectorAux);
 
	// 
	s.setNume("IOANA");
	s.setNote(3, new int[3]{6,6,6});
	s.setGen('f');
	s.setBursa(100);
	s.setBuget(false);

	char* numeS = s.getNume();
	 
	cout << numeS << endl;

	delete[] numeS;


	int* noteS = s.getNote();

	for (int i = 0; i < s.getNrNote(); i++)
	{
		cout << noteS[i] << " ";
	}
	cout << endl << endl;
	delete[] noteS;




	Student s1;

	

	// mamaa??? cata bursa are s si s1 impreuna? ca sa stim cat alocam buget la scoala pentru ei. 

	float bursaStudenti = s.getBursa()+ s1.getBursa();



	Student* ps;
	ps = new Student("Fanel", 'm');
	 
// 	(*ps).afisare();
// 	ps->afisare(); // metodele pentru pointeri se apealza cu ->
	
	delete ps; // fara []  ca in ps e doar un obiect. 

	Student* vectorDInamic;

	vectorDInamic = new Student[5];

	delete[] vectorDInamic; // cu [] ca e vector 

	//de cate ori am dat delete s a apelat destructorul in mod explicit de noi. 

 




	/*
	
	Sa se gestioneze clasa Tren

	trenul este descris de: 

	punctPlecare - > sir caractere alocat dinamic ce reprezinta locul de udne pleaca trenul
	destinatie -> sir de caractere unde ajunge trenul
	distanta -> nr de kiloemtri parcursi de teren 
	nrLocuri -> capactiatea trenului.
	locuri -> vecor dinamic de booleane ce spune cate locuri sunt ocvupate true=ocupat.
	clasa -> char care este A B C D .. reprezinta clasa trenului de lucx A 
	pret -> nr real ce reprezinta pretul unui bilet.



	// sa se faca constructori fara apram cu param, cu 2 param, cu 4 param , de copeire, 
	// destructor\
	//op =
	// toti seterii si toti geterii 
	// fucntie de afisare metoida.

	//sa se faca metoida ce returneaza pretul pe kiloemtru.
	// sa se calculeze veniturile per tren. 


	
	
	
	
	
	
	
	*/











	return 0;
}



