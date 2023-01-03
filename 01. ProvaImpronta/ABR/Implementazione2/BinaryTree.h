#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include "nodo.h"

using namespace std;

template<class T>
class BinaryTree
{
    private:
        nodo<T> *root;

        void insertRic(T value,nodo<T> *prev , nodo<T> *curr);
        void insertNodo(T, nodo<T> * ,nodo<T> * );

        nodo<T> *findSuccessor();
        nodo<T> *findPredecessor();
    public:
        BinaryTree(/* args */);

        nodo<T> *getRoot(){return root;}

        void insert(T value);

        void visitInOrder(nodo<T> *x);

};

//Costruttore
template<class T> BinaryTree<T>::BinaryTree(/* args */)
{
    root = nullptr;
}

//INSERT
template <class T> void BinaryTree<T>::insert(T value)
{
    insertRic(value,nullptr,root);
}

//INSERT RIC
template <class T> void BinaryTree<T>::insertRic(T value,nodo<T> *prev , nodo<T> *curr)
{
    if(root == nullptr)
        root = new nodo<T>(value);
    else if(curr == nullptr)
        insertNodo(value,prev,curr);
    else if(curr->getInfo() > value)
        insertRic(value,curr,curr->getLeft());
    else
        insertRic(value,curr,curr->getRight());
}

template<class T> void BinaryTree<T>::insertNodo(T value, nodo<T> *prev, nodo<T> *curr)
{
    curr = new nodo<T>(value);
    curr->setParent(prev);

    if(curr->getInfo() > prev->getInfo())
        prev->setRight(curr);
    else
        prev->setLeft(curr);
}


//VISITE
template<class T> void BinaryTree<T>::visitInOrder(nodo<T> *x)
{
    if( x != nullptr){
        visitInOrder(x->getLeft());
        cout << x->getInfo() << " ";   //E la radice
        visitInOrder(x->getRight());
    }
}
#endif