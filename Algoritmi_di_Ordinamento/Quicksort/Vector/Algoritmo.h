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
        static typename vector<Item>::iterator partition(typename vector<Item>::iterator,typename vector<Item>::iterator);
        static void swap(Item &,Item  &);
    public:
        static void quicksort(typename vector<Item>::iterator ,typename vector<Item>::iterator );
};


template <class Item> typename vector<Item>::iterator Algoritmo <Item>::partition(typename vector<Item>::iterator l,typename vector<Item>::iterator r){

    typename vector<Item>::iterator it;   
    typename vector<Item>::iterator jt;  //Scorre l'array
       

    it = l-1;    //Imposto l'indice inizialmente a SX fuori dall'array 
    jt = r;
    Item pivot = *(r);   //Imposto la posizione del pivot che si trova all'estremo destro

    for (;;)    //Finchè è vero
    {
        while (*(++it) < pivot);
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

    Item t = a;
    a = b;
    b = t;

}

template <class Item> void Algoritmo <Item>::quicksort(typename vector<Item>::iterator l,typename vector<Item>::iterator r){

    if (r <= l)
        return;
    auto i = partition(l,r);
    quicksort(l,i-1);  //Porzione prima pivot
    quicksort(i+1,r); //Porzione dopo pivot

}

#endif //ALGORITMO_H