#include <iostream>
#include "DrzewoBST.h"
#include "PlikZarzadca.h"

using namespace std;

void menu() {
    cout << "1. Dodaj element" << endl;
    cout << "2. Usuń element" << endl;
    cout << "3. Wyczyść drzewo" << endl;
    cout << "4. Szukaj element" << endl;
    cout << "5. Wyświetl drzewo" << endl;
    cout << "6. Zapisz do pliku" << endl;
    cout << "7. Wczytaj z pliku" << endl;
    cout << "0. Wyjdź" << endl;
}

int main() {
    DrzewoBST drzewo;
    int wybor;
    
    while (true) {
        menu();
        cout << "Wybierz opcję: ";
        cin >> wybor;

        if (wybor == 0) {
            break;
        }

        switch (wybor) {
            case 1: {
                int wartosc;
                cout << "Podaj wartość do dodania: ";
                cin >> wartosc;
                drzewo.dodaj(wartosc);
                break;
            }
            case 2: {
                int wartosc;
                cout << "Podaj wartość do usunięcia: ";
                cin >> wartosc;
                drzewo.usun(wartosc);
                break;
            }
            case 3:
                drzewo.wyczysc();
                break;
            case 4: {
                int wartosc;
                cout << "Podaj wartość do wyszukiwania: ";
                cin >> wartosc;
                if (drzewo.szukaj(wartosc)) {
                    cout << "Znaleziono!" << endl;
                } else {
                    cout << "Nie znaleziono!" << endl;
                }
                break;
            }
            case 5: {
                int metoda;
                cout << "Wybierz metodę (1 - preorder, 2 - inorder, 3 - postorder): ";
                cin >> metoda;
                drzewo.wyswietl(metoda);
                cout << endl;
                break;
            }
            case 6: {
                string nazwaPliku;
                cout << "Podaj nazwę pliku do zapisu: ";
                cin >> nazwaPliku;
                PlikZarzadca::zapiszDrzewo(drzewo, nazwaPliku);
                break;
            }
            case 7: {
                string nazwaPliku;
                cout << "Podaj nazwę pliku do wczytania: ";
                cin >> nazwaPliku;
                PlikZarzadca::wczytajDrzewo(drzewo, nazwaPliku);
                break;
            }
            default:
                cout << "Nieprawidłowy wybór!" << endl;
        }
    }

    return 0;
}
