#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Carte {
private:
 
    string titlu;
    string autor;
    static int contorID;
    const int idExemplar;
public:
 //c.default
    Carte() : idExemplar(++contorID), titlu("Necunoscut"), autor("Anonim") {}
    //c.param
    Carte(string _titlu, string _autor) : idExemplar(++contorID), titlu(_titlu), autor(_autor) {
    }
    //cc
    Carte(const Carte& sursa): idExemplar(++contorID), titlu(sursa.titlu), autor(sursa.autor) {
    }
    ~Carte() {  }

    string getTitlu() const { return titlu; }//?
    string getAutor() const { return autor; }
    int getId() const { return idExemplar; }

    // Testeaz? dac? dou? exemplare se refer? la aceea?i oper? (acela?i titlu ?i autor),
    // chiar dac? au coduri de exemplar diferite.
    bool operator==(const Carte& sursa) const {//ATENTIEE
        if (this->titlu == sursa.titlu && this->autor == sursa.autor) return true;
        else return false;

    }

   
    friend ostream& operator<<(ostream& os, const Carte& c);
};


int Carte::contorID = 1000;


ostream& operator<<(ostream& out, const Carte& c) {
    out << "ID: " << c.idExemplar << endl << c.titlu << endl << c.autor;
    return out;
}


class Cititor {
private:
    const string cnp;       
    string nume;
    Carte** cartiImprumutate; // Vector dinamic de pointeri la Carte
    int nrCarti;

public:
    // Constructor cu parametri
    Cititor(string _nume, string _cnp) : nume(_nume), cnp(_cnp), nrCarti(0) {
        cartiImprumutate = nullptr;
    }

    // cc deep copy
    Cititor(const Cititor& sursa) : cnp(sursa.cnp), nume(sursa.nume), nrCarti(sursa.nrCarti) {
        if (sursa.nrCarti > 0) {
            cartiImprumutate = new Carte * [nrCarti];////
            for (int i = 0; i < nrCarti; i++) {
                // Cre?m copii noi ale c?r?ilor (exemplare noi)
                cartiImprumutate[i] = new Carte(*sursa.cartiImprumutate[i]);///
            }
        }
        else {
            cartiImprumutate = nullptr;
        }
    }

    
    ~Cititor() {
        if (cartiImprumutate != nullptr) {
            for (int i = 0; i < nrCarti; i++) {
                delete cartiImprumutate[i]; // ?tergem fiecare obiect Carte
            }
            delete[] cartiImprumutate; // ?tergem vectorul de pointeri
        }
    }

 
    string getNume() const { return nume; }
    void setNume(string numeNou) { this->nume = numeNou; }

    void afiseazaStatus() const {
        cout << "Cititorul " << nume << " (CNP: " << cnp << ") are "
            << nrCarti << " carti imprumutate." << endl;
    }


    void afiseazaCarti() const {
        if (nrCarti == 0) {
            cout << "Nu exista carti imprumutate." << endl;
            return;
        }
        cout << "Lista carti imprumutate de " << nume << ":" << endl;
        for (int i = 0; i < nrCarti; i++) {
            cout << "  " << *(cartiImprumutate[i]) << endl;
        }
    }

    //  operator += (Împrumutare)
    Cititor& operator+=(const Carte& carteNoua) {
        Carte** temp = new Carte * [nrCarti + 1];
        for (int i = 0; i < nrCarti; i++) {
            temp[i] = cartiImprumutate[i];
        }
     temp[nrCarti] = new Carte(carteNoua);

        // ATWNTIE ?tergem vechiul vector (doar containerul, nu ?i c?r?ile din el)
        delete[] cartiImprumutate;

        cartiImprumutate = temp;
        nrCarti++;
        return *this;
    }

   // operator -= (Returnare)
    Cititor& operator-=(const Carte& carteDeReturnat) {
        int indexGasit = -1;
        for (int i = 0; i < nrCarti; i++) {
            if (*(cartiImprumutate[i]) == carteDeReturnat) {
                indexGasit = i;
                break; 
            }
        }

        if (indexGasit != -1) {
            delete cartiImprumutate[indexGasit];
            Carte** temp = new Carte * [nrCarti - 1];
            int k = 0;
            for (int i = 0; i < nrCarti; i++) {
                if (i != indexGasit) {
                    temp[k++] = cartiImprumutate[i];
                }
            }
            delete[] cartiImprumutate;
            cartiImprumutate = temp;
            nrCarti--;
            cout << "Cartea" << carteDeReturnat.getTitlu() << " a fost returnata." << endl;
        }
        else {
            cout << " Cartea nu a fost gasita." << endl;
        }

        return *this;
    }


    friend ostream& operator<<(ostream& out, const Cititor& cititor);
};

ostream& operator<<(ostream& out, const Cititor& cititor) {
    out << "Fisa Cititor: " << cititor.nume << " | CNP: " << cititor.cnp << endl;
    out<< "Numar carti curente: " << cititor.nrCarti;
    return out;
}


int main() {
  
    Carte c1("Morometii", "Marin Preda");
    Carte c2("Ion", "Liviu Rebreanu");
    Carte c3("Morometii", "Marin Preda"); // Alt exemplar din aceea?i carte
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl; // Va avea ID diferit de c1
 
    Cititor s("Popescu Ion", "1990101123456");
    s += c1;
    s += c2; 
    cout << s << endl;
    s.afiseazaCarti();

    Cititor s2 = s; // Cc
    s.setNume("Ionescu Maria"); 
    cout << "Copie:    " << s.getNume() << endl;

    // Încerc?m s? return?m o carte identic? ca titlu cu c1 (folosind c3 pentru compara?ie)
    // Cerin?a d) cere folosirea operatorului == pentru a g?si cartea.
    // De?i c3 are alt ID decât c1, ele sunt "egale" ca titlu/autor, deci returnarea va reu?i.

    s -= c3;

    s.afiseazaStatus();
    s.afiseazaCarti();

    return 0;
}