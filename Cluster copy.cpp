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

    this->sortList();


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

    this->sortList();

    return * this;
}

//Destructor
Clustering::Cluster::~Cluster() {
    delete [] points;

}


//Addition Cluster Overload, Union Operator
const Clustering::Cluster& operator+(const Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB) {
    Clustering::Cluster* result;// = new Clustering::Cluster();

    *result = clusterA;
    int size = clusterA.getSize();
    Clustering::LNode* currentA = clusterA.getPoints();
    Clustering::LNode* currentB = clusterB.getPoints();
    Clustering::LNode* end = result->getPoints();
    while(end->next != NULL){
        end = end->next;
    }


    for(int i = 0; i < clusterA.getSize(); i++){
        for(int k = 0; k < clusterB.getSize(); k++){
            if(currentA->p == currentB->p){
                //do nothing
            }
            else{
                Clustering::LNode* addedNode = new Clustering::LNode();
                addedNode->p = currentB->p;
                end->next = addedNode;
                end = end->next;
                size++;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;

    }
    result->setSize(size);
    result->sortList();

    return * result;
}

const Clustering::Cluster& operator+=(Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB){


    Clustering::LNode* currentA = clusterA.getPoints();
    Clustering::LNode* currentB = clusterB.getPoints();
    int size = clusterA.getSize();
    Clustering::LNode* end = clusterA.getPoints();
    while(end->next != NULL){
        end = end->next;
    }


    for(int i = 0; i < clusterA.getSize(); i++){
        for(int k = 0; k < clusterB.getSize(); k++){
            if(currentA->p == currentB->p){
                //do nothing
            }
            else{
                Clustering::LNode* addedNode = new Clustering::LNode();
                addedNode->p = currentB->p;
                end->next = addedNode;
                end = end->next;
                size++;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;

    }
    clusterA.setSize(size);
    clusterA.sortList();


    return clusterA;
}


const Clustering::Cluster& operator+(const Clustering::Cluster &cluster, const Clustering::PointPtr p){
    Clustering::Cluster* result;// = new Clustering::Cluster();
    *result = cluster;

    int size = cluster.getSize();
    Clustering::LNode* end = result->getPoints();
    while(end->next != NULL){
        end = end->next;
    }

    Clustering::LNode* addedNode = new Clustering::LNode();
    addedNode->p = p;
    end->next = addedNode;
    end = end->next;
    end->next = NULL;
    size++;
    result->setSize(size);

    result->sortList();

    return * result;
}


const Clustering::Cluster& operator+=(Clustering::Cluster &cluster, const Clustering::PointPtr p){

    int size = cluster.getSize();
    Clustering::LNode* end = cluster.getPoints();
    while(end->next != NULL){
        end = end->next;
    }

    Clustering::LNode* addedNode = new Clustering::LNode();
    addedNode->p = p;
    end->next = addedNode;
    end = end->next;
    end->next = NULL;
    size++;
    cluster.setSize(size);

    cluster.sortList();

    return cluster;

}

//Subtraction Cluster Overload, Intersect Operator
const Clustering::Cluster& operator-(const Clustering::Cluster &clusterA, const Clustering::Cluster &clusterB) {
    Clustering::Cluster* result;// = new Clustering::Cluster();

    *result = clusterA;
    int size = clusterA.getSize();
    Clustering::LNode* currentA = result->getPoints();
    Clustering::LNode* currentB = clusterB.getPoints();
    Clustering::LNode* head = result->getPoints();
    Clustering::LNode* prev = nullptr;


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
        if(head == result->getPoints()){
            result->setPointsToNext();
        }
        else{}
        prev->next = head->next;
        currentA = prev->next;
        delete [] head;
        size--;
        result->setSize(size);



    }
    result->sortList();


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
    clusterA.sortList();


    return clusterA;
}


const Clustering::Cluster& operator-(const Clustering::Cluster &cluster, const Clustering::PointPtr p){
    Clustering::Cluster* result; //= new Clustering::Cluster();   <====Do I Need This?
    *result = cluster;
    Clustering::LNode* current = result->getPoints();
    Clustering::LNode* head = current;
    Clustering::LNode* prev = nullptr;
    int size = cluster.getSize();


    for(int i = 0; i < cluster.getSize(); i++) {
        if (current->p == p) {
            if (current == head) {
                current = current->next;
                result->setPoints(current);
                delete[] head;
                size--;
                result->setSize(size);
            }
            else {
                prev->next = head->next;
                current = head->next;
                delete[] head;
                size--;
                result->setSize(size);
            }
        }
        else {
            prev = current;
            current = current->next;
            head = current;
        }
    }

    return * result;


}


const Clustering::Cluster& operator-=(Clustering::Cluster &cluster, const Clustering::PointPtr p){
    Clustering::LNode* current = cluster.getPoints();
    Clustering::LNode* head = current;
    Clustering::LNode* prev = nullptr;
    int size = cluster.getSize();


    for(int i = 0; i < cluster.getSize(); i++) {
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



void Clustering::Cluster::sortList() {
    if (this->getPoints() != NULL)
    {
        Clustering::LNode* current = this->getPoints();
        Clustering::LNode* previous = nullptr;
        Clustering::LNode* tempPoint = nullptr;
        bool swapTest = false;
        int size = this->getSize();
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
                    if (this->getPoints() == current)
                        this->setPoints(tempPoint);

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
                current = this->getPoints();
                swapTest = false;
            }
        }

    }

}

void Clustering::Cluster::add(Clustering::Cluster &cluster, const Clustering::PointPtr p){

    int size = cluster.getSize();
    Clustering::LNode* end = cluster.getPoints();
    while(end->next != NULL){
        end = end->next;
    }

    Clustering::LNode* addedNode = new Clustering::LNode();
    addedNode->p = p;
    end->next = addedNode;
    end = end->next;
    end->next = NULL;
    size++;
    cluster.setSize(size);

    cluster.sortList();
}


void Clustering::Cluster::remove(Clustering::Cluster &cluster, const Clustering::PointPtr p){
    Clustering::LNode* current = cluster.getPoints();
    Clustering::LNode* head = current;
    Clustering::LNode* prev = nullptr;
    int size = cluster.getSize();


    for(int i = 0; i < cluster.getSize(); i++) {
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



