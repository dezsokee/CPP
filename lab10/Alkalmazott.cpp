#include "Alkalmazott.h"
#include "Szemely.h"
#include <iostream>

using namespace std;

int Alkalmazott::count = 1;

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, const string &munkakor) : Szemely(
        vezetekNev, keresztNev, szuletesiEv), munkakor{munkakor}, id{count++} {
}

Alkalmazott::Alkalmazott() {

};

void Alkalmazott::print(ostream &os) const {
    os<<"Alkalmazott "<<id<<" "<<vezetekNev<<" "<<keresztNev<<" "<<munkakor<<endl;
}

int Alkalmazott::getId() const {
    return id;
}
