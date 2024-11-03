#include "DrzewoBST.h"
using namespace std;

// Konstruktor
DrzewoBST::DrzewoBST() : korzen(nullptr) {}

// Destruktor
DrzewoBST::~DrzewoBST() {
    wyczysc();
}

// Wstawia nowy węzeł do drzewa
void DrzewoBST::wstaw(Wezel*& wez, int wartosc) {
    if (wez == nullptr) {
        wez = new Wezel(wartosc);
    } else if (wartosc < wez->wartosc) {
        wstaw(wez->lewy, wartosc);
    } else {
        wstaw(wez->prawy, wartosc);
    }
}

// Usuwa węzeł z drzewa
void DrzewoBST::usun(Wezel*& wez, int wartosc) {
    if (wez == nullptr) return;

    if (wartosc < wez->wartosc) {
        usun(wez->lewy, wartosc);
    } else if (wartosc > wez->wartosc) {
        usun(wez->prawy, wartosc);
    } else {
        Wezel* doUsuniecia = wez;
        if (wez->lewy == nullptr) {
            wez = wez->prawy;
        } else if (wez->prawy == nullptr) {
            wez = wez->lewy;
        } else {
            Wezel* minWezel = wez->prawy;
            while (minWezel->lewy != nullptr) minWezel = minWezel->lewy;
            wez->wartosc = minWezel->wartosc;
            usun(wez->prawy, minWezel->wartosc);
        }
        delete doUsuniecia;
    }
}

// Oczyszcza drzewo
void DrzewoBST::wyczysc(Wezel*& wez) {
    if (wez != nullptr) {
        wyczysc(wez->lewy);
        wyczysc(wez->prawy);
        delete wez;
        wez = nullptr;
    }
}

// Szuka węzeł w drzewie
bool DrzewoBST::szukaj(Wezel* wez, int wartosc) {
    if (wez == nullptr) {
        return false;
    } else if (wez->wartosc == wartosc) {
        return true;
    } else if (wartosc < wez->wartosc) {
        return szukaj(wez->lewy, wartosc);
    } else {
        return szukaj(wez->prawy, wartosc);
    }
}

// Wyświetla drzewo w porządku preorder
void DrzewoBST::preorder(Wezel* wez) {
    if (wez != nullptr) {
        cout << wez->wartosc << " ";
        preorder(wez->lewy);
        preorder(wez->prawy);
    }
}

// Wyświetla drzewo w porządku inorder
void DrzewoBST::inorder(Wezel* wez) {
    if (wez != nullptr) {
        inorder(wez->lewy);
        cout << wez->wartosc << " ";
        inorder(wez->prawy);
    }
}

// Wyświetla drzewo w porządku postorder
void DrzewoBST::postorder(Wezel* wez) {
    if (wez != nullptr) {
        postorder(wez->lewy);
        postorder(wez->prawy);
        cout << wez->wartosc << " ";
    }
}

// Zapisuje drzewo do pliku
void DrzewoBST::zapiszDoPliku(Wezel* wez, ofstream& out) {
    if (wez != nullptr) {
        out << wez->wartosc << " ";
        zapiszDoPliku(wez->lewy, out);
        zapiszDoPliku(wez->prawy, out);
    }
}

// Wczytuje drzewo z pliku
void DrzewoBST::wczytajZPliku(Wezel*& wez, ifstream& in) {
    int wartosc;
    while (in >> wartosc) {
        dodaj(wartosc);
    }
}

// Metoda do dodawania elementów
void DrzewoBST::dodaj(int wartosc) {
    wstaw(korzen, wartosc);
}

// Metoda do usuwania elementów
void DrzewoBST::usun(int wartosc) {
    usun(korzen, wartosc);
}

// Metoda do czyszczenia drzewa
void DrzewoBST::wyczysc() {
    wyczysc(korzen);
}

// Metoda do szukania elementów
bool DrzewoBST::szukaj(int wartosc) {
    return szukaj(korzen, wartosc);
}

// Metoda do wyświetlania drzewa
void DrzewoBST::wyswietl(int metoda) {
    switch (metoda) {
        case 1:
            preorder(korzen);
            break;
        case 2:
            inorder(korzen);
            break;
        case 3:
            postorder(korzen);
            break;
        default:
            std::cout << "Nieprawidłowa metoda!" << endl;
    }
}

// Zapisuje drzewo do pliku
void DrzewoBST::zapisz(const string& nazwaPliku) {
    ofstream out(nazwaPliku);
    if (out.is_open()) {
        zapiszDoPliku(korzen, out);
        out.close();
    } else {
        cout << "Nie można otworzyć pliku do zapisu." << endl;
    }
}

// Wczytuje drzewo z pliku
void DrzewoBST::wczytaj(const string& nazwaPliku) {
    ifstream in(nazwaPliku);
    if (in.is_open()) {
        wczytajZPliku(korzen, in);
        in.close();
    } else {
        cout << "Nie można otworzyć pliku do wczytania." << endl;
    }
}
