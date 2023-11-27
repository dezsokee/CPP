#include "Szemely.h"
#include <iostream>

using namespace std;

Szemely::Szemely(string vezetekNev, string keresztNev, int szuletesiEv) {
    this->vezetekNev = vezetekNev;
    this->keresztNev = keresztNev;
    this->szuletesiEv = szuletesiEv;
}

void Szemely::print(ostream &os) const {
    os << "Vezeteknev: " << vezetekNev << endl;
    os << "Keresztnev: " << keresztNev << endl;
    os << "Szuletesi ev: " << szuletesiEv << endl;
}

ostream &operator<<(ostream &os, const Szemely &szemely) {
    szemely.print(os);
    return os;
}
