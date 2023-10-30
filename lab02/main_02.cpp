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
    delete pp2;

    testIsSquare("points.txt");

    if(isSquare(Point(20, 10), Point(10, 20), Point(20, 20), Point(10, 10))) {
        cout<<"The points form a square."<<endl;
    } else {
        cout<<"The points do not form a square."<<endl;
    }*/

    srand(time(0));

    int numPoints;

    cout<<"The number of the points: " << endl;
    cin>>numPoints;

    Point * points = createArray(numPoints);

   // printArray(points, numPoints);

    cout<<"Default:"<<endl;
    //printArray(points, numPoints);

    cout<<"The two closest points are: (" << closestPoints(points, numPoints).first.getX() << ", " << closestPoints(points, numPoints).first.getY() << ") and (" << closestPoints(points, numPoints).second.getX() << ", " << closestPoints(points, numPoints).second.getY() << ")" <<endl;

    cout<<"The two farthest points are: (" << farthestPoints(points, numPoints).first.getX() << ", " << farthestPoints(points, numPoints).first.getY() << ") and (" << farthestPoints(points, numPoints).second.getX() << ", " << farthestPoints(points, numPoints).second.getY() << ")" <<endl;

    /*sortPoints(points, numPoints);

    cout<<"Sorted points:"<<endl;
    printArray(points, numPoints);

    Point *farthestPointsFromOriginArray = farthestPointsFromOrigin(points, numPoints);

    cout<<"The first 10 farthest points from the origin are: "<<endl;
    for (int i = 0; i < 10; ++i) {
        cout<< "(" << farthestPointsFromOriginArray[i].getX() << ", " << farthestPointsFromOriginArray[i].getY() << ")" << endl;
    }

    deletePoints(points);*/

    return 0;
}
