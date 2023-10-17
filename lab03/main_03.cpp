#include <iostream>
#include "List.h"
#include "List.cpp"

using namespace std;

int main() {
    cout<<"Hello word!"<<endl;
    List list = new List ();
    list.insertFirst(1);
    return 0;
}
