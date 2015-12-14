//
// Created by Bryan Wheeler on 12/9/15.
//

#ifndef IP_PA_2_KMEANS_H
#define IP_PA_2_KMEANS_H

#include <math.h>
#include <vector>
#include "Cluster.h"

namespace Clustering {
    class KMeans {
        double Din;
        double Dout;
        double Pin;
        double Pout;
        std::vector<Cluster> clusterArr;

    public:
        static const double SCORE_DIFF_THRESHOLD;

        double computeClusteringScore();
        double computeDin();
        double computeDout();
        double computePin();
        double computePout();
        void addCluster(Cluster& cluster);

    };
}

#endif //IP_PA_2_KMEANS_H
