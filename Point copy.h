#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>

namespace Clustering {

    class Point {


    private:

        int dim;        // number of dimensions of the point
        double *values; // values of the point's dimensions

    public:
        Point() : dim(0), values(NULL){};

        Point(int);

        Point(int, double *);

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &);

        Point &operator=(const Point &);

        ~Point();

        //Overloaded Comparison Operators
        friend bool operator==(const Point &, const Point&);
        friend bool operator!=(const Point &, const Point&);
        friend bool operator<(const Point &, const Point&);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);

        //Overloaded Arithmetic Operators
        friend const Point &operator+(const Point &, const Point &);
        friend const Point &operator-(const Point &, const Point &);
        friend const Point &operator-(const Point &);
        friend const Point &operator*(const Point &, double);
        friend const Point &operator/(const Point &, double);

        //Overloaded Compound Assignment Operators
        friend const Point &operator+=(const Point &, const Point&);
        friend const Point &operator-=(const Point &, const Point &);
        friend const Point &operator*=(const Point &, double);
        friend const Point &operator/=(const Point &, double);




        //Mutator Methods
        void setValue(int, double);

        //Accessor Methods
        int getDims() const { return dim; }
        double getValue(int) const;

        //MemberFunctions
        double distanceTo(Point& point);


    };
}