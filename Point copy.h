#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>

namespace Clustering {

    class Point {

    private:

        int dim;        // number of dimensions of the point
        double *values; // values of the point's dimensions

    public:
        Point(int);

        Point(int, double *);

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &);

        Point &operator=(const Point &);

        //Overloaded Comparison Operators
        bool operator==(const Point &, const Point &);
        bool operator!=(const Point &, const Point &);
        bool operator<(const Point &, const Point &);
        bool operator<=(const Point &, const Point &);
        bool operator>(const Point &, const Point &);
        bool operator>=(const Point &, const Point &);

        //Overloaded Arithmetic Operators
        Point &operator+(const Point &, const Point &);
        Point &operator-(const Point &, const Point &);
        Point &operator*(const Point &, double);
        Point &operator/(const Point &, double);

        //Overloaded Compound Assignment Operators
        Point &operator+=(Point &, const Point &);
        Point &operator-=(Point &, const Point &);
        Point &operator*=(Point &, double);
        Point &operator/=(Point &, double);



        ~Point();


        //Mutator Methods
        void setValue(int, double);

        //Accessor Methods
        int getDims() const { return dim; }
        double getValue(int) const;

        //MemberFunctions
        double distanceTo(Point& point);


    };
}