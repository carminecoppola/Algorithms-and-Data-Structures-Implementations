
#ifndef BLOCCHI_H
#define BLOCCHI_H
#include <iostream>
#include <string>
#include "linkedList.h"
#include "transazioni.h"

using namespace std;
//template <class T>

class Blocchi{
    private:
        linkedList<Transazioni> *lista;
    public:
        Blocchi(linkedList<Transazioni> *);
        //~Blocchi();


};

Blocchi::Blocchi(linkedList<Transazioni> *l){
    lista = l;
}

//Blocchi::~Blocchi(){}

#endif //BLOCCHI_H