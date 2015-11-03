//
// Created by Bryan Wheeler on 9/20/15.
//

#include "Point.h"
#include <cassert>
#include <cmath>



Clustering::Point::Point(int i) {
    this->dim = i;
    this->values = new double[i];

}

Clustering::Point::Point(int i, double *pDouble) {
    //assert((sizeof(pDouble)/(sizeof(*pDouble))) == i);

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
    assert(pointA.getDims() == pointB.getDims());

    int size = pointA.getDims();
    for (int i = 0; i < size; i++) {
        if (pointA.getValue(i) == pointB.getValue(i)) {
            //do nothing
        }
        else {
            return false;
        }
    }
    return true;
}




bool operator!=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    bool result = false;
    int size = pointA.getDims();
    for (int i = 0; i < size; i++) {
        if (pointA.getValue(i) != pointB.getValue(i)) {
            result = true;
        }
        else {
            return false;
        }
    }
    return result;
}


bool operator<(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    bool result = false;
    int size = pointA.getDims();
    for (int i = 0; i < size; i++) {
        if (pointA.getValue(i) == pointB.getValue(i)) {
            //doesn't have to do much, make its way until its either not true or false
            result = false;
        }
        else if (pointA.getValue(i) < pointB.getValue(i)) {
            return true;
        }
        else{
            return false;
        }

    }
    return result;
}


bool operator<=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    bool result = false;
    int size = pointA.getDims();
    for (int i = 0; i < size; i++) {
        if (pointA.getValue(i) == pointB.getValue(i)) {
            //doesn't have to do much, make its way until its either not true or false
            result = true;
        }
        else if (pointA.getValue(i) < pointB.getValue(i)) {
            return true;
        }
        else{
            return false;
        }

    }
    return result;
}



bool operator>(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    bool result = false;
    int size = pointA.getDims();
    for (int i = 0; i < size; i++) {
        if (pointA.getValue(i) == pointB.getValue(i)) {
            //doesn't have to do much, make its way until its either not true or false
            result = false;
        }
        else if (pointA.getValue(i) > pointB.getValue(i)) {
            return true;
        }
        else{
            return false;
        }

    }
    return result;
}


bool operator>=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    bool result = false;
    int size = pointA.getDims();
    for (int i = 0; i < size; i++) {
        if (pointA.getValue(i) == pointB.getValue(i)) {
            //doesn't have to do much, make its way until its either not true or false
            result = true;
        }
        else if (pointA.getValue(i) > pointB.getValue(i)) {
            return true;
        }
        else{
            return false;
        }

    }
    return result;
}


const Clustering::Point& operator+(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    int size = pointA.getDims();
    double value;
    Clustering::Point result(size);// = new Clustering::Point(size);

    for (int i = 0; i < size; i++) {
        value = pointA.getValue(i) + pointB.getValue(i);
        result.setValue(i, value);
    }

    return result;
}


const Clustering::Point& operator-(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    int size = pointA.getDims();
    double value;
    Clustering::Point result(size);// = new Clustering::Point(size);

    for (int i = 0; i < size; i++) {
        value = pointA.getValue(i) - pointB.getValue(i);
        result.setValue(i, value);
    }

    return result;


}

const Clustering::Point& operator-(const Clustering::Point &point){
    int size = point.getDims();
    double value;
    Clustering::Point result(size);// = new Clustering::Point(size);

    for (int i = 0; i < size; i++) {
        value = (-1)*point.getValue(i);
        result.setValue(i, value);
    }

    return result;
}


const Clustering::Point& operator*(const Clustering::Point &point, const double d) {
    int size = point.getDims();
    double value;
    Clustering::Point result(size);// = new Clustering::Point(size);

    for (int i = 0; i < size; i++) {
        value = point.getValue(i) * d;
        result.setValue(i, value);
    }

    return result;

}

const Clustering::Point& operator/(const Clustering::Point &point, const double d) {
    assert(d != 0);

    int size = point.getDims();
    double value;
    Clustering::Point result(size);// = new Clustering::Point(size);

    for (int i = 0; i < size; i++) {
        value = point.getValue(i) / d;
        result.setValue(i, value);
    }

    return result;

}


const Clustering::Point& operator+=(Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    int size = pointA.getDims();
    double value;
    //Clustering::Point* result = new Clustering::Point(size);


    for (int i = 0; i < size; i++) {
        value = pointA.getValue(i) + pointB.getValue(i);
        pointA.setValue(i, value);
    }

    return pointA;

}

const Clustering::Point& operator-=(Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.getDims() == pointB.getDims());

    int size = pointA.getDims();
    double value;
    //Clustering::Point* result = new Clustering::Point(size);


    for (int i = 0; i < size; i++) {
        value = pointA.getValue(i) - pointB.getValue(i);
        pointA.setValue(i, value);
    }

    return pointA;

}

const Clustering::Point& operator*=(Clustering::Point &point, const double d) {
    int size = point.getDims();
    double value;

    //Clustering::Point* result = new Clustering::Point(size);

    for (int i = 0; i < size; i++) {
        value = point.getValue(i) * d;
        point.setValue(i, value);
    }

    return point;

}

const Clustering::Point& operator/=(Clustering::Point &point, const double d) {
    assert(d != 0);

    int size = point.getDims();
    double value;
    //Clustering::Point* result = new Clustering::Point(size);

    for (int i = 0; i < size; i++) {
        value = point.getValue(i) / d;
        point.setValue(i, value);
    }

    return point;

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
//    delete [] values;
//    delete values;
//    delete [] Point;

}

