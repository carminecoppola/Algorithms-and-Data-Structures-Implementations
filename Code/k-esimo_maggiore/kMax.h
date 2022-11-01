#ifndef KMAX_H
#define KMAX_H

#include <iostream>
#include <vector>
#include"minHeap.h"

using namespace std;

template <class Item>
class kMax : public minHeap <Item>{
    private:
        /* data */
    public:
        kMax(vector<Item> albero, int k);
        void insertMH(Item x);
        Item minimum();
        Item extractMin();
        Item secondoMin();
        void decreasePriority(int, Item);
};

//Costruttore
template <class Item> kMax<Item>::kMax(vector<Item> albero,int k):minHeap<Item>(albero,k){

}

template<class Item> void kMax <Item>::insertMH(Item x){
    this->insert(x);

}

template<class Item> Item kMax <Item>::minimum(){
    return this->getAlbero().at(0);
}

template<class Item> Item kMax<Item>::extractMin(){

    if (this->getSize() == 0){
        return -1;
    }
    int min = minimum();

    swap(this->albero.at(0),this->albero.at(this->getSize()-1));
    this->setSize(this->getSize()-1);
    this->minHeapify(0);

    return min;
   
}

template<class Item> void kMax <Item>::decreasePriority(int i, Item key){

    if (key < this->getAlbero().at(i)){
        cout<<"Invalid Data"<<endl;
        exit;
    }

    this->albero.at(i) = key;
        
    while(i > 0 && this->getAlbero().at(this->parent(i)) > this->getAlbero().at(i))
    {
        swap(this->albero.at(this->parent(i)),this->albero.at(i));
        i = this->parent(i);
    }

}

#endif