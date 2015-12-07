//
// Created by Bryan Wheeler on 9/20/15.
//

#include "Cluster.h"

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
    if (cluster.getSize() ==0) {
      std::cout << "You tried to copy an empty list." << std::endl;
      }


    this->setSize(cluster.getSize());
    LNode* current = cluster.getPoints();

    while (current != nullptr) {
        this->add(current->p);
        current = current->next;

    }



}

//Assignment operator overload
//Exit code 11 after multiple runs*************
Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    LNode* current = cluster.getPoints();

    for(current; current != nullptr; current = current->next){
        Point* point(current->p);
        this->add(point);
        std::cout << "After add function\n";
    }

    return * this;
}

//Destructor
Clustering::Cluster::~Cluster() {

    clear();

}





Clustering::Cluster & Clustering::Cluster::remove(const Clustering::PointPtr p){
    Clustering::LNode* current = this->getPoints();
    Clustering::LNode* head = current;
    Clustering::LNode* prev = nullptr;
    int size = this->getSize();


    while (current != nullptr) {
        if (*current->p == *p) {
            if (current == head) {
                current = current->next;
                this->setPoints(current);
                delete[] head;
                size--;
                this->setSize(size);
            }
            else {
                prev->next = current->next;
                head = current;
                current = current->next;
                delete[] head;
                size--;
                this->setSize(size);
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}


void Clustering::Cluster::clear() {
    LNode *head = this->getPoints();
    LNode *current = head;

    while (current != NULL) {
        current = current->next;
        delete[] head;
        head = current;
    }

}

Clustering::Cluster &Clustering::Cluster::add(Clustering::PointPtr const p) {
    Clustering::LNode *head = this->getPoints();
    Clustering::LNode *addedNode = new Clustering::LNode();
    addedNode->p = p;
    Clustering::LNode *prev = head;
    Clustering::LNode *current = head;

    int size = this->getSize();


    if (head == nullptr) {
        this->setPoints(addedNode);
    }
    else {
        while (current != nullptr) {
            if (*addedNode->p == *current->p) {
                addedNode->next = current->next;
                current->next = addedNode;
                current = nullptr;
            }

            else if (*addedNode->p > *current->p) {
                prev = current;
                current = current->next;
                if (current == nullptr || *current->p > *addedNode->p) {
                    addedNode->next = current;
                    prev->next = addedNode;
                    current = nullptr;
                }
            }

            else if (*addedNode->p < *current->p) {
                if (current == head) {
                    addedNode->next = head;
                    this->setPoints(addedNode);
                    current = nullptr;

                }

            }
        }

    }
    ++size;
    this->setSize(size);


    return *this;
}

