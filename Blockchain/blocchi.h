
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
        int id;
        linkedList<Transazioni> *lista;
    public:
        Blocchi(int ,linkedList<Transazioni> *);
        //~Blocchi();
        void setID(int );
        void setLista(linkedList<Transazioni> *);
        int getID(){
            return id;
        }
        linkedList<Transazioni>* getLista(){
            return lista;
        }



};

Blocchi::Blocchi(int i, linkedList<Transazioni> *l){
}

void Blocchi::setID(int i){
     id = i;
}

void Blocchi::setLista(linkedList<Transazioni> *lst){
    lista = lst;
}

//Blocchi::~Blocchi(){}

#endif //BLOCCHI_H