#include <iostream>

#include "Point.h"

using namespace std;
using namespace Clustering;

int main() {

    int dimension = 5;
    int dimensions = 6;
    double values[5] = {1,2,3,4,5};
    double values2[5] = {1,2,3,7,9};
    double values3[6] = {1,2,5,6,7,8};

    Point test(dimension, values);
    Point test2(dimension, values2);
    Point test3(dimensions, values3);


/*

    if (test == test3) {
        cout << "meh" << endl;
    }
    else{
        cout << "oops" << endl;
    }
    
*/

/*

    if(test == test2) {
        cout << "It worked" << endl;
    }
    else {
        cout << "Guess Not" << endl;
    }


*/


    return 0;
}