#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// interfata
class InterfataAfisare {
public:
    virtual void afiseaza() = 0;
};

// clasa parinte
class Student : public InterfataAfisare {
protected:
    char nume[50];
    int* note;
    int nrNote;

public:
    // constructor fara parametri
    Student() {
        this->nrNote = 0;
        this->note = new int[0];
        strcpy(this->nume, "Nedefinit");
    }

    // constructor cu parametri
    Student(const char* n, int* v, int nr) {
        strcpy(this->nume, n);
        this->nrNote = nr;
        this->note = new int[this->nrNote];
        for (int i = 0;i < this->nrNote;i++)
            this->note[i] = v[i];
    }

    // constructorul de  copiere
    Student(const Student& s) {
        strcpy(this->nume, s.nume);
        this->nrNote = s.nrNote;
        this->note = new int[this->nrNote];
        for (int i = 0;i < this->nrNote;i++)
            this->note[i] = s.note[i];
    }

    // operator =
    Student& operator=(const Student& s) {
        if (this != &s) {
            strcpy(this->nume, s.nume);
            delete[] this->note;
            this->nrNote = s.nrNote;
            this->note = new int[this->nrNote];
            for (int i = 0;i < this->nrNote;i++)
                this->note[i] = s.note[i];
        }
        return *this;
    }

    ~Student() {
        delete[] this->note;
    }

    void afiseaza() override {
        if (this->note == nullptr || this->nrNote == 0) {
            cout << "Student fara note\n";
            return;
        }

        cout << "Student: " << this->nume << " | Note: ";
        for (int i = 0; i < this->nrNote; i++)
            cout << this->note[i] << " ";
        cout << "\n";
    }


    friend istream& operator>>(istream& in, Student& s) {
        cout << "Nume student: ";
        in >> s.nume;
        cout << "Numar note: ";
        in >> s.nrNote;

        delete[] s.note;
        s.note = new int[s.nrNote];

        cout << "Note: ";
        for (int i = 0;i < s.nrNote;i++)
            in >> s.note[i];

        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Student: " << s.nume << " | Note: ";
        for (int i = 0;i < s.nrNote;i++)
            out << s.note[i] << " ";
        return out;
    }
};

// clasa copil
class StudentOlimpic : public Student {
protected:
    char materie[30];
    int punctaj;
public:
    StudentOlimpic() : Student() {
        strcpy(this->materie, "N/A");
        this->punctaj = 0;
    }

    StudentOlimpic(const char* n, int* v, int nr, const char* m, int pct)
        : Student(n, v, nr) {
        strcpy(this->materie, m);
        this->punctaj = pct;
    }

    void afiseaza() override {
        if (this->note == nullptr || this->nrNote == 0) {
            cout << "Student Olimpic fara note\n";
            return;
        }

        cout << "Student Olimpic: " << this->nume
            << " | Materie: " << this->materie
            << " | Punctaj: " << this->punctaj
            << " | Note: ";
        for (int i = 0; i < this->nrNote; i++)
            cout << this->note[i] << " ";
        cout << "\n";
    }


    friend ostream& operator<<(ostream& out, const StudentOlimpic& s) {
        out << "Student Olimpic: " << s.nume
            << " | Materie: " << s.materie
            << " | Punctaj: " << s.punctaj
            << " | Note: ";
        for (int i = 0;i < s.nrNote;i++)
            out << s.note[i] << " ";
        return out;
    }
};

int main() {
    int n;
    cout << "Nr de studenti:  ";
    cin >> n;

    InterfataAfisare** v = new InterfataAfisare * [n];

    for (int i = 0;i < n;i++) {
        cout << "\n1 - Student normal\n2 - Student olimpic\nAlege tip: ";
        int tip; cin >> tip;

        if (tip == 1) {
            Student* s = new Student();
            cin >> *s;
            v[i] = s;
        }
        else if(tip==2){
            char nume[50], mat[30];
            int nr, pct;

            cout << "Nume: ";
            cin >> nume;
            cout << "Numar note: ";
            cin >> nr;
            int* x = new int[nr];
            cout << "Note: ";
            for (int j = 0;j < nr;j++)
                cin >> x[j];

            cout << "Materie: ";
            cin >> mat;
            cout << "Punctaj: ";
            cin >> pct;

            v[i] = new StudentOlimpic(nume, x, nr, mat, pct);
            delete[] x;
        }
          else {
               cout << "Tip invalid, se va crea student default.\n";
               v[i] = new Student();

        }
    }

    cout << "\n--- AFISARE ---\n";
    for (int i = 0;i < n;i++) {
        if (v[i] != nullptr)
            v[i]->afiseaza();
    }

    for (int i = 0;i < n;i++)
        delete v[i];
    delete[]v;

    return 0;
}
