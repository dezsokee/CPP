#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

using namespace std;

int main() {
    /*Szemely szemely1("Nagy", "Botond", 2003);

    cout<<szemely1<<endl;

    Alkalmazott alkalmazott1("Dezso", "Szabolcs", 2003, "IT");
    Alkalmazott alkalmazott2("Szasz", "Alpar", 2003, "IT");

    cout<<alkalmazott1<<endl;

    Manager manager1("Tofalvi", "Patrik", 2003, "IT");

    cout<<"A hozzaadas elott"<<endl;
    cout<<manager1<<endl;

    manager1.addAlkalmazott(&alkalmazott1);
    manager1.addAlkalmazott(&alkalmazott2);

    cout<<"A hozzaadas utan"<<endl;
    cout<<manager1<<endl;

    manager1.deleteAlkalmazott(&alkalmazott1);

    cout<<"Torles utan"<<endl;
    cout<<manager1<<endl;*/

    Ceg ceg1("Bitdefender");

    Alkalmazott alkalmazott1("Dezso", "Szabolcs", 2003, "IT");
    Alkalmazott alkalmazott2("Szasz", "Alpar", 2003, "IT");
    Alkalmazott alkalmazott3("Cseh", "Barna", 2003, "Marketing");
    Alkalmazott alkalmazott4("Bekk", "Norbert", 2003, "Marketing");
    Alkalmazott alkalmazott5("Nagy", "Botond", 2003, "IT");
    Alkalmazott alkalmazott6("Tofalvi", "Patrik", 2003, "IT");
    Alkalmazott alkalmazott7("Dezso", "Norbert", 2003, "Marketing");

    Manager manager1("Tofalvi", "Patrik", 2003, "IT");
    Manager manager2("Tofalvi", "Patrik", 2003, "IT");
    Manager manager3("Tofalvi", "Patrik", 2003, "IT");

    return 0;
}