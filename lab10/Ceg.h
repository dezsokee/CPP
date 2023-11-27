#ifndef LAB10_CEG_H
#define LAB10_CEG_H

#include <string>
#include <iostream>
#include <vector>
#include "Alkalmazott.h"
#include "Manager.h"

using namespace std;

class Ceg {
private:
    string nev;
    vector<Alkalmazott *> alkalmazottak;
public:
    Ceg(string nev);

    void addAlkalmazott(Alkalmazott *alkalmazott);

    void deleteAlkalmazott(int id);

    void alkalmazottHozzarendeleseManagerhez(Alkalmazott *alkalmazott, Manager *manager);

    void alkalmazottLevalasztasaManagerrol(Alkalmazott *alkalmazott, Manager *manager);

    void osszesAlkalmazott();

    void csakManagerek();
};


#endif //LAB10_CEG_H
