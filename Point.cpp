//
// Created by Bryan Wheeler on 9/20/15.
//

#include "Point.h"
#include <cmath>

using namespace Clustering;

int Clustering::Point::idGen = 0;



Clustering::Point::Point(int i) {
    this->dim = i;
    this->values = new double[i];
    this->id = ++idGen;

}

Clustering::Point::Point(int i, double *pDouble) {
    //assert((sizeof(pDouble)/(sizeof(*pDouble))) == i);

    this->dim = i;
    this->values = new double[i];

    for (int k = 0; k < i; k++) {
        this->values[k] = pDouble[k];
    }
    this->id = ++idGen;
}

Clustering::Point::Point(const Clustering::Point &point) {
    this->dim = point.dim;
    this->values = new double[this->dim];
    int size = this->dim;

    for (int k = 0; k < size; k++) {
        this->values[k] = point.values[k];
    }

}



void Clustering::Point::setValue(int i, double d) {

        this->values[i] = d;


}

double Clustering::Point::getValue(int i) const {

        return this->values[i];

}


double Clustering::Point::distanceTo(Clustering::Point &point) {
    assert(this->getDims() == point.dim);

    double distance = 0.0;
    double inside = 0.0;

    for (int i = 0; i < dim; i++) {
        inside += pow(point.values[i] - this->getValue(i), 2);
    }
    distance = sqrt(inside);
    return distance;

}


//Assignment Operator
Clustering::Point &Clustering::Point::operator=(const Clustering::Point &point) {
    this->dim = point.getDims();
    this->values = new double[this->getDims()];
    int size = this->getDims();

    for (int k = 0; k < size; k++) {
        this->values[k] = point.values[k];
    }

    return * this;
}
//Destructor
Clustering::Point::~Point() {
    delete [] values;


}

