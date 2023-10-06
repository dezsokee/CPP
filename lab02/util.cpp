#include "util.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include "Point.h"
#include <algorithm>
#include <vector>

using namespace std;

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double ab = distance(a, b);
    double ac = distance(a, c);
    double ad = distance(a, d);
    double bc = distance(b, c);
    double bd = distance(b, d);
    double cd = distance(c, d);

    if(ab == 0 || ac == 0 || ad == 0 || bc == 0 || bd == 0 || cd == 0) {
        return false;
    } else  if ((ab == ad && ab == bc && ab == cd) && (ac == bd)) {
        return true;
    } else if  ((ad == ac && ad == bd && ad == bc) && (ab == cd)){
        return true;
    } else if  ((ab == bd && ab == ac && ab == cd) && (ad == bc)) {
        return true;
    } else {
        return false;
    }
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

    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point(rand() % 2000, rand() % 2000);
    }

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

pair<Point, Point> closestPoints(Point* points, int numPoints) {

    pair<Point, Point> closestPair = make_pair(points[0], points[1]);
    double minDistance = distance(points[0], points[1]);

    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            if (distance(points[i], points[j]) < minDistance) {
                minDistance = distance(points[i], points[j]);
                closestPair.first = points[i];
                closestPair.second = points[j];
            }
        }
    }

    return closestPair;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    pair<Point, Point> farthestPoints = make_pair(points[0], points[1]);
    double maxDistance = distance(points[0], points[1]);

    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            if (distance(points[i], points[j]) > maxDistance) {
                maxDistance = distance(points[i], points[j]);
                farthestPoints.first = points[i];
                farthestPoints.second = points[j];
            }
        }
    }

    return farthestPoints;
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    vector<pair <Point, double>> farthestPointsFromOriginVector;

    for (int i = 0; i < numPoints; ++i) {
        double currentDistance = distance(points[i], Point(0, 0));
        farthestPointsFromOriginVector.push_back(make_pair(points[i], currentDistance));
    }

    sort(farthestPointsFromOriginVector.begin(), farthestPointsFromOriginVector.end(), [](pair<Point, double>& a, pair<Point, double>& b) {
        return a.second > b.second;
    });

    Point* farthestPointsFromOriginArray = new Point[numPoints];

    for (int i = 0; i < 10; ++i) {
        farthestPointsFromOriginArray[i] = farthestPointsFromOriginVector[i].first;
    }

    return farthestPointsFromOriginArray;
}

