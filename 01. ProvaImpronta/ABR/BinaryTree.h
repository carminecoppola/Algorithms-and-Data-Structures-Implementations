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

        void insertRicorsivo(T ,Nodo<T>* , Nodo<T>* );
        void insertNodo(T ,Nodo<T>* , Nodo<T>* );

        Nodo<T> *findSuccessor(Nodo<T> *);
        Nodo<T> *findPredecessor(Nodo<T> *);
        
    public:
        BinaryTree(/* args */);

        Nodo<T> *getRoot(){return root;}

        void insert(T);
        Nodo<T> *treeSearch(Nodo<T> *, T);
        Nodo<T> *getMinimum(Nodo<T> *);
        Nodo<T> *getMaximum(Nodo<T> *);
        Nodo<T> *successor(Nodo<T> *);
        Nodo<T> *predecessor(Nodo<T> *);

        void visitInOrder(Nodo<T> *);
        void visitPreOrder(Nodo<T> *);
        void visitPostOrder(Nodo<T> *);
};

//Costruttore
template<class T> BinaryTree <T>::BinaryTree(/* args */)
{
    root = nullptr;
}

//Insert
template<class T> void BinaryTree<T>::insert(T value)
{
    insertRicorsivo(value,nullptr,root);
}

//Insert Ricorsivo
template<class T> void BinaryTree <T>::insertRicorsivo(T value,Nodo<T> *prev , Nodo<T> *curr)
{ 
    if (root = nullptr)
        root = new Nodo<T>(value);
    else if(curr = nullptr)
        insertNodo(value,prev,curr);
    else if(curr->getInfo() > value)
        insertRicorsivo(value,curr,curr->getLeft());
    else
        insertRicorsivo(value,curr,curr->getRight());
    
}

//Insert Nodo
template<class T> void BinaryTree<T>::insertNodo(T value, Nodo<T> *prev, Nodo<T> *curr)
{
    curr = new Nodo<T>(value);
    curr->setParent(prev);  //Setto il padre che sarà l'elemento precedente

    if(curr->getInfo() > prev->getInfo())   //Se il nodo corrente è maggiore di quello precedente lo metto DX
        prev->setRight(curr);
    else
        prev->setLeft(curr);        
}
#endif