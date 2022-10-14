#ifndef ALGORITMO_H
#define ALGOTITMO_H

#include "vector"
using namespace std;

template <class Item>

class Algoritmo{

    private:
        static void merge(vector<Item> ,Item);

    public:
        static void mergesord();
    
};

template <class Item> void Algoritmo<Item>::merge(vector<Item> a, Item center){
    
    vector<Item> aux;

    for (vector<int>::iterator it = center + 1; it != a.begin() ; it--){
        aux.at(*it-1) = a.at(*it-1);
    }
    
    for (vector<int>::iterator it = center; it != a.end() ; it++){
        aux.at(a.end()+center-*it) = a.at(*it+1);
    }

    for (vector<int>::iterator it = center; it != a.end() ; it++){
        if (/* condition */){
            
        }
        
    }
}


#endif