//
// Created by Bryan Wheeler on 9/20/15.
//

#include "Cluster.h"

//Mutator Method

int Clustering::Cluster::idGen = 0;

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
                current = nullptr;
            }
            else {
                prev->next = current->next;
                head = current;
                current = current->next;
                delete[] head;
                size--;
                this->setSize(size);
                current = nullptr;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return * this;
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

const Clustering::Point &Clustering::Cluster::getCentroid() {
    return centroid;
}

void Clustering::Cluster::setCentroid(Clustering::Point &point) {
    centroid = point;
    centroidValid = true;
}

Clustering::Point &Clustering::Cluster::computeCentroid(Clustering::Cluster &cluster) {
    Point* newPoint = new Point();
    LNode* current = cluster.getPoints();
    *newPoint = *current->p;
    current = current->next;
    while(current != nullptr){
        *newPoint += *current->p;
        current = current->next;
    }

    return * newPoint;
}

bool Clustering::Cluster::centroidValidation() {
    Point checkPoint = this->computeCentroid(*this);
    if (checkPoint == this->getCentroid()){
        centroidValid = true;
        return true;
    }
    else{
        return false;
    }

}

void Clustering::Cluster::setValid(bool b) {
    centroidValid = b;
}

Clustering::Cluster::Move::Move(Clustering::PointPtr const &pointer, Clustering::Cluster *clusterF,
                                Clustering::Cluster *clusterT) {
    ptr = pointer;
    clusterFrom = clusterF;
    clusterTo = clusterT;

}

void Clustering::Cluster::Move::perform() {
    clusterTo->add(ptr);
    clusterFrom->remove(ptr);
    clusterFrom->setValid(false);
    clusterTo->setValid(false);

}

void Clustering::Cluster::Move::pickPoints(int k, Clustering::PointPtr *pointArray) {
    LNode* current = clusterFrom->getPoints();
    int i = 0;

    while(current != nullptr){
        if(i < k){
            *pointArray[i] = *current->p;
            current = current->next;
        }
        else{
            current = nullptr;
        }
    }
}

double Clustering::Cluster::intraClusterDistance() const {
    LNode* pointOne = this->getPoints();
    LNode* pointTwo;
    double distance;

    while(pointOne != nullptr){
        pointTwo = pointOne->next;

        while(pointTwo != nullptr){
            distance += pointOne->p->distanceTo(*pointTwo->p);
            pointTwo = pointTwo->next;
        }
        pointOne = pointOne->next;
    }
    distance /= 2;
    return distance;

}

double Clustering::interClusterDistance(const Clustering::Cluster &c1, const Clustering::Cluster &c2) {
    double distance;
    LNode* clusterOne = c1.getPoints();
    LNode* clusterTwo;

    while (clusterOne != nullptr){
        clusterTwo = c2.getPoints();

        while (clusterTwo != nullptr){
            distance += clusterOne->p->distanceTo(*clusterTwo->p);
            clusterTwo = clusterTwo->next;
        }
        clusterOne = clusterOne->next;
    }
    distance /= 2;
    return distance;
}

int Clustering::Cluster::getClusterEdges() {
    int edges;
    int size = this->getSize();
    edges = (size * (size - 1)) / 2;
    return edges;
}

double Clustering::interClusterEdges(const Clustering::Cluster &c1, const Clustering::Cluster &c2) {
    int edges;
    int sizeOne = c1.getSize();
    int sizeTwo = c2.getSize();

    edges = (sizeOne * sizeTwo);
    return edges;
}
