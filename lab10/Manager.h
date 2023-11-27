#ifndef LAB10_MANAGER_H
#define LAB10_MANAGER_H

#include "Alkalmazott.h"
#include <iostream>
#include <vector>

using namespace std;

class Manager : public Alkalmazott {
private:
    static const string MANAGER_MUNKAKOR;
    vector<Alkalmazott *> alkalmazottak;
public:
    Manager(const string &vezetekNev, const string &keresztNev, const int &szuletesiEv, const string &munkakor);

    void addAlkalmazott(Alkalmazott *alkalmazott);

    void deleteAlkalmazott(Alkalmazott *alkalmazott);

    void deleteAlkalmazottID(int ID);

    int beosztottakSzama() const;

    virtual void print(ostream &os) const override;
};


#endif //LAB10_MANAGER_H
