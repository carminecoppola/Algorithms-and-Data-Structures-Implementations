#ifndef NODO_H
#define NODO_H

#include<iostream>
using namespace std;

template<class Item>
class Nodo{
    private:
        Item info;
        Nodo *parent;
        Nodo *left;
        Nodo *right;
    public:
        Nodo(Item );    //Costruttore

        void setInfo(Item );
        void setParent(Item * );
        void setLeft(Item * );
        void setRight(Item * );

        Item getInfo(){
            return info;
        };
        Nodo *getParent(){
            return parent;
        };
        Nodo *getLeft(){
            return left;
        };
        Nodo *getRight(){
            return right;
        };
};

template<class Item> Nodo <Item>::Nodo(Item value){
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    info = value;
}

template<class Item> void Nodo<Item>::setInfo(Item i){
    info = i;
}

template<class Item> void Nodo<Item>::setParent(Item *padre){
    parent = padre;
}

template<class Item> void Nodo<Item>::setLeft(Item *sx){
    left = sx;
}

template<class Item> void Nodo<Item>::setRight(Item *dx){
    right = dx;
}


#endif