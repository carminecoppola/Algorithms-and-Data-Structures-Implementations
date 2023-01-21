#ifndef ALGORITMO_H
#define ALGORITMO_H

#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Algoritmo
{
    private:
        int heapSize;
        int left(int i){return (i*2)+1;}
        int right(int i){return (i*2)+2;}

        void buildMaxHeap();
    protected:

        vector<T> tree;
        int parent(int i){return (i-1)/2;}

        //Metodi di set
        void setHeapSize(int heapSize){this->heapSize = heapSize;}

        //Metodi di get
        vector<T> getTree(){return tree;}
        int getHeapSize(){return heapSize;}


        void swap(T &a, T&b);
        void maxHeapify(int i);

    public:

        Algoritmo(vector<T> );
        Algoritmo();

        void heapSort();
        void insert(T nodo);
        void printArray();
};

template<class T> Algoritmo<T>::Algoritmo(vector<T> albero)
{
    heapSize = albero.size();
    tree = albero;
    buildMaxHeap();
}

template<class T> Algoritmo<T>::Algoritmo()
{
    heapSize = 0;
}

template<class T> void Algoritmo<T>::swap(T &a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T> void Algoritmo<T>::buildMaxHeap()
{
    setHeapSize((int)getTree().size());
    for(int i = (getHeapSize()/2)-1; i>= 0; i--)
        maxHeapify(i);
}

template<class T> void Algoritmo<T>::maxHeapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(max) < getTree().at(l))
        max = l;
    if(r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;
    if(max != i)
    {
        swap(tree.at(max),tree.at(i));
        maxHeapify(i);
    }
}

template<class T> void Algoritmo<T>::heapSort()
{
    buildMaxHeap();

    for(int i = getHeapSize()-1; i >= 0; i--)
    {
        swap(tree.at(0),tree.at(i));
        setHeapSize(getHeapSize()-1);
        maxHeapify(0);
    }
}

template<class T> void Algoritmo<T>::insert(T nodo)
{
    setHeapSize(getHeapSize()+1);
    tree.push_back(nodo);

    int i = getHeapSize()-1;
    while(i > 0 && getTree().at(parent(i)) < nodo)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }
}


template<class T> void Algoritmo<T>::printArray()
{
    for(auto i:tree)
        cout<<i<<" ";
    cout<<endl;   
}

#endif