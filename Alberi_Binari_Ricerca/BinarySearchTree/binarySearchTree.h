#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>
#include<vector>

using namespace std;

template<class Item>
class binarySearchTree{
    private:
        vector<Item> tree;
        int size;
        int parent(int i){
            int padre = (i+1)/2;
            return padre;
        };
        int left(int i){
            int sx = (i*2)+1;
            return sx;
        };
        int right(int i){
            int dx = (i*2)+2;
            return dx;
        };
    public:
        binarySearchTree(vector<Item> );

        Item minimumTree(vector<Item> );
        int maximumTree();
        int predecessorTree();
        int successorTree();
        void insertTree();
        void deleteTree();
};

//Costruttore
template<class Item> binarySearchTree <Item>::binarySearchTree(vector<Item>albero){
    tree = albero;
    size = 0;
}

template<class Item> Item binarySearchTree <Item>::minimumTree(vector<Item> albero){

    while(left(albero)!= nullptr){
        albero = left(albero);
    }
    return albero;
}

#endif