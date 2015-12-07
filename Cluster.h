#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"
#include <cassert>

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



        //Add Function
        Cluster& add(const PointPtr);   //DONE***WORKS
        friend const Cluster &operator+(const Cluster&, const PointPtr);   //DONE***WORKS
        friend const Cluster &operator+=(Cluster&, const PointPtr);        //DONE***WORKS
        //Remove Function
        void remove(Cluster&, const PointPtr);   //DONE***WORKS
        friend const Cluster &operator-(const Cluster&, const PointPtr);   //DONE***WORKS
        friend const Cluster &operator-=(Cluster&, const PointPtr);   //DONE***WORKS

        //Overloaded Arithmetic Operators
        friend const Cluster &operator+(const Cluster&, const Cluster&);   //DONE***WORKS
        friend const Cluster &operator+=(Cluster&, const Cluster&);   //DONE***WORKS
        friend const Cluster &operator-(const Cluster&, const Cluster&);   //DONE***WORKS
        friend const Cluster &operator-=(Cluster&, const Cluster&);   //DONE***WORKS
        friend bool operator==(const Cluster&, const Cluster&);   //DONE***WORKS

        //Overloaded file stream
        friend std::ostream &operator<<(std::ostream &, const Cluster &);   //DONE***WORKS
        friend std::istream &operator>>(std::istream &, Cluster &);


        ///Accessor Methods
        int getSize() const {return size;}
        LNodePtr getPoints() const {return points;}

        //Mutator Method
        void setSize(int);
        void setPointsToNext();
        void setPoints(LNodePtr);

        void clear();

    };

    inline const Cluster& operator+(const Cluster& cluster, const PointPtr p){
        Clustering::Cluster* result = new Cluster();
        *result = cluster;

        result->add(p);


        return * result;

    }

    inline const Cluster& operator+=(Cluster &cluster, const PointPtr p){

        cluster.add(p);

        return cluster;

    }

    inline const Cluster& operator-(const Cluster &cluster, const PointPtr p){
        Clustering::Cluster* result = new Cluster();   //<====Do I Need This?
        *result = cluster;

        result->remove(*result, p);


        return * result;


    }

    inline const Cluster& operator-=(Cluster &cluster, const PointPtr p){

        cluster.remove(cluster, p);

        return cluster;

    }

    inline const Cluster& operator+(const Cluster &clusterA, const Cluster &clusterB) {
        Cluster* result = new Cluster();

        *result = clusterB;
        Clustering::LNode* currentA = clusterA.getPoints();
        Clustering::LNode* currentB;


        while (currentA != nullptr){
            currentB = clusterB.getPoints();

            while (currentB != nullptr){
                if(*currentA->p == *currentB->p){
                    //Value doesn't need to be added
                    currentA = currentA->next;
                    currentB = clusterB.getPoints();
                }
                else{
                    //Don't do anything...let it run through to find if there are any matches
                    currentB = currentB->next;
                }
            }
            if (currentA != nullptr) {
                result->add(currentA->p);
                currentA = currentA->next;
            }


        }

        return * result;
    }

    inline const Cluster& operator+=(Cluster &clusterA, const Cluster &clusterB){


        Clustering::LNode* currentA = clusterA.getPoints();
        Clustering::LNode* currentB;

        while (currentA != nullptr){
            currentB = clusterB.getPoints();

            while (currentB != nullptr){
                if(*currentA->p == *currentB->p){
                    //Value doesn't need to be added
                    currentA = currentA->next;
                    currentB = clusterB.getPoints();
                }
                else{
                    //Don't do anything...let it run through to find if there are any matches
                    currentB = currentB->next;
                }
            }
            if (currentA != nullptr) {
                clusterA.add(currentA->p);
                currentA = currentA->next;
            }


        }

        return clusterA;
    }

    inline const Cluster& operator-(const Cluster &clusterA, const Cluster &clusterB) {
        Cluster* result = new Cluster();

        Clustering::LNode* currentA = clusterA.getPoints();
        Clustering::LNode* currentB = clusterB.getPoints();


        while(currentA != nullptr){
            while(currentB != nullptr){
                if(*currentA->p == *currentB->p){
                    result->add(currentA->p);
                    currentA = currentA->next;
                    currentB = clusterB.getPoints();
                }
                else{
                    currentB = currentB->next;
                    //do nothing
                }

            }



        }


        return * result;
    }

    inline const Cluster& operator-=(Cluster &clusterA, const Cluster &clusterB){

        Clustering::LNode* currentA = clusterA.getPoints();
        Clustering::LNode* currentB, *prev;

        while (currentA != nullptr){
            currentB = clusterB.getPoints();

            while (currentB != nullptr){
                if(*currentA->p == *currentB->p){
                    //Value doesn't need to be added
                    prev = currentA;
                    currentA = currentA->next;
                    currentB = clusterB.getPoints();
                }
                else{
                    //Don't do anything...let it run through to find if there are any matches
                    currentB = currentB->next;

                }
            }
            if (currentA != nullptr) {
                clusterA.remove(clusterA, currentA->p);
                currentA = prev->next;
            }


        }

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
                std::cout << "Entered true area\n";
            }
            else {
                std::cout << "Entered false area\n";
                return false;
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }
        std::cout << "Entered\n";
        return result;
    }

    inline std::ostream &operator<<(std::ostream & os, const Cluster & cluster){
        LNode * current = cluster.getPoints();
        os << "Values:\n";
        while(current != nullptr){
            os << *current->p;
            current = current->next;
        }

        return os;

    }




    }



#endif