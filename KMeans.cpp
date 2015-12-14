//
// Created by Bryan Wheeler on 12/9/15.
//

#include "KMeans.h"
#include "ZeroClustersEx.h"

template<int k, int dim>
double Clustering::KMeans<k, dim>::computeDin() {
    try {
        if(clusterArr.size() == 0){
            throw ZeroClustersEx();
        }
        double result;
        for (int i = 0; i < clusterArr.size(); i++) {
            result += clusterArr[i].intraClusterDistance();
        }
        //Din = result;
        return result;
    }
    catch(double){
        return 0;
    }
}

template<int k, int dim>
void Clustering::KMeans<k, dim>::addCluster(Clustering::Cluster &cluster) {
    clusterArr.push_back(cluster);

}

template <int k ,int dim>
double Clustering::KMeans<k, dim>::computeDout() {
    try {
        if(clusterArr.size() == 0){
            throw ZeroClustersEx();
        }
        double result;
        for (int i = 0; i < clusterArr.size(); i++) {
            for (int j = 0; j < clusterArr.size(); j++) {
                result += interClusterDistance(clusterArr[i], clusterArr[j]);
            }
        }
        result /= 2;
        //Dout = result;
        return result;
    }
    catch(double){
        return 0;
    }
}

template<int k, int dim>
double Clustering::KMeans<k, dim>::computePin() {
    try {
        if(clusterArr.size() == 0){
            throw ZeroClustersEx();
        }
        double result;
        for (int i = 0; i < clusterArr.size(); i++) {
            result += clusterArr[i].getClusterEdges();
        }
        //Pin = result;
        return result;
    }
    catch(double){
        return 0;
    }
}

template <int k, int dim>
double Clustering::KMeans<k, dim>::computePout() {
    try {
        if (clusterArr.size() == 0) {
            throw ZeroClustersEx();
        }

        double result;
        for (int i = 0; i < clusterArr.size(); i++) {
            for (int j = i + 1; j < clusterArr.size(); j++) {
                result += interClusterEdges(clusterArr[i], clusterArr[j]);
            }
        }
        result /= 2;
        //Pout = result;
        return result;
    }
    catch(double){
        return 0;
    }

}

template <int k, int dim>
double Clustering::KMeans<k, dim>::computeClusteringScore() {
    Din = computeDin();
    Dout = computeDout();
    Pin = computePin();
    Pout = computePout();
    double result = ((Din / Pin) / (Dout / Pout));
    return result;
}
