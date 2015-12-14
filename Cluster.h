#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

//    struct LNode;
//    typedef LNode *LNodePtr;

    struct LNode {
        PointPtr p;
        LNodePtr next;
    };

    class Cluster {
        int size;
        LNodePtr points;
        Point centroid;
        unsigned int id;
        bool centroidValid;
        static int idGen;


    public:
        Cluster() : size(0), points(nullptr), id(++idGen){}

        //void insertAfter (LNode*&, const PointPtr&);

        //Big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &);

        Cluster &operator=(const Cluster &);

        ~Cluster();


        //FRIEND FUNCTIONS----------------------------------------------------------------
        //Add Function
        void add(const PointPtr);   //DONE***WORKS
        friend const Cluster &operator+(const Cluster &, const PointPtr);   //DONE***WORKS
        friend const Cluster &operator+=(Cluster &, const PointPtr);        //DONE***WORKS
        //Remove Function
        const PointPtr &remove(const PointPtr&);   //DONE***WORKS
        friend const Cluster &operator-(const Cluster &, const PointPtr);   //DONE***WORKS
        friend const Cluster &operator-=(Cluster &, const PointPtr);   //DONE***WORKS

        //Overloaded Arithmetic Operators
        friend const Cluster &operator+(const Cluster &, const Cluster &);   //DONE***WORKS
        friend const Cluster &operator+=(Cluster &, const Cluster &);   //DONE***WORKS
        friend const Cluster &operator-(const Cluster &, const Cluster &);   //DONE***WORKS
        friend const Cluster &operator-=(Cluster &, const Cluster &);   //DONE***WORKS
        friend bool operator==(const Cluster &, const Cluster &);   //DONE***WORKS

        //Overloaded file stream
        friend std::ostream &operator<<(std::ostream &, const Cluster &);   //DONE***WORKS
        friend std::istream &operator>>(std::istream &, Cluster &);

        //Distance between clusters
        friend double interClusterDistance(const Cluster &c1, const Cluster &c2);

        //returns number of distinct point pairs, or edges, between two clusters
        friend double interClusterEdges(const Cluster &c1, const Cluster &c2);

        Point& computeCentroid(Cluster&);

        bool centroidValidation();


        ///Accessor Methods
        const int getSize() const { return size; }

        LNodePtr getPoints() const { return points; }

        const bool getValid() const {return centroidValid;}

        const int getID() const {return id;}

        const Point& getCentroid();

        //Mutator Method
        void setSize(int);

        void setPointsToNext();

        void setPoints(LNodePtr);

        void clear();

        void setCentroid(Point&);

        void setValid(bool);

        //sum of the distance between points within a cluster
        double intraClusterDistance() const;

        //returns number of distinct point pairs, or edges, in a cluster
        int getClusterEdges();



        class Move{
            PointPtr ptr;
            Cluster* clusterFrom;
            Cluster* clusterTo;
        public:
            Move(const PointPtr& pointer, Cluster* clusterF, Cluster* clusterT);
            void perform();
            void pickPoints(int k, PointPtr *pointArray);
        };


    };


    inline const Cluster &operator+(const Cluster &cluster, const PointPtr p) {
        Clustering::Cluster *result = new Cluster();
        *result = cluster;

        result->add(p);
        result->setValid(false);

        return *result;

    }

    inline const Cluster &operator+=(Cluster &cluster, const PointPtr p) {

        cluster.add(p);
        cluster.setValid(false);

        return cluster;

    }

    inline const Cluster &operator-(const Cluster &cluster, const PointPtr p) {
        Clustering::Cluster *result = new Cluster();
        *result = cluster;

        result->remove(p);
        result->setValid(false);

        return *result;


    }

    inline const Cluster &operator-=(Cluster &cluster, const PointPtr p) {

        cluster.remove(p);
        cluster.setValid(false);

        return cluster;

    }

    inline const Cluster &operator+(const Cluster &clusterA, const Cluster &clusterB) {
        Cluster *result = new Cluster();

        *result = clusterB;
        Clustering::LNode *currentA = clusterA.getPoints();
        Clustering::LNode *currentB;


        while (currentA != nullptr) {
            currentB = clusterB.getPoints();

            while (currentB != nullptr) {
                if (*currentA->p == *currentB->p) {
                    //Value doesn't need to be added
                    currentA = currentA->next;
                    currentB = clusterB.getPoints();
                }
                else {
                    //Don't do anything...let it run through to find if there are any matches
                    currentB = currentB->next;
                }
            }
            if (currentA != nullptr) {
                result->add(currentA->p);
                currentA = currentA->next;
            }


        }
        result->setValid(false);

        return *result;
    }

    inline const Cluster &operator+=(Cluster &clusterA, const Cluster &clusterB) {


        Clustering::LNode *currentA = clusterA.getPoints();
        Clustering::LNode *currentB;

        while (currentA != nullptr) {
            currentB = clusterB.getPoints();

            while (currentB != nullptr) {
                if (*currentA->p == *currentB->p) {
                    //Value doesn't need to be added
                    currentA = currentA->next;
                    currentB = clusterB.getPoints();
                }
                else {
                    //Don't do anything...let it run through to find if there are any matches
                    currentB = currentB->next;
                }
            }
            if (currentA != nullptr) {
                clusterA.add(currentA->p);
                currentA = currentA->next;
            }


        }
        clusterA.setValid(false);

        return clusterA;
    }

    inline const Cluster &operator-(const Cluster &clusterA, const Cluster &clusterB) {
        Cluster *result = new Cluster();

        Clustering::LNode *currentA = clusterA.getPoints();
        Clustering::LNode *currentB;


        while (currentA != nullptr) {
            currentB = clusterB.getPoints();

            while (currentB != nullptr) {
                if (*currentA->p == *currentB->p) {
                    result->add(currentA->p);
                    currentB = nullptr;

                }
                else {
                    currentB = currentB->next;
                    //do nothing
                }
            }
            currentA = currentA->next;


        }

        result->setValid(false);

        return *result;
    }

    inline const Cluster &operator-=(Cluster &clusterA, const Cluster &clusterB) {

        Clustering::LNode *currentA = clusterA.getPoints();
        Clustering::LNode *currentB, *prev;

        while (currentA != nullptr) {
            currentB = clusterB.getPoints();

            while (currentB != nullptr) {
                if (*currentA->p == *currentB->p) {
                    //Value doesn't need to be removed
                    prev = currentA;
                    currentA = currentA->next;
                    currentB = clusterB.getPoints();
                }
                else {
                    //Don't do anything...let it run through to find if there are any matches
                    currentB = currentB->next;

                }
            }
            if (currentA != nullptr) {
                clusterA.remove(currentA->p);
                currentA = prev->next;
            }


        }
        clusterA.setValid(false);

        return clusterA;
    }

    inline bool operator==(const Cluster &clusterA, const Cluster &clusterB) {
        assert(clusterA.getSize() == clusterB.getSize());
        bool result;
        Clustering::LNode *currentA = clusterA.getPoints();
        Clustering::LNode *currentB = clusterB.getPoints();
        //for (int i = 0; i < clusterA.getSize(); i++, currentA=currentA->next, currentB=currentB->next) {
        while (currentA != nullptr) {
            if (*currentA->p == *currentB->p) {
                result = true;
            }
            else {
                return false;
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }
        return result;
    }

    inline std::ostream &operator<<(std::ostream &os, const Cluster &cluster) {
        LNode *current = cluster.getPoints();
        os << "Values:\n";
        while (current != nullptr) {
            os << *current->p;
            os << ": " << cluster.getID() << "\n";
            current = current->next;
        }

        return os;

    }

    inline std::istream &operator>>(std::istream &os, Cluster &cluster) {
        std::string data = "";
        std::getline(os, data, '\n');
        std::stringstream ss(data);
        Cluster temp(cluster);
        Point point;

        while (ss >> point) {

            if (ss.peek() == ',' || ss.peek() == ' ') {
                ss.ignore();
            }

        }
        temp.add(&point);
        cluster = temp;

    }


}





#endif