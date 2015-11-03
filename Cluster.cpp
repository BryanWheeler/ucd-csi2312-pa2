//
// Created by Bryan Wheeler on 9/20/15.
//

#include "Cluster.h"
#include <cassert>

//Mutator Method
void Clustering::Cluster::setSize(int i) {
this->size = i;
}

void Clustering::Cluster::setPointsToNext() {
    this->points = this->points->next;
}

void Clustering::Cluster::setPoints(LNodePtr point) {
    this->points = point;
}


//Copy Constructor
Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {
    /*if (cluster.size ==0) {
     * std::cout << "You tried to copy an empty list." << std::endl;
     * }
     */

    this->size = cluster.size;
    LNode* current = cluster.getPoints();

    while (current != NULL) {
        add(*this, current->p);
        current = current->next;

    }



}

//Assignment operator overload
Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    this->size = cluster.size;
    LNode* current = cluster.getPoints();

    while (current != NULL) {
        add(*this, current->p);
        current = current->next;

    }


    return * this;
}

//Destructor
Clustering::Cluster::~Cluster() {

    clear();

}


//Addition Cluster Overload, Union Operator
const Clustering::Cluster& operator+(const Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB) {
    Clustering::Cluster* result;// = new Clustering::Cluster();

    *result = clusterA;
    int size = clusterA.getSize();
    Clustering::LNode* currentA = clusterA.getPoints();
    Clustering::LNode* currentB = clusterB.getPoints();
    /*Clustering::LNode* end = result->getPoints();
    while(end->next != NULL){
        end = end->next;
    }
     */


    while (currentA != NULL){
        while (currentB != NULL){
            if(currentA->p == currentB->p){
                //do nothing
            }
            else{
                /*Clustering::LNode* addedNode = new Clustering::LNode();
                addedNode->p = currentB->p;
                end->next = addedNode;
                end = end->next;
                */
                result->add(*result, currentB->p);
                size++;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;

    }
    result->setSize(size);

    return * result;
}

const Clustering::Cluster& operator+=(Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB){


    Clustering::LNode* currentA = clusterA.getPoints();
    Clustering::LNode* currentB = clusterB.getPoints();
    int size = clusterA.getSize();
    /*Clustering::LNode* end = clusterA.getPoints();
    while(end->next != NULL){
        end = end->next;
    }
     */


    while(currentA != NULL){
        while(currentB != NULL){
            if(currentA->p == currentB->p){
                //do nothing
            }
            else{
                clusterA.add(clusterA, currentB->p);
                size++;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;

    }
    clusterA.setSize(size);

    return clusterA;
}


const Clustering::Cluster& operator+(const Clustering::Cluster &cluster, const Clustering::PointPtr p){
    Clustering::Cluster* result;// = new Clustering::Cluster();
    *result = cluster;

    int size = cluster.getSize();
    /*Clustering::LNode* end = result->getPoints();
    while(end->next != NULL){
        end = end->next;
    }
     */

    result->add(*result, p);


    return * result;
}


const Clustering::Cluster& operator+=(Clustering::Cluster &cluster, const Clustering::PointPtr p){

    int size = cluster.getSize();
    /*Clustering::LNode* end = cluster.getPoints();
    while(end->next != NULL){
        end = end->next;
    }
     */

    cluster.add(cluster, p);

    return cluster;

}

//Subtraction Cluster Overload, Intersect Operator
const Clustering::Cluster& operator-(const Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB) {
    Clustering::Cluster* result;// = new Clustering::Cluster();

    int size = 0;
    Clustering::LNode* currentA = result->getPoints();
    Clustering::LNode* currentB = clusterB.getPoints();


    while(currentA != NULL){
        while(currentB != NULL){
            if(currentA->p == currentB->p){
                result->add(*result, currentA->p);
                size++;
                currentA = currentA->next;
                break;
            }
            else{
                currentB = currentB->next;
                //do nothing
            }

        }

        result->setSize(size);


    }

    return * result;
}

const Clustering::Cluster& operator-=(Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB){
    /*Cluster* result = new Cluster();

    *result = clusterA;
    */
    Clustering::LNode* currentA = clusterA.getPoints();
    Clustering::LNode* currentB = clusterB.getPoints();
    Clustering::LNode* head = clusterA.getPoints();
    Clustering::LNode* prev = nullptr;
    int size = clusterA.getSize();


    for(int i = 0; i < clusterA.getSize(); i++){
        for(int k = 0; k < clusterB.getSize(); k++){
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
        if(head == clusterA.getPoints()){
            clusterA.setPointsToNext();
        }
        else{}
        prev->next = head->next;
        currentA = prev->next;
        delete [] head;
        size--;
        clusterA.setSize(size);



    }


    return clusterA;
}


const Clustering::Cluster& operator-(const Clustering::Cluster &cluster, const Clustering::PointPtr p){
    Clustering::Cluster* result; //= new Clustering::Cluster();   <====Do I Need This?
    *result = cluster;

    result->remove(*result, p);


    return * result;


}


const Clustering::Cluster& operator-=(Clustering::Cluster &cluster, const Clustering::PointPtr p){

    cluster.remove(cluster, p);

    return cluster;

}

//Equivalence Comparison Operator Overload
bool operator==(const Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB){

    assert(clusterA.getSize() == clusterB.getSize());
    bool result = false;
    Clustering::LNode* currentA = clusterA.getPoints();
    Clustering::LNode* currentB = clusterB.getPoints();
    for (int i = 0; i < clusterA.getSize(); i++){
        if(currentA->p == currentB->p){
            result = true;
        }
        else{
            return false;
        }
    }

    return result;


}





void Clustering::Cluster::add(Clustering::Cluster &cluster, const Clustering::PointPtr p){


    Clustering::LNode* head = cluster.getPoints();
    Clustering::LNode* addedNode = new Clustering::LNode();
    addedNode->p = p;
    Clustering::LNode* prev = head;
    Clustering::LNode* current = head;
    int size = cluster.getSize();

    if (current == NULL) {
        addedNode->p = p;
        cluster.setPoints(addedNode);
    }
    else {
        while (current != NULL) {
            if (addedNode->p == current->p) {
                addedNode->next = current->next;
                current->next = addedNode;
                return;
            }

            else if (addedNode->p > current->p) {
                prev = current;
                current = current->next;
            }

            else if (addedNode->p < current->p) {
                if (current == head) {
                    addedNode->next = head;
                    cluster.setPoints(addedNode);
                    return;
                }
                else {
                    prev->next = addedNode;
                    addedNode->next = current;
                    return;

                }
            }

        }
    }
    size++;
    cluster.setSize(size);
}


void Clustering::Cluster::remove(Clustering::Cluster &cluster, const Clustering::PointPtr p){
    Clustering::LNode* current = cluster.getPoints();
    Clustering::LNode* head = current;
    Clustering::LNode* prev = nullptr;
    int size = cluster.getSize();


    while (current != NULL) {
        if (current->p == p) {
            if (current == head) {
                current = current->next;
                cluster.setPoints(current);
                delete[] head;
                size--;
                cluster.setSize(size);
            }
            else {
                prev->next = head->next;
                current = head->next;
                delete[] head;
                size--;
                cluster.setSize(size);
            }
        }
        else {
            prev = current;
            current = current->next;
            head = current;
        }
    }
}


void Clustering::Cluster::clear() {
    LNode* head = this->getPoints();
    LNode* current = head;

    while(current != NULL) {
        current = current->next;
        delete [] head;
        head = current;
    }

}
