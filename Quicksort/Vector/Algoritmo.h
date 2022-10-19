/*  Riscrivere il quicksort utilizzando il contenitore Vector
    ed gli iteratori 
*/
#ifndef ALGORITMO_H
#define ALGORITMO_H

#include "vector"
using namespace std;

template <class Item>

class Algoritmo{
    private:
        static int partition(vector<int>::iterator,vector<int>::iterator);
        static void swap(Item &,Item  &);
    public:
        static void quicksort(vector<int>::iterator ,vector<int>::iterator );
};


template <class Item> int Algoritmo <Item>::partition(vector<int>::iterator l,vector<int>::iterator r){

    typename vector<int>::iterator it;   
    typename vector<int>::iterator jt;  //Scorre l'array
       

    it = l-1;    //Imposto l'indice inizialmente a SX fuori dall'array 
    jt = r-1;
    auto pivot = *(r-1);   //Imposto la posizione del pivot che si trova all'estremo destro

    for (;;)    //Finchè è vero
    {
        while (*(++it) < pivot)
            while (pivot < *(--jt))
                if (jt == l)
                   break;   
        if (it >= jt)
            break;
            

            swap(*it,*jt); 
        
    }//Fine del FOR
    swap(*it,*r);
    return it;
}

template <class Item> void Algoritmo <Item>::swap(Item &a,Item  &b){

    auto t = a;
    a = b;
    b = a;

}

template <class Item> void Algoritmo <Item>::quicksort(vector<int>::iterator l,vector<int>::iterator r){

    l = begin();
    r = end();

    if (r <= 1)
        return;
    auto i = partition(l,r);
    quicksort(l,i-1);  //Porzione prima pivot
    quicksort(i+1,r); //Porzione dopo pivot

}

#endif //ALGORITMO_H