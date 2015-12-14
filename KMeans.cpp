//
// Created by Bryan Wheeler on 12/9/15.
//

#include "KMeans.h"

double Clustering::KMeans::computeDin() {
        double result;
        for (int i = 0; i < clusterArr.size(); i++) {
            result += clusterArr[i].intraClusterDistance();
        }
        //Din = result;
        return result;

}

void Clustering::KMeans::addCluster(Clustering::Cluster &cluster) {
    clusterArr.push_back(cluster);

}

double Clustering::KMeans::computeDout() {

        double result;
        for (int i = 0; i < clusterArr.size(); i++) {
            for (int k = 0; k < clusterArr.size(); k++) {
                result += interClusterDistance(clusterArr[i], clusterArr[k]);
            }
        }
        result /= 2;
        //Dout = result;
        return result;

}

double Clustering::KMeans::computePin() {

        double result;
        for (int i = 0; i < clusterArr.size(); i++) {
            result += clusterArr[i].getClusterEdges();
        }
        //Pin = result;
        return result;

}

double Clustering::KMeans::computePout() {


        double result;
        for (int i = 0; i < clusterArr.size(); i++) {
            for (int k = i + 1; k < clusterArr.size(); k++) {
                result += interClusterEdges(clusterArr[i], clusterArr[k]);
            }
        }
        result /= 2;
        //Pout = result;
        return result;

}

double Clustering::KMeans::computeClusteringScore() {
    Din = computeDin();
    Dout = computeDout();
    Pin = computePin();
    Pout = computePout();
    double result = ((Din / Pin) / (Dout / Pout));
    return result;
}
