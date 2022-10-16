#ifndef ALGORITMO_H
#define ALGOTITMO_H

#include "vector"
using namespace std;

template <class Item>

class Algoritmo{

    private:
        static void merge(vector<Item>[] ,Item);

    public:
        static void mergesort(vector<Item>[],vector<int>::iterator ,vector<int>::iterator );
    
};

template <class Item> void Algoritmo <Item>::merge(vector<Item> a[], Item center){
    
    vector<Item> aux[];         //Array di vector
    vector<int>::iterator it;
    vector<int>::iterator jt;


    for (it = center + 1; it > aux.begin(); it++){
        aux.at(*it-1) = a.at(*it-1);
    }

    for (jt = center + 1; jt < aux.end(); jt++){
        aux.at(aux.end() + center - *jt) = a.at(*jt+1);
    }
    
    for (vector<int>::iterator kt = aux.begin(); kt < aux.end(); kt++){
        if (aux.at(*jt) < aux.at(*it)){
            a.at(*kt) = aux.at(*jt--);  
        }
        else
            a.at(*kt) = aux.at(*it++);  
    }
}

template <class Item> void Algoritmo <Item>::mergesort(vector<Item> a,vector<int>::iterator begin,vector<int>::iterator end){

    if (left<right)
    {
        Item center = (left+right)/2;
        mergesort(a,left,center);
        mergesort(a,center+1,right);
        Algoritmo<int>::merge(a,center);
    }
}


#endif