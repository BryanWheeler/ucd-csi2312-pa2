#include <iostream>

#include "Point.h"
#include "Cluster.h"

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
    Point test4, test5, test6, test7;

    cout << test.getDims() << "\n";
    cout << test3.getDims() << "\n";

    for(int i = 0; i < test.getDims(); i++){
        cout << test.getValue(i) << " ";
    }
    cout << "\n";


    if ((test == test2)) {
        cout << "meh" << endl;
    }
    else{
        cout << "oops" << endl;
    }


    if (test != test2) {
        cout << "meh" << endl;
    }
    else{
        cout << "oops" << endl;
    }


    if (test < test2) {
        cout << "meh" << endl;
    }
    else{
        cout << "oops" << endl;
    }

    if (test2 <= test) {
        cout << "meh" << endl;
    }
    else{
        cout << "oops" << endl;
    }


    if (test > test2) {
        cout << "meh" << endl;
    }
    else{
        cout << "oops" << endl;
    }

    if (test2 >= test2) {
        cout << "meh" << endl;
    }
    else{
        cout << "oops" << endl;
    }

    test4 = (test + test2);

    for(int i = 0; i < test4.getDims(); i++){
        cout << test4.getValue(i) << " ";
    }
    cout << "\n";

    test5 = (test4 - test);

    for(int i = 0; i < test5.getDims(); i++){
        cout << test5.getValue(i) << " ";
    }
    cout << "\n";

    test6 = (test * 2);

    for(int i = 0; i < test6.getDims(); i++){
        cout << test6.getValue(i) << " ";
    }
    cout << "\n";


    test7 = (test6 / 2);

    for(int i = 0; i < test7.getDims(); i++){
        cout << test7.getValue(i) << " ";
    }
    cout << "\n";

    test7 += test;
    for(int i = 0; i < test7.getDims(); i++){
        cout << test7.getValue(i) << " ";
    }
    cout << "\n";

    test7 -= test;
    for(int i = 0; i < test7.getDims(); i++){
        cout << test7.getValue(i) << " ";
    }
    cout << "\n";

    test7 *= 3;
    for(int i = 0; i < test7.getDims(); i++){
        cout << test7.getValue(i) << " ";
    }
    cout << "\n";

    test7 /= 3;
    for(int i = 0; i < test7.getDims(); i++){
        cout << test7.getValue(i) << " ";
    }
    cout << "\n";


    cout << "END OF TESTING OF POINT CLASS\n\n";

    Cluster clusterTest, clusterTest2, clusterTest3, clusterTest4, clusterTest5;
    clusterTest.add(&test2);
    clusterTest2.add(&test);

    cout << clusterTest;
    cout << clusterTest2;




    if(clusterTest == clusterTest2){
        cout << "woohoo\n";
    }
    else{
        cout << "Whelp\n";
    }

    clusterTest3 = clusterTest + clusterTest2;
    cout << clusterTest3;

    clusterTest4 = clusterTest;

    cout << clusterTest4;

    cout << clusterTest3;

    clusterTest5 = clusterTest3 - clusterTest; //WORKS
    clusterTest3 -= clusterTest2;






    if(clusterTest4 == clusterTest2){
        cout << "woot woot\n";
    }
    else{
        cout << "nope nope\n";
    }

    cout << clusterTest5;

    cout << clusterTest3;


    return 0;

}
