#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<iostream>
#include <vector>
using namespace std;

template <class T>
class maxHeap
{
    private:
        int heapSize;
        int left(int i){return (i*2)+1;}
        int right(int i){return (i*2)+2;}

        void buildMaxHeap();

    protected:
        vector<T> tree;
        int parent(int i){return (i-1)/2;}

        vector<T> getTree(){return tree;}
        void setHeapSize(int size){heapSize = size;}
        int getHeapSize(){return heapSize;}

        void swap(T &a, T&b);
        void maxHeapify(int i);
        
    public:
        maxHeap(vector<T> t);
        maxHeap();

        void heapSort();
        void insert(T nodo);
        void printArray();
};

template <class T> maxHeap<T>::maxHeap(vector<T> t)
{
    heapSize = t.size();
    tree = t;
    buildMaxHeap();
}

template <class T> maxHeap<T>::maxHeap()
{
   heapSize = 0;
}

template <class T> void maxHeap<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T> void maxHeap<T>::maxHeapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(r);

    if (l < getHeapSize() && getTree().at(max) < getTree().at(l))
        max = l;
        
    if (r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;

    if (max != i){
        swap(tree.at(max) ,tree.at(i));
        maxHeapify(i);
    }
}

template <class T> void maxHeap<T>::buildMaxHeap()
{
    setHeapSize((int) getTree().size());
    for (int i = (getHeapSize()/2)-1; i >= 0; i--)
        maxHeapify(i);
}

template <class T> void maxHeap<T>::insert(T nodo)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(nodo);

    int i = getHeapSize()-1;
    
    while (i > 0 && getTree().at(parent(i)) < nodo)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }  
}

template <class T> void maxHeap<T>::heapSort()
{
    buildMaxHeap();

    for (int i = getHeapSize()-1; i >= 0; i--)
    {
        swap(tree.at(0), tree.at(i));
        setHeapSize(getHeapSize()-1);
        maxHeapify(0);
    }
    
}

template<class T> void maxHeap<T>::printArray()
{
    for(auto i:tree)
        cout<<i<<" ";
    cout<<endl;
}

#endif