#ifndef DRZEWOBST_H
#define DRZEWOBST_H

#include <iostream>
#include <fstream>
#include <string>

class Wezel {
public:
    int wartosc;
    Wezel* lewy;
    Wezel* prawy;

    Wezel(int wart) : wartosc(wart), lewy(nullptr), prawy(nullptr) {}
};

class DrzewoBST {
private:
    Wezel* korzen;

    void wstaw(Wezel*& wez, int wartosc); // Wstawia nowy węzeł
    void usun(Wezel*& wez, int wartosc);  // Usuwa węzeł
    void wyczysc(Wezel*& wez);             // Oczyszcza drzewo
    bool szukaj(Wezel* wez, int wartosc); // Szuka węzeł w drzewie
    void preorder(Wezel* wez);            // Preorder traversal
    void inorder(Wezel* wez);             // Inorder traversal
    void postorder(Wezel* wez);           // Postorder traversal
    void zapiszDoPliku(Wezel* wez, std::ofstream& out); // Zapisuje drzewo do pliku
    void wczytajZPliku(Wezel*& wez, std::ifstream& in); // Wczytuje drzewo z pliku

public:
    DrzewoBST(); // Konstruktor
    ~DrzewoBST(); // Destruktor

    void dodaj(int wartosc); // Metoda dodająca element
    void usun(int wartosc); // Metoda usuwająca element
    void wyczysc(); // Metoda czyszcząca drzewo
    bool szukaj(int wartosc); // Metoda szukająca element
    void wyswietl(int metoda); // Metoda do wyświetlania drzewa
    void zapisz(const std::string& nazwaPliku); // Zapisuje drzewo do pliku
    void wczytaj(const std::string& nazwaPliku); // Wczytuje drzewo z pliku
};

#endif
