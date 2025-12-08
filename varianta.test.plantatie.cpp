#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

class ExceptieCostum : public exception {
public:
    ExceptieCostum(const char* mesaj) : exception(mesaj) {};
};

class Plantatie {
private:
    const int id;
    char* adresa;
    int nrPomi;
    int* varsta;
    static int varstaMininmaRod;
    bool esteTratat;
    static int NrPlantatii;

public:
   //constr cu un param-id
    Plantatie() : id(++NrPlantatii) {
        this->adresa = new char[strlen("default") + 1];
        strcpy(this->adresa, "default");
        this->nrPomi = 0;
        this->varsta = nullptr;
        this->esteTratat = true;
    }

   
    Plantatie(const char* adresaData, int nrPomiDati, int* varstaDATA, bool stare) : id(++NrPlantatii) {
        if (adresaData != nullptr) {
            this->adresa = new char[strlen(adresaData) + 1];
            strcpy(this->adresa, adresaData);
        }
        else {
            this->adresa = new char[strlen("default") + 1];
            strcpy(this->adresa, "default");
        }

        if (nrPomiDati > 0) {
            this->nrPomi = nrPomiDati;
            this->varsta = new int[this->nrPomi];
            for (int i = 0; i < this->nrPomi; i++) {
                this->varsta[i] = varstaDATA[i];
            }
        }
        else {
            this->nrPomi = 0;
            this->varsta = nullptr;
        }
        this->esteTratat = stare;
    }
    //cc
    Plantatie(const Plantatie& sursa) : id(++NrPlantatii) {
        if (sursa.adresa != nullptr) {
            this->adresa = new char[strlen(sursa.adresa) + 1];
            strcpy(this->adresa, sursa.adresa);
        }
        else {
            this->adresa = nullptr;
        }

        if (sursa.nrPomi > 0 && sursa.varsta != nullptr) {
            this->nrPomi = sursa.nrPomi;
            this->varsta = new int[sursa.nrPomi];
            for (int i = 0; i < sursa.nrPomi; i++) {
                this->varsta[i] = sursa.varsta[i];
            }
        }
        else {
            this->nrPomi = 0;
            this->varsta = nullptr;
        }
        this->esteTratat = sursa.esteTratat;
    }

    
    Plantatie& operator=(const Plantatie& sursa) {
        if (this != &sursa) {
            if (this->adresa != nullptr) {
                delete[] this->adresa;
            }
            if (sursa.adresa != nullptr) {
                this->adresa = new char[strlen(sursa.adresa) + 1];
                strcpy(this->adresa, sursa.adresa);
            }
            else {
                this->adresa = nullptr;
            }
            if (this->varsta != nullptr) {
                delete[] this->varsta;
                this->varsta = nullptr;
            }

            this->nrPomi = sursa.nrPomi; 

            if (sursa.nrPomi > 0 && sursa.varsta != nullptr) {
                this->varsta = new int[sursa.nrPomi];
                for (int i = 0; i < sursa.nrPomi; i++) {
                    this->varsta[i] = sursa.varsta[i];
                }
            }
            else {
                this->varsta = nullptr;
            }

            this->esteTratat = sursa.esteTratat;
        }
        return *this;
    }


    ~Plantatie() {
        if (this->adresa != nullptr) {
            delete[] this->adresa;
            this->adresa = nullptr;
        }
        if (this->varsta != nullptr) {
            delete[] this->varsta;
            this->varsta = nullptr;
        }
    }

    
    void setAdresa(const char* adresaNoua) {
        if (this->adresa != nullptr)
            delete[] this->adresa;
        this->adresa = new char[strlen(adresaNoua) + 1];
        strcpy(this->adresa, adresaNoua);
    }

    char* getAdresa() {
        if (this->adresa == nullptr) return nullptr;
        char* copie = new char[strlen(this->adresa) + 1];
        strcpy(copie, this->adresa);
        return copie;
    }

    static void setVarstaMinimaRod(int valoare) {
        if (valoare > 0)
            Plantatie::varstaMininmaRod = valoare;
        else throw ExceptieCostum("Valoare negativa");
    }

    static int getVarstaMinimaRod() {
        return Plantatie::varstaMininmaRod;
    }

    int getNrPomiVarstaMinima(int varsta) {
        int k = 0;
        for (int i = 0; i < this->nrPomi; i++) {
            if (this->varsta[i] >= varsta) {
                k++;
            }
        }
        if (k > 0) return k;
        else throw ExceptieCostum("Nu exista pomi cu aceasta varsta");
    }

   
    explicit operator int() {
        int k = 0;
        for (int i = 0; i < this->nrPomi; i++) {
            if (this->varsta[i] >= Plantatie::varstaMininmaRod)
                k++;
        }
        if (k > 0) return k;
        else throw ExceptieCostum("invalid");
    }

  
    bool operator==(const Plantatie& sursa) {
       
        if (strcmp(this->adresa, sursa.adresa) != 0) return false;
        if (this->nrPomi != sursa.nrPomi) return false;
        if (this->esteTratat != sursa.esteTratat) return false;

        for (int i = 0; i < this->nrPomi; i++) {
            if (this->varsta[i] != sursa.varsta[i]) return false;
        }

        return true; 
    }

    friend Plantatie operator+(int nrpomi, Plantatie& sursa);
    friend ostream& operator<<(ostream& out, const Plantatie& sursa);
    friend istream& operator>>(istream& in, Plantatie& sursa);
};


int Plantatie::varstaMininmaRod = 0;
int Plantatie::NrPlantatii = 0;


Plantatie operator+(int nrpomi, Plantatie& sursa) {
    if (nrpomi <= 0) return sursa;///

    int* vectorNou = new int[sursa.nrPomi + nrpomi];
    for (int i = 0; i < sursa.nrPomi; i++) {
        vectorNou[i] = sursa.varsta[i];
    }
 
    for (int i = sursa.nrPomi; i < sursa.nrPomi + nrpomi; i++) {
        vectorNou[i] = 0; 
    }

    if (sursa.varsta != nullptr) {
        delete[] sursa.varsta;
    }

    sursa.varsta = vectorNou;
    sursa.nrPomi += nrpomi;

    return sursa;
}

ostream& operator<<(ostream& out, const Plantatie& sursa) {
    out << "ID: " << sursa.id << endl;
    out << "Adresa: " << sursa.adresa<< endl;
    out << "Nr Pomi: " << sursa.nrPomi << endl;
    out << "Varste: ";
    for (int i = 0; i < sursa.nrPomi; i++) {
        out << sursa.varsta[i] << " ";
    }
    out << endl << "Varsta rod: " << Plantatie::getVarstaMinimaRod() << endl;
    out << "Nr Plantatii Global: " << Plantatie::NrPlantatii << endl;
    out << "Tratat: " << sursa.esteTratat << endl;
    return out;
}

istream& operator>>(istream& in, Plantatie& sursa) {
    cout << "Adresa: ";
    char buffer[100];
    in >> buffer;
    cin.getline(buffer,100);///atentie
    if (sursa.adresa != nullptr)
        delete[] sursa.adresa;
    sursa.adresa = new char[strlen(buffer) + 1];
    strcpy(sursa.adresa, buffer);

    cout << "Nr Pomi: ";
    in >> sursa.nrPomi;

    if (sursa.varsta != nullptr) delete[] sursa.varsta;

    if (sursa.nrPomi > 0) {
        sursa.varsta = new int[sursa.nrPomi];
        for (int i = 0; i < sursa.nrPomi; i++) {
            cout << "Varsta pom " << i + 1 << ": ";
            in >> sursa.varsta[i];
        }
    }
    else {
        sursa.varsta = nullptr;
    }

    cout << "Stare: ";
    in >> sursa.esteTratat;

    return in;
}

int main() {
   
        int varstePomi[] = { 2, 5, 1, 7, 3 };
        Plantatie p1("Sos. Viei nr. 20", 5, varstePomi, true);
        cout << p1;

        Plantatie p2(p1);//cc

       
        Plantatie p3;

        try {
            p1.getNrPomiVarstaMinima(4);
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }

        p2 = p3; 

        operator+(3, p2); //APEL +GLOBAL
        cout << p2;

        Plantatie::setVarstaMinimaRod(2);

            int nrPomiVarstaMinima = (int)p1;
            cout  << nrPomiVarstaMinima << endl;
       

        if (p2 == p3) {
            cout << "sunt la fel" << endl;
        }
        else {
            cout << "nu sunt la fel" << endl;
        }

        p2.setAdresa("str libertatii");
       cout<< p2.getAdresa();
     
   

    return 0;
}