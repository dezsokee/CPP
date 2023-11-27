#ifndef LAB10_ALKALMAZOTT_H
#define LAB10_ALKALMAZOTT_H

#include <string>
#include "Szemely.h"
#include <iostream>

using namespace std;

class Alkalmazott : public Szemely{
protected:
    string munkakor;
    static int count;
    int id;
public:
    Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, const string &munkakor);

    Alkalmazott();

    virtual void print(ostream &os) const override;

    int getId() const;
};


#endif //LAB10_ALKALMAZOTT_H
