#ifndef ALGORITMO_H
#define ALGORITMO_H

#include "vector"
#include "Stack.h"
using namespace std;

template <class Item>

class Algoritmo{
    private:
        static int partition(Item [], int ,int);
        static void swap(Item &,Item  &);
    public:
        static void quicksort_iterativo(Item [], int ,int);
};


template <class Item> int Algoritmo <Item>::partition(Item a[], int l,int r){

    int i= l-1, j=r;
    int v = a[r];

    for(;;)
    {
        while (a[++i] < v);
        while (v < a[--j])
            if(j == l)
                break;
        if (i >= j)
            break;
        swap (a[i],a[j]);
    }
    swap(a[i],a[r]);
    return i;
}

template <class Item> void Algoritmo <Item>::swap(Item &a,Item  &b){

    Item t = a;
    a = b;
    b = t;

}

template <class Item> void Algoritmo <Item>::quicksort_iterativo(Item a[], int l,int r){

    Stack <Item> Sti;   //Crea Stack
    Sti.Push(l);        //Inserisci l e r nello Stack
    Sti.Push(r);
    //Finchè ci sono elementi nello Stack estrai l e r
    while (!Sti.isEmpty())
    {
        Sti.Pop(r);
        Sti.Pop(l);

        int p = partition(a,l,r);

        if (l < p)
        {
           Sti.Push(l);
           Sti.Push(p-1);
        }
        
        else if (p < r)
        {
            Sti.Push(p+1);
            Sti.Push(r);
        }
    }
}



#endif //ALGORITMO_H