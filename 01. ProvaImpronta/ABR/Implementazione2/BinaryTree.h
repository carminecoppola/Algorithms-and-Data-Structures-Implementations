#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include "nodo.h"

using namespace std;

template<class T>
class BinaryTree
{
    private:
        Nodo<T> *root;

        void insertRic(T value,Nodo<T> *prev , Nodo<T> *curr);
        void insertNodo(T, Nodo<T> * ,Nodo<T> * );

        Nodo<T> *findSuccessor();
        Nodo<T> *findPredecessor();
    public:
        BinaryTree(/* args */);

        Nodo<T> *getRoot(){return root;}

        void insert(T value);

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
template <class T> void BinaryTree<T>::insertRic(T value,Nodo<T> *prev , Nodo<T> *curr)
{
    if(root == nullptr)
        root = new Nodo<T>(value);
}
#endif