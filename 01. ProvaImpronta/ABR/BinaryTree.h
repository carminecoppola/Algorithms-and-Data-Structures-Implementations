#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include<vector>
#include"Nodo.h"

using namespace std;

template<class T>
class BinaryTree
{
    private:
        Nodo<T> *root;

        void insertRicorsivo(T ,Nodo<T> * , Nodo<T> * );
        void insertNodo(T ,Nodo<T> * , Nodo<T> * );

        Nodo<T> *findSuccessor(Nodo<T> *);
        Nodo<T> *findPredecessor(Nodo<T> *);
        
    public:
        BinaryTree();

        Nodo<T> *getRoot(){return root;}

        void insert(T value);
        Nodo<T> *treeSearch(Nodo<T> *x, T key);

        Nodo<T> *getMinimum(Nodo<T> *);
        Nodo<T> *getMaximum(Nodo<T> *);
        Nodo<T> *successor(Nodo<T> *);
        Nodo<T> *predecessor(Nodo<T> *);

        void visitInOrder(Nodo<T> *x);
        void visitPreOrder(Nodo<T> *x);
        void visitPostOrder(Nodo<T> *x);
};

//Costruttore
template<class T> BinaryTree <T>::BinaryTree()
{
    root = nullptr;
}

//Insert
template<class T> void BinaryTree<T>::insert(T value)
{
    insertRicorsivo(value, nullptr, root);
}

//Insert Ricorsivo
template<class T> void BinaryTree <T>::insertRicorsivo(T value,Nodo<T> *prev , Nodo<T> *curr)
{ 
    if (root == nullptr)
        root == new Nodo<T>(value);

    else if(curr == nullptr)
        insertNodo(value, prev, curr);

    else if(curr->getInfo() > value)
        insertRicorsivo(value, curr, curr->getLeft());

    else
        insertRicorsivo(value, curr, curr->getRight());
    
}

//Insert Nodo
template<class T> void BinaryTree<T>::insertNodo(T value, Nodo<T> *prev, Nodo<T> *curr)
{
    curr = new Nodo<T>(value);
    curr->setParent(prev);  //Setto il padre che sarà l'elemento precedente

    if(curr->getInfo() < prev->getInfo())   //Se il nodo corrente è maggiore di quello precedente lo metto DX
        prev->setLeft(curr);
    else
        prev->setRight(curr);        
}

//TREE SEARCH
template<class T> Nodo<T> *BinaryTree<T>::treeSearch(Nodo<T> *x, T key)
{
    if( x == nullptr || key == x->getInfo() )
        return x;
    else if( key < x->getInfo())
        return treeSearch(x->getLeft(),key);
    else
        return treeSearch(x->getRight(),key);
}

//MINIMO
template<class T> Nodo<T> * BinaryTree<T>::getMinimum(Nodo<T> *x)
{
    if(root == nullptr)
        return nullptr;
    else if (x->getLeft() == nullptr)
        return x;
    else
        return getMinimum(x->getLeft());
}

//MASSIMO
template<class T> Nodo<T> * BinaryTree<T>::getMaximum(Nodo<T> *x)
{
    if(root == nullptr)
        return nullptr;
    else if (x->getRight() == nullptr)
        return x;
    else
        return getMaximum(x->getRight());
}

//SUCCESSOR
template<class T> Nodo<T> * BinaryTree<T>::successor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;
    else if(x->getRight() != nullptr)
        return getMinimum(x->getRight());
    else
        return findSuccessor(x);
}

//FIND SUCCESSOR
template<class T> Nodo<T> * BinaryTree<T>::findSuccessor(Nodo<T> *x)
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

//PREDECESSOR
template<class T> Nodo<T> * BinaryTree<T>::predecessor(Nodo<T> *x)
{
    if(x == nullptr)
        return nullptr;
    else if(x->getLeft() != nullptr)
        return getMaximum(x->getLeft());
    else
        return findPredecessor(x);
}

//FIND PREDECESSOR
template<class T> Nodo<T> * BinaryTree<T>::findPredecessor(Nodo<T> *x)
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

//VISITE
template<class T> void BinaryTree<T>::visitInOrder(Nodo<T> *x)
{
    if( x != nullptr){
        visitInOrder(x->getLeft());
        cout << x->getInfo() << " ";   //E la radice
        visitInOrder(x->getRight());
    }
}

template<class T> void BinaryTree<T>::visitPostOrder(Nodo<T> *x)
{
    if( x != nullptr){
        visitPostOrder(x->getLeft());
        visitPostOrder(x->getRight());
        cout << x->getInfo() << " ";   //E la radice
    }
}

template<class T> void BinaryTree<T>::visitPreOrder(Nodo<T> *x)
{
    if( x != nullptr){
        cout << x->getInfo() << " ";   //E la radice
        visitPreOrder(x->getLeft());
        visitPreOrder(x->getRight());
    }
}

#endif