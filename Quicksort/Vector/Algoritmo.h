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
        static void partition(vector<Item> ,vector<int>::iterator,vector<int>::iterator);
        static void swap(Item &,Item  &);
    public:
        static void quicksort(vector<Item> ,vector<int>::iterator ,vector<int>::iterator );
};


template <class Item> void Algoritmo <Item>::partition(vector<Item> a,vector<int>::iterator l,vector<int>::iterator r ){

    typename vector<int>::iterator it;   
    typename vector<int>::iterator jt;  //Scorre l'array
       

    it = a.begin()-1;    //Imposto l'indice inizialmente a SX fuori dall'array 
    auto pivot = a.end()-1;      //Imposto la posizione del pivot che si trova all'estremo destro

    for (;;)    //Finchè è vero
    {
        while (*(++it) < pivot){

            while (pivot > *(--jt)){
                if (jt == l){
                   break;
                }
            if (it >= jt){
                    break;
            }
            swap();  
            }
        swap
        }
        
    }
    

}

template <class Item> void Algoritmo <Item>::swap(Item &a,Item  &b){

    auto t = *a;
    *a = *b;
    *b = *a;

}

template <class Item> void Algoritmo <Item>::quicksort(vector<Item> array,vector<int>::iterator l,vector<int>::iterator r){

}

#endif //ALGORITMO_H