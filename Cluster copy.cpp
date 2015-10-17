//
// Created by Bryan Wheeler
//

#include "Cluster.h"
#include <cassert>

//Copy Constructor
Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {
    /*if (cluster.size ==0) {
     * std::cout << "You tried to copy an empty list." << std::endl;
     * }
     */

    this->size = cluster.size;
    this->points = new LNode();

    this->points->p = cluster.points->p;
    int size = cluster.size;

    LNode *cpyOfCluster = cluster.points;
    LNode *cpyOfThis = this->points;
    for (int i = 1; i < size; i++) {
        LNode *addedNode = new LNode();
        cpyOfThis->next = addedNode;
        addedNode->p = cluster.points->p;
        cpyOfThis->next = addedNode->next;
        cpyOfCluster = cpyOfCluster->next;
    }

    cpyOfThis->next = NULL;

    sortList(*this);


}

//Assignment operator overload
Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    this->size = cluster.size;
    this->points = new LNode();

    this->points->p = cluster.points->p;
    int size = cluster.size;

    LNode *cpyOfCluster = cluster.points;
    LNode *cpyOfThis = this->points;
    for (int i = 1; i < size; i++) {
        LNode *addedNode = new LNode();
        cpyOfThis->next = addedNode;
        addedNode->p = cluster.points->p;
        cpyOfThis->next = addedNode->next;
        cpyOfCluster = cpyOfCluster->next;
    }

    cpyOfThis->next = NULL;

    sortList(*this);

    return * this;
}

//Destructor
Clustering::Cluster::~Cluster() {
    delete points;

}


//Addition Cluster Overload, Union Operator
const Clustering::Cluster& operator+(const Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB) {
    Cluster* result = new Cluster();

    *result = clusterA;
    LNode* currentA = clusterA.points;
    LNode* currentB = clusterB.points;
    /*LNode* end = result->points;
    while(end->next != NULL){
        end = end->next;
    }
    */

    for(int i = 0; i < clusterA.size; i++){
        for(int k = 0; k < clusterB.size; k++){
            if(currentA->p == currentB->p){
                //do nothing
            }
            else{
                /*LNode* addedNode = new LNode();
                addedNode->p = currentB->p;
                end->next = addedNode;
                end = end->next;
                result->size++;
                */
                Clustering::Cluster::add(*result, currentB->p);
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;

    }
    //sortList(*result);


    return * result;
}

const Clustering::Cluster& operator+=(Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB){
    /*Cluster* result = new Cluster();

    *result = clusterA;
    */
    LNode* currentA = clusterA.points;
    LNode* currentB = clusterB.points;
    int size = clusterA.size;
    LNode* end = clusterA.points;
    while(end->next != NULL){
        end = end->next;
    }


    for(int i = 0; i < clusterA.size; i++){
        for(int k = 0; k < clusterB.size; k++){
            if(currentA->p == currentB->p){
                //do nothing
            }
            else{
                LNode* addedNode = new LNode();
                addedNode->p = currentB->p;
                end->next = addedNode;
                end = end->next;
                size++;

            }
            currentB = currentB->next;
        }
        currentA = currentA->next;

    }
    clusterA.size = size;
    sortList(clusterA);


    return clusterA;
}
/******************************************* DO THIS **********************/
const Clustering::Cluster& operator+=(Clustering::Cluster &cluster, const PointPtr){

}

//Subtraction Cluster Overload, Intersect Operator
const Clustering::Cluster& operator-(const Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB) {
    Cluster* result = new Cluster();

    *result = clusterA;
    LNode* currentA = result->points;
    LNode* currentB = clusterB.points;
    LNode* head = result->points;
    LNode* prev = nullptr;


    for(int i = 0; i < clusterA.size; i++){
        for(int k = 0; k < clusterB.size; k++){
            if(currentA->p == currentB->p){
                prev = currentA;
                currentA = currentA->next;
                head = currentA;
                currentB = currentB->next;
                i++;
                break;
            }
            else{
                currentB = currentB->next;
                //do nothing
            }

        }
        if(head == result->points){
            result->points = result->points->next;
        }
        else{}
        prev->next = head->next;
        currentA = prev->next;
        delete [] head;
        result->size--;



    }
    sortList(*result);


    return * result;
}

const Clustering::Cluster& operator-=(Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB){
    /*Cluster* result = new Cluster();

    *result = clusterA;
    */
    LNode* currentA = clusterA.points;
    LNode* currentB = clusterB.points;
    LNode* head = clusterA.points;
    LNode* prev = nullptr;


    for(int i = 0; i < clusterA.size; i++){
        for(int k = 0; k < clusterB.size; k++){
            if(currentA->p == currentB->p){
                prev = currentA;
                currentA = currentA->next;
                head = currentA;
                currentB = currentB->next;
                i++;
                break;
            }
            else{
                currentB = currentB->next;
                //do nothing
            }
        }
        if(head == clusterA.points){
            clusterA.points = clusterA.points->next;
        }
        else{}
        prev->next = head->next;
        currentA = prev->next;
        delete [] head;
        clusterA.size--;



    }
    sortList(clusterA);


    return clusterA;
}

/******************************************* DO THIS **********************/
const Clustering::Cluster& operator-=(Clustering::Cluster &cluster, const PointPtr){

}

//Equivalence Comparison Operator Overload
bool operator==(const Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB){
    assert(clusterA.size == clusterB.size);
    bool result = false;
    LNode* currentA = clusterA.points;
    LNode* currentB = clusterB.points;
    for (int i = 0; i < clusterA.size; i++){
        if(currentA->p == currentB->p){
            result = true;
        }
        else{
            return false;
        }
    }

    return result;


}



void Clustering::Cluster::sortList(Clustering::Cluster &cluster) {
    if (cluster.points != 0)
    {
        LNode* current = cluster.points;
        LNode* previous = nullptr;
        LNode* tempPoint = nullptr;
        bool swapTest = false;
        int size = cluster.size;
        for (int i = 0; i < size; i++)
        {
            while (current->next != NULL)
            {
                tempPoint = current->next;

                if (current->p > tempPoint->p)
                {
                    swapTest = true;
                    current->next = tempPoint->next;
                    tempPoint->next = current;
                    if (previous != 0)
                        previous->next = tempPoint;
                    previous = tempPoint;
                    if (cluster.points == current)
                        cluster.points = tempPoint;

                }
                else
                {
                    previous = current;
                    current = current->next;
                }
            }
            if (swapTest == false)
                break;
            else
            {
                previous = nullptr;
                current = cluster.points;
                swapTest = false;
            }
        }

    }

}

void Clustering::Cluster::add(Clustering::Cluster &cluster, const Clustering::PointPtr p){

    LNode* end = cluster.points;
    while(end->next != NULL){
        end = end->next;
    }

    LNode* addedNode = new LNode();
    addedNode->p = p;
    end->next = addedNode;
    end = end->next;
    end->next = NULL;
    cluster.size++;

    sortList(cluster);
}


void Clustering::Cluster::remove(Clustering::Cluster &cluster, const Clustering::PointPtr p){
    LNode* current = cluster.points;
    LNode* head = current;
    LNode* prev = nullptr;


    for(int i = 0; i < cluster.size; i++) {
        if (current->p == p) {
            if (current == head) {
                current = current->next;
                cluster.points = current;
                delete[] head;
                cluster.size--;
            }
            else {
                prev->next = head->next;
                current = head->next;
                delete[] head;
                cluster.size--;
            }
        }
        else {
            prev = current;
            current = current->next;
            head = current;
        }
    }
}



