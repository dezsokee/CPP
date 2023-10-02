#include "util.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include "Point.h"
#include <algorithm>

using namespace std;

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    return false;
}

void testIsSquare(const char *filename) {
    ifstream file(filename);

    if(!file) {
        cerr<<"Error opening file: "<<filename<<endl;
        return;
    } else {
        cout<<"Opened file: "<<filename<<endl;
    }

    while(true) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        file>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        if(!file) {
            break;
        }

        Point a(x1, y1);
        Point b(x2, y2);
        Point c(x3, y3);
        Point d(x4, y4);

        a.print();
        cout<<" ";
        b.print();
        cout<<" ";
        c.print();
        cout<<" ";
        d.print();
        cout<<endl;

        cout<<"("<<x1<<","<<y1<<") ("<<x2<<","<<y2<<") ("<<x3<<","<<y3<<") ("<<x4<<","<<y4<<") is square? "<<(isSquare(a, b, c, d) ? "yes" : "no")<<endl;
    }
}

Point *createArray(int numPoints) {
    Point* points = new Point[numPoints];

    return points;
}

void deletePoints(Point *points) {
    if (points != nullptr) {
        delete[] points;
    }
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
        cout << " ";
    }
    cout << endl;
}

bool compPoints (Point a, Point b) {
    return (a.getX() < b.getX());
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, compPoints);
}

