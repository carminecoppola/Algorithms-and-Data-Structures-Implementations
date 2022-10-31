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
        kMax(vector<Item> albero);
        //Item maximum();
        Item minimum();
        //Item extractMax();
        Item extractMin();
        Item secondoMin();
        void decreasePriority(int, Item);
};

//Costruttore
template <class Item> kMax<Item>::kMax(vector<Item> albero):minHeap<Item>(albero){}



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

template<class Item> Item kMax<Item>::secondoMin(){
    
    int max1,max2;

    max1=minimum();
    cout<<"Max1: "<<max1<<endl;
    max2=minimum();
    cout<<"Max2: "<<max2<<endl;


    for (int i = 0; i < this->getSize(); i++)
    {
        if (this->albero.at(i) > max1){
            swap(this->albero.at(i),max1);
            cout<<"\nA[i]: "<<this->albero.at(i)<<endl;
            cout<<"Max1: "<<max1<<endl;
            cout<<"Max2: "<<max2<<endl;
        }
        else if(this->albero.at(i) > max2){
            swap(this->albero.at(i),max2);
            cout<<"\nA[i]: "<<this->albero.at(i)<<endl;
            cout<<"Max1: "<<max1<<endl;
            cout<<"Max2: "<<max2<<endl;
        }
        else if(max1 < max2){
            //swap(max1,max2);
            max2=max1;
        }
        cout<<"\nA[i]: "<<this->albero.at(i)<<endl;
        cout<<"Max1: "<<max1<<endl;
        cout<<"Max2: "<<max2<<endl;
        
    }

    return max2;
    
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