#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"

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

    public:
        Cluster() : size(0), points(nullptr) { };

        //void insertAfter (LNode*&, const PointPtr&);

        //Big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster&);
        Cluster& operator=(const Cluster&);
        ~Cluster();

        //Linked List Sort
        void sortList(Cluster&);

        //Add Function
        void add(Cluster&, const PointPtr);
        friend const Cluster &operator+=(Cluster&, const PointPtr);
        //Remove Function
        void remove(Cluster&, const PointPtr);
        friend const Cluster &operator-=(Cluster&, const PointPtr);

        //Overloaded Arithmetic Operators
        friend const Cluster &operator+(const Cluster&, const Cluster&);
        friend const Cluster &operator+=(Cluster&, const Cluster&);
        friend const Cluster &operator-(const Cluster&, const Cluster&);
        friend const Cluster &operator-=(Cluster&, const Cluster&);
        friend bool operator==(const Cluster&, const Cluster&);




    };
}