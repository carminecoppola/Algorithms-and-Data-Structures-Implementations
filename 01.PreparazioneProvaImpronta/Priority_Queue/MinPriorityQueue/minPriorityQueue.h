#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include<iostream>
#include"minHeap.h"
#include<vector>

using namespace std;

template<class T>
class minPriorityQueue : public minHeap<T>
{
    private:
        /* data */
    public:
        minPriorityQueue(vector<T> albero);

        T minimum();
        T extractMin();
        void insertPQ(T nodo);
        void decrasePriority(int i, T key);
        void print();
};

//Costruttore
template<class T> minPriorityQueue<T>::minPriorityQueue(vector<T> albero):minHeap<T>(albero){}

//INSERT Priority Queque
template<class T> void minPriorityQueue<T>::insertPQ(T nodo)
{
    this->insert(nodo);
}

//MINIMUM
template<class T> T minPriorityQueue<T>::minimum()
{
    return this->getTree().at(0);
}

//EXTRACT MIN
template<class T> T minPriorityQueue<T>::extractMin()
{
        if(this->getHeapSize() == 0)
            return -1;
    
        T min = minimum();
        int i = this->getHeapSize()-1;
        this->swap(this->tree.at(0), this->tree.at(i));
        this->setHeapSize(this->getHeapSize()-1);
        this->minHeapify(0);
    
    return min;
}

//DECRASEPRIORITY
template<class T> void minPriorityQueue<T>::decrasePriority(int i, T key)
{
    if (key < this->getTree().at(i))
    {
        cout<<"Invalid Data..."<<endl;
        exit;
    }

    this->getTree().at(i) = key;

    while (i > 0 && this->getTree().at(this->parent(i)) < this->getTree().at(i))
    {
        this->swap(this->tree.at(this->parent(i)) , this->tree.at(i));
        i = this->parent(i);
    }
    
    
}

//Print
template<class T> void minPriorityQueue<T>::print()
{
    cout<<endl << "**Albero***" << endl;
    for (int i = 0; i < this->getHeapSize(); i++) 
        cout << this->getTree().at(i) <<" ";
    cout<<endl<<endl;
}




#endif