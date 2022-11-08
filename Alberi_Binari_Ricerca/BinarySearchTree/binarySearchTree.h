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

        int minimumTree();
        int maximumTree();
        int predecessorTree();
        int successorTree();
        void insertTree(Item value);
        void deleteTree();
        void preOrderVisit(Nodo<Item> *current);
        void inOrderVisit(Nodo<Item> *current);
};

template<class Item> binarySearchTree<Item>::binarySearchTree(){
    root = nullptr;
}

template<class Item> void binarySearchTree<Item>::insertTree(Item value){

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
        preOrderVisit(current->getRight());
        cout<<current->getInfo()<<" ";
    }
    
}

#endif