//
// Created by Bryan Wheeler
//

#include "Point.h"
#include <cassert>
#include <cmath>



Clustering::Point::Point(int i) {
    this->dim = i;
    this->values = new double[i];

}

Clustering::Point::Point(int i, double *pDouble) {
    assert((sizeof(pDouble)/(sizeof(int))) == i);

    this->dim = i;
    this->values = new double[i];

    for (int k = 0; k < i; k++) {
        this->values[i] = pDouble[i];
    }
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



bool operator==(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = pointA.dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) == pointB.getValue(k)) {
            result = true;
        }
        else {
            return false;
        }
    }
    return result;
}




bool operator!=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = pointA.dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) != pointB.getValue(k)) {
            result = true;
        }
        else {
            return false;
        }
    }
    return result;
}


bool operator<(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) == pointB.getValue(k)) {
            //doesn't have to do much, make its way until its either not true or false
            result = false;
        }
        else if (pointA.getValue(k) == pointB.getValue(k)) {
            result = false;
        }
        else {
            return false;
        }
    }
    return result;
}


bool operator<=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) < pointB.getValue(k)) {
            return true;
        }
        else if (pointA.getValue(k) == pointB.getValue(k)) {
            result = true;
        }
        else {
            return false;
        }
    }
    return result;
}



bool operator>(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = dim;
    for (int k = 0; k > i; k++) {
        if (pointA.getValue(k) > pointB.getValue(k)) {
            return true;
        }
        else if (pointA.getValue(k) == pointB.getValue(k)){
            //doesn't have to do much, will continue till true or false
            result = false;
        }
        else {
            return false;
        }
    }
    return result;
}


bool operator>=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) > pointB.getValue(k)) {
            return true;
        }
        else if (pointA.getValue(k) == pointB.getValue(k)){
            result = true;
        }
        else {
            return false;

        }
    }
    return result;
}


const Clustering::Point& operator+(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    int size = pointA.dim;
    Point* result = new Point(size);
    result->values = new double[size];

    for (int i = 0; i < size; i++) {
        result->values[i] = pointA.values[i] + pointB.values[i];
    }

    return * result;
    //return something!!!!!!!!
}


const Clustering::Point& operator-(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    int size = pointA.dim;
    Point* result = new Point();
    result->values = new double[size];

    for (int i = 0; i < size; i++) {
        result->values[i] = pointA.values[i] - pointB.values[i];
    }

    return * result;


}

const Clustering::Point& operator-(const Clustering::Point &point){
    int size = point.dim;
    Point* result = new Point();
    result->values = new double[size];

    for (int i = 0; i < size; i++) {
        result->values[i] = -point.values[i];
    }

    return * result;
}


const Clustering::Point& operator*(const Clustering::Point &point, const double d) {
    int size = point.dim;
    Point* result = new Point();
    result->values = new double[size];

    for (int i = 0; i < size; i++) {
        result->values[i] = point.values[i] * d;
    }

    return * result;

}

const Clustering::Point& operator/(const Clustering::Point &point, const double d) {
    assert(d != 0);

    int size = point.dim;
    Point* result = new Point();
    result->values = new double[size];

    for (int i = 0; i < size; i++) {
        result->values[i] = point.values[i] / d;
    }

    return * result;

}


const Clustering::Point& operator+=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    int size = pointA.dim;
    Point* result = new Point();
    result->values = new double[size];


    for (int i = 0; i < size; i++) {
        result->values[i] = pointA.values[i] + pointB.values[i];
    }

    return * result;

}

const Clustering::Point& operator-=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    int size = this->dim;
    Point* result = new Point();
    result->values = new double[size];


    for (int i = 0; i < size; i++) {
        result->values[i] = pointA.->values[i] - pointB.values[i];
    }

    return * result;

}

const Clustering::Point& operator*=(const Clustering::Point &point, const double d) {
    int size = point.dim;

    Point* result = new Point();
    result->values = new double[size];

    for (int i = 0; i < size; i++) {
        result->values[i] = point.values[i] * d;
    }

    return * result;

}

const Clustering::Point& operator/=(const Clustering::Point &point, const double d) {
    assert(d != 0);

    int size = this->dim;
    Point* result = new Point();
    result->values = new double[size];

    for (int i = 0; i < size; i++) {
        result->values[i] = point.values[i] / d;
    }

    return * result;

}
//Assignment Operator
Clustering::Point &Clustering::Point::operator=(const Clustering::Point &point) {
    this->dim = point.dim;
    this->values = new double[this->dim];
    int size = this->dim;

    for (int k = 0; k < size; k++) {
        this->values[k] = point.values[k];
    }

    return * this;
}
//Destructor
Clustering::Point::~Point() {
    delete [] values;

}

