#ifndef NODO_H
#define NODO_H 
#include "linkedList.h"
#include <iostream>

template <class T>

class Nodo{
    private:
        T *info;
        Nodo<T> *nextnodo;
    public:
        Nodo(T* );
        //~Nodo();
        void setInfo(T *);
        void setNext(Nodo <T> *);
        T *getInfo(){
            return info;
        }
        Nodo <T> *getNext(){
            return nextnodo;
        }
};

//Costruttore
template <class T> Nodo<T>::Nodo(T* i){
    info = i;
    nextnodo = nullptr;
}

//Nodo::~Nodo(){}
template <class T> void Nodo<T>::setInfo(T *inf){
    info = inf;
}


template <class T> void Nodo<T>::setNext(Nodo <T> *next){
    nextnodo = next;
}

#endif //NODO_H
