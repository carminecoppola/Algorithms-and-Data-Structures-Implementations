#ifndef ALGORITMO_H
#define ALGORITMO_H

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class algoritmo
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
        void setHeapSize(int hSize){ heapSize = hSize;}
        int getHeapSize(){return heapSize;}

        void swap(T &a, T &b);
        void maxHeapify(int i);

    public:
        algoritmo(vector<T> );
        algoritmo();

        void heapSort();
        void printArray();
        void insert(T nodo);
};

//Costruttore
template<class T> algoritmo<T>::algoritmo(vector<T> albero)
{
    heapSize = albero.size();
    tree = albero;
    buildMaxHeap(); //Costruzione dell'albero
}
//Secondo Costruttore per il size
template<class T> algoritmo<T>::algoritmo()
{
    heapSize = 0;
}
//SWAP
template<class T> void algoritmo<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
//MAXHEAPIFY
template<class T> void algoritmo<T>::maxHeapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if (l < getHeapSize() && getTree().at(max) < getTree().at(l))
        max = l;
    if (r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;
    if( max != i){
        swap(tree.at(max), tree.at(i));
        maxHeapify(i);
    }
}
//BUILDMAXHEAP
template<class T> void algoritmo<T>::buildMaxHeap()
{
    setHeapSize((int)getTree().size());
    for (int i = (getHeapSize()/2)-1; i >= 0; i--)
        maxHeapify(i);
    
}
//INSERT
template<class T> void algoritmo<T>::insert(T nodo)
{
    setHeapSize(getHeapSize() + 1); //Creo lo spazio
    tree.push_back(nodo);          //Inserisco il nodo

    int i = getHeapSize()-1;
    while (i > 0 && getTree().at(parent(i)) < nodo){
        swap(tree.at(parent(i)), tree.at(i));   //Scambio la radice con il figlio
        i = parent(i);                          
    }
}
//HEAPSORT
template<class T> void algoritmo<T>::heapSort()
{
    buildMaxHeap();

    for (int i = getHeapSize()-1; i >= 0 ; i--)
    {
        swap(tree.at(0), tree.at(i));
        setHeapSize(getHeapSize() - 1);
        maxHeapify(0);
    }
    
}
//PRINTARRAY
template<class T> void algoritmo<T>::printArray()
{
    for(auto i:tree)
        cout<<i<<" ";
    cout<<endl;
}
#endif