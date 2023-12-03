#include "Ceg.h"
#include <algorithm>

Ceg::Ceg(string nev) : nev{nev} {}

void Ceg::addAlkalmazott(Alkalmazott *alkalmazott) {
    alkalmazottak.push_back(alkalmazott);
}

void Ceg::deleteAlkalmazott(int id) {
    for (const auto &item : alkalmazottak) {
        if(item->getId() == id) {
            alkalmazottak.erase(remove(alkalmazottak.begin(), alkalmazottak.end(), item), alkalmazottak.end());
        }
    }

}

void Ceg::alkalmazottHozzarendeleseManagerhez(Alkalmazott *alkalmazott, Manager *manager) {
    manager->addAlkalmazott(alkalmazott);
}

void Ceg::alkalmazottLevalasztasaManagerrol(Alkalmazott *alkalmazott, Manager *manager) {
    manager->deleteAlkalmazott(alkalmazott);
}

void Ceg::osszesAlkalmazott() {
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [] (const Alkalmazott* item) {
        cout<<*item<<endl;
    });
}

void Ceg::csakManagerek() {
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [] (Alkalmazott* item) {
        Manager* actualAlkalmazott = dynamic_cast<Manager *>(item);
        if(actualAlkalmazott != nullptr) {
            cout<<*item<<endl;
        }
    });
}