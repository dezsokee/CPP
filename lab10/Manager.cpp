#include "Manager.h"
#include <algorithm>

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const string &vezetekNev, const string &keresztNev, const int &szuletesiEv, const string &munkakor) : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor) {}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    alkalmazottak.push_back(alkalmazott);
}

int Manager::beosztottakSzama() const {
    return alkalmazottak.size();
}

void Manager::print(ostream &os) const {

    os<<"Manager "<<id<<" "<<vezetekNev<<" "<<keresztNev<<" beosztottjai:"<<endl;

    for (const auto &item: alkalmazottak)
        cout<<*item;
}

void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
    alkalmazottak.erase(remove(alkalmazottak.begin(), alkalmazottak.end(), alkalmazott), alkalmazottak.end());
}

void Manager::deleteAlkalmazottID(int ID) {
    for (const auto &item : alkalmazottak) {
        if(item->getId() == ID) {
            alkalmazottak.erase(remove(alkalmazottak.begin(), alkalmazottak.end(), item), alkalmazottak.end());
        }
    }
}



