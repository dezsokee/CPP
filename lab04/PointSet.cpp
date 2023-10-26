#include "PointSet.h"
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

PointSet::PointSet(int n) {
    this->n = n;
    points.reserve(n);
    distances.reserve((n * (n - 1)) / 2);

    matrix = new int*[M+1];
    for (int i = 0; i < M+1; ++i)
        matrix[i] = new int[M+1];

    for (int i = 0; i < M+1; ++i) {
        for (int j = 0; j < M+1; ++j) {
            matrix[i][j] = false;
        }
    }

    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range

    while(points.size() != n) {
        int x = dist(mt);
        int y = dist(mt);

        Point p(x, y);

        if(matrix[x][y]) {
            continue;
        } else {
            matrix[x][y] = true;
            points.push_back(p);
        }
    }

    computeDistances();
}

PointSet::~PointSet() {
    for (int i = 0; i < M+1; ++i)
        delete [] matrix[i];
    delete [] matrix;

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
    return count;
}

int PointSet::numDistinctDistances2() {
    vector<double>::iterator ip;
    ip = unique(distances.begin(), distances.begin()+distances.size());

    distances.resize(std::distance(distances.begin(), ip));

    return distances.size();
}

