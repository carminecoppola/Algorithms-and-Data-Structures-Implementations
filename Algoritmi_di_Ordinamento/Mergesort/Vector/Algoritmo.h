#ifndef ALGORITMO_H
#define ALGOTITMO_H

#include <vector>
using namespace std;

template <class Item>

class Algoritmo{

    private:
        static void merge(vector<int>::iterator ,vector<int>::iterator,vector<int>::iterator );

    public:
        static void mergesort(vector<int>::iterator ,vector<int>::iterator );
    
};

template <class Item> void Algoritmo <Item>::merge(vector<int>::iterator low ,vector<int>::iterator mediano,vector<int>::iterator high){
    
    typename vector<int>::iterator it;
    typename vector<int>::iterator jt;
    typename vector<int>::iterator kt;
    

    int size = high-low;

    auto centro = (int)(size/2)-1;    //-1 perchè approssimiamo per difetto
    vector<int> a(size);    

    //Parte di SX
    for (it = mediano-1; it != low-1; it--){

        a.at(centro) = *it;
        centro--;
    
    }

    centro=size;
    //Parte di DX
    for (jt = mediano; jt != high; jt++)
    {   
        a.at(centro-1) = *jt;
        centro--;
    }

    //Reimposto il valore di dei puntatori all'inizio e alla fine dell'array
    it = a.begin();
    jt = a.end()-1;

    //Riordino l'array finale
    for (kt = low; kt != high; kt++){
        if (*jt<*it){
            *kt = *jt;
            jt--;
        }
        else{
            *kt=*it;
            it++;
        }
    
    }

}

template <class Item> void Algoritmo <Item>::mergesort(vector<int>::iterator left,vector<int>::iterator right){

    auto size = right - left;

    if (size >= 2)
    {
        auto centro = left;
        advance(centro,size/2);
        mergesort(left,centro);
        mergesort(centro,right);
        merge(left,centro,right);
    }
}


#endif