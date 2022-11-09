#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>
#include<vector>
#include"nodo.h"
#define vuoto 5

using namespace std;

template<class Item>
class binarySearchTree{
    private:
       Nodo<Item> *root;
    public:
        binarySearchTree();

        Nodo<Item> *getRoot(){
            return root;
        };

        bool isEmpty(){
            if (root == NULL)
                return true;
            return false;
        }

        Nodo<Item> *treeSearch(Item, Nodo<Item> * );
        Nodo<Item> *minimumTree(Nodo<Item> *);
        Nodo<Item> *maximumTree(Nodo<Item> *);

        int predecessorTree();
        int successorTree();

        void insertTreeIter(Item value);
        void insertTreeRicors(Item , Nodo<Item>* ,Nodo<Item> * );
        void insert(Item, Nodo<Item> * , Nodo<Item> * );
        void deleteTree();

        void preOrderVisit(Nodo<Item> *current);
        void inOrderVisit(Nodo<Item> *current);
        void postOrderVisit(Nodo<Item> *current);
};

//Costruttore
template<class Item> binarySearchTree<Item>::binarySearchTree(){
    root = nullptr;
}

//Search
template<class Item> Nodo<Item> *binarySearchTree<Item>::treeSearch(Item key, Nodo<Item> *x){
    
    if (x == nullptr || key == x->getInfo())
        return x;
    if (key < x->getInfo())
        return treeSearch(key, x->getLeft());
    else
        return treeSearch(key,x->getRight());
    
    
}
//Insert
template<class Item> void binarySearchTree<Item>::insertTreeIter(Item value){

    Nodo<Item> *nodeToInsert = new Nodo<Item>(value);
    Nodo<Item> *parent = nullptr;
    Nodo<Item> *current = root;

    while (current != nullptr)
    {
        parent = current;
        if (nodeToInsert->getInfo() < current->getInfo()){
            current = current->getLeft();
        }
        else{
            current = current->getRight();
        }
        
    }

    //Nodo inseguitore
    nodeToInsert->setParent(parent);

    if (parent == nullptr)
        root = nodeToInsert;
    else if(nodeToInsert->getInfo() < parent->getInfo())
        parent->setLeft(nodeToInsert);
    else
        parent->setRight(nodeToInsert);

}

template<class Item> void binarySearchTree<Item>::insertTreeRicors(Item nodoNew, Nodo<Item> *prev,Nodo<Item> *curr){

    if (root == nullptr){
        root = new Nodo<Item>(nodoNew);
    }
    //Caso Base
    if (curr == nullptr)
        insert(nodoNew,prev,curr);   
    //Ricorsione SX
    else if(curr->getInfo() > nodoNew){
        insertTreeRicors(nodoNew,curr,curr->getLeft());
    }
    //Ricorsione DX
    else{
        insertTreeRicors(nodoNew,curr,curr->getRight());
    }

}

template<class Item> void binarySearchTree<Item>::insert(Item nodoNew, Nodo<Item> *prev,Nodo<Item> *curr){

    curr = new Nodo<Item>(nodoNew);
    curr->setParent(prev);
    if(prev == nullptr){
        root = curr;
    }
    else if (curr->getInfo() > prev->getInfo()){
        prev->setRight(curr);
    }
    else{
        prev->setLeft(curr);
    }
    
}

//Min && Max
template<class Item> Nodo<Item> *binarySearchTree<Item>::minimumTree(Nodo<Item> *radice){

    if (isEmpty())
        return nullptr;
    else if(radice->getLeft() == nullptr)
        return radice;
    else
        return minimumTree(radice->getLeft());
    
}

template<class Item> Nodo<Item> *binarySearchTree<Item>::maximumTree(Nodo<Item> *radice){
    if (isEmpty())
        return nullptr;
    else if(radice->getRight() == nullptr)
        return radice;
    else
        return maximumTree(radice->getRight());
}
//Visite
template<class Item> void binarySearchTree<Item>::preOrderVisit(Nodo<Item> *current){

    if( current != nullptr){

        cout<<current->getInfo()<<" ";
        preOrderVisit(current->getLeft());
        preOrderVisit(current->getRight());
    }
}

template <class Item> void binarySearchTree <Item>::inOrderVisit(Nodo<Item> *current){
    if (current != nullptr)
    {
        preOrderVisit(current->getLeft());
        cout<<current->getInfo()<<" ";
        preOrderVisit(current->getRight());
    }
    
}

template <class Item> void binarySearchTree <Item>::postOrderVisit(Nodo<Item> *current){
    if (current != nullptr)
    {
        preOrderVisit(current->getLeft());
        preOrderVisit(current->getRight());
        cout<<current->getInfo()<<" ";
    }
    
}

#endif