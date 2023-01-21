#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include"nodo.h"

using namespace std;

template<class T>
class BinaryTree
{
    private:
        Nodo<T> *root;

        //Inserimeto
        void insertRic(T value, Nodo<T> *prev,Nodo<T> *curr);
        void insertNodo(T value, Nodo<T> *prev, Nodo<T> *curr);

        //Succ & Pred
        Nodo<T> *findSuccessor(Nodo<T> *nodo);
        Nodo<T> *findPredecessor(Nodo<T> *nodo);

    public:
        BinaryTree(){root = nullptr;}

        //Metodi di get
        Nodo<T> *getRoot(){return root;}
        Nodo<T> *getMaximum(Nodo<T> *x);
        Nodo<T> *getMinimum(Nodo<T> *x);
        Nodo<T> *successor(Nodo<T> *x);
        Nodo<T> *predecessor(Nodo<T> *x);

        Nodo<T> *treeSearch(Nodo<T> *x, T key);
        void insert(T value);

        void visitInOrder(Nodo<T> *x);
};

//INSERT
template<class T> void BinaryTree<T>::insert(T value)
{
    insertRic(value,nullptr,root);
}

template<class T> void BinaryTree<T>::insertRic(T value,Nodo<T> *prev, Nodo<T> *curr)
{
    if(root == nullptr)
        root = new Nodo<T>(value);
    else if(curr == nullptr)
        insertNodo(value,prev,curr);
    else if(curr->getInfo() > value)
        insertRic(value,curr, curr->getLeft());
    else
        insertRic(value,curr, curr->getRight());
}

template<class T> void BinaryTree<T>::insertNodo(T value, Nodo<T> *prev, Nodo<T> *curr)
{
    curr = new Nodo<T>(value);
    curr->setParent(prev);

    if(curr->getInfo() < prev->getInfo())
        prev->setLeft(curr);
    else
        prev->setRight(curr);
}

//VISIT
template<class T> void BinaryTree<T>::visitInOrder(Nodo<T> *x)
{
    if (x != nullptr){
        visitInOrder(x->getLeft());
        cout<< x->getInfo()<<" ";
        visitInOrder(x->getRight());
    }
}

//MAX && MIN
template<class T> Nodo<T> * BinaryTree<T>::getMaximum(Nodo<T> *x)
{
    if(root == nullptr)
        return nullptr;
    else if(x->getRight() == nullptr)
        return x;
    else   
        return getMaximum(x->getRight());
}

template<class T> Nodo<T> * BinaryTree<T>::getMinimum(Nodo<T> *x)
{
    if(root == nullptr)
        return nullptr;
    else if(x->getLeft() == nullptr)
        return x;
    else   
        return getMinimum(x->getLeft());

    
}

//SUCCESS && PREDECESS
template<class T> Nodo<T> *BinaryTree<T>::successor(Nodo<T> *x)
{
    if (x == nullptr)
        return nullptr;
    else if(x->getRight() != nullptr)
        return getMinimum(x->getRight());
    else
        return findSuccessor(x);
}

template<class T> Nodo<T> *BinaryTree<T>::findSuccessor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;

    Nodo<T> *y = x->getParent();

    if(y == nullptr)
        return nullptr;
    else if(x == y->getLeft())
        return y;
    else
        return findSuccessor(y);
}

template<class T> Nodo<T> *BinaryTree<T>::predecessor(Nodo<T> *x)
{
    if (x == nullptr)
        return nullptr;
    else if(x->getLeft() != nullptr)
        return getMaximum(x->getLeft());
    else
        return findPredecessor(x);
}

template<class T> Nodo<T> *BinaryTree<T>::findPredecessor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;

    Nodo<T> *y = x->getParent();

    if(y == nullptr)
        return nullptr;
    else if(x == y->getRight())
        return y;
    else
        return findPredecessor(y);
}


//TREESEARCH
template<class T> Nodo<T>* BinaryTree<T>::treeSearch(Nodo<T> *x, T key)
{
    if(x == nullptr || key == x->getInfo())
        return x;
    if(key < x->getInfo())
        return treeSearch(x->getLeft(),key);
    else
        return treeSearch(x->getRight(),key);
}


#endif
