#include "PointSet.h"
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

PointSet::PointSet(int n) {
    this->n = n;
    points.reserve(n);
    distances.reserve((n * (n - 1)) / 2);

    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range

    bool exists[M + 1][M + 1] = new bool[M + 1][M + 1]{false};

    while(points.size() != n) {
        int x = dist(mt);
        int y = dist(mt);
        //ellenorzes, hogy kulonbozo pontok legyenek a tombben
        Point p(x, y);

        if(exists[x][y]) {
            continue;
        } else {
            exists[x][y] = true;
            points.push_back(p);
        }
    }

    computeDistances();
}

void PointSet::computeDistances() {
    for(int i = 0; i< n; i++) {
        for (int j = i+1; j < n; ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point& lhs, const Point& rhs) {
        return lhs.getX() < rhs.getX();
    });
}


void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point& lhs, const Point& rhs) {
        return lhs.getY() < rhs.getY();
    });
}

void PointSet::printPoints() const {
    for (int i = 0; i < n; ++i) {
        cout << "(" << points[i].getX() << ", " << points[i].getY() << ") " << " ";
    }
    cout<<endl;
}

void PointSet::printDistances() const {
    for (int i = 0; i < distances.size(); ++i) {
        cout << distances[i] << " ";
    }
    cout<<endl;
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

int PointSet::numDistinctDistances() {
    sortDistances();
    int count = 1;
    for (int i = 1; i < distances.size(); ++i) {
        if(distances[i] != distances[i-1]) {
            count++;
        }
    }
    vector<double>::iterator ip = unique(distances.begin(), distances.begin() + distances.size());

    for (ip = distances.begin(); ip != distances.end(); ++ip) {
        cout << *ip << " ";
    }


    return count;
}


