#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include<iostream>
#include"maxHeap.h"
#include<vector>

using namespace std;

template<class T>
class priority_queue : public maxHeap<T>
{
    private:
        
    public:
        priority_queue(vector<T> albero);

        T maximum();
        T extractMax();
        void insertPQ(T nodo);
        void increaseKey(int i, T key);
};

//Costruttore
template<class T> priority_queue<T>::priority_queue(vector<T> albero):maxHeap<T>(albero){}

//INSERTPQ
template<class T> void priority_queue<T>::insertPQ(T nodo)
{
    this->insert(nodo);
}

//MAXIMUM
template<class T> T priority_queue <T>::maximum()
{
    return this->getTree().at(0);
}

//EXTRACT MAX
template<class T> T priority_queue<T>::extractMax()
{
    if (this->getHeapSize() == 0)
        return -1;
    
    // T max = maximum();
    // swap(this->tree.at(0) , this->tree.at(this->getHeapSize()-1));
    // this->setHeapSize(this->getHeapSize()-1);
    // this->maxHeapify(0);

    T max = maximum();
    int i = this->getHeapSize()-1;
    this->swap(this->tree.at(0), this->tree.at(i));
    this->setHeapSize(this->getHeapSize()-1);
    this->maxHeapify(0);

    return max;
}

//INCREASE KEY
template<class T> void priority_queue<T>::increaseKey(int i, T key)
{
    if (key < this->getTree().at(i))
    {   
        cout<<"Invalid data"<<endl;
        exit;
    }
    this->tree.at(i) = key;
    while (i > 0 && this->getTree().at(this->parent(i)) < this->getTree().at(i))
    {
        swap(this->tree.at(this->parent(i)), this->tree.at(i));
        i = this->parent(i);
    }
}

#endif