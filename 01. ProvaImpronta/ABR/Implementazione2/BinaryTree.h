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

        nodo<T> *findSuccessor(nodo<T> *x);
        nodo<T> *findPredecessor(nodo<T> *x);
    public:
        BinaryTree(/* args */);

        nodo<T> *getRoot(){return root;}

        void insert(T value);
        nodo<T> *treeSearch(nodo<T> *x ,T key);

        nodo<T> *getMaximum(nodo<T> *x);
        nodo<T> *getMinimum(nodo<T> *x);

        nodo<T> *successor(nodo<T> *x);
        nodo<T> *predecessor(nodo<T> *x);

        void treeDelete(nodo<T> *x);
        void transplant(nodo<T> *x, nodo<T> *y );

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

//INSERT NODO
template<class T> void BinaryTree<T>::insertNodo(T value, nodo<T> *prev, nodo<T> *curr)
{
    curr = new nodo<T>(value);
    curr->setParent(prev);

    if(curr->getInfo() > prev->getInfo())
        prev->setRight(curr);
    else
        prev->setLeft(curr);
}

//TREE SEARCH
template<class T> nodo<T> *BinaryTree<T>::treeSearch(nodo<T> *x, T key)
{
    if(x == nullptr || key == x->getInfo())
        return x;
    if( key < x->getInfo())
        return treeSearch(x->getLeft(),key);
    else
        return treeSearch(x->getRight(),key);

}

//GET MAXIMUM
template<class T> nodo<T> *BinaryTree<T>::getMaximum(nodo<T> *x)
{
    if(root == nullptr)
        return nullptr;
    else if(x->getRight() == nullptr)
        return x;
    else
        return getMaximum(x->getRight());
} 

//GET MINIMUM
template<class T> nodo<T> *BinaryTree<T>::getMinimum(nodo<T> *x)
{
    if(root == nullptr)
        return nullptr;
    else if(x->getLeft() == nullptr)
        return x;
    else
        return getMinimum(x->getLeft());
}

//SUCCESSORE
template<class T> nodo<T> *BinaryTree<T>::successor(nodo<T> *x)
{
    if (x == nullptr)
        return nullptr;
    else if(x->getRight() != nullptr)
        return getMinimum(x->getRight());
    else
        return findSuccessor(x);
}

//FindSuccessor
template<class T> nodo<T> *BinaryTree<T>::findSuccessor(nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;
    
    nodo<T> *y = x->getParent();

    if(y == nullptr)
        return nullptr;
    else if(x == y->getLeft())
        return y;
    else  
        return findSuccessor(y);
}

//PREDECESSORE
template<class T> nodo<T> *BinaryTree<T>::predecessor(nodo<T> *x)
{
    if (x == nullptr)
        return nullptr;
    else if(x->getLeft() != nullptr)
        return getMaximum(x->getLeft());
    else
        return findPredecessor(x);
}

//FindPredecessor
template<class T> nodo<T> *BinaryTree<T>::findPredecessor(nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;
    
    nodo<T> *y = x->getParent();

    if(y == nullptr)
        return nullptr;
    else if(x == y->getRight())
        return y;
    else  
        return findPredecessor(y);
}

//DELETE
template<class T> void BinaryTree<T>::treeDelete(nodo<T> *x)
{
    if(x == nullptr)
        x = nullptr;
    if(x->getLeft() == nullptr)
        transplant(x,x->getRight());
    else if(x->getRight() == nullptr)
        transplant(x,x->getLeft());

    else
    {
        nodo<T> *y = successor(x);
        if(y->getParent() != x)
        {
            transplant(y,y->getRight());
            y->setRight(x->getRight());
            (y->getRight()->setParent(y));
        }
        transplant(x,y);
        y->setLeft(x->getLeft());
        (y->getLeft())->setParent(y);
    }
}
//TRANSPLANT
template<class T> void BinaryTree<T>::transplant(nodo<T> *x, nodo<T> *y)
{
   if(x->getParent() == nullptr)
        root = y;
    else if( x  == (x->getParent())->getLeft())
        (x->getParent())->setLeft(y);
    else
        (x->getParent())->setRight(y);

    if(y != nullptr)
        y->setParent(x->getParent());
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