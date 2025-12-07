#include<iostream>
using namespace std;





class TrotinetaElectrica
{
private:

	float nivelBaterie;
	float consumPerKm;
	float* kmPerSesiuneInchiriere;
	int nrSesiuniInchiriere;

	static float pretKm;




public:




	TrotinetaElectrica ()
	{
		this->nivelBaterie = 0;
		this->consumPerKm = 1;
		this->kmPerSesiuneInchiriere = nullptr;
		this->nrSesiuniInchiriere = 0;
	}
	






	 //TrotinetaElectrica t1(   50.0,        5.0,          3,          new float[3] {12.0, 5.0, 6.0});
	TrotinetaElectrica(float nivelDat,float consumDat, int nrDat, float* sesiuniDate)
	{
		this->nivelBaterie =  nivelDat;
		this->consumPerKm = consumDat;
		this->nrSesiuniInchiriere = nrDat;
		this->kmPerSesiuneInchiriere = new float[nrDat];
		for (int i = 0; i < nrDat; i++)
		{
			this->kmPerSesiuneInchiriere[i] = sesiuniDate[i];
		}
		
	}











	~TrotinetaElectrica()
	{
		delete[] this->kmPerSesiuneInchiriere;
	}











	//TrotinetaElectrica t2(t1);
	TrotinetaElectrica( const TrotinetaElectrica & sursa )
	{
		this->nivelBaterie = sursa.nivelBaterie;
		this->consumPerKm = sursa.consumPerKm;
		this->nrSesiuniInchiriere = sursa.nrSesiuniInchiriere;
		this->kmPerSesiuneInchiriere = new float[sursa.nrSesiuniInchiriere];
		for (int i = 0; i < sursa.nrSesiuniInchiriere; i++)
		{
			this->kmPerSesiuneInchiriere[i] = sursa.kmPerSesiuneInchiriere[i];
		}

	}












	TrotinetaElectrica  &operator= (const TrotinetaElectrica& sursa)
	{
		if (this == &sursa)return *this;
		delete[] this->kmPerSesiuneInchiriere;
		this->nivelBaterie = sursa.nivelBaterie;
		this->consumPerKm = sursa.consumPerKm;
		this->nrSesiuniInchiriere = sursa.nrSesiuniInchiriere;
		this->kmPerSesiuneInchiriere = new float[sursa.nrSesiuniInchiriere];
		for (int i = 0; i < sursa.nrSesiuniInchiriere; i++)
		{
			this->kmPerSesiuneInchiriere[i] = sursa.kmPerSesiuneInchiriere[i];
		} 
		return *this;
	}





	 


	friend ostream& operator<<(ostream& out, TrotinetaElectrica  sursa);







	// t1+=10.0;
	TrotinetaElectrica& operator+= (float sesiuneNoua)
	{
		float* vn = new float[this->nrSesiuniInchiriere + 1];
		for (int i = 0; i < this->nrSesiuniInchiriere; i++)
		{
			vn[i] = this->kmPerSesiuneInchiriere[i];
		}
		vn[this->nrSesiuniInchiriere] = sesiuneNoua;
		delete[] this->kmPerSesiuneInchiriere;
		this->kmPerSesiuneInchiriere = vn;
		this->nrSesiuniInchiriere++;
		return *this;
	}









	float& operator[] (int index)
	{
		if (index >= 0 && index < this->nrSesiuniInchiriere)
		{
			return this->kmPerSesiuneInchiriere[index];
		}
		else {
			throw new exception(); 
		}

	}









	float operator() ()
	{
		return this->nivelBaterie / this->consumPerKm;

	}



	float getMedie( ) 
	{
		float m = 0;

		if (this->nrSesiuniInchiriere > 0)
		{
			for (int i = 0; i < this->nrSesiuniInchiriere; i++)
			{
				m += this->kmPerSesiuneInchiriere[i];
			}

			m /= this->nrSesiuniInchiriere;

		}

		return m;
	}



	float getSuma()
	{
		float s = 0;

		 
			for (int i = 0; i < this->nrSesiuniInchiriere; i++)
			{
				s += this->kmPerSesiuneInchiriere[i];
			}

			 
		 
		return s;
	}




	
	float  getVenit()
	{
	
		return this->getSuma()* TrotinetaElectrica::pretKm;


	}




	 
	float getNivelBaterie()
	{
		return this->nivelBaterie;

	}



	void setBaterie(float baterieNoua)
	{
		if (baterieNoua >= 0 && nivelBaterie <= 100) {
			this->nivelBaterie = baterieNoua;
		}

	}



	friend istream& operator >> (istream& in, TrotinetaElectrica& sursa);



};
float TrotinetaElectrica::pretKm = 1.5;



ostream& operator<<(ostream& out, TrotinetaElectrica  sursa)
{
	out << endl << endl;
	out << "nivel baterie " << sursa.nivelBaterie << endl;
	out << "consum per km " << sursa.consumPerKm << endl;
	out << "nr sesiuni" << sursa.nrSesiuniInchiriere << endl;
	out << "valori sesiuni: ";
	for (int i = 0; i < sursa.nrSesiuniInchiriere; i++)
	{
		out << sursa.kmPerSesiuneInchiriere[i] << " ";
	}
	out << endl << endl;


	return out;
}



istream& operator >> (istream& in, TrotinetaElectrica & sursa)
{
	
	cout << "Da nivel baterie:";
	in >> sursa.nivelBaterie;

	cout << "Da consum:";
	in >> sursa.consumPerKm;

	cout << "Da nr ses: ";
	in >> sursa.nrSesiuniInchiriere;
	delete[] sursa.kmPerSesiuneInchiriere;
	sursa.kmPerSesiuneInchiriere = new float[sursa.nrSesiuniInchiriere];
	for (int i = 0; i < sursa.nrSesiuniInchiriere; i++)
	{
		cout << "Da km pt ses " << i + 1 << ": ";
		in >> sursa.kmPerSesiuneInchiriere[i];
	}



	return in;
}






int main()
{


	TrotinetaElectrica t;
	TrotinetaElectrica t1(50.0, 5.0, 3, new float[3] {12.0, 5.0, 6.0});
	TrotinetaElectrica t2(t1);
	t = t1;
	t = t;

	cout << t1 << t;

	t1 += 10.0;

	t1[1] = 14.0;
	cout << t1;

	cout << t1() << endl; //apel operator functie ()

	cout << t1.getMedie() << endl;


	cout << t1.getVenit() << endl;



	cout<< t1.getNivelBaterie()<<endl;

	t1.setBaterie(75);

	cout << t1;

	 cin >> t1;
	 cout << t1;






	return 0;
}

