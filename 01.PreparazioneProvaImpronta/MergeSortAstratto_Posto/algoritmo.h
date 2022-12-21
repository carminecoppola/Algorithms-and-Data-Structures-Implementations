#ifndef ALGORITMO_H
#define ALGORITMO_H


/*Merge astratto sul posto quindi abbiamo due sottoarray dove uno e ordinato 
in modo crescente e l'altro in modo decrescente;*/

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class algoritmo
{
private:
    static void merge(vector<int>::iterator start, vector<int>::iterator mid ,vector<int>::iterator end);
public:
    static void mergesort(vector<int>::iterator start, vector<int>::iterator end);
};

template<class T> void algoritmo<T>::merge(vector<int>::iterator start, vector<int>::iterator mid ,vector<int>::iterator end){

    //Ci serviranno 3 iteratori
    vector<int>::iterator it;
    vector<int>::iterator jt;
    vector<int>::iterator kt;

    //Calcoliamo il size
    int size = end-start;

    /*Calcoliamo il centro ed utilizziamo la variabile di tipo auto visto che parliamo di template
      e facciamo il cast ad (int). */
    auto centro = (int) (size/2)-1;         // Mettiamo (-1) poiche approssimiamo per difetto;

    //Creiamo il nostro array di vector
    vector<int> a(size);

    //Parte di SX

    for(it = mid-1 ; it != start-1 ; it--){
        a.at(centro) = *it;
        centro --;
    }

    centro = size;
    //Parte di DX

    for(jt = mid ; jt != end; jt ++){
        a.at(centro-1) = *jt;
        centro --;
    }
    
    //Riordiniamo l'array
    
    it = a.begin();
    jt = a.end()-1;

    for(kt = start; kt != end; kt++){

        if(*jt < *it){
            *kt = *jt;
            jt --;
        }
        else{
            *kt = *it;
            it ++;
        }

    }
    

}

template<class T> void algoritmo<T>::mergesort(vector<int>::iterator start, vector<int>::iterator end){

    auto size = end-start;

    if (size >= 2)
    {
        auto mid = start;
        advance(mid,size/2);
        mergesort(start,mid);
        mergesort(mid,end);
        merge(start,mid,end);
    }
    
}

#endif