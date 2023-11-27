#ifndef LAB10_SZEMELY_H
#define LAB10_SZEMELY_H

#include <string>

using namespace std;

class Szemely {
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(string vezetekNev="", string keresztNev="", int szuletesiEv=0);

    virtual void print(ostream &os) const;

    friend ostream &operator<<(ostream &os, const Szemely &szemely);
};


#endif //LAB10_SZEMELY_H
