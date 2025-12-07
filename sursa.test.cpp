#include<iostream>
using namespace std;



enum SursaEnergie {
	verde, eoliana, solara
};


class Client {
private:

	SursaEnergie sursaEnergetica;
	int consumEstimatLunar; 
	int nrLuni; 
	int* kwh; 
	static float pretKwh;


public:

Client()
	{
		this->sursaEnergetica = verde;
		this->consumEstimatLunar = 100;
		this->nrLuni = 0;
		this->kwh = nullptr;
	}


 

	Client( SursaEnergie sursaData, int costEstimatDat,  int nrLuniDate, int* kwhDati)
	{
		this->sursaEnergetica = sursaData;
		this->consumEstimatLunar = costEstimatDat;
		this->nrLuni = nrLuniDate;
		this->kwh =  new int [nrLuniDate] ;
		for (int i = 0; i < nrLuniDate;i++)
		{
			this->kwh[i] = kwhDati[i];
		}

	}







	Client(const  Client & sursa)
	{
		this->sursaEnergetica = sursa.sursaEnergetica;
		this->consumEstimatLunar = sursa.consumEstimatLunar;
		this->nrLuni = sursa.nrLuni;
		this->kwh = new int[sursa.nrLuni];
		for (int i = 0; i < sursa.nrLuni;i++)
		{
			this->kwh[i] = sursa.kwh[i];
		}

	}








	~Client()
	{
		delete[] this->kwh;
	}






	
	Client&  operator= (const  Client& sursa)
	{
		if (this != &sursa)//auto asignare
		{
			delete[] this->kwh;
			this->sursaEnergetica = sursa.sursaEnergetica;
			this->consumEstimatLunar = sursa.consumEstimatLunar;
			this->nrLuni = sursa.nrLuni;
			this->kwh = new int[sursa.nrLuni];
			for (int i = 0; i < sursa.nrLuni;i++)
			{
				this->kwh[i] = sursa.kwh[i];
			}
		}


		return *this; 
	}






	friend ostream& operator<< (ostream& out, Client sursa);


	void operator() (int nrLunaCautata, int valoareKwmNoua)
	{
		if (nrLunaCautata >= 0 && nrLunaCautata < this->nrLuni)
		{
			this->kwh[nrLunaCautata] = valoareKwmNoua;
		}

	}



	explicit operator double()
	{
		double t = 0;

		for (int i = 0; i < this->nrLuni; i++)
		{
			if (this->consumEstimatLunar - this->kwh[i] >= 0)
			{
				t += (this->consumEstimatLunar - this->kwh[i]);
			}
			else {
				t += ((this->consumEstimatLunar - this->kwh[i])*(-1));
			}
			
		}


		return t;
	}





	int getMinim()
	{
		int min = -1; 

		if (this->nrLuni > 0)
		{
			if (this->consumEstimatLunar - this->kwh[0] >= 0)
			{
				min = (this->consumEstimatLunar - this->kwh[0]);
			}
			else {
				min = ((this->consumEstimatLunar - this->kwh[0]) * (-1));
			}
			// am initializat min cu diferenta din luna 1 luata in modul. 


			for (int i = 0; i < this->nrLuni; i++)
			{
				int dif = 0;
				if (this->consumEstimatLunar - this->kwh[i] >= 0)
				{
					dif = (this->consumEstimatLunar - this->kwh[i]);
				}
				else {
					dif = ((this->consumEstimatLunar - this->kwh[i]) * (-1));
				}

				if (min > dif)
				{
					min = dif;
				}

			}




			return min;
		}





		return min;
	}



	int getSuma()
	{
		int s = 0;
		for (int i = 0; i < this->nrLuni; i++)
		{
			s += this->kwh[i];
		}

		return s;
	}






};
float Client::pretKwh = 1.5;




ostream& operator<< (ostream& out, Client sursa)
{
	out << "Sursa energie: " << sursa.sursaEnergetica << endl;
	out << "Consum estimat: " << sursa.consumEstimatLunar << endl;
	out << "Nr luni " << sursa.nrLuni << endl;
	out << "Kwh lista:  "  ;
	for (int i = 0; i < sursa.nrLuni; i++)
	{
		out << sursa.kwh[i] << " ";
	}
	out << endl << endl;


	return  out; 
}





int main()
{

	Client c; //                           0    1    2
	Client c1(eoliana, 100, 3, new int[3] {80, 110, 90});
	Client c2(c1);
	c = c1;

	c1(1,120);  

	cout << "Totalul dif lunare: " << (double)c1 << endl;

	cout << c1.getMinim() << endl; 

	cout << "SUma: " << c1.getSuma() << endl;

	cout << c1;
	cout << c1 << c2 << endl;
 









	return 0;
}