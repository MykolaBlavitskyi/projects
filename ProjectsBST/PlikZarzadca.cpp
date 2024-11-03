#include "PlikZarzadca.h"

using namespace std;

// Metoda do zapisywania drzewa do pliku
void PlikZarzadca::zapiszDrzewo(DrzewoBST& drzewo, const string& nazwaPliku) {
    drzewo.zapisz(nazwaPliku);
}

// Metoda do wczytywania drzewa z pliku
void PlikZarzadca::wczytajDrzewo(DrzewoBST& drzewo, const string& nazwaPliku) {
    drzewo.wczytaj(nazwaPliku);
}
