#ifndef NODI_H
#define NODI_H
#include <iostream>
#include "impiegato.h"

class Nodi{

    private:
        Impiegato *info; //Puntatore ad impiegato
        Nodi *nextnodo; //Puntatore al prossimo nodo
    public:
        Nodi(Impiegato *);

        void setInfo(Impiegato *);
        void setNext(Nodi *);

        Impiegato *getInfo(){
            return info;
        }
        
        Nodi *getNext(){
            return nextnodo;
        }
    
};

Nodi::Nodi(Impiegato *i){
    info = i;
    nextnodo = nullptr;
}

void Nodi::setInfo(Impiegato *i){

    info = i;
}

void Nodi::setNext(Nodi *nodo){

    nextnodo = nodo;
}

#endif //NODI_H