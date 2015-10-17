#include <iostream>

#include "Point.h"

using namespace std;
using namespace Clustering;

int main() {

    int dimension = 5;
    double values[dimension] = {1,2,3,4,5};
    double values2[dimension] = {1,2,3,7,9};

    Point test(dimension, values);
    Point test2(dimension, values2);

    /*  :(      Why always true/false
     *
     * if(test == test2) {
        cout << "It worked" << endl;
    }
    else {
        cout << "Guess Not" << endl;
    }

     */



    return 0;
}