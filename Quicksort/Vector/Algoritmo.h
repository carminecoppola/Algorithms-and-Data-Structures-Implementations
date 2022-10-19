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
        static void swap(vector<int>::iterator ,vector<int>::iterator );
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
        while (*(++i) < pivot){

            while (pivot > *(--j)){
                if (j == l){
                    /* code */
                }
                
            }
            
        }
        
    }
    

}

template <class Item> void Algoritmo <Item>::swap(vector<int>::iterator a,vector<int>::iterator b){

    typename vector<int>::iterator t;

    t = a;
    a = b;
    b = a;

}

template <class Item> void Algoritmo <Item>::quicksort(vector<Item> array,vector<int>::iterator l,vector<int>::iterator r){

}

#endif //ALGORITMO_H