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

    };
}