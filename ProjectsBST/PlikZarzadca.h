#ifndef PLIKZARZADCA_H
#define PLIKZARZADCA_H


#include "DrzewoBST.h"

using namespace std;

class PlikZarzadca {
public:
    static void zapiszDrzewo(DrzewoBST& drzewo, const string& nazwaPliku);
    static void wczytajDrzewo(DrzewoBST& drzewo, const string& nazwaPliku);
};

#endif
