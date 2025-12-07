#include<iostream>
using namespace std;

 
enum Transport{ avion, masina, barca};

class Sejur
{
private:
	const int id;
	string destinatie;
	float pretBaza;
	int nrExcursiiOptionale;
	float* preturiExcursii;
	int durata; // nr zile 
	Transport transport;



public:


	Sejur(int idDat):id(idDat)
	{
		this->destinatie = "na";
		this->pretBaza = 0;
		this->nrExcursiiOptionale = 0;
		this->preturiExcursii = NULL;
		this->durata = 0;
		this->transport = masina;
	}


	int getDurata()
	{
		return this->durata;
	}

	Transport getTransport()
	{
		return this->transport;
	}

	void setDurata(int durataNoua)
	{
		if (durataNoua >= 1) {
			this->durata = durataNoua;
		}
	}


	void setTransport( Transport  transportNou)
	{
			this->transport = transportNou;		 
	}

 // Sejur s1( 102,             "Dubai",                 avion,             5,                2000,                3,      new float[3]{100, 350, 150});
	Sejur(int idDat, string destinatieData, Transport trasnportDat, int durataData, float pretBazaDat, int nrExcursiiDate, float* preturiDate) :id(idDat)
	{
		this->destinatie = destinatieData;
		this->pretBaza = pretBazaDat;
		this->nrExcursiiOptionale = nrExcursiiDate;
		this->preturiExcursii = new float[nrExcursiiDate];
		for (int i = 0; i < nrExcursiiDate; i++)
		{
			this->preturiExcursii[i] = preturiDate[i];
		}
		this->durata = durataData;
		this->transport = trasnportDat;
	}


	~Sejur()
	{
		delete[] this->preturiExcursii;
	}


	// Sejur s2(s1);
	Sejur( const Sejur & sursa  ) :id(sursa.id )
	{
		this->destinatie = sursa.destinatie;
		this->pretBaza = sursa.pretBaza;
		this->nrExcursiiOptionale = sursa.nrExcursiiOptionale;
		this->preturiExcursii = new float[sursa.nrExcursiiOptionale];
		for (int i = 0; i < sursa.nrExcursiiOptionale; i++)
		{
			this->preturiExcursii[i] = sursa.preturiExcursii[i];
		}
		this->durata = sursa.durata;
		this->transport = sursa.transport;
	}




	Sejur  &operator= (const Sejur& sursa)  
	{
		if (this != &sursa)//test autoasignare dadaca vrei sau e cerut 
		{
			delete[] this->preturiExcursii;
			this->destinatie = sursa.destinatie;
			this->pretBaza = sursa.pretBaza;
			this->nrExcursiiOptionale = sursa.nrExcursiiOptionale;
			this->preturiExcursii = new float[sursa.nrExcursiiOptionale];
			for (int i = 0; i < sursa.nrExcursiiOptionale; i++)
			{
				this->preturiExcursii[i] = sursa.preturiExcursii[i];
			}
			this->durata = sursa.durata;
			this->transport = sursa.transport;
		}
		


		return *this;
	}




	//200 300 500

	 friend ostream& operator<<(ostream& out, Sejur sursa);
 


	 float getMax()
	 {
		 float max = 0;
		 if (this->nrExcursiiOptionale > 0)
		 {
			 max = this->preturiExcursii[0];
			 for (int i = 0; i < this->nrExcursiiOptionale; i++)
			 {
				 if (max < this->preturiExcursii[i])
				 {
					 max = this->preturiExcursii[i];
				 }
			 }

		 }


		 return max;
	 }


	 //s1<23;
	 bool operator< (float val)
	 {
		 if (this->getMax() < val)
		 {
			 return true;
		 }
		 else {
			 return false;
		 }


	 }


	 friend bool operator<= (float val, Sejur sursa);
	 friend istream& operator>>(istream& in, Sejur& sursa);






	 float getMin()
	 {
		 float min = 0;
		 if (this->nrExcursiiOptionale > 0)
		 {
			 min = this->preturiExcursii[0];
			 for (int i = 0; i < this->nrExcursiiOptionale; i++)
			 {
				 if (min > this->preturiExcursii[i])
				 {
					 min = this->preturiExcursii[i];
				 }
			 }

		 }


		 return min;
	 }


	 void eliminaElement(int val_de_eliminat)
	 {
		 int poz = -1;
		 for (int i = 0; i < this->nrExcursiiOptionale; i++)
		 {
			 if (val_de_eliminat == this->preturiExcursii[i])
			 {
				 poz = i;
				 break;
			 }
		 }

		 if (poz >= 0)
		 {
			 float* vn = new float[this->nrExcursiiOptionale - 1];
			 int k = 0;
			 for (int i = 0; i < this->nrExcursiiOptionale; i++)
			 {
				 if (i != poz)
				 {
					 vn[k] = this->preturiExcursii[i];
					 k++;
				 }

			 }

			 delete[] this->preturiExcursii;
			 this->preturiExcursii = vn;
			 this->nrExcursiiOptionale--;


		 }



	 }



	 Sejur operator--(int)
	 {
		 Sejur copie = (*this);

		 float  min = this->getMin();

		 for (int i = 0; i < this->nrExcursiiOptionale; i++)
		 {
			 if (min == this->preturiExcursii[i])
			 {
				 this->eliminaElement(min);
			 }

		 }


		 return copie;

	 }





	 explicit operator float()
	 {
		 float s = 0;
		 s += this->pretBaza;
		 for (int i = 0; i < this->nrExcursiiOptionale; i++)
		 {
			 s += this->preturiExcursii[i];
		 }
		 return s;

	 }
 
	 void sortareCrescatoare()
	 {
		 for (int i = 0; i < this->nrExcursiiOptionale; i++)
		 {

			 for (int j = i + 1; j < this->nrExcursiiOptionale; j++)
			 {
				 float aux;
				 if (this->preturiExcursii[i] > this->preturiExcursii[j])
				 {
					 aux = this->preturiExcursii[i];
					 this->preturiExcursii[i] = this->preturiExcursii[j] ;
					 this->preturiExcursii[j] = aux;
				 }

			 }


		 }


	 }


	 int getNrMaximExcursii(float bugetMaximSejur)
	 {
		 int k = 0; //nr de excursii

		 float baniRamasi; // banii ramasi dupa ce am achetat excursia de baza, baniir amsi pentru excursiile optionale

		 //                 2200    -  2000
		 baniRamasi = bugetMaximSejur-this->pretBaza; // banii ramasi sunt 200.

		 if (baniRamasi >= 1)
		 {
			 this->sortareCrescatoare();

			 //0- 2 
			 // banii ramasi=0 
			 //     150 350
			 
			 for (int i = 0; i < this->nrExcursiiOptionale; i++)
			 {
				 if (baniRamasi >= this->preturiExcursii[i])
				 {
					 baniRamasi -= this->preturiExcursii[i];\
						 k++;
					
				 }
			 }

		 }

		
		 return k;
	 }




};


//                             cout <<      s1<<s2;
ostream& operator<<( ostream& out, Sejur sursa)
{
 
	out << "ID "<< sursa.id << endl;
	out << "Destinatie:  " << sursa.destinatie << endl;
	out << "Durata zile:  " << sursa.durata << endl;
	out << "pret baza "<< sursa.pretBaza << endl;
	out << "Transport  :  "<< sursa.transport << endl;
	out << "NrExcursii  :  "<< sursa.nrExcursiiOptionale << endl;
	out << "Preutri excursii  op:  "  ;
	for (int i = 0; i < sursa.nrExcursiiOptionale; i++)
	{
		out << sursa.preturiExcursii[i] << " ";
	}
	out << endl << endl;




	return out;
}

istream& operator>>(istream& in, Sejur& sursa)
{

	cout << "Da destinatie; ";
	char buffer[200];
	in.getline(buffer, 200);
	sursa.destinatie = buffer;

	cout << "Da pret baza: ";
	in >> sursa.pretBaza;


	cout << "Da durata: ";
	in >> sursa.durata;


	cout << "Da transport: ";
	int auxT;
	in >> auxT;
	sursa.transport = (Transport)auxT;

	cout << "Da nr de excursii ";
	in >> sursa.nrExcursiiOptionale;
	delete[] sursa.preturiExcursii;
	sursa.preturiExcursii = new float[sursa.nrExcursiiOptionale];
	for (int i = 0; i < sursa.nrExcursiiOptionale; i++)
	{
		cout << "da pretul pt exxcursia " << i + 1 << ": ";
		in >> sursa.preturiExcursii[i];
	}
	 





	return in;
}

//                      23<=       s1
bool operator<= (float val, Sejur sursa)
{

	//if (val <= sursa.getMax())
	//{
	//	return true;
	//}
	//else {
	//	return false;
	//}

	// cum s ar face daca nu avem voiie cu getMAx 
	float max = 0;
	if (sursa.nrExcursiiOptionale > 0)
	{
		max = sursa.preturiExcursii[0];
		for (int i = 0; i < sursa.nrExcursiiOptionale; i++)
		{
			if (max < sursa.preturiExcursii[i])
			{
				max = sursa.preturiExcursii[i];
			}
		}

	}

	if (val <= max)
	{
		return true;
	}
	else {
		return  false;
	}
	 


}





int main()
{


	Sejur s(101);  //apel const cu 1 param. 


	s.setDurata(10);
	s.setTransport(avion);

	cout << s.getDurata() << endl;
	cout << s.getTransport() << endl;

	float auxExcursii[3]{ 100,350,150 };         //0        //    150 350
	Sejur s1(102, "Dubai", avion, 5, 2000,4, new float[4]{100, 350,100, 150});


	int nrExcursiiPermise = s1.getNrMaximExcursii(2200);
	cout <<"FMM excursii permise: " << nrExcursiiPermise << endl;
	


	s1--;
	cout << s1;

	Sejur s2(s1);

	s = s1;

	cout << s1;



	if (s1 < 23)
	{
		cout << "Da, pretul maxim din s1 e mai mic ca 23" << endl;
	}
	else {
		cout << "NU, pretul maxim din s1 NU < 23" << endl;
	}



	//<= 
	if ( 23 <= s1)
	{
		cout << "Da 23 e mai mci decat maxul lui s1" << endl;
	}
	else {
		cout << "Nu ,23 nu e mai mci decat maxul lui s1" << endl;
	}

	// cin >> s;
	// cout << s;



	cout << (float)s << endl; // apel operator cast la float 









	return 0;
}
