#include <iostream>
#include "Point.h"
#include "util.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
    /*Point p1(2,3);
    p1.print();
    cout<<endl;

    Point p2(100, 200);
    p2.print();
    cout<<endl;

    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);

    pp1->print();
    cout<<endl;

    pp2->print();
    cout<<endl;

    cout<<distance(Point(1, 1), Point(1, 1))<<endl;

    delete pp1;
    delete pp2;*/

    //testIsSquare("points.txt");

    srand(time(0));

    int numPoints = 10;

    Point * points = createArray(numPoints);
    printArray(points, numPoints);

    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point(rand() % 100, rand() % 100);
    }

    cout<<"Default:"<<endl;
    printArray(points, numPoints);

    sortPoints(points, numPoints);

    cout<<"Sorted:"<<endl;
    printArray(points, numPoints);

    deletePoints(points);


    return 0;
}
