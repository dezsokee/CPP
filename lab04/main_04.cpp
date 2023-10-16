#include <iostream>
#include <iomanip>
#include "Point.h"
#include "PointSet.h"

using namespace std;

int main() {
    Point p1;
    Point p2( 1, 1 );

    double distanceFromP1ToP2 = p1.distanceTo( p2 );

    cout<<"The distance from p1 to p2 is: "<<distanceFromP1ToP2<<"\n";

    int n = 2;
    cout<< fixed;

    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );

        /*if(n == 8) {
            pSet.sortPointsX();
            pSet.printPoints();
        }*/

        cout<<"Number of points: "<<n<<endl;

        cout<<"Minimum distance: " << pSet.minDistance()<<endl;
        cout<<"Maximum distance: " << pSet.maxDistance()<<endl;

        cout<<"Number of distances: " << pSet.numDistances()<<endl;
        cout<<"Number of distinct distances: " << pSet.numDistinctDistances()<<endl;

        n = n << 1;
    }

    return 0;
}