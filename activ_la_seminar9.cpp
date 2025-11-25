#include <iostream>
#include <string>
using namespace std;

class calatorie {
private:
    float pret = 0;

public:
    calatorie() {}
    calatorie(float pret) {
        this->pret = pret;
    }

    float getpret() const {
        return this->pret;
    }
};

class vacanta {
private:
    calatorie* calatorii;
    int nrcalatorii;
    string destinatie;

public:
    vacanta(string destinatie, int nrcalatorii, float* preturi) {
        this->destinatie = destinatie;
        this->nrcalatorii = nrcalatorii;

        calatorii = new calatorie[nrcalatorii];
        for (int i = 0; i < nrcalatorii; i++) {
            calatorii[i] = calatorie(preturi[i]);
        }
    }

    // Copy constructor corect
    vacanta(const vacanta& v) {
        this->destinatie = v.destinatie;
        this->nrcalatorii = v.nrcalatorii;

        if (v.calatorii != nullptr) {
            this->calatorii = new calatorie[nrcalatorii];
            for (int i = 0; i < nrcalatorii; i++)
                this->calatorii[i] = v.calatorii[i];
        }
        else {
            this->calatorii = nullptr;
        }
    }
    void afisare() const {
        cout << "Destinatie: " << destinatie << endl;
        cout << "Numar calatorii: " << nrcalatorii << endl;

        for (int i = 0; i < nrcalatorii; i++) {
            cout << "   Calatoria " << i + 1 << ": "
                << calatorii[i].getpret() << " euro" << endl;
        }
    }


    // Destructor
    ~vacanta() {
        delete[] calatorii;
    }

    calatorie& operator[](int index) {
        if (index >= 0 && index < nrcalatorii)
            return calatorii[index];
        else
            throw "Indexul este in afara intervalului";
    }

    string getdestinatie() const {
        return destinatie;
    }

};

int main() {

    float preturi[2] = { 350, 140 };

    vacanta v("Londra", 2, preturi);

    cout << "Pretul primei calatorii din "
        << v.getdestinatie()
        << " este de "
        << v[0].getpret()
        << " euro.";
    vacanta vacanta2 = v;
    cout << endl << " pretul pt a doua calatorie din " << v.getdestinatie() << " este de " << v[1].getpret() << " euro.";
    v.afisare();
    cout << endl;
    vacanta2.afisare();


    return 0;
}