#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;


class ExceptieCostum : public exception {
public:
    ExceptieCostum(const char*  mesaj) : exception(mesaj) {}
   
};

class StatieAlimentare {
private:

    const int idStatie;          // Membru CONST
    char* adresa;                // Membru ALOCAT DINAMIC
    string tipCombustibil;
    double pretPeLitru;
    double capacitateRezervor;
    double stocCurent;
    double totalVandut;

    static int numarStatii;

public:

    StatieAlimentare() : idStatie(++numarStatii) {
        this->adresa = new char[strlen("Necunoscut") + 1];
        strcpy(this->adresa, "Necunoscut");
        this->tipCombustibil = "N/A";
        this->pretPeLitru = 0.0;
        this->capacitateRezervor = 0.0;
        this->stocCurent = 0.0;
        this->totalVandut = 0.0;
    }


    StatieAlimentare(const char* adresa, string tip, double pret, double capacitate) : idStatie(++numarStatii) {
        this->adresa = new char[strlen(adresa) + 1];
        strcpy(this->adresa, adresa);
        this->tipCombustibil = tip;
        this->pretPeLitru = pret;
        this->capacitateRezervor = capacitate;
        this->stocCurent = 0;
        this->totalVandut = 0;
    }


    StatieAlimentare(const StatieAlimentare& s) : idStatie(++numarStatii) {
        this->adresa = new char[strlen(s.adresa) + 1];
        strcpy(this->adresa, s.adresa);
        this->tipCombustibil = s.tipCombustibil;
        this->pretPeLitru = s.pretPeLitru;
        this->capacitateRezervor = s.capacitateRezervor;
        this->stocCurent = s.stocCurent;
        this->totalVandut = s.totalVandut;
    }


    StatieAlimentare& operator=(const StatieAlimentare& s) {
        if (this != &s) {
            if (this->adresa != nullptr) {
                delete[] this->adresa;
            }
            this->adresa = new char[strlen(s.adresa) + 1];
            strcpy(this->adresa, s.adresa);
            this->tipCombustibil = s.tipCombustibil;
            this->pretPeLitru = s.pretPeLitru;
            this->capacitateRezervor = s.capacitateRezervor;
            this->stocCurent = s.stocCurent;
            this->totalVandut = s.totalVandut;
        }
        return *this;
    }


    ~StatieAlimentare() {
        if (this->adresa != nullptr) {
            delete[] this->adresa;
        }
    }
    double getTotalVandut() const { return totalVandut; }
    string getTipCombustibil() const { return tipCombustibil; }
    StatieAlimentare& operator+=(double cantitate) {//se alimenteaza rezervorul statiei
        if (this->capacitateRezervor >= this->capacitateRezervor + cantitate && cantitate > 0) {
            this->capacitateRezervor += cantitate;
            return*this;
        }
        else throw ExceptieCostum("capacitate depaSITA");
    }
    StatieAlimentare& operator-=(double cantitateAutovehicul)//se alimenteaza un autovehicul
    {
        if (cantitateAutovehicul > 0 && cantitateAutovehicul < this->stocCurent) {
            this->stocCurent -= cantitateAutovehicul;
        }
        else throw ExceptieCostum("stoc insuficient");
        return *this;
    }
    bool operator!() {
        if (this->stocCurent != 0)return false;
        else return true;
    }
    friend ostream& operator<<(ostream& out, const StatieAlimentare& s);
};
int StatieAlimentare::numarStatii = 0;//determinarea tipului de combustibilului cel mai vândut.
void determinaCelMaiVandutCombustibil(StatieAlimentare* statii, int nrStatii) {
    if (nrStatii == 0) return;

    int indexMax = 0;
    double maxVandut = statii[0].getTotalVandut();

    for (int i = 1; i < nrStatii; i++) {
        if (statii[i].getTotalVandut() > maxVandut) {
            maxVandut = statii[i].getTotalVandut();
            indexMax = i;
        }
    }
}
  
    ostream& operator<<(ostream& out, const StatieAlimentare& s) {
        out << "ID Statie: " << s.idStatie << endl;
        out << "Adresa: " << s.adresa << endl;
        out << "Combustibil: " << s.tipCombustibil << endl;
        out << "Pret/Litru: " << s.pretPeLitru << " RON" << endl;
        out << "Capacitate: " << s.capacitateRezervor << " L" << endl;
        out << "Stoc Curent: " << s.stocCurent << " L" << endl;
        out << "Total Vandut: " << s.totalVandut << " L" << endl;
        return out;
    }
   
   int main() {

       StatieAlimentare benzina95("Bd. Unirii nr. 10", "Benzina 95", 7.5, 1000.0);
       StatieAlimentare diesel("Bd. Unirii nr. 10", "Diesel Standard", 7.8, 1000.0);
       StatieAlimentare gpl("Bd. Unirii nr. 10", "GPL", 3.2, 500.0);
       benzina95 += 800.0; 
       diesel += 1200.0;  
       gpl += 100.0;     

       try {
       
           cout << "Client 1 alimenteaza 50L Benzina..." << endl;
           benzina95 -= 50.0;
          

           cout << "Client 2 incearca sa alimenteze 1500L Diesel..." << endl;
           diesel -= 1500.0; // exceptia

       }
       catch (const ExceptieCostum& e) {
           cout << "EXCEPTION CAUGHT: " << e.what() << endl;
       }
       catch (...) {
           cout << "Alta eroare a aparut." << endl;
       }

       if (!gpl) {
           cout << "Rezervorul GPL este gol!" << endl;
       }
       else {
           cout << "Rezervorul GPL mai are combustibil." << endl;
       }

       
       benzina95 -= 200.0; 
       gpl -= 50.0;        

       
       StatieAlimentare listaStatii[] = { benzina95, diesel, gpl };///////ATENTIE ENUMERARE
       determinaCelMaiVandutCombustibil(listaStatii, 3);////








       return 0;
   }
