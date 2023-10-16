#include <valarray>
#include "Point.h"

using namespace std;

Point::Point(int x, int y) {
    if(x <= M && y <=M) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(point.getX() - this->x, 2) + pow(point.getY() - this->y, 2));
}