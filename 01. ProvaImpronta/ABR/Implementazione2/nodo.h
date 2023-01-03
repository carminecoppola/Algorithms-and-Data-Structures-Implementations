#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

template<class T>
class nodo
{
    private:
        nodo<T> *parent;
        nodo<T> *left;
        nodo<T> *right;

        T  info;
    public:
        nodo(T info);
        ~nodo();

        void setParent(nodo<T> *p){parent = p;}
        void setLeft(nodo<T> *l){left = l;}
        void setRight(nodo<T> *r){right = r;}

        nodo<T> *getParent(){return parent;}
        nodo<T> *getLeft(){return left;}
        nodo<T> *getRight(){return right;}
        T getInfo(){return info;}
};

template<class T> nodo<T>::nodo(T info)
{
    this->info = info;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

template<class T> nodo<T>::~nodo()
{
    delete parent;
    delete left;
    delete right;
    delete info;
}


#endif