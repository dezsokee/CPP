#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {

    Polynomial p1(3, new double[4]{1, 2, 3, 4});

    cout << "p1: " << p1 << endl;

    Polynomial p2(2, new double[3]{1, 2, 3});

    cout << "p2: " <<  p2 << endl;

    Polynomial p3 = p1 + p2;

    cout << "p3 = p1 + p2 =  " << p3 << endl;

    Polynomial p4 = p1 - p2;

    cout << "p4 = p1 - p2 =  " << p4 << endl;

    Polynomial p5 = p1 * p2;

    cout << "p5 = p1 * p2 =  " << p5 << endl;

    Polynomial p6 = p1.derivative();

    cout << "p6 = p1.derivative() =  " << p6 << endl;

    Polynomial p7 = -p1;

    cout << "p7 = -p1 =  " << p7 << endl;

    cout<<"p1[2] = "<<p1[2]<<endl;

    cout<<"p1(2) = "<<p1.evaluate(2)<<endl;

    return 0;
}