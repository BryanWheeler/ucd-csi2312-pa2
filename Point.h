#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <vector>

namespace Clustering {

    class Point {

        //Overloaded Relational Operators
        friend bool operator==(const Point &, const Point &);   //DONE***WORKS
        friend bool operator!=(const Point &, const Point &);   //DONE***WORKS
        friend bool operator<(const Point &, const Point &);   //DONE***WORKS
        friend bool operator<=(const Point &, const Point &);   //DONE***WORKS
        friend bool operator>(const Point &, const Point &);   //DONE***WORKS
        friend bool operator>=(const Point &, const Point &);   //DONE***WORKS

        //Overloaded Arithmetic Operators
        friend const Point &operator+(const Point &, const Point &);   //DONE***WORKS
        friend const Point &operator-(const Point &, const Point &);   //DONE***WORKS
        friend const Point &operator*(const Point &, double);   //DONE***WORKS
        friend const Point &operator/(const Point &, double);   //DONE***WORKS

        //Overloaded Compound Assignment Operators
        friend const Point &operator+=(Point &, const Point &);   //DONE***WORKS
        friend const Point &operator-=(Point &, const Point &);   //DONE***WORKS
        friend const Point &operator*=(Point &, const Point &);   //DONE***WORKS
        friend const Point &operator/=(Point &, const Point &);   //DONE***WORKS

        //Overloaded File Stream
        friend std::ostream &operator<<(std::ostream &, const Point &);   //DONE***WORKS
        friend std::istream &operator>>(std::istream &, const Point &);


    private:

        int dim;        // number of dimensions of the point
        double *values; // values of the point's dimensions
        unsigned int id;
        static int idGen;


    public:
        Point() : dim(0), values(NULL), id(++idGen) { };

        Point(int);

        Point(int, double *);

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &);

        Point &operator=(const Point &);

        ~Point();


        //Mutator Methods
        void setValue(int, double);

        void setValue(int i) { *values = values[i]; }

        void setDims(int k) {this->dim = k;}

        //Accessor Methods
        int getDims() const { return dim; }

        double getValue(int) const;

        int getId() const {return id;}

        //MemberFunctions
        double distanceTo(Point &point);


    };


    inline bool operator==(const Point &pointA, const Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());
            int size = pointA.getDims();
            for (int i = 0; i < size; i++) {
                if (pointA.getValue(i) == pointB.getValue(i)) {
                    //Do nothing...Let it run through
                }
                else {
                    return false;
                }
            }
            return true;


    }


    inline bool operator!=(const Point &pointA, const Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            bool result;
            for (int i = 0; i < size; i++) {
                result = (pointA.getValue(i) != pointB.getValue(i));
            }
            return result;


    }


    inline bool operator<(const Point &pointA, const Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            for (int i = 0; i < size; i++) {
                if (pointA.getValue(i) == pointB.getValue(i)) {
                    //doesn't have to do much, make its way until its either not true or false
                }
                else if (pointA.getValue(i) < pointB.getValue(i)) {
                    return true;
                }
                else {
                    return false;
                }

            }
            return false;

    }

    inline bool operator<=(const Point &pointA, const Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            for (int i = 0; i < size; i++) {
                if (pointA.getValue(i) == pointB.getValue(i)) {
                    //doesn't have to do much, make its way until its either not true or false
                }
                else if (pointA.getValue(i) < pointB.getValue(i)) {
                    return true;
                }
                else {
                    return false;
                }

            }
            return true;

    }

    inline bool operator>(const Clustering::Point &pointA, const Clustering::Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            for (int i = 0; i < size; i++) {
                if (pointA.getValue(i) == pointB.getValue(i)) {
                    //doesn't have to do much, make its way until its either not true or false
                }
                else if (pointA.getValue(i) > pointB.getValue(i)) {
                    return true;
                }
                else {
                    return false;
                }

            }
            return false;

    }

    inline bool operator>=(const Clustering::Point &pointA, const Clustering::Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            for (int i = 0; i < size; i++) {
                if (pointA.getValue(i) == pointB.getValue(i)) {
                    //doesn't have to do much, make its way until its either not true or false
                }
                else if (pointA.getValue(i) > pointB.getValue(i)) {
                    return true;
                }
                else {
                    return false;
                }

            }
            return true;

    }

    inline const Point &operator+(const Point &pointA, const Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            double value;
            Point *result = new Point(size);

            for (int i = 0; i < size; i++) {
                value = pointA.getValue(i) + pointB.getValue(i);
                result->setValue(i, value);
            }

            return *result;

    }

    inline const Point &operator-(const Point &pointA, const Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            double value;
            Point *result = new Point(size);

            for (int i = 0; i < size; i++) {
                value = pointA.getValue(i) - pointB.getValue(i);
                result->setValue(i, value);
            }

            return *result;


    }

    inline const Point &operator*(const Point &point, const double d) {
        int size = point.getDims();
        double value;
        Point *result = new Point(size);

        for (int i = 0; i < size; i++) {
            value = point.getValue(i) * d;
            result->setValue(i, value);
        }

        return *result;

    }

    inline const Point &operator/(const Point &point, const double d) {
        assert(d != 0);

        int size = point.getDims();
        double value;
        Point *result = new Point(size);

        for (int i = 0; i < size; i++) {
            value = point.getValue(i) / d;
            result->setValue(i, value);
        }

        return *result;

    }

    inline const Point &operator+=(Point &pointA, const Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            double value;


            for (int i = 0; i < size; i++) {
                value = pointA.getValue(i) + pointB.getValue(i);
                pointA.setValue(i, value);
            }

            return pointA;

    }

    inline const Point &operator-=(Point &pointA, const Point &pointB) {
        assert(pointA.getDims() == pointB.getDims());

        int size = pointA.getDims();
            double value;


            for (int i = 0; i < size; i++) {
                value = pointA.getValue(i) - pointB.getValue(i);
                pointA.setValue(i, value);
            }

            return pointA;


    }

    inline const Point &operator*=(Point &point, const double d) {
        int size = point.getDims();
        double value;


        for (int i = 0; i < size; i++) {
            value = point.getValue(i) * d;
            point.setValue(i, value);
        }

        return point;

    }

    inline const Point &operator/=(Point &point, const double d) {
        assert(d != 0);

        int size = point.getDims();
        double value;

        for (int i = 0; i < size; i++) {
            value = point.getValue(i) / d;
            point.setValue(i, value);
        }

        return point;

    }

    inline std::ostream &operator<<(std::ostream &os, const Point &point) {
        int size = point.getDims();
        for (int i = 0; i < size; i++) {
            if (i != size - 1) {
                os << std::setprecision(1) << std::fixed << point.getValue(i) << ", ";
            }
            else {
                os << std::setprecision(1) << std::fixed << point.getValue(i);
            }
        }

        return os;
    }

    inline std::istream &operator>>(std::istream &os, Point &point) {
        std::vector<double> valueArr;
        std::string data = "";
        std::getline(os, data, '\n');
        std::stringstream ss(data);
        double k;
        int dimensions = point.getDims();
        int count = 0;

        while (ss >> k) {
            valueArr.push_back(k);
            ++count;

            if (ss.peek() == ',' || ss.peek() == ' ') {
                ss.ignore();
            }
        }

            for (int i = 0; i < dimensions; i++) {
                point.setValue(i, valueArr[i]);
            }


    }

}





#endif