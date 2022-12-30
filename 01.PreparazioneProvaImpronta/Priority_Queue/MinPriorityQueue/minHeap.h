#ifndef MINHEAP_H
#define MINHEAP_H

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class minHeap
{
    private:
        int heapSize;
        
        int left(int i){return (i*2)+1;}
        int right(int i){return (i*2)+2;}

    protected:
        vector<int> tree;
        int parent(int i){return (i-1)/2;}
        void swap(T &a, T&b);

        void setHeapSize(int size){heapSize = size;}
        int getHeapSize(){return heapSize;}
        vector<T> getTree(){return tree;}

        void minHeapify(int);
    public:
        minHeap(vector<T> );
        minHeap();

        void buildMinHeap();
        void insert(T nodo);
        void heapSort();
        void printArray();
};

//Costruttore
template<class T> minHeap<T>::minHeap(vector<T> x)
{
    tree = x;
    heapSize = x.size();
}
//Secondo Costruttore
template<class T> minHeap<T>::minHeap()
{
    heapSize = 0;
}
//SWAP
template<class T> void minHeap<T>::swap(T &a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}
//MINHEAPIFY
template<class T> void minHeap<T>::minHeapify(int i)
{
    int min = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(min) > getTree().at(l))
        min = l;
    if(r < getHeapSize() && getTree().at(min) > getTree().at(r))
        min = r;
    if(min != i){
        swap(tree.at(i), tree.at(min));
        minHeapify(min);
    }
}
//BUILDMINHEAP
template<class T> void minHeap<T>::buildMinHeap()
{
    setHeapSize((int) tree.size());

    for (int i = getHeapSize()/2 -1; i >= 0; i--)
        minHeapify(i);
}
//INSERT
template<class T> void minHeap<T>::insert(T nodo)
{
    setHeapSize(getHeapSize()+ 1);
    tree.push_back(nodo);

    int i = getHeapSize()-1;
    while (i > 0 && getTree().at(parent(i)) > nodo)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }
}
//HEAPSORT
template<class T> void minHeap<T>::heapSort()
{
    buildMinHeap();
    for(int i = getHeapSize()-1; i >= 0 ; i--)
    {
        swap(tree.at(i),tree.at(0));
        setHeapSize(getHeapSize()-1);
        minHeapify(0);
    }
}
//PRINTARRAY
template<class T> void minHeap<T>::printArray()
{
    for(auto i:tree)
        cout<<i<<" ";
    cout<<endl;
}
#endif
