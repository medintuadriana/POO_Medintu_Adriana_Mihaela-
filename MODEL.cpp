#include <iostream>
using namespace std;

class Bloc
{
    const int id = 1; // Atribut constant initializat in definitia clasei
    int nr_etaje = 1;
public:
    Bloc()
    {
        // EROARE: 'id' este const si nu poate fi modificat prin atribuire
        // id = 2; 
        nr_etaje = 4;
    }
};

int main()
{
    // Bloc b; // Daca decomentezi, programul nu va compila din cauza liniei 'id = 2'
    cout << "Codul are erori de compilare conform grilei." << endl;
    return 0;
}