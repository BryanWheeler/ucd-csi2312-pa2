//
// Created by Bryan Wheeler on 9/20/15.
//

#include "Point.h"
#include <cassert>
#include <cmath>



Clustering::Point::Point(int i) {
    dim = i;

}

Clustering::Point::Point(int i, double *pDouble) {
    dim = i;
    values = pDouble;
    values = new double[i];

}

Clustering::Point::Point(const Clustering::Point &point) {
    dim = point.dim;
    values = point.values;

    delete [] point.values;

}



void Clustering::Point::setValue(int i, double d) {
    *(values+i) = d;

}

double Clustering::Point::getValue(int i) const {
    return *(values+i);
}


double Clustering::Point::distanceTo(Clustering::Point &point) {
    assert(getDims() == point.dim);

    double distance = 0.0;
    double inside = 0.0;

    for (int i = 0; i < dim; i++) {
        inside += pow(point.*(values+i) - getValue(i), 2);
    }
    distance = sqrt(inside);
    return distance;

}

bool Clustering::Point::operator==(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = pointA.dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) == pointB.getValue(k)) {
            result = true;
        }
        else {
            result = false;
            k = i;
        }
    }

    return result;
}

bool Clustering::Point::operator!=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = pointA.dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) != pointB.getValue(k)) {
            result = true;
        }
        else {
            result = false;
            k = i;
        }
    }
    return result;

}

bool Clustering::Point::operator<(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = pointA.dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) < pointB.getValue(k)) {
            return true;
        }
        else if (pointA.getValue(k) == pointB.getValue(k)){
            //doesn't have to do much, make its way until its either not true or false
            result = false;
        }
        else {
            return false;
        }
    }
    return result;
}

bool Clustering::Point::operator<=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = pointA.dim;
    for (int k = 0; k < i; k++) {
        if (pointA.getValue(k) < pointB.getValue(k)) {
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


bool Clustering::Point::operator>(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = pointA.dim;
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

bool Clustering::Point::operator>=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    bool result = false;
    int i = pointA.dim;
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

Clustering::Point &Clustering::Point::operator+(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    int size = pointA.dim;
    Point result(size);
    //result.values = new double[size];

    for (int i = 0; i < size; i++) {
        result.*(values+i) = pointA.*(values+i) + pointB.*(values+i);
    }

    return result;
}

Clustering::Point &Clustering::Point::operator-(const Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    int size = pointA.dim;
    Point result(size);
    //result.values = new double[size];

    for (int i = 0; i < size; i++) {
        result.*(values+i) = pointA.*(values+i) - pointB.*(values+i);
    }

    return result;


}

Clustering::Point &Clustering::Point::operator*(const Clustering::Point &point, double d) {

    int size = point.dim;
    Point result(size);
    //result.values = new double[size];

    for (int i = 0; i < size; i++) {
        result.*(values+i) *= d;
    }

    return result;

}

Clustering::Point &Clustering::Point::operator/(const Clustering::Point &point, double d) {
    assert(d != 0);

    int size = point.dim;
    Point result(size);
    //result.values = new double[size];

    for (int i = 0; i < size; i++) {
        result.*(values + i) /= d;
    }

    return result;

}

Clustering::Point &Clustering::Point::operator+=(Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    int size = pointA.dim;
    //Point result(size);
    //result.values = new double[size];

    for (int i = 0; i < size; i++) {
        pointA.*(values+i) = pointA.*(values+i) + pointB.*(values+i);
    }

    return pointA;

}

Clustering::Point &Clustering::Point::operator-=(Clustering::Point &pointA, const Clustering::Point &pointB) {
    assert(pointA.dim == pointB.dim);

    int size = pointA.dim;
    //Point result(size);
    //result.values = new double[size];

    for (int i = 0; i < size; i++) {
        pointA.*(values+i) = pointA.*(values+i) - pointB.*(values+i);
    }

    return pointA;

}

Clustering::Point &Clustering::Point::operator*=(Clustering::Point &point, double d) {
    int size = point.dim;
    //Point result(size);
    //result.values = new double[size];

    for (int i = 0; i < size; i++) {
        point.*(values+i) *= d;
    }

    return point;

}

Clustering::Point &Clustering::Point::operator/=(Clustering::Point &point, double d) {
    assert(d != 0);

    int size = point.dim;
    //Point result(size);
    //result.values = new double[size];

    for (int i = 0; i < size; i++) {
        point.*(values + i) /= d;
    }

    return point;

}

Clustering::Point &Clustering::Point::operator=(const Clustering::Point &point) {
    return <#initializer#>;
}

Clustering::Point::~Point() {
    delete [] values;

}
